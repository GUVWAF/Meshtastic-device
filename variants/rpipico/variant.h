// #define RADIOLIB_CUSTOM_ARDUINO 1
// #define RADIOLIB_TONE_UNSUPPORTED 1
// #define RADIOLIB_SOFTWARE_SERIAL_UNSUPPORTED 1

#define ARDUINO_ARCH_AVR

#define USE_SH1106 1

// default I2C pins:
// SDA = 4
// SCL = 5

// Recommended pins for SerialModule:
// txd = 8
// rxd = 9

#define LED_PIN PIN_LED

#define BATTERY_PIN 26
// ratio of voltage divider = 3.0 (R17=200k, R18=100k)
#define ADC_MULTIPLIER 3.1 // 3.0 + a bit for being optimistic

#undef LORA_SCK
#undef LORA_MISO
#undef LORA_MOSI
#undef LORA_CS

#define LORA_SCK 10
#define LORA_MISO 12
#define LORA_MOSI 11

#define USE_RF95
#define LORA_DIO0 14
#define LORA_DIO1 15
#define LORA_DIO2 18
#define LORA_CS 9
#define LORA_RESET 13
