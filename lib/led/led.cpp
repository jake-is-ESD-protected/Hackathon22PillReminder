#include "Arduino.h"
#include "led.h"

c_led::c_led()
{
    pinMode(LED_PIN, OUTPUT);
}

void c_led::on()
{
    state = HIGH;
    digitalWrite(LED_PIN, state);
}

void c_led::off()
{
    state = LOW;
    digitalWrite(LED_PIN, state);
}

void c_led::toggle()
{
    state = !state;
    digitalWrite(LED_PIN, state);
}

c_led led;