/*
 * global.c
 *
 *  Created on: Oct 5, 2025
 *      Author: ADMIN
 */


#include "global.h"

int sw=0;

uint8_t table[10] = {
    0b1000000, // 0
    0b1111001, // 1
    0b0100100, // 2
    0b0110000, // 3
    0b0011001, // 4
    0b0010010, // 5
    0b0000010, // 6
    0b1111000, // 7
    0b0000000, // 8
    0b0010000 // 9
};

void display7SEG(int num){
    uint8_t n = table[num] & 0x7F;
    GPIOB->ODR = (GPIOB->ODR & ~(0x7F)) | n;
}

void display7SEG2(int num){
    uint8_t n = table[num] & 0x7F;
    GPIOB->ODR = (GPIOB->ODR & ~(0x7F << 7)) | (n << 7);
}

void displayNumber0(int num){
	int num1= num /10;
	int num2= num %10;

	if(sw==0){
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, RESET);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, SET);
		display7SEG(num1);
	}
	else {
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, SET);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, RESET);
		display7SEG(num2);
	}

}

void displayNumber1(int num){
	int num1= num /10;
	int num2= num %10;

	if(sw==0){
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, RESET);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, SET);
		display7SEG2(num1);
	}
	else {
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, SET);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, RESET);
		display7SEG2(num2);
	}

}

void LED_monitor(int num){
	switch(num){
	case GREEN :
		HAL_GPIO_WritePin(LED_RED0_GPIO_Port, LED_RED0_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED_GREEN0_GPIO_Port, LED_GREEN0_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED_YELLOW0_GPIO_Port, LED_YELLOW0_Pin, GPIO_PIN_SET);
		break;
	case YELLOW :
		HAL_GPIO_WritePin(LED_RED0_GPIO_Port, LED_RED0_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED_GREEN0_GPIO_Port, LED_GREEN0_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED_YELLOW0_GPIO_Port, LED_YELLOW0_Pin, GPIO_PIN_RESET);
		break;
	case RED :
		HAL_GPIO_WritePin(LED_RED0_GPIO_Port, LED_RED0_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED_GREEN0_GPIO_Port, LED_GREEN0_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED_YELLOW0_GPIO_Port, LED_YELLOW0_Pin, GPIO_PIN_SET);
		break;
	default :
		HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, GPIO_PIN_SET);
		break;
	}
}


void LED_monitor2(int num){
	switch(num){
		case GREEN :
			HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, GPIO_PIN_SET);
			break;
		case YELLOW :
			HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, GPIO_PIN_RESET);
			break;
		case RED :
			HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, GPIO_PIN_SET);
			break;
		default :
			HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, GPIO_PIN_SET);
			break;
		}
}


