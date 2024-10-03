/*
 * Blinky_7SEG.c
 *
 *  Created on: Sep 13, 2024
 *      Author: LENOVO
 */

#include "Blinky_7SEG.h"

int flag1 = 0, flag2 = 0, flag3 = 0, flag4 = 0;
int counter1 = 0, counter2 = 0, counter3 = 0, counter4 = 0;

void setTime1(int duration){
	counter1 = duration;
	flag1 = 0;
}
void setTime2(int duration){
	counter2 = duration;
	flag2 = 0;
}
void setTime3(int duration){
	counter3 = duration;
	flag3 = 0;
}
void setTime4(int duration){
	counter4 = duration;
	flag4 = 0;
}

void timeRun1(){
	if(counter1 <= 0){
		flag1 = 1;
	}
	--counter1;
}
void timeRun2(){
	if(counter2 <= 0){
		flag2 = 1;
	}
	--counter2;
}
void timeRun3(){
	if(counter3 <= 0){
		flag3 = 1;
	}
	--counter3;
}
void timeRun4(){
	if(counter4 <= 0){
		flag4 = 1;
	}
	--counter4;
}
