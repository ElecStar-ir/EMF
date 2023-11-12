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
 * v4.1_14020824            E.Rahmanian    Create
 ******************************************************************************************
 */
#ifndef EMF_PREPARATION_H
#define EMF_PREPARATION_H
#if defined(EMF_C)

    #if defined(IDE3000__V3__HT8__HT66F002_0025_003_004__HT66F004)
        #include "EMF.Preparation.IDE3000__V3__HT8__HT66F002_0025_003_004__HT66F004.h"
    // #elif defined()
    #else
        #error "Please Uncomment the target MCU define in EMF.Config.h"
    #endif

#endif
#endif