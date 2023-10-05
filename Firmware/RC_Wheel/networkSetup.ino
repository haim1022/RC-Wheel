void wifiSetup() {
  Serial.println("Creating the local access point");
  WiFi.mode(WIFI_AP);
  WiFi.setSleepMode(WIFI_NONE_SLEEP);
  WiFi.softAP(DEFAULT_AP_SSID, DEFAULT_AP_PASSWORD);
  Serial.print("Access point succesfuly created - SSID: ");
  Serial.println(DEFAULT_AP_SSID);
  Serial.print("Local IP address: ");
  Serial.println(WiFi.softAPIP());
  if(MDNS.begin(DEFAULT_MDNS_ADDRESS)) {
    Serial.println("mDNS responder started");
    Serial.print("mDNS address: ");
    Serial.print(DEFAULT_MDNS_ADDRESS);
    Serial.println(".local");
  }
}

void webserverSetup() {
  server.on("/", handleRoot);
  server.on("/style.css", handleCSSStyle);
  server.on("/main.js", handleJSScript);
  server.on("/manifest.json", handleManifest);
  server.on("/sw.js", handleServiceWorker);
  server.on("/data", handleControllerData);
  server.onNotFound(handleNotFound);
  server.begin();
  Serial.println("HTTP server started");
}
