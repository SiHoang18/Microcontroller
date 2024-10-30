/*
 * Timer.c
 *
 *  Created on: Oct 2, 2024
 *      Author: LENOVO
 */
#include "Timer.h"
int flag[NUM_BUFFER + 3] = {0};
int counter[NUM_BUFFER + 3] = {0};

void setTime(int duration, int index){
	if(index <= NUM_BUFFER + 2){
		flag[index] = 0;
		counter[index] = duration / DURATION;
	}
}

void runTime(){
	for(int i = 0;i <= NUM_BUFFER + 2; ++i){
		if(counter[i] > 0){
			counter[i]--;
			if(counter[i] <= 0) flag[i] = 1;
		}
	}
}

