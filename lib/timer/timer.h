#ifndef _TIMER_H_
#define _TIMER_H_

#include "Arduino.h"
#include "led.h"

class c_timer
{
public:
    c_timer();
    void init(uint32_t ms_interval);

private:
    uint32_t ms_interval = 0;

};

extern c_timer tim;

#endif