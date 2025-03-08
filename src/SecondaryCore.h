#include "api/PacketAPI.h"
#include "api/PacketClient.h"
#include "api/PacketServer.h"

PacketClient *packetClient = nullptr;
void (*textMessageCallback)(meshtastic_MeshPacket);

// Receive packets from the Meshtastic firmware
void receivePackets()
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
                        Serial.print("Received packet with portnum ");
                        Serial.println(from.packet.decoded.portnum);
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
        Serial.println("No connection to packet client");
        delay(1000);
    }
}

// Send a text message to the Meshtastic firmware
void sendTextMessage(const char *message)
{
    meshtastic_Data data = {.portnum = meshtastic_PortNum_TEXT_MESSAGE_APP};
    memcpy(data.payload.bytes, message, strlen(message));
    data.payload.size = strlen(message);
    meshtastic_MeshPacket packet = {
        .to = 0xFFFFFFFF, .which_payload_variant = meshtastic_MeshPacket_decoded_tag, .decoded = data};
    packetClient->send(meshtastic_ToRadio{.which_payload_variant = meshtastic_ToRadio_packet_tag, .packet = packet});
}