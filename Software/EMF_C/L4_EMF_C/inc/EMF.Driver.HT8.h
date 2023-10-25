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
#ifndef EMF_DRIVER_HT8_H
#define EMF_DRIVER_HT8_H

#if defined(EMF__TYPE_HT8)
    #include "STDINT.H"
    #include "STDLIB.H"
    #include "STRING.H"
    #include "build-in.h"
    #include "ctype.h"
    #include "math.h"
    #include "time.h"
    #if defined(EMF__TARGET_HT66F004)
        #include "HT66F004.h"
    #elif defined(EMF__TARGET_HT66F018)
        #include "HT66F018.h"
    #endif
#endif
#endif
