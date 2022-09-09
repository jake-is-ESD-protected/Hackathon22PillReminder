#include <Arduino.h>
#include "avr8-stub.h"
#include "app_api.h"

void setup() {
  debug_init();
  pinMode(LED_BUILTIN, OUTPUT);
  // put your setup code here, to run once:
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
  // put your main code here, to run repeatedly:
}