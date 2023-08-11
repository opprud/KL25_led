/**
 *@file led.h
 */

#ifndef LED_H_
#define LED_H_

/// Enumeration to set led color
typedef enum
{
	BLACK,
	WHITE,
	RED,
	GREEN,
	BLUE,
	YELLOW,
	CYAN,
	MAGENTA
}col_t;



void initLed(void);
int setLedColor(col_t color);


#endif /* LED_H_ */
