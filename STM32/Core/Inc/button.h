/*
 * button.h
 *
 *  Created on: Oct 4, 2025
 *      Author: ADMIN
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#define NORMAL_STATE GPIO_PIN_SET
#define PRESSED_STATE GPIO_PIN_RESET

extern int button_flag0;
extern int button_flag1;
extern int button_flag2;

void getKeyInput0();
void getKeyInput1();
void getKeyInput2();

int isButtonPressed0();
int isButtonPressed1();
int isButtonPressed2();

#endif /* INC_BUTTON_H_ */
