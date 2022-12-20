#ifndef LED_HPP
#define LED_HPP

#include <Arduino.h>

/************************************************************************/
/* Public Enum                                                          */
/************************************************************************/
enum LedState_e
{
  LED_ON = 0U,
  LED_OFF,
};

/************************************************************************/
/* Class Definition                                                     */
/************************************************************************/
class Led 
{
    public:
        //methodes
        Led(byte pinLed);
        void setState( LedState_e state );

    private:
        //attributes
        LedState_e state;
        byte pinLed;     
};

#endif // LED_HPP
