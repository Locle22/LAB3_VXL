/*
 * timer.c
 *
 *  Created on: Oct 6, 2025
 *      Author: ADMIN
 */


#include "timer.h"

int TIMER_CYCLE = 10;

int timer0_counter = 0;
int timer0_flag = 0;

int timer1_counter = 0;
int timer1_flag = 0;

int timer2_counter = 0;
int timer2_flag = 0;

int timer3_counter = 0;
int timer3_flag = 0;

int one_sec=100;
int one_sec_flag=0;

void set_timer0(int duration) {
    timer0_counter = duration / TIMER_CYCLE;
    timer0_flag = 0;
}

void timer0_run() {
    if (timer0_counter > 0) {
        timer0_counter--;
        if (timer0_counter == 0)
            timer0_flag = 1;
    }
}

void set_timer1(int duration) {
    timer1_counter = duration / TIMER_CYCLE;
    timer1_flag = 0;
}

void timer1_run() {
    if (timer1_counter > 0) {
        timer1_counter--;
        if (timer1_counter == 0)
            timer1_flag = 1;
    }
}

void set_timer2(int duration) {
    timer2_counter = duration / TIMER_CYCLE;
    timer2_flag = 0;
}

void timer2_run() {
    if (timer2_counter > 0) {
        timer2_counter--;
        if (timer2_counter == 0)
            timer2_flag = 1;
    }
}

void set_timer3(int duration) {
    timer3_counter = duration / TIMER_CYCLE;
    timer3_flag = 0;
}

void timer3_run() {
    if (timer3_counter > 0) {
        timer3_counter--;
        if (timer3_counter == 0)
            timer3_flag = 1;
    }
}

void one_sec_run(){
	one_sec--;
	if(one_sec<=0){
		one_sec_flag=1;
		one_sec=100;
	}

}
int oneSecPast(){
	if(one_sec_flag==1){
		one_sec_flag=0;
		return 1;
	}
	return 0;
}
