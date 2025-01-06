/**
******************************************************************************************
* This file is part of EMF(Effective Multi Microcontroller Framework).
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
* v5.0_14031021            E.Rahmanian    Optimize
******************************************************************************************
*/
#include "EMF.h"
#if defined(EMF_SYSTEM_IDE3000__V3__HT8__HT66F0021_31_41_H)

//=========================================================================================
//=========================================================================================
// SCC Register
// Bit 7 6 5 4 3 2 1 0
// Name CKS2 CKS1 CKS0 — — — FHIDEN FSIDEN
// R/W R/W R/W R/W — — — R/W R/W
// POR 0 0 0 — — — 0 0

// Bit 7~5 CKS2~CKS0: System clock selection
// 000: fH
// 001: fH/2
// 010: fH/4
// 011: fH/8
// 100: fH/16
// 101: fH/32
// 110: fH/64
// 111: fSUB
// These three bits are used to select which clock is used as the system clock source. In
// addition to the system clock source directly derived from fH or fSUB, a divided version
// of the high speed system oscillator can also be chosen as the system clock source.

// HIRCC Register
// Bit 7 6 5 4 3 2 1 0
// Name — — — — — — HIRCF HIRCEN
// R/W — — — — — — R R/W
// POR — — — — — — 0 1
// Bit 7~2 Unimplemented, read as “0”
// Bit 1 HIRCF: HIRC oscillator stable flag
// 0: HIRC unstable
// 1: HIRC stable
// This bit is used to indicate whether the HIRC oscillator is stable or not. When the
// HIRCEN bit is set to 1 to enable the HIRC oscillator, the HIRCF bit will first be
// cleared to 0 and then set to 1 after the HIRC oscillator is stable.
// Bit 0 HIRCEN: HIRC oscillator enable control
// 0: Disable
// 1: Enable

uint32 EMF_GetCoreClock_HZ() {
    _rw uint8 a = _scc >> 5;
    if (a == 0) { // 000: fH
        return Core_HIRC_ClockSource_Hz;
    } else if (a == 0b001) {  // 001: fH/2
        return Core_HIRC_ClockSource_Hz / 2;
    } else if (a == 0b010) {  // 010: fH/4
        return Core_HIRC_ClockSource_Hz / 4;
    } else if (a == 0b011) {  // 011: fH/8
        return Core_HIRC_ClockSource_Hz / 8;
    } else if (a == 0b100) {  // 100: fH/16
        return Core_HIRC_ClockSource_Hz / 16;
    } else if (a == 0b101) {  // 101: fH/32
        return Core_HIRC_ClockSource_Hz / 32;
    } else if (a == 0b110) {  // 110: fH/64
        return Core_HIRC_ClockSource_Hz / 64;
    } else {  // 111: fSUB
        return Core_LIRC_ClockSource_Hz;
    }
}
//=========================================================================================
//=========================================================================================
bool EMF_SetCoreClockTo_HIRC_DIV64_125KHZ_Return_1Ok_0Failed(){
    _hircen = 1; _cks2 = 1; _cks1 = 1; _cks0 = 0;	//set Fsys as FH/64
    while (!_hircf);  // wait until ready
    return (125000 == GetCoreClock_HZ());
}
//=========================================================================================
//=========================================================================================
bool EMF_SetCoreClockTo_HIRC_DIV1_8MHZ_Return_1Ok_0Failed(){
    _hircen = 1; _cks2 = 0; _cks1 = 0; _cks0 = 0;	//set Fsys as FH/1
    while (!_hircf);  // wait until ready
    return (8000000 == GetCoreClock_HZ());
}
//=========================================================================================
//=========================================================================================
bool EMF_SetCoreClockTo_HIRC_DIV2_4MHZ_Return_1Ok_0Failed(){
    _hircen = 1; _cks2 = 0; _cks1 = 0; _cks0 = 1;	//set Fsys as FH/2
    while (!_hircf);  // wait until ready
    return (4000000 == GetCoreClock_HZ());
}
//=========================================================================================
//=========================================================================================
bool EMF_SetCoreClockTo_LIRC_32KHZ_Return_1Ok_0Failed(){
    _cks2 = 0; _cks1 = 0; _cks0 = 0;	//set Fsys as FLIRC(32K)
    return (32000 == GetCoreClock_HZ());
}
#endif
