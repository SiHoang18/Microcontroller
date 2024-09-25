/*
 * Exercise_5.h
 *
 *  Created on: Sep 7, 2024
 *      Author: SIHOANG
 */

#ifndef SRC_EXERCISE_5_H_
#define SRC_EXERCISE_5_H_
#include "main.h"
#include "Exercise_4.h"

void Traffic_Light1(int count){
//	HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, RESET);
	if(count - 5 > 0){
		HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, RESET);
		HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, SET);
		HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, SET);
//		if(count - 5 >= 3){
//			HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, SET);
//			HAL_GPIO_WritePin(YELLOW2_GPIO_Port, YELLOW2_Pin, SET);
//			HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, RESET);
//		}
//		else{
//			HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, SET);
//			HAL_GPIO_WritePin(YELLOW2_GPIO_Port, YELLOW2_Pin, RESET);
//			HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, SET);
//		}
		display7SEG(count - 5);
//		HAL_Delay(10);
//		if(count - 7 > 0) display7SEG1(count - 7);
//		else display7SEG1(count - 5);
//		--count;
	}
	else if(count - 2 > 0){
		HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, SET);
		HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, SET);
		HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, RESET);
//		HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, RESET);
//		HAL_GPIO_WritePin(YELLOW2_GPIO_Port, YELLOW2_Pin, SET);
//		HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, SET);
		display7SEG(count - 2);
//		HAL_Delay(10);
//		display7SEG1(count);
//		--count;
	}
	else if(count > 0){
		HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, SET);
		HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, RESET);
		HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, SET);
//		HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, RESET);
//		HAL_GPIO_WritePin(YELLOW2_GPIO_Port, YELLOW2_Pin, SET);
//		HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, SET);
		display7SEG(count);
//		HAL_Delay(10);
//		display7SEG1(count);
	}
//	HAL_Delay(1000);
}
void Traffic_Light2(int count){
//	HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, RESET);
	if(count - 5 > 0){
		HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, RESET);
		HAL_GPIO_WritePin(YELLOW2_GPIO_Port, YELLOW2_Pin, SET);
		HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, SET);
//		if(count - 5 >= 3){
//			HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, SET);
//			HAL_GPIO_WritePin(YELLOW2_GPIO_Port, YELLOW2_Pin, SET);
//			HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, RESET);
//		}
//		else{
//			HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, SET);
//			HAL_GPIO_WritePin(YELLOW2_GPIO_Port, YELLOW2_Pin, RESET);
//			HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, SET);
//		}
		display7SEG1(count - 5);
//		HAL_Delay(10);
//		if(count - 7 > 0) display7SEG1(count - 7);
//		else display7SEG1(count - 5);
//		--count;
	}
	else if(count - 2 > 0){
		HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, SET);
		HAL_GPIO_WritePin(YELLOW2_GPIO_Port, YELLOW2_Pin, SET);
		HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, RESET);
//		HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, RESET);
//		HAL_GPIO_WritePin(YELLOW2_GPIO_Port, YELLOW2_Pin, SET);
//		HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, SET);
		display7SEG1(count - 2);
//		HAL_Delay(10);
//		display7SEG1(count);
//		--count;
	}
	else if(count > 0){
		HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, SET);
		HAL_GPIO_WritePin(YELLOW2_GPIO_Port, YELLOW2_Pin, RESET);
		HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, SET);
//		HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, RESET);
//		HAL_GPIO_WritePin(YELLOW2_GPIO_Port, YELLOW2_Pin, SET);
//		HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, SET);
		display7SEG1(count);
//		HAL_Delay(10);
//		display7SEG1(count);
	}
//	HAL_Delay(1000);
}
#endif /* SRC_EXERCISE_5_H_ */
