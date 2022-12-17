#include "Piezzo.h"

/************************************************************************/
/* Private Define                                                       */
/************************************************************************/
void detect();

/************************************************************************/
/* Class Methods                                                        */
/************************************************************************/
Piezzo::Piezzo(byte pin, callbackPiezzoChangedState cb) 
{
    this->state = PIEZZO_IDLE;
    this->pinPiezzo = pin;
    this->cb = cb;
    pinMode(this->pinPiezzo, INPUT);
    attachInterrupt(digitalPinToInterrupt(this->pinPiezzo),detect,CHANGE);
}

PiezzoState_e Piezzo::getState() 
{     
    return this->state;
}

/************************************************************************/
/* ISR Methods                                                          */
/************************************************************************/
void detect() 
{ 
}