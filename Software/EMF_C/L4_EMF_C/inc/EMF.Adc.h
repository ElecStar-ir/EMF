/**
******************************************************************************************
* Copyright (c) Electro Pardazesh Daghigh Aria(EPDA).Ltd Corporation. All rights
*reserved. This software is licensed under the MIT License.
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
*
******************************************************************************************
*/
#ifndef EMF_ADC_H
#define EMF_ADC_H

#if defined(EMF__TYPE_HT8)
    #if defined(EMF__TARGET_HT66F004)
        #include "EMF.Adc.HT8.HT66F002_0025_003_004.h"
    #elif defined(EMF__TARGET_HT66F018)
        #include "EMF.Adc.HT8.HT66F018.h"
    #endif
#endif

#endif
