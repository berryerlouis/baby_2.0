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
        //methodes
        Piezzo(byte pin);
        PiezzoState_e getState( void );

    private:
        //attributes
        volatile PiezzoState_e state;
        byte pinPiezzo;     
};

#endif // PIEZZO_HPP
