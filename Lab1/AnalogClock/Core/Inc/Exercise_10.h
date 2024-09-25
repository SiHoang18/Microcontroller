/*
 * Exercise_10.h
 *
 *  Created on: Sep 7, 2024
 *      Author: SIHOANG
 */

#ifndef SRC_EXERCISE_10_H_
#define SRC_EXERCISE_10_H_
#include "main.h"
#include "Exercise_7.h"
#include "Exercise_8.h"
#include "Exercise_9.h"

void Analog_Clock(){
	clearAllClock();
	int hour = 0, min = 0, sec = -1;
	while(1){
		if(sec == 60){
			sec = 0;
			clearNumberOnClock(min / 5);
			++min;
		}
		if(min == 60){
			clearNumberOnClock(min / 5);
			min = 0;
			clearNumberOnClock(hour);
			++hour;
		}
		if(hour == 12){
			clearNumberOnClock(hour);
			hour = 0;
		}
		clearNumberOnClock(sec / 5);
		++sec;
		setNumberOnClock(sec / 5);
		setNumberOnClock(min / 5);
		setNumberOnClock(hour);
		HAL_Delay(10);
	}
}


#endif /* SRC_EXERCISE_10_H_ */
