#include "Piezzo.h"

/************************************************************************/
/* Private Define                                                       */
/************************************************************************/
#define ADC_THRESHOLD_IMPACT    1024U / 2U

/************************************************************************/
/* Private Methods                                                      */
/************************************************************************/

/************************************************************************/
/* Class Methods                                                        */
/************************************************************************/
Piezzo::Piezzo(byte pin) 
{
    this->state = PIEZZO_IDLE;
    this->pinPiezzo = pin;
    pinMode(this->pinPiezzo, INPUT);
}

PiezzoState_e Piezzo::getState() 
{     
    unsigned int analogPiezzo = analogRead(this->pinPiezzo);
    unsigned int analogInputV = map(analogPiezzo, 0, 1023, 0, 5000);
    this->state = PIEZZO_IDLE;
    if( analogInputV > ADC_THRESHOLD_IMPACT)
    {
        this->state = PIEZZO_IMPACT;
    }
    return this->state;
}
