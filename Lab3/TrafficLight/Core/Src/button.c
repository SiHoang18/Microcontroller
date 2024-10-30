/*
 * button.c
 *
 *  Created on: Oct 2, 2024
 *      Author: LENOVO
 */
#include "button.h"
int KeyReg0[NUM_BUTTON] = {NORMAL_STATE};
int KeyReg1[NUM_BUTTON] = {NORMAL_STATE};
int KeyReg2[NUM_BUTTON] = {NORMAL_STATE};
int KeyReg3[NUM_BUTTON] = {NORMAL_STATE};

int TimeOutForKeyPress[NUM_BUTTON] =  {50};
int button_long_pressed[NUM_BUTTON] = {0};
Segments button[NUM_BUTTON] = {
		{BUT0_GPIO_Port,BUT0_Pin}, {BUT1_GPIO_Port,BUT1_Pin}, {BUT2_GPIO_Port,BUT2_Pin}
};
int button_flag[NUM_BUTTON] = {0};
int isButtonPressed(int index){
	if(button_flag[index] == 1){
		button_flag[index] = 0;
		return 1;
	}
	return 0;
}

int isButtonLongPressed(int index){
	if(button_long_pressed[index] == 1){
		button_long_pressed[index] = 0;
		return 1;
	}
	return 0;
}

void subKeyProcess(int index){
	//TODO
	button_state = (button_state < 3) ? button_state + 1 : 1;
	HAL_GPIO_WritePin(leds[0][button_state - 1].port, leds[0][button_state - 1].pin, SET);
	HAL_GPIO_WritePin(leds[1][button_state - 1].port, leds[1][button_state - 1].pin, SET);
	setTime(250,NUM_BUFFER + 2);
}

void getKeyInput(){
  // Add your key
  for(int i = 0;i < NUM_BUTTON; ++i){
	  KeyReg2[i] = KeyReg1[i];
	  KeyReg1[i] = KeyReg0[i];
	  KeyReg0[i] = HAL_GPIO_ReadPin(button[i].port, button[i].pin);

	  if ((KeyReg1[i] == KeyReg0[i]) && (KeyReg1[i] == KeyReg2[i])){
	    if (KeyReg2[i] != KeyReg3[i]){
	      KeyReg3[i] = KeyReg2[i];
	      if (KeyReg2[i] == PRESSED_STATE){
	        TimeOutForKeyPress[i] = 50;
	        button_flag[i] = 1;
	      }
	    }
	    else{
	        TimeOutForKeyPress[i]--;
	        if (TimeOutForKeyPress[i] == 0){
	        	TimeOutForKeyPress[i] = 50;
	        	if (KeyReg2[i] == PRESSED_STATE){
	        		KeyReg3[i] = NORMAL_STATE;
	        	}
	        }
	    }
	  }
  }
}

