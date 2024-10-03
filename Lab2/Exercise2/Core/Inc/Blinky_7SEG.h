/*
 * Blinky_7SEG.h
 *
 *  Created on: Sep 13, 2024
 *      Author: LENOVO
 */

#ifndef INC_BLINKY_7SEG_H_
#define INC_BLINKY_7SEG_H_

extern int flag1;
extern int flag2;
extern int flag3;
extern int flag4;

void setTime1(int duration);
void setTime2(int duration);
void setTime3(int duration);
void setTime4(int duration);

void timeRun1();
void timeRun2();
void timeRun3();
void timeRun4();

#endif /* INC_BLINKY_7SEG_H_ */
