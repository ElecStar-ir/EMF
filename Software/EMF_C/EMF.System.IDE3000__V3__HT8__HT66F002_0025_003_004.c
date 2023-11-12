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
#include "EMF.h"
#if defined(EMF_SYSTEM_IDE3000__V3__HT8__HT66F002_0025_003_004_H)

//=========================================================================================
//=========================================================================================
// SMOD Register
// Bit 7 6 5 4 3 2 1 0
// Name CKS2 CKS1 CKS0 — LTO HTO IDLEN HLCLK
// R/W R/W R/W R/W — R R R/W R/W
// POR 0 0 0 — 0 0 1 1

// Bit 7 ~ 5 CKS2 ~ CKS0: The system clock selection when HLCLK is “0”
// 000: fL (fLIRC)
// 001: fL (fLIRC)
// 010: fH/64
// 011: fH/32
// 100: fH/16
// 101: fH/8
// 110: fH/4
// 111: fH/2

// Bit0 HLCLK: System Clock Selection
//  0: fH/2 ~ fH/64 or fL
//  1: fH
//  This bit is used to select if the fH clock or the fH/2 ~ fH/64 or fL clock is used as the system clock.
//  When the bit is high the fH clock will be selected and if low the fH/2 ~ fH/64 or fL clock will be
//  selected. When system clock switches from the fH clock to the fL clock and the fH clock will be
//  automatically switched off to conserve power

uint32 GetCoreClock_HZ() {
    _rw uint8 a = _smod >> 5;
    if (_hlclk == 1) {
        return Core_HIRC_ClockSource_Hz;
    } else if (a == 0b111) {  // 111: fH/2
        return Core_HIRC_ClockSource_Hz / 2;
    } else if (a == 0b110) {  // 110: fH/4
        return Core_HIRC_ClockSource_Hz / 4;
    } else if (a == 0b101) {  // 101: fH/8
        return Core_HIRC_ClockSource_Hz / 8;
    } else if (a == 0b100) {  // 100: fH/16
        return Core_HIRC_ClockSource_Hz / 16;
    } else if (a == 0b011) {  // 011: fH/32
        return Core_HIRC_ClockSource_Hz / 32;
    } else if (a == 0b010) {  // 010: fH/64
        return Core_HIRC_ClockSource_Hz / 64;
    } else {  // 000 or 001: Flirc
        return Core_LIRC_ClockSource_Hz;
    }
}
//=========================================================================================
//=========================================================================================
bool SetCoreClockTo_HIRC_DIV64_125KHZ_Return_1Ok_0Failed(){
    _hlclk = 0; _cks2 = 0; _cks1 = 1; _cks0 = 0;	//set Fsys as FH/64
    while (!_hto);  // wait until ready
    return (125000 == GetCoreClock_HZ());
}
//=========================================================================================
//=========================================================================================
bool SetCoreClockTo_HIRC_DIV1_8MHZ_Return_1Ok_0Failed(){
    _hlclk = 1;										//set Fsys as FH
    while (!_hto);  // wait until ready
    return (8000000 == GetCoreClock_HZ());
}
//=========================================================================================
//=========================================================================================
bool SetCoreClockTo_HIRC_DIV2_4MHZ_Return_1Ok_0Failed(){
    _hlclk = 0; _cks2 = 1; _cks1 = 1; _cks0 = 1;	//set Fsys as FH/2
    while (!_hto);  // wait until ready
    return (4000000 == GetCoreClock_HZ());
}
//=========================================================================================
//=========================================================================================
bool SetCoreClockTo_LIRC_32KHZ_Return_1Ok_0Failed(){
    _hlclk = 0; _cks2 = 0; _cks1 = 0; _cks0 = 0;	//set Fsys as FLIRC(32K)
    while (!_lto);  // wait until ready
    return (32000 == GetCoreClock_HZ());
}
#endif
