#ifndef PIEZZO_HPP
#define PIEZZO_HPP

#include <Arduino.h>

/************************************************************************/
/* Public Enum                                                          */
/************************************************************************/
enum PiezzoState_e
{
  PIEZZO_IDLE = 0U,
  PIEZZO_IMPACT,
};

/************************************************************************/
/* Class Definition                                                     */
/************************************************************************/
class Piezzo 
{
    public:
        //attributes
        typedef void (*callbackPiezzoChangedState)(PiezzoState_e state);
        //methodes
        Piezzo(byte pin, callbackPiezzoChangedState cb);
        PiezzoState_e getState( void );

    private:
        //attributes
        byte pinPiezzo;  
        PiezzoState_e state;
        callbackPiezzoChangedState cb;      
};

#endif // PIEZZO_HPP

