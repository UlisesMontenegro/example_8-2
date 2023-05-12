/*
   Pines de placa NUCLEO asociados al RGB LED: PB_4(PWM3/1), PA_0(PWM4/1), y PD_12(PWM2/1).
    
    Este archivo de codigo modifica la intensidad de los 3 leds del LED RGB (Red, Green and Blue) para
    obtener así distintas combinaciones logrando diferentes colores. Esto se logra mediante el uso de
    señales PWM generadas a partir de la clase PWMOut. Modificando el Duty Cycle de las señales PWM se 
    logran diferentes intensidades (cuanto mayores el tiempo en ON del PWM, entonces mayor será el brillo 
    en el led). En este ejemplo se hace mas sencilla y clara la implementacion que en el example_8-1.
    
    Arbol de funciones:
    brightControlInit()
        |- setPeriod()
        |- setDutyCycle()
   */

//=====[Libraries]=============================================================

#include "arm_book_lib.h"

#include "bright_control.h"

#include "light_level_control.h"

//=====[Declaration of private defines]========================================

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

PwmOut RGBLed[] = {(PB_4), (PA_0), (PD_12)};

//=====[Declaration and initialization of private global objects]===============

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

static void setPeriod( lightSystem_t light, float period );

//=====[Implementations of public functions]===================================

void brightControlInit()
{
    setPeriod( RGB_LED_RED, 0.01f );
    setPeriod( RGB_LED_GREEN, 0.01f );
    setPeriod( RGB_LED_BLUE, 0.01f );

    setDutyCycle( RGB_LED_RED, 0.5f );
    setDutyCycle( RGB_LED_GREEN, 0.5f );
    setDutyCycle( RGB_LED_BLUE, 0.5f );
}

void setDutyCycle( lightSystem_t light, float dutyCycle )
{
    RGBLed[light].write(dutyCycle);
}

//=====[Implementations of private functions]==================================

static void setPeriod( lightSystem_t light, float period )
{
    RGBLed[light].period(period);
}
