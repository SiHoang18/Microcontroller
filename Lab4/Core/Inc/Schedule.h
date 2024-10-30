/*
 * Schedule.h
 *
 *  Created on: Oct 13, 2024
 *      Author: LENOVO
 */

#ifndef INC_SCHEDULE_H_
#define INC_SCHEDULE_H_
#include "main.h"
#include "stdlib.h"
#define SCH_MAX_TASK 40
#define NO_TASK_ID 0
#define DURATION 10

typedef struct{
	void (*pTask)(void);
	uint32_t Delay;
	uint32_t Period;
	uint8_t RunMe;
	uint32_t TaskID;
} sTask;

// For LinkedList
typedef struct Node{
	struct Node* next;
	sTask data;
}Node;

Node* newNode(sTask data);
void addNode(Node* temp);
void remove();
extern Node* head;
extern Node* tail;
extern int curTask;
//

void SCH_Init();
void SCH_Add_Task(void (*pTask), int Delay, int Period);
void SCH_Delete_Task(int taskID);
void SCH_Dispatch_Tasks();
void SCH_Update();


#endif /* INC_SCHEDULE_H_ */
