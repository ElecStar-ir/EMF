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
* v4.3_14020830            E.Rahmanian    Create
* v5.0_14031021            E.Rahmanian    Optimize
* v5.1.1_14031024          E.Rahmanian    Fixed
******************************************************************************************
*/
#if defined(IDE3000__V3__HT8)
#ifndef EMF_BUTTON_IDE3000__V3__HT8_H
#define EMF_BUTTON_IDE3000__V3__HT8_H

/**
* @code
#include "EMF.h"
#include "HT66F004.h"

void main() {
    EMF_init();
    EMF_SetCoreClockTo_HIRC_DIV1_8MHZ_Return_1Ok_0Failed();

    EMF_GIO_Init(GIOB, 0b11, GIO_MODE_INPUT, GIO_INPUT_PULLLUP);
    while (1){
        EMF_SoftWareUART_Transmit_Byte(EMF_Button_1Detect_0NotDetect(GIOB, 0, 0));
        EMF_SoftWareUART_Transmit_Byte(EMF_Button_1Detect_0NotDetect(GIOB, 1, 0));
        EMF_SoftWareUART_Transmit_Byte('\n');
        EMF_delay_tick(250000);
        EMF_delay_tick(250000);
        EMF_delay_tick(250000);
    }
}
* @endcode
*/
#define ButtonDebounceTick() EMF_delay_tick(2500)
//=========================================================================================
//=========================================================================================
bool EMF_Button_1Detect_0NotDetect(GIO_TypeDef *Ex_GIOA, uint8 PinNumber_0tox, bool DetectValue);

#endif
#endif
