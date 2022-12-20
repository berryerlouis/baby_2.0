#include "led.h"

/************************************************************************/
/* Private Define                                                       */
/************************************************************************/

/************************************************************************/
/* Private Methods                                                      */
/************************************************************************/

/************************************************************************/
/* Class Methods                                                        */
/************************************************************************/
Led::Led(byte pinLed) 
{
    this->state = LED_OFF;
    this->pinLed = pinLed;
    pinMode(this->pinLed, OUTPUT);
    this->setState(LED_OFF);
}

void Led::setState( LedState_e state) 
{     
    if(this->state != state)
    {
	    digitalWrite(this->pinLed, state);
        this->state = state;
    }
}
