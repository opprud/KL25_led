#include <stdint.h> //for uint32_t datatype
#include "led.h"    //for led functions

#define DELAY_COUNT 1000000

unsigned int myglobal[10] = {10,11,12,13,14,15,16,17,18,19};
/**
 * @brief delay function
 *
 * @param nof
 */
void delay(volatile uint32_t nof)
{
    while (nof != 0)
    {
        __asm("NOP");
        nof--;
    }
}

/**
 * @brief main function, bliks led colorsequences with dumb (busy) delay
 *
 * @return int
 */
int main(void)
{
    unsigned int mylocal[10] = {0,1,2,3,4,5,6,7,8,9};
    unsigned int i = 0;
    int j = 0;
    initLed();

    while (1)
    {   
        j = j+myglobal[i%10];
        myglobal[i%10] = i;
        setLedColor(RED);
        delay(DELAY_COUNT);
        setLedColor(GREEN);
        delay(DELAY_COUNT);
    }

    return 0;
}