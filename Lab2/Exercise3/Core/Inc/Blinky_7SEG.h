/*
 * Blinky_7SEG.h
 *
 *  Created on: Sep 13, 2024
 *      Author: LENOVO
 */

#ifndef INC_BLINKY_7SEG_H_
#define INC_BLINKY_7SEG_H_

#define MAX_LED 4

extern int led_buffer[MAX_LED];
extern int flag[MAX_LED];
extern int led_index;

void update7SEG(int index);
void setTime(int duration, int index);
void runTime();


#endif /* INC_BLINKY_7SEG_H_ */
