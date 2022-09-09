#ifndef _TIMER_H_
#define _TIMER_H_

#include "Arduino.h"
#include "led.h"

#define CLOCK_PERIOD    0xE
#define DAY             60 * 60 //(60 * 60 * 24)

class c_timer
{
public:
    c_timer();
    void init(uint32_t ms_interval);
    uint32_t getCurVal();
    void increment();
    void reset();
    void disable();
    void setThresh(uint32_t);
    uint32_t getThresh();

private:
    uint32_t ms_interval = 0;
    uint32_t cur_val = 0;
    uint32_t tresh = DAY;
};

extern c_timer tim;

#endif