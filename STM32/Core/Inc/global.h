/*
 * global.h
 *
 *  Created on: Oct 5, 2025
 *      Author: ADMIN
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "main.h"
#include "timer.h"
#include "button.h"

#define GREEN 0
#define YELLOW 1
#define RED 2
#define OFF_STATE 4

extern int sw;

void display7SEG(int num);
void display7SEG2(int num);
void LED_monitor(int num);
void LED_monitor2(int num);

void displayNumber0(int num);
void displayNumber1(int num);
#endif /* INC_GLOBAL_H_ */
