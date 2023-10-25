// /**
// ******************************************************************************************
// * Copyright (c) Electro Pardazesh Daghigh Aria(EPDA).Ltd Corporation. All
// *rights reserved. This software is licensed under the MIT License.
// *
// * This file is part of EMF(EPDA Multi Microcontroller Framework).
// *
// * @author  Ebrahim Rahmanian (elecstar.ir@gmail.com) (www.elecstar.ir)
// * @brief
// ******************************************************************************************
// * @attention
// *
// ******************************************************************************************
// * @RELEASE HISTORY
// *
// * DATE                     NAME           DESCRIPTION
// * v4.0_14020803            E.Rahmanian    Create
// ******************************************************************************************
// */
#ifndef EMF_SYSTEM_IAR__HAL__F0__STM32F030X6__STM32F030F4P6_H
#define EMF_SYSTEM_IAR__HAL__F0__STM32F030X6__STM32F030F4P6_H
#if defined(IAR__HAL__F0__STM32F030X6__STM32F030F4P6)

    #define GetCoreClock_HZ() SystemCoreClock
    #define ResetMCU() NVIC_SystemReset()
namespace EMF::System {
/**
* @code
#include "main.h"
#include <stdio.h>
#include "EMF.h"

int main(void){
    int32 a;
    EMF_init();
    a = SetCoreClockTo_HSI_1MHZ_Return_1Ok_0Failed();
    printf("%d\n", a);
    a = GetCoreClock_HZ();
    printf("%d\n", a);
    a = SetCoreClockTo_HSI_8MHZ_Return_1Ok_0Failed();
    printf("%d\n", a);
    a = GetCoreClock_HZ();
    printf("%d\n", a);
    a = SetCoreClockTo_HSI_PLL_24MHZ_Return_1Ok_0Failed();
    printf("%d\n", a);
    a = GetCoreClock_HZ();
    printf("%d\n", a);
    a = SetCoreClockTo_HSI_PLL_48MHZ_Return_1Ok_0Failed();
    printf("%d\n", a);
    a = GetCoreClock_HZ();
    printf("%d\n", a);
    ResetMCU();
    while (1);
}
* @endcode
*/
bool SetCoreClockTo_HSI_1MHZ_Return_1Ok_0Failed();       // Min Speed in HSi
bool SetCoreClockTo_HSI_8MHZ_Return_1Ok_0Failed();       // Max Speed in HSi
bool SetCoreClockTo_HSI_PLL_24MHZ_Return_1Ok_0Failed();  // CPU_Max_Speed / 2
bool SetCoreClockTo_HSI_PLL_48MHZ_Return_1Ok_0Failed();  // CPU_Max_Speed
}  // namespace EMF::System
using namespace EMF::System;

#endif
#endif
