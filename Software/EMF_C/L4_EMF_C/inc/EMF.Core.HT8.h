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
#ifndef EMF_CORE_HT8_H
#define EMF_CORE_HT8_H
/**
* @code
#include "EMF.h"

void main() {
    EMF_init();

    SetCoreClockTo_HIRC_1MHZ();

    if(_pb0 == 1){
        ResetCpu();
    }
    
    // User Code
    
    while(1);
}
* @endcode
*/
#if defined(EMF__TARGET_HT66F004) || defined(EMF__TARGET_HT66F018)
void ResetCpu();
uint32 GetCoreClock_HZ(uint32 SystemClockSource_Hz);
void SetCoreClockTo_FH_Div1();   // Default and Max Speed HIRC Or HXT
void SetCoreClockTo_FH_Div64();  // Min Speed HIRC Or HXT
void SetCoreClockTo_FSub();      // LIRC Or LXT
#endif
#endif
