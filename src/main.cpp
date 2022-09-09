#include <Arduino.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include "timer.h"

ISR(RTC_PIT_vect) {
    // routine goes here
    led.toggle();
    RTC.PITINTFLAGS = 1; // reset interrupt
}


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  tim.init(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
}