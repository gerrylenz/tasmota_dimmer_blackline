/*
  Dimmer config
*/

#ifndef _CONFIG_DIMMER_H_
#define _CONFIG_DIMMER_H_

// force the compiler to show a warning to confirm that this file is included
#warning **** config_dimmer.h: Using Settings from this File ****

/*****************************************************************************************************\
 * USAGE:
 *   To modify the stock configuration without changing the my_user_config.h file:
 *   (1) copy this file to "user_config_override.h" (It will be ignored by Git)
 *   (2) define your own settings below
 *   (3) for platformio:
 *         define USE_CONFIG_OVERRIDE as a build flags.
 *         ie1 : export PLATFORMIO_BUILD_FLAGS='-DUSE_CONFIG_OVERRIDE'
 *         ie2 : enable in file platformio.ini "build_flags = -Wl,-Tesp8266.flash.1m0.ld -DUSE_CONFIG_OVERRIDE"
 *       for Arduino IDE:
 *         enable define USE_CONFIG_OVERRIDE in my_user_config.h
 ******************************************************************************************************
 * ATTENTION:
 *   - Changes to SECTION1 PARAMETER defines will only override flash settings if you change define CFG_HOLDER.
 *   - Expect compiler warnings when no ifdef/undef/endif sequence is used.
 *   - You still need to update my_user_config.h for major define USE_MQTT_TLS.
 *   - All parameters can be persistent changed online using commands via MQTT, WebConsole or Serial.
\*****************************************************************************************************/
#define USE_EXS_DIMMER                           // Add support for ES-Store WiFi Dimmer (+1k5 code)
  #define EXS_MCU_CMNDS                          // Add command to send MCU commands (+0k8 code)

#undef  MODULE
#define MODULE                 EXS_DIMMER        // [Module] Select default model from sonoff_template.h

#undef  PROJECT
#define PROJECT                "DIMMER"      // PROJECT is used as the default topic delimiter

#undef  FRIENDLY_NAME
#define FRIENDLY_NAME          "EXS_Dimmer"      // [FriendlyName] Friendlyname up to 32 characters used by webpages and Alexa

// -- Setup your own Wifi settings  ---------------
#undef  STA_SSID1
#define STA_SSID1             ""                 // [Ssid1] Wifi SSID

#undef  STA_PASS1
#define STA_PASS1             ""                 // [Password1] Wifi password

#undef  STA_SSID2
#define STA_SSID2              ""                // [Ssid2] Optional alternate AP Wifi SSID
#undef  STA_PASS2
#define STA_PASS2              ""                // [Password2] Optional alternate AP Wifi password

#undef  MQTT_HOST
#define MQTT_HOST             "192.168.178.5"    // [MqttHost]

#undef  MQTT_GRPTOPIC
#define MQTT_GRPTOPIC          "dimmer"          // [GroupTopic] MQTT Group topic

#undef  MQTT_FULLTOPIC
#define MQTT_FULLTOPIC         "%topic%/%prefix%/" // [FullTopic] Subscribe and Publish full topic name - Legacy topic

#undef  MQTT_TOPIC
#define MQTT_TOPIC             PROJECT "/DVES_%06X"   // [Topic] (unique) MQTT device topic, set to 'PROJECT "_%06X"' for unique topic including device MAC address

#undef  SUB_PREFIX
#define SUB_PREFIX             "IN/CMD"            // [Prefix1] Sonoff devices subscribe to %prefix%/%topic% being SUB_PREFIX/MQTT_TOPIC and SUB_PREFIX/MQTT_GRPTOPIC

#undef  PUB_PREFIX
#define PUB_PREFIX             "OUT/STAT"          // [Prefix2] Sonoff devices publish to %prefix%/%topic% being PUB_PREFIX/MQTT_TOPIC

#undef  PUB_PREFIX2
#define PUB_PREFIX2            "OUT/TELE"// [Prefix3] Sonoff devices publish telemetry data to %prefix%/%topic% being PUB_PREFIX2/MQTT_TOPIC/UPTIME, POWER and TIME

#undef  WIFI_CONFIG_TOOL
#define WIFI_CONFIG_TOOL       WIFI_RETRY        // [WifiConfig] Default tool if wifi fails to connect (default option: 4 - WIFI_RETRY)
                                                 // (WIFI_RESTART, WIFI_SMARTCONFIG, WIFI_MANAGER, WIFI_WPSCONFIG, WIFI_RETRY, WIFI_WAIT, WIFI_SERIAL, WIFI_MANAGER_RESET_ONLY)
                                                 // The configuration can be changed after first setup using WifiConfig 0, 1, 2, 3, 4, 5, 6 and 7.
#undef  WIFI_CONFIG_NO_SSID
#define WIFI_CONFIG_NO_SSID    WIFI_MANAGER      // Default tool if wifi fails to connect and no SSID is configured

#undef  APP_TIMEZONE
#define APP_TIMEZONE           99                 // [Timezone] +1 hour (Amsterdam) (-13 .. 14 = hours from UTC, 99 = use TIME_DST/TIME_STD)

#undef  APP_LEDSTATE
#define APP_LEDSTATE           LED_POWER_MQTTPUB // [LedState] Function of led

#undef  MY_LANGUAGE
#define MY_LANGUAGE            de-DE             // German in Germany

#undef USE_EMULATION_WEMO                        // Enable Belkin WeMo emulation for Alexa (+6k code, +2k mem common)

#undef USE_RULES                                 // Add support for rules (+8k code)
#define USE_SCRIPT                               // Add support for script (+17k code)

#define USE_EXPRESSION                           // Add support for expression evaluation in rules (+3k2 code, +64 bytes mem)
  #define SUPPORT_IF_STATEMENT                   // Add support for IF statement in rules (+4k2 code, -332 bytes mem)
  #define SUPPORT_MQTT_EVENT                     // Support trigger event with MQTT subscriptions (+3k5 code)

#undef USE_SONOFF_RF                             // Add support for Sonoff Rf Bridge (+3k2 code)
#undef USE_SONOFF_SC                             // Add support for Sonoff Sc (+1k1 code)
#undef USE_TUYA_MCU                              // Add support for Tuya Serial MCU
#undef USE_ARMTRONIX_DIMMERS                     // Add support for Armtronix Dimmers (+1k4 code)
#undef USE_PS_16_DZ                              // Add support for PS-16-DZ Dimmer (+2k code)
#undef USE_SONOFF_IFAN                           // Add support for Sonoff iFan02 and iFan03 (+2k code)
#undef USE_BUZZER                                // Add support for a buzzer (+0k6 code)
#undef USE_ARILUX_RF                             // Add support for Arilux RF remote controller (+0k8 code, 252 iram (non 2.3.0))

#endif  // _CONFIG_DIMMER_H_
