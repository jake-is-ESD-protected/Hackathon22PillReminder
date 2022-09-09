#ifndef _OLED_H_
#define _OLED_H_

#include <Arduino.h>
#include <string.h>
#include <SFE_MicroOLED.h>
#include <Wire.h>

#define PIN_RESET -1
#define DC_JUMPER 1

class c_time{
    public:
        c_time(uint32_t);
        String convert();
        uint32_t currTime = 0;
};

void oled_init();

void oled_updateTime(uint32_t currTime);

extern MicroOLED myOLED;

#endif