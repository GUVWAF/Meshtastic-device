/* Automatically generated nanopb header */
/* Generated by nanopb-0.4.7 */

#ifndef PB_MESHTASTIC_MESHTASTIC_CONNECTION_STATUS_PB_H_INCLUDED
#define PB_MESHTASTIC_MESHTASTIC_CONNECTION_STATUS_PB_H_INCLUDED
#include <pb.h>

#if PB_PROTO_HEADER_VERSION != 40
#error Regenerate this file with the current version of nanopb generator.
#endif

/* Struct definitions */
/* Ethernet or WiFi connection status */
typedef struct _meshtastic_NetworkConnectionStatus {
    /* IP address of device */
    uint32_t ip_address;
    /* Whether the device has an active connection or not */
    bool is_connected;
    /* Whether the device has an active connection to an MQTT broker or not */
    bool is_mqtt_connected;
    /* Whether the device is actively remote syslogging or not */
    bool is_syslog_connected;
} meshtastic_NetworkConnectionStatus;

/* Ethernet connection status */
typedef struct _meshtastic_EthernetConnectionStatus {
    /* Connection status */
    bool has_status;
    meshtastic_NetworkConnectionStatus status;
} meshtastic_EthernetConnectionStatus;

/* WiFi connection status */
typedef struct _meshtastic_WifiConnectionStatus {
    /* Connection status */
    bool has_status;
    meshtastic_EthernetConnectionStatus status;
    /* WiFi access point ssid */
    char ssid[33];
    /* Rssi of wireless connection */
    int32_t rssi;
} meshtastic_WifiConnectionStatus;

/* Bluetooth connection status */
typedef struct _meshtastic_BluetoothConnectionStatus {
    /* The pairing pin for bluetooth */
    uint32_t pin;
    /* Rssi of bluetooth connection */
    int32_t rssi;
    /* Whether the device has an active connection or not */
    bool is_connected;
} meshtastic_BluetoothConnectionStatus;

/* Serial connection status */
typedef struct _meshtastic_SerialConnectionStatus {
    /* The serial baud rate */
    uint32_t baud;
    /* Whether the device has an active connection or not */
    bool is_connected;
} meshtastic_SerialConnectionStatus;

typedef struct _meshtastic_DeviceConnectionStatus {
    /* WiFi Status */
    bool has_wifi;
    meshtastic_WifiConnectionStatus wifi;
    /* WiFi Status */
    bool has_ethernet;
    meshtastic_EthernetConnectionStatus ethernet;
    /* Bluetooth Status */
    bool has_bluetooth;
    meshtastic_BluetoothConnectionStatus bluetooth;
    /* Serial Status */
    bool has_serial;
    meshtastic_SerialConnectionStatus serial;
} meshtastic_DeviceConnectionStatus;


