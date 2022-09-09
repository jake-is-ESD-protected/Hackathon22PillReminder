#include "oled.h"
#include <Arduino.h>

// singleton
MicroOLED myOLED(PIN_RESET, DC_JUMPER);

void oled_init(){

    Wire.begin();
    myOLED.begin();
    delay(100);
    myOLED.clear(ALL);
    myOLED.clear(PAGE);
    myOLED.display();
}

c_time::c_time(uint32_t _currTime){
    currTime = _currTime;
}

String c_time::convert(){

    uint32_t hrs = currTime / 3600;
    uint32_t mins = (currTime % 3600) / 60;

    if(hrs == 100)
    {
        // TBD
    }

    String str_hrs = String(hrs);
    String str_mins = String(mins);

    //debug
    Serial.print(currTime);
    Serial.print(" -> ");
    Serial.print(str_hrs + ":" + str_mins);
    Serial.print("\n");

    return (str_hrs + ":" + str_mins);
}

void oled_updateTime(uint32_t currTime){

    c_time t(currTime);
    String disp = t.convert();

    myOLED.setCursor(16, 14);
    myOLED.setFontType(2);
    myOLED.print(disp);
    myOLED.display();
}








