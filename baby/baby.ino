#include <Arduino.h>
#include "./src/hardware.h"
#include "./src/piezzo.h"
#include "./src/led.h"
#include "./src/rubanLed.h"

/************************************************************************/
/* Private Define                                                       */
/************************************************************************/


/************************************************************************/
/* Static methods                                                       */
/************************************************************************/

/************************************************************************/
/* Private variable                                                     */
/************************************************************************/
Piezzo *piezzos[ PIEZZOS_NB ];

Led *leds[ LEDS_NB ];

RubanLed *rubanLed[ LED_RUBAN_NB ];
byte ledsRubanBuffer[LED_RUBAN_LEDS_NB * LED_RUBAN_COLORS] = { 0U };

/************************************************************************/
/* Setup function                                                       */
/************************************************************************/
void setup( void ) 
{
	//sytem init
	Serial.begin(57600);
    Serial.println("Initialization");
	
	//init led
    Serial.println("\t-Led");
	leds[ LED_ID_1 ] = new Led(LED_PIN_1);
	leds[ LED_ID_1 ]->setState(LED_ON);

	//init piezzos	
    Serial.println("\t-Piezzos");
	piezzos[ PIEZZO_ID_1 ] = new Piezzo(PIEZZO_PIN_1);
	piezzos[ PIEZZO_ID_2 ] = new Piezzo(PIEZZO_PIN_2);

	//init ruban	
    Serial.println("\t-Ruban Led");
	rubanLed[ LED_RUBAN_ID_1 ] = new RubanLed(LED_RUBAN_PIN,LED_RUBAN_LEDS_NB,ledsRubanBuffer);
	
	//sytem is ready
	leds[ LED_ID_1 ]->setState(LED_OFF);
    Serial.println("Initialization Done !");
}


/************************************************************************/
/* Loop function                                                        */
/************************************************************************/
void loop() 
{
	rubanLed[ LED_RUBAN_ID_1 ]->refreshLeds();
	for (unsigned int i = 0U; i < PIEZZOS_NB; i++)
	{
		if(piezzos[ i ]->getState() == PIEZZO_IMPACT)
		{
    		Serial.print("Impact on piezzo id: ");
    		Serial.print(i, DEC);
    		Serial.println(" !");
		}
	}
}