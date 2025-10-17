/*
 * button.c
 *
 *  Created on: Oct 4, 2025
 *      Author: ADMIN
 */

#include "main.h"
#include "button.h"
///////////////////////////////////////////////// BUTTON 0////////////////////////////////////////////////////

int Key0= NORMAL_STATE;
int Key1= NORMAL_STATE;
int Key2= NORMAL_STATE;


int LPress0= NORMAL_STATE;
int countForPressedKey0=200;
int button_flag0=0;

int isButtonPressed0(){
	if(button_flag0==1){
		button_flag0=0;
		return 1;
	}
	return 0;
}

void getKeyInput0(){
	Key0= Key1;
	Key1= Key2;
	Key2= HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13);

	if((Key0==Key1)&&(Key1==Key2)){
		if(LPress0!= Key2){
			LPress0= Key2;
			if(Key2==PRESSED_STATE){
				button_flag0=1;
				countForPressedKey0=200;
			}
		} else {
			countForPressedKey0--;
			if(countForPressedKey0==0){
				LPress0= NORMAL_STATE;
				countForPressedKey0=200;
			}
		}
	}
}

////////////////////////////////////////////////// BUTTON 1 //////////////////////////////////////////////////////////////////////////////

int Key3= NORMAL_STATE;
int Key4= NORMAL_STATE;
int Key5= NORMAL_STATE;


int LPress1= NORMAL_STATE;
int countForPressedKey1=200;
int button_flag1=0;

int isButtonPressed1(){
	if(button_flag1==1){
		button_flag1=0;
		return 1;
	}
	return 0;
}

void getKeyInput1(){
	Key3= Key4;
	Key4= Key5;
	Key5= HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_14);

	if((Key3==Key4)&&(Key4==Key5)){
		if(LPress1!= Key5){
			LPress1= Key5;
			if(Key5==PRESSED_STATE){
				button_flag1=1;
				countForPressedKey1=200;
			}
		} else {
			countForPressedKey1--;
			if(countForPressedKey1==0){
				LPress1= NORMAL_STATE;
				countForPressedKey1=200;
			}
		}
	}
}

////////////////////////////////////////////////////////////////// BUTTON 2 //////////////////////////////////////////////////////////////

int Key6= NORMAL_STATE;
int Key7= NORMAL_STATE;
int Key8= NORMAL_STATE;


int LPress2= NORMAL_STATE;
int countForPressedKey2=200;
int button_flag2=0;

int isButtonPressed2(){
	if(button_flag2==1){
		button_flag2=0;
		return 1;
	}
	return 0;
}

void getKeyInput2(){
	Key6= Key7;
	Key7= Key8;
	Key8= HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_15);

	if((Key6==Key7)&&(Key7==Key8)){
		if(LPress2!= Key8){
			LPress2= Key8;
			if(Key8==PRESSED_STATE){
				button_flag2=1;
				countForPressedKey2=200;
			}
		} else {
			countForPressedKey2--;
			if(countForPressedKey2==0){
				LPress2= NORMAL_STATE;
				countForPressedKey2=200;
			}
		}
	}
}


