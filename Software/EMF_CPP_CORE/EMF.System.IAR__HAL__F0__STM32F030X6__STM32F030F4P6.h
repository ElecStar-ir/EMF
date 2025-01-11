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

#if defined(IAR__HAL__F0__STM32F030X6__STM32F030F4P6)
#ifndef EMF_SYSTEM_IAR__HAL__F0__STM32F030X6__STM32F030F4P6_H
#define EMF_SYSTEM_IAR__HAL__F0__STM32F030X6__STM32F030F4P6_H

/**
* @code
#include <stdio.h>

#include "EMF.h"
#include "main.h"

int main(void){

    int32 a;
    EMF_init();
    printf("%d\n",a);
    a = EMF_SetCoreClockTo_HSI_1MHZ_Return_1Ok_0Failed();
    printf("%d\n",a);
    a =  EMF_GetCoreClock_HZ();
    printf("%d\n",a);
    a = EMF_SetCoreClockTo_HSI_8MHZ_Return_1Ok_0Failed();
    printf("%d\n",a);
    a = EMF_GetCoreClock_HZ();
    printf("%d\n",a);
    a = EMF_SetCoreClockTo_HSI_PLL_24MHZ_Return_1Ok_0Failed();
    printf("%d\n",a);
    a = EMF_GetCoreClock_HZ();
    printf("%d\n",a);
    a = EMF_SetCoreClockTo_HSI_PLL_32MHZ_Return_1Ok_0Failed();
    printf("%d\n",a);
    a = EMF_GetCoreClock_HZ();
    printf("%d\n",a);
    a = EMF_SetCoreClockTo_HSI_PLL_48MHZ_Return_1Ok_0Failed();
    printf("%d\n",a);
    a = EMF_GetCoreClock_HZ();
    printf("%d\n",a);

}
* @endcode
*/

#define EMF_GetCoreClock_HZ() SystemCoreClock
#define EMF_ResetMCU() NVIC_SystemReset()
namespace EMF::System {
bool EMF_SetCoreClockTo_HSI_1MHZ_Return_1Ok_0Failed();       // Min Speed in HSi
bool EMF_SetCoreClockTo_HSI_8MHZ_Return_1Ok_0Failed();       // Max Speed in HSi
bool EMF_SetCoreClockTo_HSI_PLL_24MHZ_Return_1Ok_0Failed();  // CPU_Max_Speed / 2
bool EMF_SetCoreClockTo_HSI_PLL_48MHZ_Return_1Ok_0Failed();  // CPU_Max_Speed
}  // namespace EMF::System
using namespace EMF::System;

#endif
#endif
