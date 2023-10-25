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
 * v3.0.0_14011102_3        E.Rahmanian    Create
 ******************************************************************************************
 */
#ifndef EMF_PREPARATION_H
#define EMF_PREPARATION_H

//=========================================================================================
//=========================================================================================
// EMF TARGET  : TYPE -> FAMILY -> TARGET
//          EX : STM32-> STM32F0 -> STM32F030X6

// EMF IDE     :  IDE
//          EX :  IAR

// EMF LANGUAGE: LANGUAGE
//          EX : CPP

#if defined(EMF__TARGET_HT66F004__DRIVER_HOLTEK8BIT__IDE_IDE3000__LANGUAGE_C)
    #define EMF__TARGET_HT66F004 (1)
    #define EMF__TYPE_HT8        (1)
    #define EMF__FAMILY_HT66     (1)
    #define EMF__IDE_IDE3000     (1)
    #define EMF__LANGUAGE_C      (1)
#elif defined(EMF__TARGET_HT66F018__DRIVER_HOLTEK8BIT__IDE_IDE3000__LANGUAGE_C)
    #define EMF__TARGET_HT66F018 (1)
    #define EMF__TYPE_HT8        (1)
    #define EMF__FAMILY_HT66     (1)
    #define EMF__IDE_IDE3000     (1)
    #define EMF__LANGUAGE_C      (1)
#else
    #error "Please select the target MCU in EMF.Config.h"
#endif

#endif