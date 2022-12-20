#include <Arduino.h>
#include "./src/Piezzo.h"
#include "./src/Led.h"

/************************************************************************/
/* Private Define                                                       */
/************************************************************************/
#define NB_PIEZZOS		2U
#define ID_PIEZZO_1		0U
#define ID_PIEZZO_2		1U
#define PIN_PIEZZO_1	A0
#define PIN_PIEZZO_2	A1

#define NB_LEDS			1U
#define ID_LED_1		0U
#define PIN_LED_1		LED_BUILTIN

/************************************************************************/
/* Static methods                                                       */
/************************************************************************/

/************************************************************************/
/* Private variable                                                     */
/************************************************************************/
Piezzo *piezzos[ NB_PIEZZOS ];
Led *leds[ NB_LEDS ];

void setup( void ) 
{
	//sytem init
	Serial.begin(57600);
    Serial.println("Initialization");
	
	//init led
    Serial.println("\t-Led");
	leds[ ID_LED_1 ] = new Led(PIN_LED_1);
	leds[ ID_LED_1 ]->setState(LED_ON);

	//init piezzos	
    Serial.println("\t-Piezzos");
	piezzos[ ID_PIEZZO_1 ] = new Piezzo(PIN_PIEZZO_1);
	piezzos[ ID_PIEZZO_2 ] = new Piezzo(PIN_PIEZZO_2);
	
	//sytem is ready
	leds[ ID_LED_1 ]->setState(LED_OFF);
    Serial.println("Initialization Done !");
}


void loop() 
{
	for (unsigned int i = 0U; i < NB_PIEZZOS; i++)
	{
		if(piezzos[ i ]->getState() == PIEZZO_IMPACT)
		{
    		Serial.print("Impact on piezzo id: ");
    		Serial.print(i, DEC);
    		Serial.println(" !");
		}
	}
}