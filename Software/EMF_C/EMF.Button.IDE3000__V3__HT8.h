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
 * v4.3_14020830            E.Rahmanian    Create
 ******************************************************************************************
 */
#ifndef EMF_BUTTON_IDE3000__V3__HT8_H
#define EMF_BUTTON_IDE3000__V3__HT8_H
#if defined(IDE3000__V3__HT8)

/**
* @code
#include "EMF.h"
#include "HT66F004.h"

void main() {
    EMF_init();
    SetCoreClockTo_HIRC_DIV1_8MHZ_Return_1Ok_0Failed();

    GIO_Init(GIOB, 0b11, GIO_MODE_INPUT, GIO_INPUT_PULLLUP);
    while (1){
        SoftWareUART_Transmit_Byte(Button_1Detect_0NotDetect(GIOB, 0, 0));
        SoftWareUART_Transmit_Byte(Button_1Detect_0NotDetect(GIOB, 1, 0));
        SoftWareUART_Transmit_Byte('\n');
        delay_tick(250000);
        delay_tick(250000);
        delay_tick(250000);
    }
}
* @endcode
*/
#define ButtonDebounceTick() delay_tick(2500)
//=========================================================================================
//=========================================================================================
bool Button_1Detect_0NotDetect(GIO_TypeDef *Ex_GIOA, uint8 PinNumber_0tox, bool DetectValue);

#endif
#endif
