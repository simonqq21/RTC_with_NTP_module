#include <Arduino.h>
#include <WiFi.h>
#include "RTCNTPlib.h"

const char* SSID = "QUE-STARLINK";
const char* PASS = "Quefamily01258";
RTCNTP rtcntp;

void test() {
  Serial.println("DS1307 RTC and NTP library testing script.");
  rtcntp.begin();
  rtcntp.setGMTOffset(8);
  // read RTC time
  Serial.println("read RTC time");
  rtcntp.getRTCTime();
  rtcntp.printTime();
  delay(3000);
  // get NTP time
  Serial.println("get NTP time");
  rtcntp.getNTPTime();
  rtcntp.printTime();
  delay(3000);
  // set RTC time to fixed time
  Serial.println("set RTC time to fixed time");
  rtcntp.setRTCTime(DateTime(2001,01,02,0,0,0));
  rtcntp.printTime();
  delay(3000);
  // set RTC time to ISO datetime
  Serial.println("set RTC time to ISO datetime");
  rtcntp.setISODateTime("2024-01-01T01:01:01Z");
  rtcntp.printTime();
  delay(3000);
  // set RTC time to NTP time 
  Serial.println("set RTC time back to NTP time ");
  rtcntp.updateRTCWithNTP();
  rtcntp.printTime();
  delay(3000);
  Serial.println("end test");
  // // set RTC time back to fixed time
  // Serial.println("set RTC time back to fixed time");
  // rtcntp.setRTCTime(DateTime(2001,01,02,0,0,0));
  // rtcntp.getRTCTime();
  // rtcntp.printTime();
  // delay(3000);
}

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("Testing not connected to wifi");
  WiFi.begin(SSID, PASS);
  // while (WiFi.status() != WL_CONNECTED) {
  //   delay(500);
  //   Serial.print(".");
  // }
  // Serial.println("WiFi connected.");
  delay(2000);
  test();
  Serial.println("Testing connected to wifi");
  PASS="Quefamily01259";
  WiFi.disconnect();
  delay(1000);
  WiFi.begin(SSID, PASS);
  delay(2000);
  test();
}

void loop() {


}