/**
 * @file led.c
 * @brief control RGB led connected to GPIO pins
 * @author au263437
 * @date oct 2022
 */
#include "led.h"
#include "MKL25Z4.h"


// LED pins, NOTE LED's arer active low
#define LED_R_PORT	PORTB
#define LED_G_PORT	PORTB
#define LED_B_PORT	PORTD

#define LED_R_GPIO	GPIOB
#define LED_G_GPIO	GPIOB
#define LED_B_GPIO	GPIOD

#define LED_R_PIN	18
#define LED_G_PIN	19
#define LED_B_PIN	1
#define SW1_PIN		7
#define SW1_MASK 	(1 << SW1_PIN)

/**
 * @brief setup GPIO pins for RGB led
 * */
void initLed(void)
{
    // init PORT modules
    SIM->SCGC5 |= (SIM_SCGC5_PORTB_MASK | SIM_SCGC5_PORTD_MASK);

    // setup pinmux
    LED_R_PORT->PCR[LED_R_PIN] = (1UL<<8); //GPIO is '1' left shifted 8
    LED_G_PORT->PCR[LED_G_PIN] = (1UL<<8);
    LED_B_PORT->PCR[LED_B_PIN] = (1UL<<8);

    // Set LED pins to output
    LED_R_GPIO->PDDR |= (1UL << LED_R_PIN);
    LED_G_GPIO->PDDR |= (1UL << LED_G_PIN);
    LED_B_GPIO->PDDR |= (1UL << LED_B_PIN);
}


/**
 * @brief leds are active low
 * @param color, see header file for col_t datatype
 * */

int setLedColor(col_t color)
{
	switch (color) {
		case BLACK:
			LED_R_GPIO->PSOR = (1 << LED_R_PIN);
			LED_G_GPIO->PSOR = (1 << LED_G_PIN);
			LED_B_GPIO->PSOR = (1 << LED_B_PIN);
			break;

		case WHITE:
			LED_R_GPIO->PCOR = (1 << LED_R_PIN);
			LED_G_GPIO->PCOR = (1 << LED_G_PIN);
			LED_B_GPIO->PCOR = (1 << LED_B_PIN);
			break;

		case RED:
			LED_R_GPIO->PCOR = (1 << LED_R_PIN);
			LED_G_GPIO->PSOR = (1 << LED_G_PIN);
			LED_B_GPIO->PSOR = (1 << LED_B_PIN);
			break;

		case GREEN:
			LED_R_GPIO->PSOR = (1 << LED_R_PIN);
			LED_G_GPIO->PCOR = (1 << LED_G_PIN);
			LED_B_GPIO->PSOR = (1 << LED_B_PIN);
			break;

		case BLUE:
			LED_R_GPIO->PSOR = (1 << LED_R_PIN);
			LED_G_GPIO->PSOR = (1 << LED_G_PIN);
			LED_B_GPIO->PCOR = (1 << LED_B_PIN);

			break;

		case YELLOW:
			LED_R_GPIO->PCOR = (1 << LED_R_PIN);
			LED_G_GPIO->PCOR = (1 << LED_G_PIN);
			LED_B_GPIO->PSOR = (1 << LED_B_PIN);
			break;

		case CYAN:
			LED_R_GPIO->PSOR = (1 << LED_R_PIN);
			LED_G_GPIO->PCOR = (1 << LED_G_PIN);
			LED_B_GPIO->PCOR = (1 << LED_B_PIN);
			break;

		case MAGENTA:
			LED_R_GPIO->PCOR = (1 << LED_R_PIN);
			LED_G_GPIO->PSOR = (1 << LED_G_PIN);
			LED_B_GPIO->PCOR = (1 << LED_B_PIN);
			break;

		default:
			return-1;//not supported
			break;

		return 0;//OK
	}
}

