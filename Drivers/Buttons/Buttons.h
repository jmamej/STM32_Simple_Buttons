/*
 * Buttons.h
 *
 *  Created on: Oct 9, 2024
 *      Author: Juliano
 */
#ifndef BUTTONS_BUTTONS_H_
#define BUTTONS_BUTTONS_H_

#include <stdint.h>
#include <main.h>
#include <Buttons_config.h>

#define MAX_BUTTON_NUMBER	8
#define MIN_BUTTON_NUMBER	1

void btn_init(void);
void btn_update(void);
uint8_t btn_event_num(void);
uint8_t btn_event_clear(uint8_t event_num);

#endif /* BUTTONS_BUTTONS_H_ */
