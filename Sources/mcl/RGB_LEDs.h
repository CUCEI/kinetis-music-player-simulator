/****************************************************************************
 * Project developed as a simple Blink the LED's to 
 * demonstrate basic CodeWarrior functionality and capability.
 * Borrowed from Freedom Example Projects: Blinky
 * 
 * Date: 11 Sept 2012
 * Author: M. Ruthenbeck
 * Revision Level 1.0
 */
#ifndef RGB_LEDS_H                       /* To avoid double inclusion */
#define RGB_LEDS_H
#include "variables_funciones.h"

void init_entradas(void);
void init_leds(void);
void app_rgb_led(void);
void app_rgb_led_fsm(void);
extern void delay_time(int);
extern void turn_led(E_COLOR);		
extern void turn_off(void);		


#endif /* RGB_LEDS_H */
