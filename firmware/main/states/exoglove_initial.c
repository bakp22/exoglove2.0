#include <WiFi.h>
#include <MQTT.h>
#include <stdio.h>

// Configuration Constants
const char* SSID = "YOUR_SSID";
const char* PASSWORD = "YOUR_PASS";
const char* BROKER_IP = "rasticvm.internal";
const int BROKER_PORT = 1883;
const char* CLIENT_ID = "esp32_client";
const char* TEST_TOPIC = "racuum/racuum-ACE9/test";

// Network Clients
WiFiClient net;
MQTTClient client;

// Retry & Timeout Parameters (Whiteboard: "Retries > OR Time out -> Abort")
const int MAX_RETRIES = 5;
const unsigned long CONNECTION_TIMEOUT_MS = 10000; // 10 seconds

bool connectToWiFiWithTimeout() {
    int attempts = 0;
    unsigned long startTime = millis();

    Serial.print("Attempting to connect to: ");
    Serial.println(SSID);
    
    WiFi.begin(SSID, PASSWORD);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
        
        // Check for timeout or max retries
        if (millis() - startTime > CONNECTION_TIMEOUT_MS) {
            Serial.println("\n[ERROR] Connection timeout!");
            return false;
        }
        
        attempts++;
        if (attempts >= (MAX_RETRIES * 2)) { // 2 checks per second
            Serial.println("\n[ERROR] Max retries reached!");
            return false;
        }
    }

    Serial.println("\n[SUCCESS] WiFi Connected!");
    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());
    return true;
}

bool connectToMQTT() {
    client.begin(BROKER_IP, BROKER_PORT, net);
    
    int attempts = 0;
    while (!client.connect(CLIENT_ID)) {
        Serial.println("\n[INFO] Connecting to MQTT broker...");
        delay(1000);
        
        attempts++;
        if (attempts > MAX_RETRIES) {
            Serial.println("[ERROR] Failed to connect to MQTT Broker. Aborting network sequence.");
            return false;
        }
    }
    
    Serial.println("[SUCCESS] Connected to MQTT Broker!");
    return true;
}

void abortSequence() {
    Serial.println("[ABORT] Stopping process and alerting user...");
    // Implement safe shutdown or error state here (e.g., flash an LED, stop actuators)
    while (true) {
        delay(1000);
    }
}

void setup() {
    Serial.begin(115200);
    delay(1000);

    // --- State: Connect to Network & Verify ---
    if (!connectToWiFiWithTimeout()) {
        abortSequence(); // Triggers Abort path from the whiteboard diagram
    }

    if (!connectToMQTT()) {
        abortSequence(); // Triggers Abort path if broker communication fails
    }

    // Proceed to next state (e.g., Verify Safe / Telemetry Hub Check)
    Serial.println("[STATE] Network connection verified. Proceeding to safety checks...");
}

void loop() {
    client.loop();

    // Reconnection safeguard during runtime
    if (!client.connected()) {
        Serial.println("[WARN] MQTT connection lost. Reconnecting...");
        if (!connectToMQTT()) {
            abortSequence();
        }
    }
}