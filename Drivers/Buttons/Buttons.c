/*
 * Buttons.c
 *
 *  Created on: Oct 9, 2024
 *      Author: Juliano
 */
<<<<<<< Updated upstream
 #include <Buttons.h>
 #include <Buttons_config.h>
 #include <stdlib.h>
 
 #if NUM_OF_BUTTONS > MAX_BUTTON_NUMBER
 #error Number of button exccedes MAX_BUTTON_NUMBER (8)
 #endif
 #if NUM_OF_BUTTONS < MIN_BUTTON_NUMBER
 #error Number of buttons is below MIN_BUTTON_NUMBER (1)
 #endif
 #if BTN_ON_ACK > NUM_OF_READS
 #error Ammount of ON states, exceedes NUM_OF_READS array
 #endif
 #if BTN_OFF_ACK > NUM_OF_READS
 #error Ammount of OFF states, exceedes NUM_OF_READS array
 #endif
 
 volatile int8_t btn_counter[NUM_OF_BUTTONS] = {0};
 GPIO_TypeDef* btn_port[NUM_OF_BUTTONS];
 uint16_t btn_pin[NUM_OF_BUTTONS];
 
 volatile uint8_t btn_event = 0;
 uint8_t btn_ack = 0;
 
 
 void btn_init() {
 #if NUM_OF_BUTTONS >= 1
	 btn_port[0] = BUTTON_0_GPIO_Port;
	 btn_pin[0] = BUTTON_0_Pin;
 #endif
 #if NUM_OF_BUTTONS >= 2
	 btn_port[1] = BUTTON_1_GPIO_Port;
	 btn_pin[1] = BUTTON_1_Pin;
 #endif
 #if NUM_OF_BUTTONS >= 3
	 btn_port[2] = BUTTON_2_GPIO_Port;
	 btn_pin[2] = BUTTON_2_Pin;
 #endif
 #if NUM_OF_BUTTONS >= 4
	 btn_port[3] = BUTTON_3_GPIO_Port;
	 btn_pin[3] = BUTTON_3_Pin;
 #endif
 #if NUM_OF_BUTTONS >= 5
	 btn_port[4] = BUTTON_4_GPIO_Port;
	 btn_pin[4] = BUTTON_4_Pin;
 #endif
 #if NUM_OF_BUTTONS >= 6
	 btn_port[5] = BUTTON_5_GPIO_Port;
	 btn_pin[5] = BUTTON_5_Pin;
 #endif
 #if NUM_OF_BUTTONS >= 7
	 btn_port[6] = BUTTON_6_GPIO_Port;
	 btn_pin[6] = BUTTON_6_Pin;
 #endif
 #if NUM_OF_BUTTONS >= 8
	 btn_port[7] = BUTTON_7_GPIO_Port;
	 btn_pin[7] = BUTTON_7_Pin;
 #endif
 }
 
 void btn_update() {
 
	 for(int i = 0; i < NUM_OF_BUTTONS; i++){
 
 #ifdef	IDLE_HIGH
		 (!HAL_GPIO_ReadPin(btn_port[i], btn_pin[i])) ? btn_counter[i]++ : btn_counter[i]--;
 #else
		 (HAL_GPIO_ReadPin(btn_port[i], btn_pin[i])) ? btn_counter[i]++ : btn_counter[i]--;
 #endif
 
		 if(btn_counter[i] > BTN_COUNTER_MAX)			btn_counter[i] = BTN_COUNTER_MAX;
		 if(btn_counter[i] < 0)							btn_counter[i] = 0;
 
		 if(btn_counter[i] >= BTN_PRESS_ACK && (btn_ack >> i & 1) == 0) {
			 btn_ack |= 1<<i;
 #ifndef ON_RELEASE
			 btn_event |= (1<<i);
 #endif
		 }
		 else if(btn_counter[i] <= (BTN_RELEASE_ACK) && (btn_ack>>i & 1) == 1) {
 #ifdef ON_RELEASE
			 btn_event |= (1<<i);
 #endif
			 btn_ack &= ~(1<<i);
		 }
	 }
 }
 
 uint8_t btn_event_num() {
	 return btn_event;
 }
 
 uint8_t btn_event_clear(uint8_t event_num) {
	 btn_event &= ~1<<event_num;
	 return btn_event;
 }
 
