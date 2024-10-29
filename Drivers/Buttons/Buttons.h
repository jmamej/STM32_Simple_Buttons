/*
 * Buttons.h
 *
 *  Created on: Oct 9, 2024
 *      Author: Juliano
 */
#include <stdint.h>
#include <main.h>
#include <Buttons_config.h>

#ifndef BUTTONS_BUTTONS_H_
#define BUTTONS_BUTTONS_H_

#define MAX_BUTTON_NUMBER	8
#define MIN_BUTTON_NUMBER	1

//extern uint8_t** button_state;
//extern uint8_t number_of_buttons;
//extern uint8_t btn_ack;
//extern uint8_t btn_event;
//extern uint8_t btn_check_index;
//extern GPIO_TypeDef** btn_port;
//extern uint16_t* btn_pin;

int8_t btn_init(void);

void check_button_states(void);

uint8_t btn_event_num(void);
uint8_t btn_clear_event(uint8_t event_num);




#endif /* BUTTONS_BUTTONS_H_ */
