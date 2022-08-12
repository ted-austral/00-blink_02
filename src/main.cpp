#include <Arduino.h>

/*
 *  Project 01-blink_02
 *      Blinks internal and external LED outphased
 *      Changes blink frequency by pushing a key
 *      Tact switch connected to +VDD so must engage pulldown resistor
 *          and result from digitalRead reversed respect 01-blink_01 project
 *      Prints delay in milliseconds
 *      Austral 2022 - IntroCom - EAM
 */

static const int long_delay = 1000;
static const int short_delay = 100;

static int old_val = 0;

void
setup(void)
{
    pinMode(INTLED,OUTPUT);
    digitalWrite(INTLED,LOW);
    pinMode(EXTLED,OUTPUT);
    digitalWrite(EXTLED,HIGH);

    pinMode(PUSH,INPUT_PULLDOWN);
    Serial.begin(BAUD);
}

void
loop(void)
{
    int delay_val;

    digitalWrite(INTLED, !digitalRead(INTLED));
    digitalWrite(EXTLED, !digitalRead(EXTLED));

    delay( delay_val = ( digitalRead(PUSH)==LOW ? long_delay : short_delay ) );
    if( delay_val != old_val )
        Serial.println(old_val = delay_val);
}
