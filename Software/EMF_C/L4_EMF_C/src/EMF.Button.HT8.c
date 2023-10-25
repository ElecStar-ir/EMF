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
#if defined(EMF_BUTTON_HT8_H)
bool Button_1Detect_0NotDetect(GPIO_TypeDef *Ex_GPIOA, uint8 PinNumber_0tox, bool DetectValue){
    if(Get_1Bit_Return_0or1_SubfDef(Ex_GPIOA->Px, PinNumber_0tox) == DetectValue){
        delay_tick(250000);//Debounce Tick
        if(Get_1Bit_Return_0or1_SubfDef(Ex_GPIOA->Px, PinNumber_0tox) == DetectValue){
            return 1;
        }
    }
    return 0;
}
#endif
