#include <Arduino.h>
#include "RTCNTPlib.h"

RTCNTP rtcntp(8);

void setup() {
  rtcntp.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  // get NTP time

  // set RTC time to fixed time

  // print RTC time

  // set RTC time to NTP time 

  // print RTC time

}