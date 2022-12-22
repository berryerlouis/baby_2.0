#include "rubanLed.h"

/************************************************************************/
/* Private Define                                                       */
/************************************************************************/

/************************************************************************/
/* Private Methods                                                      */
/************************************************************************/

/************************************************************************/
/* Class Methods                                                        */
/************************************************************************/
RubanLed::RubanLed(byte pinRubanLed, unsigned int nbLeds, byte *ledsRubanBuffer) 
{
    this->pinRubanLed = pinRubanLed;
    this->nbLeds = nbLeds;
    this->ledsRubanBuffer = ledsRubanBuffer;
    this->refreshRate = millis();
    pinMode(this->pinRubanLed, OUTPUT);
    
    //configure Timer0 as fast as possible
    noInterrupts();
    TCCR1A = 0b00000000;
    TCCR1B = 0b00000001;
    interrupts();
}

void RubanLed::setLedColor( byte ledId, byte r, byte g, byte b )
{
    byte address = ledId * 3U;
    for(byte aRGB_aux=0 ; aRGB_aux<8 ; aRGB_aux++)
    {
        this->ledsRubanBuffer[address--] = bitRead(b, aRGB_aux);
    }
    for(byte aRGB_aux=0 ; aRGB_aux<8 ; aRGB_aux++)
    {
        this->ledsRubanBuffer[address--] = bitRead(r, aRGB_aux);
    }
    for(byte aRGB_aux=0 ; aRGB_aux<8 ; aRGB_aux++)
    {
        this->ledsRubanBuffer[address--] = bitRead(g, aRGB_aux);
    }
}

void RubanLed::refreshLeds()
{
    if(millis() >= this->refreshRate + 33)
    {
        noInterrupts();
        for(unsigned int index=0; index == this->nbLeds * 3U ; index++)
        {
            if(this->ledsRubanBuffer[index] == 1)
            {
	            digitalWrite(this->pinRubanLed, HIGH);
	            digitalWrite(this->pinRubanLed, LOW);
            }
            else
            {
	            digitalWrite(this->pinRubanLed, HIGH);
                TCNT1=0;
                while(TCNT1<=3){}
                
	            digitalWrite(this->pinRubanLed, LOW);
                TCNT1=0;
                while(TCNT1<=10){}
            }
        }
        this->refreshRate = millis();
        interrupts();
    }
}
