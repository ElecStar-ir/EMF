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
#include "EMF.h"
#if defined(EMF_BUTTON_IDE3000__V3__HT8_H)
bool Button_1Detect_0NotDetect(GIO_TypeDef *Ex_GPIOA, uint8 PinNumber_0tox, bool DetectValue){
    if(Get_1Bit_Return_0or1_SubfDef(Ex_GPIOA->Px, PinNumber_0tox) == DetectValue){
        ButtonDebounceTick();
        if(Get_1Bit_Return_0or1_SubfDef(Ex_GPIOA->Px, PinNumber_0tox) == DetectValue){
            return 1;
        }
    }
    return 0;
}
#endif
