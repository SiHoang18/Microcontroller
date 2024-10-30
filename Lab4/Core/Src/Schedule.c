/*
 * Schedule.c
 *
 *  Created on: Oct 13, 2024
 *      Author: LENOVO
 */
#include <Schedule.h>
sTask SCH_tasks_G[SCH_MAX_TASK];
Node* head = NULL;
Node* tail = NULL;
int curTask = 0;

Node* newNode(sTask data){
	Node* tmp = (Node*)malloc(sizeof(Node));
	tmp->data = data;
	tmp->next = NULL;
	return tmp;
}

void addNode(Node* temp){
	if(head == NULL){
		head = temp;
		tail = head;
	}else{
		tail->next = temp;
		tail = tail->next;
	}
	++curTask;
}
void remove(int index){
	if(index == 0){
		Node* tmp = head;
		head = head->next;
		tmp->next = NULL;
		free(tmp);
	}else if(index == curTask - 1){
		Node* tmp = head;
		while(tmp->next != tail){
			tmp = tmp->next;
		}
		tmp->next = NULL;
		free(tail);
		tail = tmp;
	}else{
		Node* cur = head;
		for(int i = 0;i < index; ++i) cur = cur->next;
		Node* tmp = cur->next;
		cur->next = tmp->next;
		tmp->next = NULL;
		free(tmp);
	}
	--curTask;
}

void SCH_Init(){
	while(curTask){
		remove(0);
	}

}
void SCH_Add_Task(void (*pTask), int Delay, int Period){
	sTask cur;
	cur.Delay = Delay / DURATION; cur.pTask = pTask ; cur.Period = Period / DURATION; cur.RunMe = 0; cur.TaskID = curTask;
	Node* temp = newNode(cur);
	addNode(temp);
}
void SCH_Delete_Task(int index){
	remove(index);
}
void SCH_Dispatch_Tasks(){
	Node* temp = head;
	while(temp){
		if(temp->data.RunMe > 0){
			(*temp->data.pTask)();
			temp->data.RunMe -= 1;
			if(temp->data.Period == 0){
				SCH_Delete_Task((int)(temp->data.TaskID));
			}
		}
		temp = temp->next;
	}
}
void SCH_Update(){
	Node* temp = head;
	while(temp){
		if(temp->data.pTask){
			if(temp->data.Delay == 0){
				temp->data.RunMe += 1;
				if(temp->data.Period){
					temp->data.Delay = temp->data.Period;
				}
			}
			else{
				temp->data.Delay -= 1;
			}
		}
		temp = temp->next;
	}
}
