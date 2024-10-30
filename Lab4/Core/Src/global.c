/*
 * global.c
 *
 *  Created on: Sep 26, 2024
 *      Author: LENOVO
 */
#include "global.h"
#include "main.h"
int status[NUM_BUFFER] = {0};
int prev_status[NUM_BUFFER] = {0};
int TIME_RED = 5000;
int TIME_YELLOW = 2000;
int TIME_GREEN = 3000;
int idx = 0;
int time_buffer[NUM_BUFFER] = {0};
int button_state = 0;
int temp = 0;
int force = 0;
Segments leds[NUM_BUFFER][3] = {
		{
				{RED1_GPIO_Port,RED1_Pin}, {GREEN1_GPIO_Port,GREEN1_Pin}, {AMBER1_GPIO_Port, AMBER1_Pin}
		},
		{
				{RED2_GPIO_Port,RED2_Pin}, {GREEN2_GPIO_Port,GREEN2_Pin}, {AMBER2_GPIO_Port, AMBER2_Pin}
		}
};

Segments enables[4] = {
		{EN0_GPIO_Port,EN0_Pin},{EN1_GPIO_Port,EN1_Pin},{EN2_GPIO_Port,EN2_Pin},{EN3_GPIO_Port,EN3_Pin}
};
