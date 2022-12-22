#ifndef RUBAN_LED_HPP
#define RUBAN_LED_HPP

#include <Arduino.h>

/************************************************************************/
/* Public Enum                                                          */
/************************************************************************/

/************************************************************************/
/* Class Definition                                                     */
/************************************************************************/
class RubanLed 
{
    public:
        //methodes
        RubanLed(byte pinRubanLed, unsigned int nbLeds, byte *ledsRubanBuffer);
        void refreshLeds();
        void setLedColor( byte ledId, byte r, byte g, byte b );

    private:
        //attributes
        byte pinRubanLed;     
        unsigned int nbLeds;
        byte *ledsRubanBuffer;
        unsigned long int refreshRate = 0U;
};

#endif // RUBAN_LED_HPP
