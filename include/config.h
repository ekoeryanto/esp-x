#ifndef CONFIG_H
#define CONFIG_H

// 0x3 ESP Project Configuration
// Version: 1.0.0
// Author: 0x3

// Project Information
#define PROJECT_NAME "0x3-ESP"
#define PROJECT_VERSION "1.0.0"
#define PROJECT_AUTHOR "0x3"

// WiFi Configuration
#define WIFI_TIMEOUT 30000          // 30 seconds
#define WIFI_RETRY_DELAY 5000       // 5 seconds
#define AP_PASSWORD "0x3Config"     // Default AP password
#define CONFIG_PORTAL_TIMEOUT 300   // 5 minutes

// OTA Configuration
#define OTA_USERNAME "0x3"
#define OTA_PASSWORD "0x3Update"
#define OTA_PORT 8080

// Web Server Configuration
#define WEB_SERVER_PORT 80

// Hardware Configuration
#define LED_BUILTIN 2               // Built-in LED pin for status indication
#define STATUS_LED_PIN LED_BUILTIN

// Debug Configuration
#define DEBUG_ENABLED true
#define DEBUG_BAUD_RATE 115200

// Network Configuration
#define HOSTNAME "0x3-esp"

// Timing Configuration
#define HEARTBEAT_INTERVAL 30000    // 30 seconds
#define STATUS_UPDATE_INTERVAL 5000 // 5 seconds

#endif // CONFIG_H
