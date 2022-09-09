#include <Arduino.h>
#include <string.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include "timer.h"
#include "avr/sleep.h"
#include "oled.h"

bool act = false;

ISR(RTC_PIT_vect) {
    sleep_disable(); 
    tim.increment();
    act = true;
    if(tim.getCurVal() == tim.getThresh())
    {
      led.toggle();
      tim.reset();
    }
    RTC.PITINTFLAGS = 1; // reset interrupt
    sleep_cpu();
}


void setup() {
  Serial.begin(115200);
  delay(100);
  oled_init();
  delay(1000);

  tim.init(1000);
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);
  sleep_enable();
  sleep_cpu();
}

void loop() {
  if(act)
  {
    oled_updateTime(tim.getCurVal());
    act = false;
  }
}