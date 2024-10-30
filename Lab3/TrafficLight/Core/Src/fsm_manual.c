/*
 * fsm_manual.c
 *
 *  Created on: Sep 26, 2024
 *      Author: LENOVO
 */
#include "fsm_automatic.h"

void fsm_manual_run(){
	switch(status[0]){
	case MANUAL_RED:
		  HAL_GPIO_WritePin(leds[0][1].port, leds[0][1].pin, SET);
		  HAL_GPIO_WritePin(leds[1][1].port, leds[1][1].pin, SET);
		  HAL_GPIO_WritePin(leds[0][2].port, leds[0][2].pin, SET);
		  HAL_GPIO_WritePin(leds[1][2].port, leds[1][2].pin, SET);
		  fsm_manual_7seg(idx, 2);
		  if(flag[NUM_BUFFER + 2]){
			  setTime(250, NUM_BUFFER + 2);
			  HAL_GPIO_TogglePin(leds[0][0].port, leds[0][0].pin);
			  HAL_GPIO_TogglePin(leds[1][0].port, leds[1][0].pin);
		  }
		  if(isButtonPressed(0)){
			  status[0] = MANUAL_GREEN;
			  temp = TIME_GREEN;
		  }else if(isButtonPressed(1)){
			  temp = (temp / 1000 < 99) ? temp + 1000 : 1000;
		  }else if(isButtonPressed(2)){
			  TIME_RED = temp;
			  force = 1;
		  }

		  break;
	case MANUAL_GREEN:
		  HAL_GPIO_WritePin(leds[0][0].port, leds[0][0].pin, SET);
		  HAL_GPIO_WritePin(leds[1][0].port, leds[1][0].pin, SET);
		  HAL_GPIO_WritePin(leds[0][2].port, leds[0][2].pin, SET);
		  HAL_GPIO_WritePin(leds[1][2].port, leds[1][2].pin, SET);
		  fsm_manual_7seg(idx, 3);
		  if(flag[NUM_BUFFER + 2]){
			  setTime(250, NUM_BUFFER + 2);
			  HAL_GPIO_TogglePin(leds[0][1].port, leds[0][1].pin);
			  HAL_GPIO_TogglePin(leds[1][1].port, leds[1][1].pin);
		  }
		  if(isButtonPressed(0)){
			  status[0] = MANUAL_YELLOW;
			  temp = TIME_YELLOW;
		  }else if(isButtonPressed(1)){
			  temp = (temp < (TIME_RED - 1000)) ? temp + 1000 : 1000;
		  }else if(isButtonPressed(2)){
			  TIME_GREEN = temp;
			  TIME_YELLOW = TIME_RED - TIME_GREEN;
			  force = 0;
		  }
		  break;
	case MANUAL_YELLOW:
		  HAL_GPIO_WritePin(leds[0][1].port, leds[0][1].pin, SET);
		  HAL_GPIO_WritePin(leds[1][1].port, leds[1][1].pin, SET);
		  HAL_GPIO_WritePin(leds[0][0].port, leds[0][0].pin, SET);
		  HAL_GPIO_WritePin(leds[1][0].port, leds[1][0].pin, SET);
		  fsm_manual_7seg(idx, 4);
		  if(flag[NUM_BUFFER + 2]){
			  setTime(250, NUM_BUFFER + 2);
			  HAL_GPIO_TogglePin(leds[0][2].port, leds[0][2].pin);
			  HAL_GPIO_TogglePin(leds[1][2].port, leds[1][2].pin);
		  }
		  if(isButtonPressed(0)){
			  if(force){
				  status[0] = MANUAL_GREEN;
				  temp = TIME_GREEN;
			  }else{
				  status[0] = prev_status[0];
				  status[1] = prev_status[1];
				  idx = 0 ;
				  int k1 = 0, k2 = 0;
				  k1 = (prev_status[0] == AUTO_RED) ? TIME_RED : (prev_status[0] == AUTO_GREEN) ?
						  TIME_GREEN : TIME_YELLOW;
				  k2 = (prev_status[1] == AUTO_RED) ? TIME_RED : (prev_status[1] == AUTO_GREEN) ?
				  						  TIME_GREEN : TIME_YELLOW;
				  if(prev_status[0] == AUTO_RED && prev_status[1] == AUTO_GREEN){
					  k1 = TIME_RED; k2 = TIME_GREEN;
				  }else if(prev_status[0] == AUTO_GREEN && prev_status[1] == AUTO_RED){
					  k1 = TIME_GREEN; k2 = TIME_RED;
				  }else if(prev_status[0] == AUTO_RED && prev_status[1] == AUTO_YELLOW){
					  k1 = TIME_RED - TIME_GREEN; k2 = TIME_YELLOW;
				  }else if(prev_status[0] == AUTO_YELLOW && prev_status[1] == AUTO_RED){
					  k1 = TIME_YELLOW; k2 = TIME_RED - TIME_GREEN;
				  }
				  time_buffer[0] = k1; time_buffer[1] = k2; setTime(k1,0); setTime(k2,1);setTime(1000, NUM_BUFFER + 1);
			  }

//			  setTime(200,NUM_BUFFER);
		  }else if(isButtonPressed(1)){
			  temp = (temp < (TIME_RED - 1000)) ? temp + 1000 : 1000;
		  }else if(isButtonPressed(2)){
			  TIME_YELLOW = temp;
			  TIME_GREEN = TIME_RED - TIME_YELLOW;
			  force = 0;
		  }
		  break;
	default:
		break;
	}
}
void fsm_manual_7seg(int index, int mode){
	if(flag[NUM_BUFFER]){
		setTime(250,NUM_BUFFER);
		idx = (idx < 3) ? idx + 1 : 0;
		switch(index){
		case 0:
			HAL_GPIO_WritePin(enables[0].port, enables[0].pin, RESET);
			HAL_GPIO_WritePin(enables[1].port, enables[1].pin, SET);
			HAL_GPIO_WritePin(enables[2].port, enables[2].pin, SET);
			HAL_GPIO_WritePin(enables[3].port, enables[3].pin, SET);
			display7SEG(temp / 10000);
			break;
		case 1:
			HAL_GPIO_WritePin(enables[0].port, enables[0].pin, SET);
			HAL_GPIO_WritePin(enables[1].port, enables[1].pin, RESET);
			HAL_GPIO_WritePin(enables[2].port, enables[2].pin, SET);
			HAL_GPIO_WritePin(enables[3].port, enables[3].pin, SET);
			display7SEG((temp / 1000) % 10);
			break;
		case 2:
			HAL_GPIO_WritePin(enables[0].port, enables[0].pin, SET);
			HAL_GPIO_WritePin(enables[1].port, enables[1].pin, SET);
			HAL_GPIO_WritePin(enables[2].port, enables[2].pin, RESET);
			HAL_GPIO_WritePin(enables[3].port, enables[3].pin, SET);
			display7SEG(0);
			break;
		case 3:
			HAL_GPIO_WritePin(enables[0].port, enables[0].pin, SET);
			HAL_GPIO_WritePin(enables[1].port, enables[1].pin, SET);
			HAL_GPIO_WritePin(enables[2].port, enables[2].pin, SET);
			HAL_GPIO_WritePin(enables[3].port, enables[3].pin, RESET);
			display7SEG(mode);
			break;
		default:
			break;
		}
	}
}
