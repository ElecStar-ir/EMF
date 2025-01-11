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
 * v5.0_14031024            E.Rahmanian    Optimize
 ******************************************************************************************
 */
#if defined(IAR__HAL__F0__STM32F030X6)
#ifndef EMF_TIMER_IAR__HAL__F0__STM32F030X6_H
#define EMF_TIMER_IAR__HAL__F0__STM32F030X6_H

/**
 * @code
#include "main.h"
#include <stdio.h>
#include "EMF.h"

int main(void){
uint8 a;
uint32 b;
EMF_init();
EMF_SetCoreClockTo_HSI_8MHZ_Return_1Ok_0Failed();

EMF_Timer_RegisterClockOnOff(TIM1, 1);


//user timer code...


EMF_Timer_RegisterClockOnOff(TIM1, 0);    

while (1);
}
 * @endcode
*/

namespace EMF::Timer {  
void EMF_Timer_RegisterClockOnOff(TIM_TypeDef *Timerx_Ptr__Ex_TIM1, bool Timerx_Clock_1On0Off);
uint32 EMF_Get_APBxTimerClock_HZ(TIM_TypeDef *Timerx_Ptr__Ex_TIM1);
}  // namespace EMF::Timer
using namespace EMF::Timer;

#endif
#endif
