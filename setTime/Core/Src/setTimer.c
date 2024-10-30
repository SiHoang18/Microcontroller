/*
 * setTimer.c
 *
 *  Created on: Sep 26, 2024
 *      Author: LENOVO
 */
int flag = 0;
int counter = 0;
void setTimer(int duration){
	flag = 0;
	counter = duration / 10;
}

void runTime(){
	--counter;
	if(counter <= 0) flag = 1;
}
