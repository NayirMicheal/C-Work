/*
 * RTO2_init.h
 *
 *  Created on: 28 Feb 2018
 *      Author: Nayir
 */

#ifndef RTO2_INIT_H_
#define RTO2_INIT_H_

typedef struct
{
	u8 u8periodicity;
	u8 u8FirstDelay;
	u8 u8State;
	void (*TaskHandler)(void);
}Task;

/*Task states*/
#define RTO_u8_ACTIVE_STATE     1
#define RTO_u8_SUSPENDED_STATE  2

/*This function initialize the RTO driver*/
void RTO_voidInitialize(void);

/*This function creates a new task*/
void RTO_voidCreateTask(Task * TaskCpy, u8 u8Priority);

#endif /* RTO2_INIT_H_ */
