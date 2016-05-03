/*
 * variables_funciones.c
 *
 *  Created on: Apr 17, 2016
 *      Author: R1CK
 */

#include "RGB_LEDs.h"

E_COLOR rub_pista1[35] = {1,1,1,3,5,4,6,3,3,5,4,5,5,2,2,1,2,1,1,2,2,3,3,6,5,4,1,2,3,6,5,2,1,1,1};
E_COLOR rub_pista2[35] = {2,2,2,3,5,6,1,4,2,2,3,6,3,5,2,2,2,1,5,3,2,1,1,4,2,3,5,4,4,4,5,1,2,2,2};
E_COLOR rub_pista3[35] = {3,3,3,2,5,5,4,4,1,1,2,5,6,3,2,5,2,1,4,2,5,6,3,3,6,6,5,5,2,2,1,4,3,3,3};
E_COLOR rub_pista4[35] = {4,4,4,2,1,2,3,6,5,2,1,2,5,4,4,5,2,2,3,3,3,6,5,2,1,2,5,4,1,2,5,2,4,4,4};
E_COLOR rub_pista5[35] = {5,5,5,6,3,2,1,2,5,4,1,2,5,3,2,1,2,5,3,2,5,2,1,4,2,5,2,3,6,5,2,1,5,5,5};


void init_var_glb(void){
	rub_pause     = 0;
	rub_num_pista = 0;
	rub_seg_rep   = 0;
	rub_volumen   = 3;
	rub_stop      = 0;
	e_color       = APAGADO;
	rub_proteccion= 0;
    rub_direccion = 0;
    e_velocidad = 	V_1S;
    rub_mode   =    1; 
    rub_pause_vel = 1;
}

void pwm(void) {
	
	switch(rub_volumen){
	
	case(1):
			turn_led(e_color);
	        delay_time(50);
	        turn_off();
	        delay_time(1950);
	        break;
	case(2):
				turn_led(e_color);
		        delay_time(300);
		        turn_off();
		        delay_time(1700);
		        break;
	case(3):
				turn_led(e_color);
		        delay_time(800);
		        turn_off();
		        delay_time(1200);
		        break;
	case(4):
				turn_led(e_color);
		        delay_time(1300);
		        turn_off();
		        delay_time(700);
		        break;
	case(5):
				turn_led(e_color);
		        delay_time(2000);
		        turn_off();
		        delay_time(0);
		        break;
	default:   turn_off();  break;
}}

void avanza_seg_rep (void){
          if(0!= rub_pause){
        	  if(rub_direccion == 1){
        	     if(rub_seg_rep>0)
        		     rub_seg_rep--;
        	     else
        		     rub_pause = 0;
        	                        }
        	   else
        	   rub_seg_rep++;  

                            }
          }






void play_pause(void){
	if(0 == rub_pause){
		rub_pause=1;
	    rub_stop=1;             
	                  }
		else
		rub_pause=0;
	
}

void stop(void){
   if(1 == rub_stop){
   e_velocidad = V_1S;
   rub_direccion=0;
   rub_pause=0;
   rub_seg_rep=0;
   e_color=APAGADO;
   rub_stop = 0;}
	
   else
	   
	   init_var_glb();
	
	  }
	




void avanza_rep (void){
	
	if(0!= rub_pause || (rub_seg_rep == 0 && rub_stop == 1)){
		
		switch(rub_num_pista){
		
		case(0):
				        e_color= rub_pista1[rub_seg_rep];
		                break;
		case(1):
						e_color = rub_pista2[rub_seg_rep];
				        break;
		case(2):
						e_color= rub_pista3[rub_seg_rep];
				        break;
		case(3):
						e_color= rub_pista4[rub_seg_rep];
				        break;
		case(4):
						e_color= rub_pista5[rub_seg_rep];
				        break;
		
		}
		
	}}



void volumen_mas(void){
	if(0 != rub_pause){
		if(rub_volumen < 5)
		rub_volumen++;
}
}
	
void volumen_menos(void){
	if(0!=rub_pause){
		if(rub_volumen>1)
		rub_volumen--;
}
}	

void cambio_pista(void){
	if(35 <= rub_seg_rep){
		
		rub_seg_rep = 0;
		rub_num_pista++;
	}
	if(5<=rub_num_pista)
		rub_num_pista = 0;
	
}

void play(void){
	
	rub_pause = 1;
	rub_direccion = 0;
	rub_pause_vel = 1;
	rub_stop=1;  
	
}

void pause(void){
	rub_pause = 0;
}

 //zona de botones!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

void init_boton(BOTON *boton){
	
	boton->currentTick  = 0;
	boton->tick1Deb     = 25;
	boton->tick2Deb     = 120;
	boton->state        = 0;
	boton->activatedeb1 = 0;
	boton->activatedeb2 = 0;
}

