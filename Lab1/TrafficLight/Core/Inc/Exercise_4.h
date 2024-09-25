/*
 * Exercise_4.h
 *
 *  Created on: Sep 7, 2024
 *      Author: SIHOANG
 */

#ifndef SRC_EXERCISE_4_H_
#define SRC_EXERCISE_4_H_
#include "main.h"

void display7SEG(int num){
	switch(num){
	case 0:
		HAL_GPIO_WritePin(PINA_GPIO_Port, PINA_Pin, RESET);
		HAL_GPIO_WritePin(PINB_GPIO_Port, PINB_Pin, RESET);
		HAL_GPIO_WritePin(PINC_GPIO_Port, PINC_Pin, RESET);
		HAL_GPIO_WritePin(PIND_GPIO_Port, PIND_Pin, RESET);
		HAL_GPIO_WritePin(PINE_GPIO_Port, PINE_Pin, RESET);
		HAL_GPIO_WritePin(PINF_GPIO_Port, PINF_Pin, RESET);
		HAL_GPIO_WritePin(PING_GPIO_Port, PING_Pin, SET);
		break;
	case 1:
		HAL_GPIO_WritePin(PINA_GPIO_Port, PINA_Pin, SET);
		HAL_GPIO_WritePin(PINB_GPIO_Port, PINB_Pin, RESET);
		HAL_GPIO_WritePin(PINC_GPIO_Port, PINC_Pin, RESET);
		HAL_GPIO_WritePin(PIND_GPIO_Port, PIND_Pin, SET);
		HAL_GPIO_WritePin(PINE_GPIO_Port, PINE_Pin, SET);
		HAL_GPIO_WritePin(PINF_GPIO_Port, PINF_Pin, SET);
		HAL_GPIO_WritePin(PING_GPIO_Port, PING_Pin, SET);
		break;
	case 2:
		HAL_GPIO_WritePin(PINA_GPIO_Port, PINA_Pin, RESET);
		HAL_GPIO_WritePin(PINB_GPIO_Port, PINB_Pin, RESET);
		HAL_GPIO_WritePin(PINC_GPIO_Port, PINC_Pin, SET);
		HAL_GPIO_WritePin(PIND_GPIO_Port, PIND_Pin, RESET);
		HAL_GPIO_WritePin(PINE_GPIO_Port, PINE_Pin, RESET);
		HAL_GPIO_WritePin(PINF_GPIO_Port, PINF_Pin, SET);
		HAL_GPIO_WritePin(PING_GPIO_Port, PING_Pin, RESET);
		break;
	case 3:
		HAL_GPIO_WritePin(PINA_GPIO_Port, PINA_Pin, RESET);
		HAL_GPIO_WritePin(PINB_GPIO_Port, PINB_Pin, RESET);
		HAL_GPIO_WritePin(PINC_GPIO_Port, PINC_Pin, RESET);
		HAL_GPIO_WritePin(PIND_GPIO_Port, PIND_Pin, RESET);
		HAL_GPIO_WritePin(PINE_GPIO_Port, PINE_Pin, SET);
		HAL_GPIO_WritePin(PINF_GPIO_Port, PINF_Pin, SET);
		HAL_GPIO_WritePin(PING_GPIO_Port, PING_Pin, RESET);
		break;
	case 4:
		HAL_GPIO_WritePin(PINA_GPIO_Port, PINA_Pin, SET);
		HAL_GPIO_WritePin(PINB_GPIO_Port, PINB_Pin, RESET);
		HAL_GPIO_WritePin(PINC_GPIO_Port, PINC_Pin, RESET);
		HAL_GPIO_WritePin(PIND_GPIO_Port, PIND_Pin, SET);
		HAL_GPIO_WritePin(PINE_GPIO_Port, PINE_Pin, SET);
		HAL_GPIO_WritePin(PINF_GPIO_Port, PINF_Pin, RESET);
		HAL_GPIO_WritePin(PING_GPIO_Port, PING_Pin, RESET);
		break;
	case 5:
		HAL_GPIO_WritePin(PINA_GPIO_Port, PINA_Pin, RESET);
		HAL_GPIO_WritePin(PINB_GPIO_Port, PINB_Pin, SET);
		HAL_GPIO_WritePin(PINC_GPIO_Port, PINC_Pin, RESET);
		HAL_GPIO_WritePin(PIND_GPIO_Port, PIND_Pin, RESET);
		HAL_GPIO_WritePin(PINE_GPIO_Port, PINE_Pin, SET);
		HAL_GPIO_WritePin(PINF_GPIO_Port, PINF_Pin, RESET);
		HAL_GPIO_WritePin(PING_GPIO_Port, PING_Pin, RESET);
		break;
	case 6:
		HAL_GPIO_WritePin(PINA_GPIO_Port, PINA_Pin, RESET);
		HAL_GPIO_WritePin(PINB_GPIO_Port, PINB_Pin, SET);
		HAL_GPIO_WritePin(PINC_GPIO_Port, PINC_Pin, RESET);
		HAL_GPIO_WritePin(PIND_GPIO_Port, PIND_Pin, RESET);
		HAL_GPIO_WritePin(PINE_GPIO_Port, PINE_Pin, RESET);
		HAL_GPIO_WritePin(PINF_GPIO_Port, PINF_Pin, RESET);
		HAL_GPIO_WritePin(PING_GPIO_Port, PING_Pin, RESET);
		break;
	case 7:
		HAL_GPIO_WritePin(PINA_GPIO_Port, PINA_Pin, RESET);
		HAL_GPIO_WritePin(PINB_GPIO_Port, PINB_Pin, RESET);
		HAL_GPIO_WritePin(PINC_GPIO_Port, PINC_Pin, RESET);
		HAL_GPIO_WritePin(PIND_GPIO_Port, PIND_Pin, SET);
		HAL_GPIO_WritePin(PINE_GPIO_Port, PINE_Pin, SET);
		HAL_GPIO_WritePin(PINF_GPIO_Port, PINF_Pin, SET);
		HAL_GPIO_WritePin(PING_GPIO_Port, PING_Pin, SET);
		break;
	case 8:
		HAL_GPIO_WritePin(PINA_GPIO_Port, PINA_Pin, RESET);
		HAL_GPIO_WritePin(PINB_GPIO_Port, PINB_Pin, RESET);
		HAL_GPIO_WritePin(PINC_GPIO_Port, PINC_Pin, RESET);
		HAL_GPIO_WritePin(PIND_GPIO_Port, PIND_Pin, RESET);
		HAL_GPIO_WritePin(PINE_GPIO_Port, PINE_Pin, RESET);
		HAL_GPIO_WritePin(PINF_GPIO_Port, PINF_Pin, RESET);
		HAL_GPIO_WritePin(PING_GPIO_Port, PING_Pin, RESET);
		break;
	case 9:
		HAL_GPIO_WritePin(PINA_GPIO_Port, PINA_Pin, RESET);
		HAL_GPIO_WritePin(PINB_GPIO_Port, PINB_Pin, RESET);
		HAL_GPIO_WritePin(PINC_GPIO_Port, PINC_Pin, RESET);
		HAL_GPIO_WritePin(PIND_GPIO_Port, PIND_Pin, RESET);
		HAL_GPIO_WritePin(PINE_GPIO_Port, PINE_Pin, SET);
		HAL_GPIO_WritePin(PINF_GPIO_Port, PINF_Pin, RESET);
		HAL_GPIO_WritePin(PING_GPIO_Port, PING_Pin, RESET);
		break;
	default:
		break;
	}
}

