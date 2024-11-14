#define BLYNK_TEMPLATE_ID "TMPL7XQtjlSm"
#define BLYNK_DEVICE_NAME "ROBOT ARM"
#define BLYNK_AUTH_TOKEN "eAhHQLbG632fQa-m7SIQiTfKDyYE22jq"

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Servo.h>

Servo servo1, servo2, servo3, servo4;

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "vivo 1907"; // Change your Wifi/Hotspot Name
char pass[] = "abhi1401";  // Change your Wifi/Hotspot Password

BLYNK_WRITE(V0) {
  int s0 = param.asInt();
  servo1.write(s0);
  Blynk.virtualWrite(V4, s0);
}

BLYNK_WRITE(V1) {
  int s1 = param.asInt();
  servo2.write(s1);
  Blynk.virtualWrite(V5, s1);
}

BLYNK_WRITE(V2) {
  int s2 = param.asInt();
  servo3.write(s2);
  Blynk.virtualWrite(V6, s2);
}

BLYNK_WRITE(V3) {
  int s3 = param.asInt();
  servo4.write(s3);
  Blynk.virtualWrite(V7, s3);
}

void setup() {
  Serial.begin(9600);
  servo1.attach(D2);
  servo2.attach(D3);
  servo3.attach(D5);
  servo4.attach(D6);
  Blynk.begin(auth, ssid, pass);
  delay(1000);
}

void loop() {
  Blynk.run();
}
