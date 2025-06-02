/* ____________________________
   This software is licensed under the MIT License:
   https://github.com/cifertech/nrfbox
   ________________________________________ */

#include "network_manager.h"

namespace network_manager {

#ifdef NETWORK_MANAGER_ENABLE_WEBSOCKETS
static WebSocketsClient wsClient;
#endif

bool begin(const char* ssid, const char* pass) {
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, pass);

    unsigned long start = millis();
    while (WiFi.status() != WL_CONNECTED && millis() - start < 15000) {
        delay(500);
    }
    return WiFi.status() == WL_CONNECTED;
}

bool isConnected() {
    return WiFi.status() == WL_CONNECTED;
}

IPAddress getIPAddress() {
    return WiFi.localIP();
}

bool httpPostJson(const char* url, const char* payload, String& response, int timeoutMs) {
    if (WiFi.status() != WL_CONNECTED) {
        return false;
    }

    HTTPClient http;
    http.setTimeout(timeoutMs);
    http.begin(url);
    http.addHeader("Content-Type", "application/json");

    int httpCode = http.POST((uint8_t*)payload, strlen(payload));
    if (httpCode > 0) {
        response = http.getString();
    }
    http.end();

    return httpCode > 0 && httpCode >= 200 && httpCode < 300;
}

#ifdef NETWORK_MANAGER_ENABLE_WEBSOCKETS
bool beginWebSocket(const char* url) {
    wsClient.begin(url);
    return true;
}

WebSocketsClient& getWebSocket() {
    return wsClient;
}
#endif

} // namespace network_manager

