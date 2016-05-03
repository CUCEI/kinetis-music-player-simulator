/*
 * variables_funciones.h
 *
 *  Created on: Apr 17, 2016
 *      Author: R1CK
 */

#ifndef VARIABLES_FUNCIONES_H_
#define VARIABLES_FUNCIONES_H_
#include "RGB_LEDs.h"
#include "stdtypedef.h"


T_UBYTE rub_pause;  // 0 pause ,  1 avanza
T_SBYTE rub_num_pista; // indica el numero de pista {0-4}
T_UBYTE rub_seg_rep; // indica el segundo de reproduccion
T_UBYTE rub_volumen; // inidca la intensidad del led 1->minimo  5-> maximo
T_UBYTE rub_stop;    // indica el estado de stop  0=stop  1=no stop
T_UBYTE rub_proteccion; //memoria de que fue oprimido mas de 1 boton
T_UBYTE rub_direccion;  //controla la direccion de reproduccion, 0 = hacia adelante   1 = hacia atras
T_UBYTE rub_mode;  // 0 normal (botones)  .   1 modo uart
T_UBYTE rub_pause_vel;  //pausa cuando cambia velocidad  0 pause    1 no pause

typedef enum {
	V_1S,
	V_500MS,
	V_200MS,
	V_100MS
	
} E_VEL;

E_VEL e_velocidad;  // velocidad de reproduccion(atras o adelante) 0 = 1s   1=500ms   2=200ms  3=100ms


typedef enum { 
	
	APAGADO,
	ROJO,
	VERDE,
	AZUL,
	AMARILLO,
	BLANCO,
	MAGENTA
} E_COLOR;

E_COLOR e_color;    // controla el color del led


typedef struct
{
	T_UBYTE currentTick;    //numero de revisiones
	T_UBYTE tick1Deb;      //numero de revisiones para alcanzar deb 1
	T_UBYTE tick2Deb;      //numero de revisiones para alcanzar deb 2
	T_UBYTE state;         // llego al estado de debounce 1 para deb1,  2 para deb 2,  0 no ah alcanzado
	T_UBYTE activatedeb1;  //1 se activo el debounce  1
	T_UBYTE activatedeb2; // se activo el debounce 2
	T_UBYTE pul_actual;   // estado del boton actual
 	
	
} BOTON;

BOTON boton_pause;   // pc12
BOTON boton_stop;    // pc13
BOTON boton_rw;      // pc16
BOTON boton_fw;     //  pc17
BOTON boton_vels_1;  // pc11
BOTON boton_vels_2;  // pc10
BOTON boton_volumen; // pc6

void init_var_glb(void);
void proteccion_botones(void);        //checa que no se oprima mas de 2 botones. si todo bien regresa 1
void init_boton(BOTON *boton);      //inicializa el boton
void debounce(BOTON *boton);        // hace la revision de debounce del boton
void pwm(void); 					// prende y apaga led, y controla duracion
void avanza_seg_rep (void);				 //avanza 1 segundo de reproduccion, si no esta en pause
void avanza_rep (void); // recibe el numero de pista, el seg y el estado del pause y modifica el color a reproducir		
void play_pause(void);  					// 0 = PAUSE   1 = PLAY  EN PARAMETRO
void stop(void);  						// recibe el estado de rub_stop, y modifica pause,color, seg rep y numero de pista segun sea el caso
void volumen_mas(void);  		//aumenta el volumen, si no esta en pause
void volumen_menos(void); 		// decrementa el volumen si no esta en pause
void cambio_pista(void); 				//cambia el numero de pista cuando se llega al final de pista.
void accion_boton(void);        // cuando es activado un boton y pasa el debounce, realiza accion
void obtener_estado_boton(void);  //obtiene el nivel del estado de los 4 botones
void detector_2botones(void);
void init_botones(void);    // inicializa todos los botones
void play(void);
void pause(void);




















#endif /* VARIABLES_FUNCIONES_H_ */
