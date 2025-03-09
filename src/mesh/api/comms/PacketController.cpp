#ifdef USE_PACKET_API
#include "PacketController.h"
#include "DebugConfiguration.h"
#ifdef ARCH_ESP32
#include "esp_task_wdt.h"
#endif

PacketController *PacketController::instance = nullptr;

PacketController::PacketController(void (*userLoop)(void))
{
    LOG_DEBUG("Setting up PacketController...");
    instance = this;
    this->userLoop = userLoop;

    PacketAPI::create(PacketServer::init());

    packetClient = new PacketClient();
    packetClient->init();

    // Initial connection with API
    packetClient->send(meshtastic_ToRadio{.which_payload_variant = meshtastic_ToRadio_want_config_id_tag, .want_config_id = 1});

    xTaskCreatePinnedToCore(PacketController::loop, "PacketController", 8192, NULL, 1, NULL, 0);
}

// Receive packets from the Meshtastic firmware and execute callback functions
void PacketController::receivePackets()
{
    const uint32_t heartBeatInterval = 3 * 60 * 1000;
    static uint32_t lastHeartBeat = 0;
    bool gotPacket = false;
    if (packetClient->isConnected()) {
        do {
            meshtastic_FromRadio from = packetClient->receive();
            if (from.which_payload_variant) {
                switch (from.which_payload_variant) {
                case meshtastic_FromRadio_packet_tag:
                    switch (from.packet.decoded.portnum) {
                    case meshtastic_PortNum_TEXT_MESSAGE_APP:
                        if (textMessageCallback) {
                            textMessageCallback(from.packet);
                        }
                        break;
                    default:
                        if (genericPacketCallback) {
                            genericPacketCallback(from.packet);
                        }
                    }
                }
            }
            gotPacket = from.which_payload_variant != 0;
        } while (gotPacket);

        // Send a heartbeat packet every 3 minutes
        if (millis() - lastHeartBeat > heartBeatInterval) {
            packetClient->send(meshtastic_ToRadio{.which_payload_variant = meshtastic_ToRadio_heartbeat_tag});
            lastHeartBeat = millis();
        }
    } else {
        LOG_WARN("No connection to PacketClient...");
        delay(1000);
    }
}

// Send a text message to the Meshtastic firmware
void PacketController::sendTextMessage(const char *message, NodeNum to)
{
    meshtastic_Data data = {.portnum = meshtastic_PortNum_TEXT_MESSAGE_APP};
    memcpy(data.payload.bytes, message, strlen(message));
    data.payload.size = strlen(message);
    meshtastic_MeshPacket packet = {.to = to, .which_payload_variant = meshtastic_MeshPacket_decoded_tag, .decoded = data};
    packetClient->send(meshtastic_ToRadio{.which_payload_variant = meshtastic_ToRadio_packet_tag, .packet = packet});
}

void PacketController::loop(void *parameter)
{
    PacketController *self = PacketController::instance;

    while (self->userLoop) {
        self->receivePackets();

        self->userLoop();

#ifdef ARCH_ESP32
        esp_task_wdt_reset(); // Reset watchdog
#endif

        delay(10);
    }
}

#endif // USE_PACKET_API