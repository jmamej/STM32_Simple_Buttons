/*
 * Buttons_config.h
 *
 *  Created on: Oct 9, 2024
 *      Author: Juliano
 */

#ifndef BUTTONS_BUTTONS_CONFIG_H_
#define BUTTONS_BUTTONS_CONFIG_H_

#define NUM_OF_BUTTONS	4		//number of used buttons
#define IDLE_HIGH				//comment if release state is low
#define NUM_OF_READS	12		//debounce time / how many ms does it take to determine button press
#define BTN_ON_ACK		10		//keep lower than NUM_OF_READS
#define BTN_OFF_ACK		10		//keep lower than NUM_OF_READS
//#define ON_RELEASE			//uncomment for button press being counted on button release

#endif /* BUTTONS_BUTTONS_CONFIG_H_ */