void debounce(BOTON *boton){
	
	boton->currentTick++;
	
	switch(boton->state){
	
	case(0): //ningun debounce
		
		if(boton->pul_actual != 0){
			if(boton->currentTick > boton->tick1Deb)
			boton->state = 1;	
		                          }
		else{
			boton->currentTick = 0;
			
		    }
	      break;
	      
	case(1):   //estado actual deb 1      
		
				if(boton->pul_actual != 0){
					if(boton->currentTick > boton->tick2Deb)
					boton->state = 2;	
				                          }
				else{
					boton->currentTick = 0;
					boton->activatedeb1= 1;
					boton->state       = 0;
				    }
			      break;
	 
	    case(2):   //estado actual deb 2      
			
					if(boton->pul_actual != 0){}
					
					                          
					else{
						boton->currentTick = 0;
						boton->activatedeb2= 1;
						boton->state       = 0;
						boton->activatedeb1= 0;
					    }
				      break;
	
	
	    default:  break;
	  
	}
	
	}

void proteccion_botones(void){
	detector_2botones();
	if( (boton_pause.pul_actual || boton_stop.pul_actual || boton_rw.pul_actual || boton_fw.pul_actual|| boton_vels_1.pul_actual|| boton_vels_2.pul_actual || boton_volumen.pul_actual) == 0)
		rub_proteccion = 0;
      }


void accion_boton(void){
	
	if(boton_pause.activatedeb1){
		play();
		
		init_botones();                                            
	                                                       }
	
	if(boton_pause.activatedeb2){
			pause();
			init_botones();                                            
		                                                       }
	
	if(boton_stop.activatedeb1 || boton_stop.activatedeb2){
		stop();
		init_botones();
	                                                      }
	if(boton_rw.activatedeb1){
		if( rub_mode == 0 )
		volumen_menos();
		else if(rub_pause!=0){ 
		rub_direccion=1;
		rub_pause_vel = 1;  }
		
		     
		init_botones();
		                                                  }
	if(boton_fw.activatedeb1){
		if( rub_mode == 0 )	
		volumen_mas();
		else if(rub_pause!=0){ 
	     rub_direccion=0;	
	    rub_pause_vel = 1;  }
		
		                      
		init_botones();
			                                                }
	if(boton_fw.activatedeb2){
		
		rub_seg_rep=0;
		rub_num_pista++;
		if(5 <= rub_num_pista)
		rub_num_pista = 0;
		init_botones();	
		rub_pause_vel = 1;		                                             }

	if(boton_rw.activatedeb2){
	
		    if(rub_seg_rep < 6){
		    rub_seg_rep = 0;
			rub_num_pista--;
			if(0 > rub_num_pista)
			rub_num_pista = 4;
			              }
			else
				rub_seg_rep = 0;
		    
		    rub_pause_vel = 1;
			        init_botones();
				  	
					                                             }

	if(boton_vels_1.activatedeb1){
		e_velocidad = V_1S;
		rub_pause_vel = 0;
		init_botones();
	                        }
	
	
	if(boton_vels_1.activatedeb2){
		e_velocidad = V_500MS;
		rub_pause_vel = 0;
		init_botones();
	                         }
	
	if(boton_vels_2.activatedeb1){
		 e_velocidad = V_200MS;
		 rub_pause_vel = 0;
		 init_botones();
	                          }
	                       	
		if(boton_vels_2.activatedeb2){
			e_velocidad = V_100MS;
			rub_pause_vel = 0;
			init_botones();
		 	
		                        }	
	
		if(boton_volumen.activatedeb1){
			volumen_menos();
					init_botones();
				 	
				                        }	
		
		if(boton_volumen.activatedeb2){
			volumen_mas();
					init_botones();
				 	
				                        }	
		
		
                             }


void obtener_estado_boton(void){
	
	if(GPIOC_PDIR & 0x00001000)
	     boton_pause.pul_actual=1;
		 else
	     boton_pause.pul_actual=0;	 
		 
		 if(GPIOC_PDIR & 0x00002000)
		 boton_stop.pul_actual=1;
		 else
		  boton_stop.pul_actual=0;
		 
		 if(GPIOC_PDIR & 0x000010000)
		 	 boton_rw.pul_actual=1;
		 	 else
		 	  boton_rw.pul_actual=0;
		 
		 if(GPIOC_PDIR & 0x000020000)
		 	 boton_fw.pul_actual=1;
		 	 else
		 	  boton_fw.pul_actual=0;
		 
		 if(GPIOC_PDIR & 0x000000800)
		 	boton_vels_1.pul_actual=1;
		 	else
		 	boton_vels_1.pul_actual=0;
		 if(GPIOC_PDIR & 0x0000000400)
		 	 boton_vels_2.pul_actual=1;
		 	else
		 	boton_vels_2.pul_actual=0;
		 if(GPIOC_PDIR & 0x0000000040)
		 boton_volumen.pul_actual=1;
		 else
		 boton_volumen.pul_actual=0;
}

void detector_2botones(void){
	
	if( (boton_pause.pul_actual + boton_stop.pul_actual + boton_rw.pul_actual + boton_fw.pul_actual + boton_vels_1.pul_actual + boton_vels_2.pul_actual + boton_volumen.pul_actual) > 1){
		init_botones();                                                                          
 	     rub_proteccion=1 ;
	                                                                                                       }
	
	
	
                            }

void init_botones(void){
	        init_boton( &boton_pause);
		    init_boton( &boton_stop);
		    init_boton( &boton_rw);
		    init_boton( &boton_fw); 
		    init_boton( &boton_vels_1);
		    init_boton( &boton_vels_2); 
		    init_boton( &boton_volumen);	
}

