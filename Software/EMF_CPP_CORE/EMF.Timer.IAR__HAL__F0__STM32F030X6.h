/**
 ******************************************************************************************
 * This file is part of EMF(Effective Multi Microcontroller Framework).
 *
 * @author  Ebrahim Rahmanian (elecstar.ir@gmail.com) (www.elecstar.ir)
 * @brief
 ******************************************************************************************
 * @attention
 *
 ******************************************************************************************
 * @RELEASE HISTORY
 *
 * DATE                     NAME           DESCRIPTION
 * v4.0_14020803            E.Rahmanian    Create
 ******************************************************************************************
 */
#ifndef EMF_TIMER_IAR__HAL__F0__STM32F030X6_H
#define EMF_TIMER_IAR__HAL__F0__STM32F030X6_H
#if defined(IAR__HAL__F0__STM32F030X6)

/**
 * @code
#include "main.h"
#include <stdio.h>
#include "EMF.h"

int main(void){
uint8 a;
uint32 b;
EMF_init();
SetCoreClockTo_HSI_8MHZ_Return_1Ok_0Failed();

Timer_RegisterClockOnOff(TIM1, 1);


//user timer code...


Timer_RegisterClockOnOff(TIM1, 0);    

while (1);
}
 * @endcode
*/


namespace EMF::Timer {
    
void Timer_RegisterClockOnOff(TIM_TypeDef *Timerx_Ptr__Ex_TIM1, bool Timerx_Clock_1On0Off);
uint32 Get_APBxTimerClock_HZ(TIM_TypeDef *Timerx_Ptr__Ex_TIM1);

}  // namespace EMF::Timer
using namespace EMF::Timer;

#endif
#endif
