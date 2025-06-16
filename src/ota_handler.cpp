#include "ota_handler.h"
#include "system_manager.h"

// Global instance
OTAHandler otaHandler;

OTAHandler::OTAHandler() {
    server = nullptr;
    updateServer = nullptr;
    otaEnabled = false;
    updateInProgress = false;
}

bool OTAHandler::initialize(ESP8266WebServer* webServer) {
    if (!webServer) {
        Serial.println("[OTA] Error: WebServer pointer is null");
        return false;
    }
    
    server = webServer;
    updateServer = new ESP8266HTTPUpdateServer();
    
    Serial.println("[OTA] Initializing OTA handler...");
    
    // Initialize HTTP Update Server
    updateServer->setup(server, "/update", OTA_USERNAME, OTA_PASSWORD);
    
    otaEnabled = true;
    Serial.println("[OTA] OTA handler initialized successfully");
    Serial.printf("[OTA] OTA URL: http://%s/update\n", WiFi.localIP().toString().c_str());
    Serial.printf("[OTA] Username: %s\n", OTA_USERNAME);
    
    return true;
}

void OTAHandler::setupOTACallbacks() {
    // HTTP Update Server handles callbacks internally
}

void OTAHandler::handle() {
    if (otaEnabled && server) {
        server->handleClient();
    }
}

void OTAHandler::begin() {
    if (server && updateServer) {
        otaEnabled = true;
        Serial.println("[OTA] OTA service started");
    }
}

void OTAHandler::end() {
    otaEnabled = false;
    Serial.println("[OTA] OTA service stopped");
}

bool OTAHandler::isEnabled() {
    return otaEnabled;
}

bool OTAHandler::isUpdateInProgress() {
    return updateInProgress;
}

void OTAHandler::enable() {
    otaEnabled = true;
    Serial.println("[OTA] OTA enabled");
}

void OTAHandler::disable() {
    otaEnabled = false;
    Serial.println("[OTA] OTA disabled");
}

String OTAHandler::getUpdateURL() {
    if (WiFi.status() == WL_CONNECTED) {
        return "http://" + WiFi.localIP().toString() + "/update";
    }
    return "Not connected to WiFi";
}

String OTAHandler::getStatus() {
    if (!otaEnabled) {
        return "Disabled";
    } else if (updateInProgress) {
        return "Update in progress";
    } else {
        return "Ready";
    }
}
