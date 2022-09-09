#ifndef _LED_H_
#define _LED_H_
#include "Arduino.h"

#define LED_PIN 7

class c_led
{
public:
    c_led();
    void on();
    void off();
    void toggle();

private:
    bool state = LOW;
};

// singleton
extern c_led led;

#endif