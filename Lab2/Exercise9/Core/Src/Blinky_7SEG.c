/*
 * Blinky_7SEG.c
 *
 *  Created on: Sep 13, 2024
 *      Author: LENOVO
 */
#include "Control_7SEG.h"
#include "Blinky_7SEG.h"
#include "main.h"

#define MAX_LED 2

int led_index = 0;
int counter[MAX_LED] = {0,0};
int flag[MAX_LED] = {0,0};
void update7SEG(int index){
	switch (index){
	case 0:
		  HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, RESET);
		  HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
		  HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
		  HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
		  HAL_GPIO_TogglePin(DOT_GPIO_Port, DOT_Pin);
		  display7SEG(1);
		  break;
	case 1:
		  HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
		  HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
		  HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
		  HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
		  display7SEG(2);
		  break;
	case 2:
		  HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
		  HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
		  HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, RESET);
		  HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
		  HAL_GPIO_TogglePin(DOT_GPIO_Port, DOT_Pin);
		  display7SEG(3);
		  break;
	case 3:
		  HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
		  HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
		  HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
		  HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, RESET);
		  display7SEG(0);
	}
}
void setTime(int duration, int index){
	if(index < MAX_LED){
		counter[index] = duration;
		flag[index] = 0;
	}
}

void runTime(){
	for(int i = 0;i < MAX_LED; ++i){
		counter[i]--;
		if(counter[i] <= 0){
			flag[i] = 1;
		}
	}
}


