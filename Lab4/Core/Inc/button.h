/*
 * button.h
 *
 *  Created on: Oct 2, 2024
 *      Author: LENOVO
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_
#include<main.h>
#include<global.h>

#define NORMAL_STATE GPIO_PIN_SET
#define PRESSED_STATE GPIO_PIN_RESET
#define NUM_BUTTON 3

extern int button_flag[];
void getKeyInput();
int isButtonPressed(int index);
#endif /* INC_BUTTON_H_ */
