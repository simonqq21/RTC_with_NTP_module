#ifndef RTCNTPLIB_H
#define RTCNTPLIB_H
#include <Arduino.h>
#include <RTClib.h>
#include <TimeLib.h>
#include <NTPClient.h>
#include <WiFiUdp.h>
#include <SPI.h>

// void printTime(int year, int month, int day, int hour, int minute, int second);
// void printRTCTime(DateTime datetime); 
// void printNTPTime(NTPClient timeClient);
// void initTime();
// void updateNTPTime();
// void adjustRTCWithNTP(NTPClient timeClient, RTC_DS1307 rtc);
// void adjustRTCFromJSON();
// void adjustRTC(int _year, int _month, int _day, int hour, int minute, int second);
// void getCurDateTime(bool readRTC);
// int getYear();
// int getMonth();
// int getDay();
// int getHour();
// int getMinute();
// int getSecond();
// void NTPUpdateLoop();
// void checkTime();

class RTCNTP {
    public:
        RTCNTP(int gmtOffset);
        void begin();
        void printTime();
        DateTime getRTCTime();
        DateTime getNTPTime();
        void setRTCTime(DateTime newDT);
        bool refreshNTPTime();
        void updateRTCWithNTP();
        void setGMTOffset(int gmtOffset);
    private: 
        RTC_DS1307 _rtc;
        bool _ntpEnabled;
        bool _ntpUpdateStatus;
        DateTime _dtnow;
        long _UTCOffsetInSeconds;
        WiFiUDP _ntpUDP;
        NTPClient _ntpClient;
        int _gmtOffsetInHours;
        unsigned long _epochTime;
};

#endif