=======
#include <Buttons.h>
#include <Buttons_config.h>
#include <stdlib.h>

#if NUM_OF_BUTTONS > MAX_BUTTON_NUMBER
#error Number of button exccedes MAX_BUTTON_NUMBER (8)
#endif
#if NUM_OF_BUTTONS < MIN_BUTTON_NUMBER
#error Number of buttons is below MIN_BUTTON_NUMBER (1)
#endif
#if BTN_ON_ACK > NUM_OF_READS
#error Ammount of ON states, exceedes NUM_OF_READS array
#endif
#if BTN_OFF_ACK > NUM_OF_READS
#error Ammount of OFF states, exceedes NUM_OF_READS array
#endif

volatile int8_t btn_counter[NUM_OF_BUTTONS] = {0};
GPIO_TypeDef* btn_port[NUM_OF_BUTTONS];
uint16_t btn_pin[NUM_OF_BUTTONS];

volatile uint8_t btn_event = 0;

static uint8_t ammount_of_on_states(uint8_t btn_num) {
	uint8_t result = 0;
	for(int i = 0; i < NUM_OF_READS; i++) {
		result += button_state[btn_num][i];
	}
	return result;
}

void btn_init() {
#if NUM_OF_BUTTONS >= 1
	btn_port[0] = BUTTON_0_GPIO_Port;
	btn_pin[0] = BUTTON_0_Pin;
#endif
#if NUM_OF_BUTTONS >= 2
	btn_port[1] = BUTTON_1_GPIO_Port;
	btn_pin[1] = BUTTON_1_Pin;
#endif
#if NUM_OF_BUTTONS >= 3
	btn_port[2] = BUTTON_2_GPIO_Port;
	btn_pin[2] = BUTTON_2_Pin;
#endif
#if NUM_OF_BUTTONS >= 4
	btn_port[3] = BUTTON_3_GPIO_Port;
	btn_pin[3] = BUTTON_3_Pin;
#endif
#if NUM_OF_BUTTONS >= 5
	btn_port[4] = BUTTON_4_GPIO_Port;
	btn_pin[4] = BUTTON_4_Pin;
#endif
#if NUM_OF_BUTTONS >= 6
	btn_port[5] = BUTTON_5_GPIO_Port;
	btn_pin[5] = BUTTON_5_Pin;
#endif
#if NUM_OF_BUTTONS >= 7
	btn_port[6] = BUTTON_6_GPIO_Port;
	btn_pin[6] = BUTTON_6_Pin;
#endif
#if NUM_OF_BUTTONS >= 8
	btn_port[7] = BUTTON_7_GPIO_Port;
	btn_pin[7] = BUTTON_7_Pin;
#endif
}

void btn_update() {
	for(int i = 0; i < NUM_OF_BUTTONS; i++){
#ifdef	IDLE_HIGH
		(!HAL_GPIO_ReadPin(btn_port[i], btn_pin[i])) ? btn_counter[i]++ : btn_counter[i]--;
#else
		(HAL_GPIO_ReadPin(btn_port[i], btn_pin[i])) ? btn_counter[i]++ : btn_counter[i]--;
#endif

		if(btn_counter[i] > BTN_COUNTER_MAX)			btn_counter[i] = BTN_COUNTER_MAX;
		if(btn_counter[i] < 0)							btn_counter[i] = 0;

		if(btn_counter[i] >= BTN_PRESS_ACK && (btn_ack >> i & 1) == 0) {
			btn_ack |= 1<<i;
#ifndef ON_RELEASE
			btn_event |= (1<<i);
#endif
		}
		else if(btn_counter[i] <= (BTN_RELEASE_ACK) && (btn_ack>>i & 1) == 1) {
#ifdef ON_RELEASE
			btn_event |= (1<<i);
#endif
			btn_ack &= ~(1<<i);
		}
	}
}

uint8_t btn_event_num() {
	return btn_event;
}

uint8_t btn_event_clear(uint8_t event_num) {
	btn_event &= ~1<<event_num;
	return btn_event;
}
>>>>>>> Stashed changes
