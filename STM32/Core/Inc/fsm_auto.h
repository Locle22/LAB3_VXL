/*
 * fsm_auto.h
 *
 *  Created on: Oct 5, 2025
 *      Author: ADMIN
 */

#ifndef INC_FSM_AUTO_H_
#define INC_FSM_AUTO_H_
#define INIT 1
#define GREEN_RED 2
#define AMBER_RED 3
#define RED_GREEN 4
#define RED_AMBER 5
#define NOT_AUTO 6
#define NOTHING 7
#include "main.h"
#include "global.h"

extern int state;
extern int init_numRed;
extern int init_numGreen;
extern int init_numAmber;

void fsm_auto_run();

#endif /* INC_FSM_AUTO_H_ */
