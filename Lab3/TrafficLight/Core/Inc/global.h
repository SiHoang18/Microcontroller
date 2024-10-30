/*
 * global.h
 *
 *  Created on: Sep 26, 2024
 *      Author: LENOVO
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_
#include "Timer.h"
#include "button.h"

#define NUM_BUFFER 2
#define DURATION 10
#define INIT 1
#define AUTO_RED 2
#define AUTO_GREEN 3
#define AUTO_YELLOW 4

#define MANUAL_RED 12
#define MANUAL_GREEN 13
#define MANUAL_YELLOW 14

typedef struct{
	GPIO_TypeDef* port;
	uint16_t pin;
}Segments;

extern Segments button[];
extern Segments leds[NUM_BUFFER][3];
extern Segments enables[];
extern int TIME_RED;
extern int TIME_YELLOW;
extern int TIME_GREEN;
extern int status[];
extern int prev_status[];
extern int time_buffer[];
extern int idx;
extern int button_state;
extern int temp;
extern int force;
#endif /* INC_GLOBAL_H_ */
