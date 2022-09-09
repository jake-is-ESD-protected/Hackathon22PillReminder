#include "timer.h"

c_timer::c_timer()
{
   // unused
}

void c_timer::init(uint32_t ms_interval)
{
  ms_interval = ms_interval;
  // from https://forum.arduino.cc/t/solved-possible-to-use-internal-real-time-counter-from-arduino-nano-every/650720/5
  
  //To operate the PIT, follow these steps:
  //1. Configure the RTC clock CLK_RTC as described in   Configure the Clock CLK_RTC.
  RTC.CLKSEL = RTC_CLKSEL_INT32K_gc; //Use OSCULP32K 1kHz oscillator
  
    
  //2. Enable the interrupt by writing a '1' to the Periodic Interrupt bit (PI) in the PIT Interrupt Control
  //register (RTC.PITINTCTRL).
  while (1 & RTC.PITSTATUS); //check if register isn't busy
  RTC.PITINTCTRL = RTC_PI_bm; //Enable interrupts
  
  //3. Select the period for the interrupt and enable the PIT by writing the desired value to the PERIOD bit
  //field and a '1' to the PIT Enable bit (PITEN) in the PIT Control A register (RTC.PITCTRLA).
  while (1 & RTC.STATUS); //check if register isn't busy
  RTC.PITCTRLA = (CLOCK_PERIOD << 3) | 1; //This should set the clock to trigger an interrupt every 128 clock cycles (The clock frequency is 32768Hz, so every 1/256 seconds)
  
  return;
}

uint32_t c_timer::getCurVal()
{
  return cur_val;
}

void c_timer::increment()
{
  cur_val++;
}

void c_timer::reset()
{
  cur_val = 0;
}

void c_timer::disable()
{
  RTC.PITCTRLA &= 0;
}

void c_timer::setThresh(uint32_t tresh)
{
  tresh = tresh;
}

uint32_t c_timer::getThresh()
{
  return tresh;
}

// singleton:
c_timer tim;