void display7SEG1(int num){
	switch(num){
	case 0:
		HAL_GPIO_WritePin(PINA1_GPIO_Port, PINA1_Pin, RESET);
		HAL_GPIO_WritePin(PINB1_GPIO_Port, PINB1_Pin, RESET);
		HAL_GPIO_WritePin(PINC1_GPIO_Port, PINC1_Pin, RESET);
		HAL_GPIO_WritePin(PIND1_GPIO_Port, PIND1_Pin, RESET);
		HAL_GPIO_WritePin(PINE1_GPIO_Port, PINE1_Pin, RESET);
		HAL_GPIO_WritePin(PINF1_GPIO_Port, PINF1_Pin, RESET);
		HAL_GPIO_WritePin(PING1_GPIO_Port, PING1_Pin, SET);
		break;
	case 1:
		HAL_GPIO_WritePin(PINA1_GPIO_Port, PINA1_Pin, SET);
		HAL_GPIO_WritePin(PINB1_GPIO_Port, PINB1_Pin, RESET);
		HAL_GPIO_WritePin(PINC1_GPIO_Port, PINC1_Pin, RESET);
		HAL_GPIO_WritePin(PIND1_GPIO_Port, PIND1_Pin, SET);
		HAL_GPIO_WritePin(PINE1_GPIO_Port, PINE1_Pin, SET);
		HAL_GPIO_WritePin(PINF1_GPIO_Port, PINF1_Pin, SET);
		HAL_GPIO_WritePin(PING1_GPIO_Port, PING1_Pin, SET);
		break;
	case 2:
		HAL_GPIO_WritePin(PINA1_GPIO_Port, PINA1_Pin, RESET);
		HAL_GPIO_WritePin(PINB1_GPIO_Port, PINB1_Pin, RESET);
		HAL_GPIO_WritePin(PINC1_GPIO_Port, PINC1_Pin, SET);
		HAL_GPIO_WritePin(PIND1_GPIO_Port, PIND1_Pin, RESET);
		HAL_GPIO_WritePin(PINE1_GPIO_Port, PINE1_Pin, RESET);
		HAL_GPIO_WritePin(PINF1_GPIO_Port, PINF1_Pin, SET);
		HAL_GPIO_WritePin(PING1_GPIO_Port, PING1_Pin, RESET);
		break;
	case 3:
		HAL_GPIO_WritePin(PINA1_GPIO_Port, PINA1_Pin, RESET);
		HAL_GPIO_WritePin(PINB1_GPIO_Port, PINB1_Pin, RESET);
		HAL_GPIO_WritePin(PINC1_GPIO_Port, PINC1_Pin, RESET);
		HAL_GPIO_WritePin(PIND1_GPIO_Port, PIND1_Pin, RESET);
		HAL_GPIO_WritePin(PINE1_GPIO_Port, PINE1_Pin, SET);
		HAL_GPIO_WritePin(PINF1_GPIO_Port, PINF1_Pin, SET);
		HAL_GPIO_WritePin(PING1_GPIO_Port, PING1_Pin, RESET);
		break;
	case 4:
		HAL_GPIO_WritePin(PINA1_GPIO_Port, PINA1_Pin, SET);
		HAL_GPIO_WritePin(PINB1_GPIO_Port, PINB1_Pin, RESET);
		HAL_GPIO_WritePin(PINC1_GPIO_Port, PINC1_Pin, RESET);
		HAL_GPIO_WritePin(PIND1_GPIO_Port, PIND1_Pin, SET);
		HAL_GPIO_WritePin(PINE1_GPIO_Port, PINE1_Pin, SET);
		HAL_GPIO_WritePin(PINF1_GPIO_Port, PINF1_Pin, RESET);
		HAL_GPIO_WritePin(PING1_GPIO_Port, PING1_Pin, RESET);
		break;
	case 5:
		HAL_GPIO_WritePin(PINA1_GPIO_Port, PINA1_Pin, RESET);
		HAL_GPIO_WritePin(PINB1_GPIO_Port, PINB1_Pin, SET);
		HAL_GPIO_WritePin(PINC1_GPIO_Port, PINC1_Pin, RESET);
		HAL_GPIO_WritePin(PIND1_GPIO_Port, PIND1_Pin, RESET);
		HAL_GPIO_WritePin(PINE1_GPIO_Port, PINE1_Pin, SET);
		HAL_GPIO_WritePin(PINF1_GPIO_Port, PINF1_Pin, RESET);
		HAL_GPIO_WritePin(PING1_GPIO_Port, PING1_Pin, RESET);
		break;
	case 6:
		HAL_GPIO_WritePin(PINA1_GPIO_Port, PINA1_Pin, RESET);
		HAL_GPIO_WritePin(PINB1_GPIO_Port, PINB1_Pin, SET);
		HAL_GPIO_WritePin(PINC1_GPIO_Port, PINC1_Pin, RESET);
		HAL_GPIO_WritePin(PIND1_GPIO_Port, PIND1_Pin, RESET);
		HAL_GPIO_WritePin(PINE1_GPIO_Port, PINE1_Pin, RESET);
		HAL_GPIO_WritePin(PINF1_GPIO_Port, PINF1_Pin, RESET);
		HAL_GPIO_WritePin(PING1_GPIO_Port, PING1_Pin, RESET);
		break;
	case 7:
		HAL_GPIO_WritePin(PINA1_GPIO_Port, PINA1_Pin, RESET);
		HAL_GPIO_WritePin(PINB1_GPIO_Port, PINB1_Pin, RESET);
		HAL_GPIO_WritePin(PINC1_GPIO_Port, PINC1_Pin, RESET);
		HAL_GPIO_WritePin(PIND1_GPIO_Port, PIND1_Pin, SET);
		HAL_GPIO_WritePin(PINE1_GPIO_Port, PINE1_Pin, SET);
		HAL_GPIO_WritePin(PINF1_GPIO_Port, PINF1_Pin, SET);
		HAL_GPIO_WritePin(PING1_GPIO_Port, PING1_Pin, SET);
		break;
	case 8:
		HAL_GPIO_WritePin(PINA1_GPIO_Port, PINA1_Pin, RESET);
		HAL_GPIO_WritePin(PINB1_GPIO_Port, PINB1_Pin, RESET);
		HAL_GPIO_WritePin(PINC1_GPIO_Port, PINC1_Pin, RESET);
		HAL_GPIO_WritePin(PIND1_GPIO_Port, PIND1_Pin, RESET);
		HAL_GPIO_WritePin(PINE1_GPIO_Port, PINE1_Pin, RESET);
		HAL_GPIO_WritePin(PINF1_GPIO_Port, PINF1_Pin, RESET);
		HAL_GPIO_WritePin(PING1_GPIO_Port, PING1_Pin, RESET);
		break;
	case 9:
		HAL_GPIO_WritePin(PINA1_GPIO_Port, PINA1_Pin, RESET);
		HAL_GPIO_WritePin(PINB1_GPIO_Port, PINB1_Pin, RESET);
		HAL_GPIO_WritePin(PINC1_GPIO_Port, PINC1_Pin, RESET);
		HAL_GPIO_WritePin(PIND1_GPIO_Port, PIND1_Pin, RESET);
		HAL_GPIO_WritePin(PINE1_GPIO_Port, PINE1_Pin, SET);
		HAL_GPIO_WritePin(PINF1_GPIO_Port, PINF1_Pin, RESET);
		HAL_GPIO_WritePin(PING1_GPIO_Port, PING1_Pin, RESET);
		break;
	default:
		break;
	}
}
#endif /* SRC_EXERCISE_4_H_ */
