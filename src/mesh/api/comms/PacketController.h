#include "MeshTypes.h"
#include "api/PacketAPI.h"
#include "api/comms/PacketClient.h"

class PacketController
{
  private:
    static void loop(void *);
    void receivePackets(void);

    static PacketController *instance;

    void (*userLoop)(void) = nullptr;
    PacketClient *packetClient = nullptr;

  public:
    PacketController(void (*userLoop)(void));

    void (*textMessageCallback)(meshtastic_MeshPacket);
    void setTextMessageCallback(void (*callback)(meshtastic_MeshPacket)) { textMessageCallback = callback; }

    void (*genericPacketCallback)(meshtastic_MeshPacket);
    void setGenericPacketCallback(void (*callback)(meshtastic_MeshPacket)) { genericPacketCallback = callback; }

    void sendTextMessage(const char *message, NodeNum to = NODENUM_BROADCAST);
};