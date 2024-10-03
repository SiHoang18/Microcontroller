/*
 * Timer.c
 *
 *  Created on: Sep 15, 2024
 *      Author: LENOVO
 */
#include "Timer.h"
#define MAX_SEG 2

int counter[MAX_SEG] = {0,0};
int flag[MAX_SEG] = {0,0};

void setTime(int duration, int index){
	if(index < MAX_SEG){
		counter[index] = duration / TIME_CYCLE;
		flag[index] = 0;
	}
}

void runTime(){
	for(int i = 0;i < MAX_SEG; ++i){
		counter[i] -= 1;
		if(counter[i] <= 0){
			flag[i] = 1;
		}
	}
}

