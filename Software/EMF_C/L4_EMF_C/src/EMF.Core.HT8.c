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
#include "EMF.h"
#if defined(EMF_CORE_HT8_H)
//=========================================================================================
//=========================================================================================
void ResetCpu() {
    // WDTC Register
    // Bit 7 6 5 4 3 2 1 0
    // Name WE4 WE3 WE2 WE1 WE0 WS2 WS1 WS0
    // R/W R/W R/W R/W R/W R/W R/W R/W R/W
    // POR 0 1 0 1 0 0 1 1

    // Bit 7~ 3 WE4 ~ WE0: WDT function software control
    // 10101: WDT disable
    // 01010: WDT enable
    // Other values: Reset MCU

    // Bit 2~ 0 WS2 ~ WS0: WDT Time-out period selection
    // 000: 28/ fLIRC
    // 001: 29/fLIRC
    // 010: 210/fLIRC
    // 011: 211/fLIRC
    // 100: 212/fLIRC
    // 101: 213/fLIRC
    // 110: 214/fLIRC
    // 111: 215/fLIRC
    // These three bits determine the division ratio of the Watchdog Timer sourece clock, which in turn
    // determines the timeout period.

    _wdtc = 0;  // Other values: Reset MCU
}
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

uint32 GetCoreClock_HZ(uint32 SystemClockSource_Hz) {
    uint8 a = _smod >> 5;
    if (_hlclk == 1) {
        return SystemClockSource_Hz;
    } else if (a == 0b111) {  // 111: fH/2
        return SystemClockSource_Hz / 2;
    } else if (a == 0b110) {  // 110: fH/4
        return SystemClockSource_Hz / 4;
    } else if (a == 0b101) {  // 101: fH/8
        return SystemClockSource_Hz / 8;
    } else if (a == 0b100) {  // 100: fH/16
        return SystemClockSource_Hz / 16;
    } else if (a == 0b011) {  // 011: fH/32
        return SystemClockSource_Hz / 32;
    } else if (a == 0b010) {  // 010: fH/64
        return SystemClockSource_Hz / 64;
    } else {  // 000 or 001: Flirc
        return SystemClockSource_Hz;
    }
}
//=========================================================================================
//=========================================================================================
void SetCoreClockTo_FH_Div1() {
    _hlclk = 1; 
    while (!_hto);  // wait until ready
}
//=========================================================================================
//=========================================================================================
void SetCoreClockTo_FH_Div64() {
    _smod = 0b01000010;  // 010: fH/64
    while (!_hto)
        ;  // wait until ready
}
//=========================================================================================
//=========================================================================================
void SetCoreClockTo_FSub() {
    _smod = 0b00000010;  // 000: Fsub
    while (!_hto);  // wait until HIRC ready
}
//=========================================================================================
//=========================================================================================


#endif
