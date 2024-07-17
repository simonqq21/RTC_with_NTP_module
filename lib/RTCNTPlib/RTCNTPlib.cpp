#include <Arduino.h>
#include "RTCNTPlib.h"

// constructor
RTCNTP::RTCNTP(int gmtOffset) : _ntpClient(_ntpUDP, "ntp.pagasa.dost.gov.ph") {
    _gmtOffsetInHours = gmtOffset;
    _ntpClient.setTimeOffset(_gmtOffsetInHours * 3600);
}

// initialize RTC and NTP
void RTCNTP::begin() {
    Wire.begin();
    while (!_rtc.begin()) {
        Serial.println("no RTC.");
        delay(500);
    }
    _ntpClient.begin();
}

// print the current time in the class
void RTCNTP::printTime() {
   Serial.printf("%4u/%02u/%02u %02u:%02u:%02u", _dtnow.year(), _dtnow.month(), 
        _dtnow.day(), _dtnow.hour(), 
        _dtnow.minute(), _dtnow.second());
}

// refresh NTP time from the internet
void RTCNTP::refreshNTPTime() {
    _ntpClient.setTimeOffset(_gmtOffsetInHours * 3600); // UTC+8 for Philippines
    _ntpUpdateStatus = _ntpClient.update();
}

// update the RTC with NTP time
void RTCNTP::updateRTCWithNTP() {
    
}

// get the time from the RTC and return it as a DateTime struct
DateTime RTCNTP::getRTCTime() {
    _dtnow = _rtc.now();
    return _dtnow; 
}

// get the NTP time and return it as a DateTime struct
DateTime RTCNTP::getNTPTime() {
    this->refreshNTPTime();
    _epochTime = _ntpClient.getEpochTime();
    return DateTime(year(_epochTime), month(_epochTime), day(_epochTime), 
        _ntpClient.getHours(), _ntpClient.getMinutes(), _ntpClient.getSeconds());
}

// set the NTP GMT offset
void RTCNTP::setGMTOffset(int gmtOffset) {
    _gmtOffsetInHours = gmtOffset;
}