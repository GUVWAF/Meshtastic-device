#include "SecondaryCore.h"
#include "esp_task_wdt.h"

// Handle received text messages here
void textMessageHandler(meshtastic_MeshPacket p)
{
    Serial.print("Received text message from ");
    Serial.print(p.from);
    Serial.print(": ");
    Serial.write(p.decoded.payload.bytes, p.decoded.payload.size);
    Serial.println();
}

void core0loop(void *parameter)
{
    while (true) {
        receivePackets();

        // Send a packet every 60 seconds
        static uint32_t lastSend = 0;
        if (millis() - lastSend > 60000) {

            Serial.println("Sending Hello World packet");
            sendTextMessage("Hello World!");

            lastSend = millis();
        }

        esp_task_wdt_reset(); // Reset watchdog
        delay(10);
    }
}

void core0setup(void)
{
    Serial.println("Starting secondary core");
    PacketAPI::create(PacketServer::init());
    packetClient = new PacketClient();
    packetClient->init();
    // Initial connection with API
    packetClient->send(meshtastic_ToRadio{.which_payload_variant = meshtastic_ToRadio_want_config_id_tag, .want_config_id = 1});

    // Set callback for text messages
    textMessageCallback = textMessageHandler;

    xTaskCreatePinnedToCore(core0loop, "core0", 8192, NULL, 1, NULL, 0);
}
