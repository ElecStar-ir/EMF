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
* v4.2.1_14020829          E.Rahmanian    Fixed{Remove @endcode of code example}
* v5.0_14031021            E.Rahmanian    Optimize
* v5.1.1_14031024          E.Rahmanian    Update Example
******************************************************************************************
*/
#if defined(IDE3000__V3__HT8__HT66F002_0025_003_004)
#ifndef EMF_SYSTEM_IDE3000__V3__HT8__HT66F002_0025_003_004_H
#define EMF_SYSTEM_IDE3000__V3__HT8__HT66F002_0025_003_004_H
/**
* @code
#include "EMF.h"
#include "HT66F004.h"

void main() {
    _rw uint8 a, b, c, d;
    EMF_init();

    a = EMF_SetCoreClockTo_HIRC_DIV2_4MHZ_Return_1Ok_0Failed();
    b = EMF_SetCoreClockTo_HIRC_DIV64_125KHZ_Return_1Ok_0Failed();
    c = EMF_SetCoreClockTo_LIRC_32KHZ_Return_1Ok_0Failed();
    d = EMF_SetCoreClockTo_HIRC_DIV1_8MHZ_Return_1Ok_0Failed();
    EMF_SoftWareUART_Transmit_Byte(a);
    EMF_SoftWareUART_Transmit_Byte(b);
    EMF_SoftWareUART_Transmit_Byte(c);
    EMF_SoftWareUART_Transmit_Byte(d);
    EMF_SoftWareUART_Transmit_Byte('\n');

    EMF_GIO_Init(GIOB, 0b1111, GIO_MODE_OUTPUT_PUSHPULL, GIO_INPUT_PULLLUP);
    EMF_SoftWareUART_Transmit_Byte(GIOB->PxC);
    EMF_SoftWareUART_Transmit_Byte(GIOB->PxPU);
    EMF_SoftWareUART_Transmit_Byte('\n');

    EMF_GIO_GetConfigState_1Pin_Return_Mode_1Input0Output(GIOB, 0);
    EMF_SoftWareUART_Transmit_Byte(GIO_GetConfigState_1Pin_Return_Mode_1Input0Output(GIOB, 7));
    EMF_SoftWareUART_Transmit_Byte(GIO_GetConfigState_1Pin_Return_Mode_1Input0Output(GIOB, 6));
    EMF_SoftWareUART_Transmit_Byte(GIO_GetConfigState_1Pin_Return_Mode_1Input0Output(GIOB, 5));
    EMF_SoftWareUART_Transmit_Byte(GIO_GetConfigState_1Pin_Return_Mode_1Input0Output(GIOB, 4));
    EMF_SoftWareUART_Transmit_Byte(GIO_GetConfigState_1Pin_Return_Mode_1Input0Output(GIOB, 3));
    EMF_SoftWareUART_Transmit_Byte(GIO_GetConfigState_1Pin_Return_Mode_1Input0Output(GIOB, 2));
    EMF_SoftWareUART_Transmit_Byte(GIO_GetConfigState_1Pin_Return_Mode_1Input0Output(GIOB, 1));
    EMF_SoftWareUART_Transmit_Byte(GIO_GetConfigState_1Pin_Return_Mode_1Input0Output(GIOB, 0));
    EMF_SoftWareUART_Transmit_Byte('\n');

    EMF_SoftWareUART_Transmit_Byte(GIO_GetConfigState_1Pin_Return_Pull_0PullNO_1PullUp(GIOB, 7));
    EMF_SoftWareUART_Transmit_Byte(GIO_GetConfigState_1Pin_Return_Pull_0PullNO_1PullUp(GIOB, 6));
    EMF_SoftWareUART_Transmit_Byte(GIO_GetConfigState_1Pin_Return_Pull_0PullNO_1PullUp(GIOB, 5));
    EMF_SoftWareUART_Transmit_Byte(GIO_GetConfigState_1Pin_Return_Pull_0PullNO_1PullUp(GIOB, 4));
    EMF_SoftWareUART_Transmit_Byte(GIO_GetConfigState_1Pin_Return_Pull_0PullNO_1PullUp(GIOB, 3));
    EMF_SoftWareUART_Transmit_Byte(GIO_GetConfigState_1Pin_Return_Pull_0PullNO_1PullUp(GIOB, 2));
    EMF_SoftWareUART_Transmit_Byte(GIO_GetConfigState_1Pin_Return_Pull_0PullNO_1PullUp(GIOB, 1));
    EMF_SoftWareUART_Transmit_Byte(GIO_GetConfigState_1Pin_Return_Pull_0PullNO_1PullUp(GIOB, 0));
    EMF_SoftWareUART_Transmit_Byte('\n');

    EMF_GIO_Write_AllPins(GIOB, 0b101);
    EMF_SoftWareUART_Transmit_Byte(GIOB->Px);
    EMF_SoftWareUART_Transmit_Byte('\n');

    EMF_GIO_Write_1Pin(GIOB, 1, 1);
    EMF_SoftWareUART_Transmit_Byte(GIOB->Px);
    EMF_SoftWareUART_Transmit_Byte('\n');

    EMF_GIO_Write_1Pin(GIOB, 0, 0);
    EMF_SoftWareUART_Transmit_Byte(GIOB->Px);
    EMF_SoftWareUART_Transmit_Byte('\n');

    GIOB->Px = 0;
    EMF_GIO_Write_Pins_High(GIOB, 0b1010);
    EMF_SoftWareUART_Transmit_Byte(GIOB->Px);
    EMF_SoftWareUART_Transmit_Byte('\n');

    GIOB->Px = 0b1111;
    EMF_GIO_Write_Pins_Low(GIOB, 0b1010);
    EMF_SoftWareUART_Transmit_Byte(GIOB->Px);
    EMF_SoftWareUART_Transmit_Byte('\n');

    GIOB->Px = 0b1111;
    EMF_GIO_Write_Pins(GIOB, 0b0101, 0b1010);
    EMF_SoftWareUART_Transmit_Byte(GIOB->Px);
    EMF_SoftWareUART_Transmit_Byte('\n');

    GIOB->Px = 0;
    EMF_GIO_Write_Pins(GIOB, 0b0101, 0b1010);
    EMF_SoftWareUART_Transmit_Byte(GIOB->Px);
    EMF_SoftWareUART_Transmit_Byte('\n');

    EMF_GIO_Write_Pins_Toggle(GIOB, 0b1111);
    EMF_SoftWareUART_Transmit_Byte(GIOB->Px);
    EMF_SoftWareUART_Transmit_Byte('\n');

    EMF_GIO_Write_Pins_Toggle(GIOB, 0b1111);
    EMF_SoftWareUART_Transmit_Byte(GIOB->Px);
    EMF_SoftWareUART_Transmit_Byte('\n');

    EMF_SoftWareUART_Transmit_Byte(GIO_GetWriteState_AllPins(GIOB));
    EMF_SoftWareUART_Transmit_Byte('\n');

    EMF_GIO_Init(GIOB, 0b1111, GIO_MODE_INPUT, GIO_INPUT_PULLLUP);

    a = 20;
    while(a--){
        EMF_SoftWareUART_Transmit_Byte(GIO_Read_AllPins(GIOB));
        EMF_SoftWareUART_Transmit_Byte('\n');
        EMF_delay_tick(250000);
        EMF_delay_tick(250000);
        EMF_delay_tick(250000);
    }

    a = 20;
    while(a--){
        EMF_SoftWareUART_Transmit_Byte(GIO_Read_1Pin(GIOB, 2));
        EMF_SoftWareUART_Transmit_Byte(GIO_Read_1Pin(GIOB, 1));
        EMF_SoftWareUART_Transmit_Byte(GIO_Read_1Pin(GIOB, 0));
        EMF_SoftWareUART_Transmit_Byte('\n');
        EMF_delay_tick(250000);
        EMF_delay_tick(250000);
        EMF_delay_tick(250000);
    }

    a = 20;
    while(a--){
        EMF_SoftWareUART_Transmit_Byte(GIO_Read_PinsIs1(GIOB, 0b100));
        EMF_SoftWareUART_Transmit_Byte(GIO_Read_PinsIs1(GIOB, 0b010));
        EMF_SoftWareUART_Transmit_Byte(GIO_Read_PinsIs1(GIOB, 0b001));
        EMF_SoftWareUART_Transmit_Byte('\n');
        EMF_delay_tick(250000);
        EMF_delay_tick(250000);
        EMF_delay_tick(250000);
    }

    a = 20;
    while(a--){
        EMF_SoftWareUART_Transmit_Byte(GIO_Read_PinsIs1(GIOB, 0b110));
        EMF_SoftWareUART_Transmit_Byte(GIO_Read_PinsIs1(GIOB, 0b101));
        EMF_SoftWareUART_Transmit_Byte(GIO_Read_PinsIs1(GIOB, 0b011));
        EMF_SoftWareUART_Transmit_Byte('\n');
        EMF_delay_tick(250000);
        EMF_delay_tick(250000);
        EMF_delay_tick(250000);
    }

    a = 20;
    while(a--){
        EMF_SoftWareUART_Transmit_Byte(GIO_Read_PinsIs0(GIOB, 0b100));
        EMF_SoftWareUART_Transmit_Byte(GIO_Read_PinsIs0(GIOB, 0b010));
        EMF_SoftWareUART_Transmit_Byte(GIO_Read_PinsIs0(GIOB, 0b001));
        EMF_SoftWareUART_Transmit_Byte('\n');
        EMF_delay_tick(250000);
        EMF_delay_tick(250000);
        EMF_delay_tick(250000);
    }

    a = 20;
    while(a--){
        EMF_SoftWareUART_Transmit_Byte(GIO_Read_PinsIs0(GIOB, 0b110));
        EMF_SoftWareUART_Transmit_Byte(GIO_Read_PinsIs0(GIOB, 0b101));
        EMF_SoftWareUART_Transmit_Byte(GIO_Read_PinsIs0(GIOB, 0b011));
        EMF_SoftWareUART_Transmit_Byte('\n');
        EMF_delay_tick(250000);
        EMF_delay_tick(250000);
        EMF_delay_tick(250000);
    }

    a = 20;
    while(a--){
        EMF_SoftWareUART_Transmit_Byte(GIO_Read_PinsIs0And1(GIOB, 0b110, 0b1));
        EMF_SoftWareUART_Transmit_Byte(GIO_Read_PinsIs0And1(GIOB, 0b101, 0b10));
        EMF_SoftWareUART_Transmit_Byte(GIO_Read_PinsIs0And1(GIOB, 0b011, 0b100));
        EMF_SoftWareUART_Transmit_Byte('\n');
        EMF_delay_tick(250000);
        EMF_delay_tick(250000);
        EMF_delay_tick(250000);
    }

    a = 20;
    while (a--) {
        b = EMF_GIO_ReadUntilDetectValue_AllPins_Return_1Detect_0TimeOut(GIOB, 0b1001, 32000);
        EMF_SoftWareUART_Transmit_Byte(b);
        EMF_SoftWareUART_Transmit_Byte('\n');
        EMF_delay_tick(250000);
        EMF_delay_tick(250000);
        EMF_delay_tick(250000);
    }

    a = 20;
    while (a--) {
        b = EMF_GIO_ReadUntilChangeValue_AllPins_Return_1Detect_0TimeOut(GIOB, 0b1001, 32000);
        EMF_SoftWareUART_Transmit_Byte(b);
        EMF_SoftWareUART_Transmit_Byte('\n');
        EMF_delay_tick(250000);
        EMF_delay_tick(250000);
        EMF_delay_tick(250000);
    }

    a = 20;
    while (a--) {
        b = EMF_GIO_ReadUntilDetectValue_1Pin_Return_1Detect_0TimeOut(GIOB, 0b10, 0, 320000);
        EMF_SoftWareUART_Transmit_Byte(b);
        EMF_SoftWareUART_Transmit_Byte('\n');
        EMF_delay_tick(250000);
        EMF_delay_tick(250000);
        EMF_delay_tick(250000);
    }
    while (1);
}
* @endcode
*/

#define Core_HIRC_ClockSource_Hz 8000000
#define Core_LIRC_ClockSource_Hz 32000
uint32 EMF_GetCoreClock_HZ();
#define EMF_ResetMCU() _wdtc = 0
bool EMF_SetCoreClockTo_HIRC_DIV64_125KHZ_Return_1Ok_0Failed();       // Min Speed in HIRC
bool EMF_SetCoreClockTo_HIRC_DIV1_8MHZ_Return_1Ok_0Failed();          // Max Speed in HSi
bool EMF_SetCoreClockTo_HIRC_DIV2_4MHZ_Return_1Ok_0Failed();          // Max CPU Speed / 2
                                                                  // Max CPU Speed
bool EMF_SetCoreClockTo_LIRC_32KHZ_Return_1Ok_0Failed();              // LIRC

#endif
#endif
