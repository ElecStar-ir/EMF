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
* v4.2_14020824            E.Rahmanian    Create
******************************************************************************************
*/
#ifndef EMF_SYSTEM_IDE3000__V3__HT8__HT66F0021_31_41_H
#define EMF_SYSTEM_IDE3000__V3__HT8__HT66F0021_31_41_H
#if defined(IDE3000__V3__HT8__HT66F0021_31_41)

/**
* @code
#include "EMF.h"
#include "HT66F004.h"

void main() {
    _rw uint8 a, b, c, d;
    EMF_init();

    a = SetCoreClockTo_HIRC_DIV2_4MHZ_Return_1Ok_0Failed();
    b = SetCoreClockTo_HIRC_DIV64_125KHZ_Return_1Ok_0Failed();
    c = SetCoreClockTo_LIRC_32KHZ_Return_1Ok_0Failed();
    d = SetCoreClockTo_HIRC_DIV1_8MHZ_Return_1Ok_0Failed();
    SoftWareUART_Transmit_Byte(a);
    SoftWareUART_Transmit_Byte(b);
    SoftWareUART_Transmit_Byte(c);
    SoftWareUART_Transmit_Byte(d);
    SoftWareUART_Transmit_Byte('\n');

    GIO_Init(GIOB, 0b1111, GIO_MODE_OUTPUT_PUSHPULL, GIO_INPUT_PULLLUP);
    SoftWareUART_Transmit_Byte(GIOB->PxC);
    SoftWareUART_Transmit_Byte(GIOB->PxPU);
    SoftWareUART_Transmit_Byte('\n');

    GIO_GetConfigState_1Pin_Return_Mode_1Input0Output(GIOB, 0);
    SoftWareUART_Transmit_Byte(GIO_GetConfigState_1Pin_Return_Mode_1Input0Output(GIOB, 7));
    SoftWareUART_Transmit_Byte(GIO_GetConfigState_1Pin_Return_Mode_1Input0Output(GIOB, 6));
    SoftWareUART_Transmit_Byte(GIO_GetConfigState_1Pin_Return_Mode_1Input0Output(GIOB, 5));
    SoftWareUART_Transmit_Byte(GIO_GetConfigState_1Pin_Return_Mode_1Input0Output(GIOB, 4));
    SoftWareUART_Transmit_Byte(GIO_GetConfigState_1Pin_Return_Mode_1Input0Output(GIOB, 3));
    SoftWareUART_Transmit_Byte(GIO_GetConfigState_1Pin_Return_Mode_1Input0Output(GIOB, 2));
    SoftWareUART_Transmit_Byte(GIO_GetConfigState_1Pin_Return_Mode_1Input0Output(GIOB, 1));
    SoftWareUART_Transmit_Byte(GIO_GetConfigState_1Pin_Return_Mode_1Input0Output(GIOB, 0));
    SoftWareUART_Transmit_Byte('\n');

    SoftWareUART_Transmit_Byte(GIO_GetConfigState_1Pin_Return_Pull_0PullNO_1PullUp(GIOB, 7));
    SoftWareUART_Transmit_Byte(GIO_GetConfigState_1Pin_Return_Pull_0PullNO_1PullUp(GIOB, 6));
    SoftWareUART_Transmit_Byte(GIO_GetConfigState_1Pin_Return_Pull_0PullNO_1PullUp(GIOB, 5));
    SoftWareUART_Transmit_Byte(GIO_GetConfigState_1Pin_Return_Pull_0PullNO_1PullUp(GIOB, 4));
    SoftWareUART_Transmit_Byte(GIO_GetConfigState_1Pin_Return_Pull_0PullNO_1PullUp(GIOB, 3));
    SoftWareUART_Transmit_Byte(GIO_GetConfigState_1Pin_Return_Pull_0PullNO_1PullUp(GIOB, 2));
    SoftWareUART_Transmit_Byte(GIO_GetConfigState_1Pin_Return_Pull_0PullNO_1PullUp(GIOB, 1));
    SoftWareUART_Transmit_Byte(GIO_GetConfigState_1Pin_Return_Pull_0PullNO_1PullUp(GIOB, 0));
    SoftWareUART_Transmit_Byte('\n');

    GIO_Write_AllPins(GIOB, 0b101);
    SoftWareUART_Transmit_Byte(GIOB->Px);
    SoftWareUART_Transmit_Byte('\n');

    GIO_Write_1Pin(GIOB, 1, 1);
    SoftWareUART_Transmit_Byte(GIOB->Px);
    SoftWareUART_Transmit_Byte('\n');

    GIO_Write_1Pin(GIOB, 0, 0);
    SoftWareUART_Transmit_Byte(GIOB->Px);
    SoftWareUART_Transmit_Byte('\n');

    GIOB->Px = 0;
    GIO_Write_Pins_High(GIOB, 0b1010);
    SoftWareUART_Transmit_Byte(GIOB->Px);
    SoftWareUART_Transmit_Byte('\n');

    GIOB->Px = 0b1111;
    GIO_Write_Pins_Low(GIOB, 0b1010);
    SoftWareUART_Transmit_Byte(GIOB->Px);
    SoftWareUART_Transmit_Byte('\n');

    GIOB->Px = 0b1111;
    GIO_Write_Pins(GIOB, 0b0101, 0b1010);
    SoftWareUART_Transmit_Byte(GIOB->Px);
    SoftWareUART_Transmit_Byte('\n');

    GIOB->Px = 0;
    GIO_Write_Pins(GIOB, 0b0101, 0b1010);
    SoftWareUART_Transmit_Byte(GIOB->Px);
    SoftWareUART_Transmit_Byte('\n');

    GIO_Write_Pins_Toggle(GIOB, 0b1111);
    SoftWareUART_Transmit_Byte(GIOB->Px);
    SoftWareUART_Transmit_Byte('\n');

    GIO_Write_Pins_Toggle(GIOB, 0b1111);
    SoftWareUART_Transmit_Byte(GIOB->Px);
    SoftWareUART_Transmit_Byte('\n');

    SoftWareUART_Transmit_Byte(GIO_GetWriteState_AllPins(GIOB));
    SoftWareUART_Transmit_Byte('\n');

    GIO_Init(GIOB, 0b1111, GIO_MODE_INPUT, GIO_INPUT_PULLLUP);

    a = 20;
    while(a--){
        SoftWareUART_Transmit_Byte(GIO_Read_AllPins(GIOB));
        SoftWareUART_Transmit_Byte('\n');
        delay_tick(250000);
        delay_tick(250000);
        delay_tick(250000);
    }

    a = 20;
    while(a--){
        SoftWareUART_Transmit_Byte(GIO_Read_1Pin(GIOB, 2));
        SoftWareUART_Transmit_Byte(GIO_Read_1Pin(GIOB, 1));
        SoftWareUART_Transmit_Byte(GIO_Read_1Pin(GIOB, 0));
        SoftWareUART_Transmit_Byte('\n');
        delay_tick(250000);
        delay_tick(250000);
        delay_tick(250000);
    }

    a = 20;
    while(a--){
        SoftWareUART_Transmit_Byte(GIO_Read_PinsIs1(GIOB, 0b100));
        SoftWareUART_Transmit_Byte(GIO_Read_PinsIs1(GIOB, 0b010));
        SoftWareUART_Transmit_Byte(GIO_Read_PinsIs1(GIOB, 0b001));
        SoftWareUART_Transmit_Byte('\n');
        delay_tick(250000);
        delay_tick(250000);
        delay_tick(250000);
    }

    a = 20;
    while(a--){
        SoftWareUART_Transmit_Byte(GIO_Read_PinsIs1(GIOB, 0b110));
        SoftWareUART_Transmit_Byte(GIO_Read_PinsIs1(GIOB, 0b101));
        SoftWareUART_Transmit_Byte(GIO_Read_PinsIs1(GIOB, 0b011));
        SoftWareUART_Transmit_Byte('\n');
        delay_tick(250000);
        delay_tick(250000);
        delay_tick(250000);
    }

    a = 20;
    while(a--){
        SoftWareUART_Transmit_Byte(GIO_Read_PinsIs0(GIOB, 0b100));
        SoftWareUART_Transmit_Byte(GIO_Read_PinsIs0(GIOB, 0b010));
        SoftWareUART_Transmit_Byte(GIO_Read_PinsIs0(GIOB, 0b001));
        SoftWareUART_Transmit_Byte('\n');
        delay_tick(250000);
        delay_tick(250000);
        delay_tick(250000);
    }

    a = 20;
    while(a--){
        SoftWareUART_Transmit_Byte(GIO_Read_PinsIs0(GIOB, 0b110));
        SoftWareUART_Transmit_Byte(GIO_Read_PinsIs0(GIOB, 0b101));
        SoftWareUART_Transmit_Byte(GIO_Read_PinsIs0(GIOB, 0b011));
        SoftWareUART_Transmit_Byte('\n');
        delay_tick(250000);
        delay_tick(250000);
        delay_tick(250000);
    }

    a = 20;
    while(a--){
        SoftWareUART_Transmit_Byte(GIO_Read_PinsIs0And1(GIOB, 0b110, 0b1));
        SoftWareUART_Transmit_Byte(GIO_Read_PinsIs0And1(GIOB, 0b101, 0b10));
        SoftWareUART_Transmit_Byte(GIO_Read_PinsIs0And1(GIOB, 0b011, 0b100));
        SoftWareUART_Transmit_Byte('\n');
        delay_tick(250000);
        delay_tick(250000);
        delay_tick(250000);
    }

    a = 20;
    while (a--) {
        b = GIO_ReadUntilDetectValue_AllPins_Return_1Detect_0TimeOut(GIOB, 0b1001, 32000);
        SoftWareUART_Transmit_Byte(b);
        SoftWareUART_Transmit_Byte('\n');
        delay_tick(250000);
        delay_tick(250000);
        delay_tick(250000);
    }

    a = 20;
    while (a--) {
        b = GIO_ReadUntilChangeValue_AllPins_Return_1Detect_0TimeOut(GIOB, 0b1001, 32000);
        SoftWareUART_Transmit_Byte(b);
        SoftWareUART_Transmit_Byte('\n');
        delay_tick(250000);
        delay_tick(250000);
        delay_tick(250000);
    }

    a = 20;
    while (a--) {
        b = GIO_ReadUntilDetectValue_1Pin_Return_1Detect_0TimeOut(GIOB, 0b10, 0, 320000);
        SoftWareUART_Transmit_Byte(b);
        SoftWareUART_Transmit_Byte('\n');
        delay_tick(250000);
        delay_tick(250000);
        delay_tick(250000);
    }
    while (1);
}
* @endcode
*/

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
