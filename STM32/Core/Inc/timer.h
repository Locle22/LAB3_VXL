/*
 * timer.h
 *
 *  Created on: Oct 6, 2025
 *      Author: ADMIN
 */

#ifndef INC_TIMER_H_
#define INC_TIMER_H_

extern int TIMER_CYCLE;

extern int timer0_counter;
extern int timer0_flag;

extern int timer1_counter;
extern int timer1_flag;

extern int timer2_counter;
extern int timer2_flag;

extern int timer3_counter;
extern int timer3_flag;

extern int one_sec;
void timer0_run();
void set_timer0(int duration);

void timer1_run();
void set_timer1(int duration);

void timer2_run();
void set_timer2(int duration);

void timer3_run();
void set_timer3(int duration);

int oneSecPast();
void one_sec_run();
#endif /* INC_TIMER_H_ */