#ifdef __cplusplus
extern "C" {
#endif

/* Initializer values for message structs */
#define meshtastic_DeviceConnectionStatus_init_default {false, meshtastic_WifiConnectionStatus_init_default, false, meshtastic_EthernetConnectionStatus_init_default, false, meshtastic_BluetoothConnectionStatus_init_default, false, meshtastic_SerialConnectionStatus_init_default}
#define meshtastic_WifiConnectionStatus_init_default {false, meshtastic_EthernetConnectionStatus_init_default, "", 0}
#define meshtastic_EthernetConnectionStatus_init_default {false, meshtastic_NetworkConnectionStatus_init_default}
#define meshtastic_NetworkConnectionStatus_init_default {0, 0, 0, 0}
#define meshtastic_BluetoothConnectionStatus_init_default {0, 0, 0}
#define meshtastic_SerialConnectionStatus_init_default {0, 0}
#define meshtastic_DeviceConnectionStatus_init_zero {false, meshtastic_WifiConnectionStatus_init_zero, false, meshtastic_EthernetConnectionStatus_init_zero, false, meshtastic_BluetoothConnectionStatus_init_zero, false, meshtastic_SerialConnectionStatus_init_zero}
#define meshtastic_WifiConnectionStatus_init_zero {false, meshtastic_EthernetConnectionStatus_init_zero, "", 0}
#define meshtastic_EthernetConnectionStatus_init_zero {false, meshtastic_NetworkConnectionStatus_init_zero}
#define meshtastic_NetworkConnectionStatus_init_zero {0, 0, 0, 0}
#define meshtastic_BluetoothConnectionStatus_init_zero {0, 0, 0}
#define meshtastic_SerialConnectionStatus_init_zero {0, 0}

/* Field tags (for use in manual encoding/decoding) */
#define meshtastic_NetworkConnectionStatus_ip_address_tag 1
#define meshtastic_NetworkConnectionStatus_is_connected_tag 2
#define meshtastic_NetworkConnectionStatus_is_mqtt_connected_tag 3
#define meshtastic_NetworkConnectionStatus_is_syslog_connected_tag 4
#define meshtastic_EthernetConnectionStatus_status_tag 1
#define meshtastic_WifiConnectionStatus_status_tag 1
#define meshtastic_WifiConnectionStatus_ssid_tag 2
#define meshtastic_WifiConnectionStatus_rssi_tag 3
#define meshtastic_BluetoothConnectionStatus_pin_tag 1
#define meshtastic_BluetoothConnectionStatus_rssi_tag 2
#define meshtastic_BluetoothConnectionStatus_is_connected_tag 3
#define meshtastic_SerialConnectionStatus_baud_tag 1
#define meshtastic_SerialConnectionStatus_is_connected_tag 2
#define meshtastic_DeviceConnectionStatus_wifi_tag 1
#define meshtastic_DeviceConnectionStatus_ethernet_tag 2
#define meshtastic_DeviceConnectionStatus_bluetooth_tag 3
#define meshtastic_DeviceConnectionStatus_serial_tag 4

/* Struct field encoding specification for nanopb */
#define meshtastic_DeviceConnectionStatus_FIELDLIST(X, a) \
X(a, STATIC,   OPTIONAL, MESSAGE,  wifi,              1) \
X(a, STATIC,   OPTIONAL, MESSAGE,  ethernet,          2) \
X(a, STATIC,   OPTIONAL, MESSAGE,  bluetooth,         3) \
X(a, STATIC,   OPTIONAL, MESSAGE,  serial,            4)
#define meshtastic_DeviceConnectionStatus_CALLBACK NULL
#define meshtastic_DeviceConnectionStatus_DEFAULT NULL
#define meshtastic_DeviceConnectionStatus_wifi_MSGTYPE meshtastic_WifiConnectionStatus
#define meshtastic_DeviceConnectionStatus_ethernet_MSGTYPE meshtastic_EthernetConnectionStatus
#define meshtastic_DeviceConnectionStatus_bluetooth_MSGTYPE meshtastic_BluetoothConnectionStatus
#define meshtastic_DeviceConnectionStatus_serial_MSGTYPE meshtastic_SerialConnectionStatus

#define meshtastic_WifiConnectionStatus_FIELDLIST(X, a) \
X(a, STATIC,   OPTIONAL, MESSAGE,  status,            1) \
X(a, STATIC,   SINGULAR, STRING,   ssid,              2) \
X(a, STATIC,   SINGULAR, INT32,    rssi,              3)
#define meshtastic_WifiConnectionStatus_CALLBACK NULL
#define meshtastic_WifiConnectionStatus_DEFAULT NULL
#define meshtastic_WifiConnectionStatus_status_MSGTYPE meshtastic_EthernetConnectionStatus

#define meshtastic_EthernetConnectionStatus_FIELDLIST(X, a) \
X(a, STATIC,   OPTIONAL, MESSAGE,  status,            1)
#define meshtastic_EthernetConnectionStatus_CALLBACK NULL
#define meshtastic_EthernetConnectionStatus_DEFAULT NULL
#define meshtastic_EthernetConnectionStatus_status_MSGTYPE meshtastic_NetworkConnectionStatus

#define meshtastic_NetworkConnectionStatus_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, FIXED32,  ip_address,        1) \
X(a, STATIC,   SINGULAR, BOOL,     is_connected,      2) \
X(a, STATIC,   SINGULAR, BOOL,     is_mqtt_connected,   3) \
X(a, STATIC,   SINGULAR, BOOL,     is_syslog_connected,   4)
#define meshtastic_NetworkConnectionStatus_CALLBACK NULL
#define meshtastic_NetworkConnectionStatus_DEFAULT NULL

#define meshtastic_BluetoothConnectionStatus_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, UINT32,   pin,               1) \
X(a, STATIC,   SINGULAR, INT32,    rssi,              2) \
X(a, STATIC,   SINGULAR, BOOL,     is_connected,      3)
#define meshtastic_BluetoothConnectionStatus_CALLBACK NULL
#define meshtastic_BluetoothConnectionStatus_DEFAULT NULL

#define meshtastic_SerialConnectionStatus_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, UINT32,   baud,              1) \
X(a, STATIC,   SINGULAR, BOOL,     is_connected,      2)
#define meshtastic_SerialConnectionStatus_CALLBACK NULL
#define meshtastic_SerialConnectionStatus_DEFAULT NULL

extern const pb_msgdesc_t meshtastic_DeviceConnectionStatus_msg;
extern const pb_msgdesc_t meshtastic_WifiConnectionStatus_msg;
extern const pb_msgdesc_t meshtastic_EthernetConnectionStatus_msg;
extern const pb_msgdesc_t meshtastic_NetworkConnectionStatus_msg;
extern const pb_msgdesc_t meshtastic_BluetoothConnectionStatus_msg;
extern const pb_msgdesc_t meshtastic_SerialConnectionStatus_msg;

/* Defines for backwards compatibility with code written before nanopb-0.4.0 */
#define meshtastic_DeviceConnectionStatus_fields &meshtastic_DeviceConnectionStatus_msg
#define meshtastic_WifiConnectionStatus_fields &meshtastic_WifiConnectionStatus_msg
#define meshtastic_EthernetConnectionStatus_fields &meshtastic_EthernetConnectionStatus_msg
#define meshtastic_NetworkConnectionStatus_fields &meshtastic_NetworkConnectionStatus_msg
#define meshtastic_BluetoothConnectionStatus_fields &meshtastic_BluetoothConnectionStatus_msg
#define meshtastic_SerialConnectionStatus_fields &meshtastic_SerialConnectionStatus_msg

/* Maximum encoded size of messages (where known) */
#define meshtastic_BluetoothConnectionStatus_size 19
#define meshtastic_DeviceConnectionStatus_size   108
#define meshtastic_EthernetConnectionStatus_size 13
#define meshtastic_NetworkConnectionStatus_size  11
#define meshtastic_SerialConnectionStatus_size   8
#define meshtastic_WifiConnectionStatus_size     60

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
