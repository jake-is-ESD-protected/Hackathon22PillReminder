#include "button.h"
#include "Arduino.h"

void BUTTON_ISR()
{
    
}

c_button::c_button()
{
    attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), BUTTON_ISR, FALLING);
}