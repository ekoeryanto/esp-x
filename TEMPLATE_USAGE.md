# 0x3 ESP8266 Template Usage Guide

This is a professional ESP8266 project template designed to be easily adapted for any ESP8266 board and project.

## 🚀 Quick Start

### 1. Copy Template
```bash
# Copy this template to your new project directory
cp -r "0x3-ESP8266-Template" "your-new-project"
cd "your-new-project"
```

### 2. Customize Project Settings
Edit `include/config.h` to match your project:
```cpp
#define PROJECT_NAME "YourProjectName"
#define PROJECT_VERSION "1.0.0"
#define PROJECT_AUTHOR "YourName"
#define HOSTNAME "your-device"
#define AP_PASSWORD "YourConfigPassword"
#define OTA_USERNAME "yourusername"
#define OTA_PASSWORD "yourpassword"
```

### 3. Select Your Board
Edit `platformio.ini` and uncomment the appropriate board section:

**For Wemos D1 Mini (default):**
```ini
[env:d1_mini]
platform = espressif8266
board = d1_mini
framework = arduino
monitor_speed = 115200
```

**For NodeMCU:**
```ini
[env:nodemcu]
platform = espressif8266
board = nodemcuv2
framework = arduino
monitor_speed = 115200
```

**For ESP-12E:**
```ini
[env:esp12e]
platform = espressif8266
board = esp12e
framework = arduino
monitor_speed = 115200
```

**For ESP-01:**
```ini
[env:esp01]
platform = espressif8266
board = esp01_1m
framework = arduino
monitor_speed = 115200
```

### 4. Build and Upload
```bash
# Build the project
platformio run

# Upload via USB (first time)
platformio run --target upload

# Monitor serial output
platformio device monitor
```

### 5. Configure WiFi
1. Device will create an AP named `YourHostname_ChipID`
2. Connect to AP with password from `config.h`
3. Navigate to `192.168.4.1` to configure WiFi
4. Device will restart and connect to your network

### 6. Access Web Interface
1. Find device IP in serial monitor
2. Navigate to `http://device-ip`
3. Use the web interface to monitor and control your device

## 🔧 Board-Specific Considerations

### LED Pin Configuration
Different boards have different built-in LED pins. Update `config.h` if needed:
```cpp
// Common LED pins for different boards:
// Wemos D1 Mini: 2
// NodeMCU: 2 or 16
// ESP-12E: 2
// ESP-01: 1 (or none)
#define LED_BUILTIN 2
```

### GPIO Pin Mapping
When adding custom features, refer to your board's pinout:
- **Wemos D1 Mini**: D0-D8 (GPIO 16, 5, 4, 0, 2, 14, 12, 13, 15)
- **NodeMCU**: D0-D10 similar mapping
- **ESP-12E**: Direct GPIO numbers
- **ESP-01**: Limited to GPIO 0, 1, 2, 3

### Memory Considerations
Different boards have different flash sizes:
- **ESP-01**: 1MB (limited features)
- **Wemos D1 Mini**: 4MB (full features)
- **NodeMCU**: 4MB (full features)
- **ESP-12E**: Usually 4MB

## 📝 Customization Examples

### Adding Custom Sensors
1. Add sensor libraries to `platformio.ini`:
```ini
lib_deps = 
    tzapu/WiFiManager@^0.16.0
    bblanchon/ArduinoJson@^6.21.3
    # Add your sensor libraries here
    adafruit/DHT sensor library@^1.4.4
```

2. Create sensor handling in `src/sensors.cpp`
3. Add sensor data to web interface and API

### Adding Custom Web Routes
```cpp
// In web_server.cpp, add to setupRoutes():
server.on("/api/sensors", [this]() { handleSensors(); });
```

### Custom Status Indicators
```cpp
// In system_manager.h, extend SystemStatus enum:
enum SystemStatus {
    SYSTEM_INITIALIZING,
    SYSTEM_WIFI_CONNECTING,
    SYSTEM_WIFI_CONNECTED,
    SYSTEM_RUNNING,
    SYSTEM_SENSOR_ERROR,  // Add custom status
    SYSTEM_ERROR
};
```

## 🔒 Security Recommendations

### For Production Use:
1. Change all default passwords
2. Use strong, unique credentials
3. Consider implementing API authentication
4. Use HTTPS if possible
5. Regular firmware updates

### Example Production Config:
```cpp
#define PROJECT_NAME "ProductionDevice"
#define AP_PASSWORD "SecureConfigPassword123!"
#define OTA_USERNAME "admin"
#define OTA_PASSWORD "SecureOTAPassword456!"
```

## 📋 Checklist for New Projects

- [ ] Update project name, version, and author in `config.h`
- [ ] Change default passwords and credentials
- [ ] Select appropriate board in `platformio.ini`
- [ ] Test build and upload process
- [ ] Verify WiFi configuration works
- [ ] Test OTA update functionality
- [ ] Customize web interface if needed
- [ ] Add project-specific features
- [ ] Update documentation for your project
- [ ] Test on target hardware
- [ ] Verify all features work as expected

## 🐛 Common Issues

### Build Errors
- Ensure correct board selection in `platformio.ini`
- Check library dependencies
- Verify PlatformIO is up to date

### WiFi Connection Issues
- Check AP password in `config.h`
- Verify WiFi credentials in configuration portal
- Check signal strength

### OTA Upload Issues
- Ensure device is on same network
- Check OTA credentials
- Verify firewall settings

### Memory Issues
- Monitor free heap in web interface
- Reduce string usage if needed
- Consider using PROGMEM for constants

## 📞 Support

This template is designed to be self-contained and documentation-driven. For additional help:

1. Check the main `README.md` for detailed usage
2. Review code comments for implementation details
3. Consult PlatformIO documentation for platform-specific issues
4. ESP8266 Arduino Core documentation for hardware-specific features

---

**Happy coding! 🚀**

*This template is part of the 0x3 ESP Project series.*
