/*
 * fsm_man.c
 *
 *  Created on: Oct 8, 2025
 *      Author: ADMIN
 */

#include "fsm_man.h"

int mode_arr[4]={ MODE1, MODE2, MODE3, MODE4 };
int mode_choose=0;
int mode_sw=0;

int tempRed= 10;
int tempAmber= 2;
int tempGreen= 8;

int in_man=0;
int boost=0;

void modeRun(){
	if(isButtonPressed0()==1){
		mode_sw++;
		if(mode_sw>=4){
			mode_sw=0;
		}
		mode_choose= mode_arr[mode_sw];
		boost=0;
	}
}


void fsm_man_run(){

	if (!in_man && mode_choose == AUTO_MODE) return;
	switch (mode_choose) {
		case MODE1:
			if(in_man==1){
			mode_choose= AUTO_MODE;
			state= INIT;
			in_man=0;
			}
			break;
		case MODE2:
			if(boost==0){
				state= NOT_AUTO;
				boost=1;
				in_man=1;
			}
			if(timer3_flag==1){
				timer3_flag=0;
				set_timer3(500);
				HAL_GPIO_TogglePin(LED_RED0_GPIO_Port, LED_RED0_Pin );
				HAL_GPIO_TogglePin(LED_RED1_GPIO_Port, LED_RED1_Pin );
			}

			if(isButtonPressed1()==1){
				if(tempRed<99)
				tempRed++;
				else tempRed=1;

			}
			displayNumber0(2);
			displayNumber1(tempRed);
			if(isButtonPressed2()==1){
				init_numRed= tempRed;
				mode_choose= MODE1;
				mode_sw=0;
				if(init_numRed- init_numAmber>0){
				init_numGreen = init_numRed- init_numAmber;
				tempGreen= init_numGreen;
				}
				else {
					init_numRed=10;
					init_numGreen=8;
					init_numAmber=2;
				}
			}
			break;
		case MODE3:

			if(boost==0){
				state= NOT_AUTO;
				boost=1;
				in_man=1;
			}
			if(timer3_flag==1){
				timer3_flag=0;
				set_timer3(500);
				HAL_GPIO_TogglePin(LED_YELLOW0_GPIO_Port, LED_YELLOW0_Pin );
			    HAL_GPIO_TogglePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin );
			}

			if(isButtonPressed1()==1){
				if(tempAmber<99)
				tempAmber++;
				else tempAmber=1;
			}

			displayNumber0(3);
			displayNumber1(tempAmber);

			if(isButtonPressed2()==1){
				init_numAmber= tempAmber;
				mode_choose= MODE1;
				mode_sw=0;
				init_numRed= init_numAmber+ init_numGreen;
				tempRed= init_numRed;
			}
			break;
		case MODE4:

			if(boost==0){
				state= NOT_AUTO;
				boost=1;
				in_man=1;
			}
			if(timer3_flag==1){
				timer3_flag=0;
				set_timer3(500);
				HAL_GPIO_TogglePin(LED_GREEN0_GPIO_Port, LED_GREEN0_Pin );
				HAL_GPIO_TogglePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin );
			}

			if(isButtonPressed1()==1){
				if(tempGreen<99)
				tempGreen++;
				else tempGreen=1;
			}

			displayNumber0(4);
			displayNumber1(tempGreen);

			if(isButtonPressed2()==1){
				init_numGreen= tempGreen;
				mode_choose= MODE1;
				mode_sw=0;
				init_numRed= init_numAmber+ init_numGreen;
				tempRed= init_numRed;
			}

			break;
		default:
			break;
	}
}
