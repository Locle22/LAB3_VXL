/*
 * fsm_man.h
 *
 *  Created on: Oct 8, 2025
 *      Author: ADMIN
 */

#ifndef INC_FSM_MAN_H_
#define INC_FSM_MAN_H_

#include "main.h"
#include "global.h"
#include "button.h"
#include "fsm_auto.h"
#define MODE1 10
#define MODE2 11
#define MODE3 12
#define MODE4 13
#define AUTO_MODE 14

extern int mode_arr[4];
extern int mode_choose;
extern int mode_sw;
void modeRun();
void fsm_man_run();
#endif /* INC_FSM_MAN_H_ */
