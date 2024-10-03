/*
 * Time_Control.c
 *
 *  Created on: Sep 12, 2024
 *      Author: SIHOANG
 */

#include "Time_Control.h"
#include "main.h"

int counter1 = 0;
int counter2 = 0;

int flag1 = 0;
int flag2 = 0;

void setTime1(int duration){
	counter1 = duration;
	flag1 = 0;
}

void timeRun1(){
	--counter1;
	if(counter1 <= 0){
		flag1 = 1;
	}
}

void setTime2(int duration){
	counter2 = duration;
	flag2 = 0;
}

void timeRun2(){
	--counter2;
	if(counter2 <= 0){
		flag2 = 1;
	}
}
