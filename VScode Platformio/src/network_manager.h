/* ____________________________
   This software is licensed under the MIT License:
   https://github.com/cifertech/nrfbox
   ________________________________________ */

#ifndef NETWORK_MANAGER_H
#define NETWORK_MANAGER_H

#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>

#ifdef NETWORK_MANAGER_ENABLE_WEBSOCKETS
#include <WebSocketsClient.h>
#endif

namespace network_manager {

bool begin(const char* ssid, const char* pass);
bool isConnected();
IPAddress getIPAddress();

bool httpPostJson(const char* url, const char* payload, String& response, int timeoutMs = 5000);

#ifdef NETWORK_MANAGER_ENABLE_WEBSOCKETS
bool beginWebSocket(const char* url);
WebSocketsClient& getWebSocket();
#endif

} // namespace network_manager

#endif // NETWORK_MANAGER_H
