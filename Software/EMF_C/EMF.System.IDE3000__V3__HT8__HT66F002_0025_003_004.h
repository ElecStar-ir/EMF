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
#ifndef EMF_SYSTEM_IDE3000__V3__HT8__HT66F002_0025_003_004_H
#define EMF_SYSTEM_IDE3000__V3__HT8__HT66F002_0025_003_004_H
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
#if defined(IDE3000__V3__HT8__HT66F002_0025_003_004)

#define Core_HIRC_ClockSource_Hz 8000000
#define Core_LIRC_ClockSource_Hz 32000
uint32 GetCoreClock_HZ();
#define ResetMCU() _wdtc = 0
bool SetCoreClockTo_HIRC_DIV64_125KHZ_Return_1Ok_0Failed();       // Min Speed in HIRC
bool SetCoreClockTo_HIRC_DIV1_8MHZ_Return_1Ok_0Failed();          // Max Speed in HSi
bool SetCoreClockTo_HIRC_DIV2_4MHZ_Return_1Ok_0Failed();          // Max CPU Speed / 2
                                                                  // Max CPU Speed
bool SetCoreClockTo_LIRC_32KHZ_Return_1Ok_0Failed();              // LIRC

#endif
#endif
