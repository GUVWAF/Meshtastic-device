#ifdef USE_SECONDARY_CORE
#include "Arduino.h"
#include "api/comms/PacketController.h"

PacketController *packetController = nullptr;

// Handle received text messages here
void textMessageHandler(meshtastic_MeshPacket p)
{
    Serial.print("Received text message from ");
    Serial.print(p.from);
    Serial.print(": ");
    Serial.write(p.decoded.payload.bytes, p.decoded.payload.size);
    Serial.println();
}

// Handle received generic packets here
void genericPacketHandler(meshtastic_MeshPacket p)
{
    Serial.print("Received packet with port number ");
    Serial.print(p.decoded.portnum);
    Serial.println();
}

void loop0()
{
    // Send a packet every 60 seconds
    static uint32_t lastSend = 0;
    if (millis() - lastSend > 60000) {

        Serial.println("Sending Hello World packet");
        packetController->sendTextMessage("Hello World!");

        lastSend = millis();
    }
}

void setup0(void)
{
    packetController = new PacketController(loop0);

    // Setup the text message and generic packet handlers
    packetController->setTextMessageCallback(textMessageHandler);
    packetController->setGenericPacketCallback(genericPacketHandler);
}
#endif