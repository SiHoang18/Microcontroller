/*
 * fsm_automatic.c
 *
 *  Created on: Sep 26, 2024
 *      Author: LENOVO
 */
#include "fsm_automatic.h"

void fsm_automation_run(int index){
	switch(status[index]){
	case INIT:
		HAL_GPIO_WritePin(leds[index][0].port, leds[index][0].pin, SET);
		HAL_GPIO_WritePin(leds[index][1].port, leds[index][1].pin, SET);
		HAL_GPIO_WritePin(leds[index][2].port, leds[index][2].pin, SET);
		if(!index){
			status[index] = AUTO_RED;
			time_buffer[index] = TIME_RED;
			setTime(TIME_RED,index);
		}else {
			status[index] = AUTO_GREEN;
			time_buffer[index] = TIME_GREEN;
			setTime(TIME_GREEN,index);
		}
		if(isButtonPressed(0)){
			prev_status[0] = status[0];
			prev_status[1] = status[1];
			status[0] = MANUAL_RED;
			status[1] = MANUAL_RED;
			HAL_GPIO_WritePin(leds[0][0].port, leds[0][0].pin, RESET);
			HAL_GPIO_WritePin(leds[1][0].port, leds[1][0].pin, RESET);
			temp = TIME_RED;
			setTime(250,NUM_BUFFER + 2);
		}
		else if(isButtonPressed(1) || isButtonPressed(2)){}
		break;
	case AUTO_RED:
		HAL_GPIO_WritePin(leds[index][0].port, leds[index][0].pin, RESET);
		HAL_GPIO_WritePin(leds[index][1].port, leds[index][1].pin, SET);
		HAL_GPIO_WritePin(leds[index][2].port, leds[index][2].pin, SET);
		run_automatic_7seg(idx);
		if(flag[index]){
			status[index] = AUTO_GREEN;
			time_buffer[index] = TIME_GREEN;
			setTime(TIME_GREEN,index);
		}
		if(isButtonPressed(0)){
			prev_status[0] = status[0];
			prev_status[1] = status[1];
			status[0] = MANUAL_RED;
			status[1] = MANUAL_RED;
			HAL_GPIO_WritePin(leds[0][0].port, leds[0][0].pin, RESET);
			HAL_GPIO_WritePin(leds[1][0].port, leds[1][0].pin, RESET);
			temp = TIME_RED;
			setTime(250,NUM_BUFFER + 2);
		}
		else if(isButtonPressed(1) || isButtonPressed(2)){}
		break;
	case AUTO_GREEN:
		HAL_GPIO_WritePin(leds[index][0].port, leds[index][0].pin, SET);
		HAL_GPIO_WritePin(leds[index][1].port, leds[index][1].pin, RESET);
		HAL_GPIO_WritePin(leds[index][2].port, leds[index][2].pin, SET);
		run_automatic_7seg(idx);
		if(flag[index]){
			status[index] = AUTO_YELLOW;
			time_buffer[index] = TIME_YELLOW;
			setTime(TIME_YELLOW,index);
		}
		if(isButtonPressed(0)){
			prev_status[0] = status[0];
			prev_status[1] = status[1];
			status[0] = MANUAL_RED;
			status[1] = MANUAL_RED;
			HAL_GPIO_WritePin(leds[0][0].port, leds[0][0].pin, RESET);
			HAL_GPIO_WritePin(leds[1][0].port, leds[1][0].pin, RESET);
			temp = TIME_RED;
			setTime(250,NUM_BUFFER + 2);
		}
		else if(isButtonPressed(1) || isButtonPressed(2)){}
		break;
	case AUTO_YELLOW:
		HAL_GPIO_WritePin(leds[index][0].port, leds[index][0].pin, SET);
		HAL_GPIO_WritePin(leds[index][1].port, leds[index][1].pin, SET);
		HAL_GPIO_WritePin(leds[index][2].port, leds[index][2].pin, RESET);
		run_automatic_7seg(idx);
		if(flag[index]){
			status[index] = AUTO_RED;
			time_buffer[index] = TIME_RED;
			setTime(TIME_RED,index);
		}
		if(isButtonPressed(0)){
			prev_status[0] = status[0];
			prev_status[1] = status[1];
			status[0] = MANUAL_RED;
			status[1] = MANUAL_RED;
			HAL_GPIO_WritePin(leds[0][0].port, leds[0][0].pin, RESET);
			HAL_GPIO_WritePin(leds[1][0].port, leds[1][0].pin, RESET);
			temp = TIME_RED;
			setTime(250,NUM_BUFFER + 2);
		}
		else if(isButtonPressed(1) || isButtonPressed(2)){}
		break;
	default:
		break;
	}
}
void run_automatic_7seg(int index){
	if(flag[NUM_BUFFER]){
		setTime(250,NUM_BUFFER);
		idx = (idx < 3) ? idx + 1 : 0;
		switch(index){
		case 0:
			HAL_GPIO_WritePin(enables[0].port, enables[0].pin, RESET);
			HAL_GPIO_WritePin(enables[1].port, enables[1].pin, SET);
			HAL_GPIO_WritePin(enables[2].port, enables[2].pin, SET);
			HAL_GPIO_WritePin(enables[3].port, enables[3].pin, SET);
			display7SEG(time_buffer[0] / 10000);
			break;
		case 1:
			HAL_GPIO_WritePin(enables[0].port, enables[0].pin, SET);
			HAL_GPIO_WritePin(enables[1].port, enables[1].pin, RESET);
			HAL_GPIO_WritePin(enables[2].port, enables[2].pin, SET);
			HAL_GPIO_WritePin(enables[3].port, enables[3].pin, SET);
			display7SEG((time_buffer[0] / 1000) % 10);
			break;
		case 2:
			HAL_GPIO_WritePin(enables[0].port, enables[0].pin, SET);
			HAL_GPIO_WritePin(enables[1].port, enables[1].pin, SET);
			HAL_GPIO_WritePin(enables[2].port, enables[2].pin, RESET);
			HAL_GPIO_WritePin(enables[3].port, enables[3].pin, SET);
			display7SEG(time_buffer[1] / 10000);
			break;
		case 3:
			HAL_GPIO_WritePin(enables[0].port, enables[0].pin, SET);
			HAL_GPIO_WritePin(enables[1].port, enables[1].pin, SET);
			HAL_GPIO_WritePin(enables[2].port, enables[2].pin, SET);
			HAL_GPIO_WritePin(enables[3].port, enables[3].pin, RESET);
			display7SEG((time_buffer[1] / 1000) % 10);
			break;
		default:
			break;
		}
	}
}
void countdown(){
	if(flag[NUM_BUFFER + 1]){
		setTime(1000,NUM_BUFFER + 1);
		time_buffer[0] -= 1000;
		time_buffer[1] -= 1000;
	}
}
