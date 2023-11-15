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
 * v4.2_14020824            E.Rahmanian    Create
 ******************************************************************************************
 */
#ifndef EMF_SYSTEM_IDE3000__V3__HT8__HT66F0021_31_41_H
#define EMF_SYSTEM_IDE3000__V3__HT8__HT66F0021_31_41_H
/**
* @code
/**
* @code
#include "EMF.h"
#include "HT66F004.h"

void main() {
    uint8 a;
    bool b;
    EMF_init();
    SetCoreClockTo_HIRC_DIV1_8MHZ_Return_1Ok_0Failed();

    GIO_Init(GIOA, 0b11, GIO_MODE_INPUT, GIO_INPUT_PULLLUP);
    a = GIO_GetConfigState_1Pin_Return_Mode_1Input0Output(GIOA, 1);
    a = GIO_GetConfigState_1Pin_Return_Pull_0PullNO_1PullUp(GIOA, 1);
    GIO_Write_AllPins(GIOA, 0b1010);
    GIO_Write_1Pin(GIOA, 1, 0);
    GIO_Write_Pins_High(GIOA, 0b11);
    GIO_Write_Pins_Low(GIOA, 0b100);
    GIO_Write_Pins(GIOA, 0b1001, 0b10);
    GIO_Write_Pins_Toggle(GIOA, 0b1010);
    a = GIO_GetWriteState_AllPins(GIOA);
    a = GIO_Read_AllPins(GIOA);
    b = GIO_Read_1Pin(GIOA, 3);
    b = GIO_Read_PinsIs1(GIOA, 0b1000);
    b = GIO_Read_PinsIs0(GIOA, 0b0101);
    b = GIO_Read_PinsIs0And1(GIOA, 0b1000, 0b011);
    b = GIO_ReadUntilDetectValue_AllPins_Return_1Detect_0TimeOut(GIOA, 0b100, 2000);
    b = GIO_ReadUntilChangeValue_AllPins_Return_1Detect_0TimeOut(GIOA, 0b100, 3000);
    b = GIO_ReadUntilDetectValue_1Pins_Return_1Detect_0TimeOut(GIOA, 0b10000, 1, 3000);
}
* @endcode
*/
#if defined(IDE3000__V3__HT8__HT66F0021_31_41)

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
