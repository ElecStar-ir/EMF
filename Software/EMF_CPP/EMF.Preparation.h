/**
 ******************************************************************************************
 * Copyright (c) Electro Pardazesh Daghigh Aria(EPDA).Ltd Corporation. All
 *rights reserved. This software is licensed under the MIT License.
 *
 * This file is part of EMF(EPDA Multi Microcontroller Framework).
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
#ifndef EMF_PREPARATION_H
#define EMF_PREPARATION_H
#if defined(EMF_CPP)

    #if defined(IAR__HAL__F0__STM32F030X6__STM32F030F4P6)
        #include "EMF.Preparation.IAR__HAL__F0__STM32F030X6__STM32F030F4P6.h"
    // #elif defined()
    #else
        #error "Please Uncomment the target MCU define in EMF.Config.h"
    #endif

#endif
#endif