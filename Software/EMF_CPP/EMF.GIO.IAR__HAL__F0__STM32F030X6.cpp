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
 * v4.0_14020803            E.Rahmanian    Create
 * v4.0.2_14020829          E.Rahmanian    Optimize{Change Name:GIO_ReadUntilDetectValue_1Pins_Return_1Detect_0TimeOut to GIO_ReadUntilDetectValue_1Pin_Return_1Detect_0TimeOut}
 *                                         Fixed{GIO_DirectWrite_Pins_Low_WithMask}
 ******************************************************************************************
 */
#include "EMF.h"
#if defined(EMF_GIO_IAR__HAL__F0__STM32F030X6_H)

void EMF::GIO::GIO_RegisterClockOnOff(GIO_TypeDef *GIOx_Ptr__Ex_GIOA, bool GIOx_Clock_1On0Off){
    switch ((uint32)GIOx_Ptr__Ex_GIOA) {
    #ifdef GIOA
    case (uint32)GIOA:
        if (GIOx_Clock_1On0Off) {
            GIOA_RegisterClockOn();
        } else {
            GIOA_RegisterClockOff();
        }
        break;
    #endif

    #ifdef GIOB
    case (uint32)GIOB:
        if (GIOx_Clock_1On0Off) {
            GIOB_RegisterClockOn();
        } else {
            GIOB_RegisterClockOff();
        }
        break;
    #endif

    #ifdef GIOC
    case (uint32)GIOC:
        if (GIOx_Clock_1On0Off) {
            GIOC_RegisterClockOn();
        } else {
            GIOC_RegisterClockOff();
        }
        break;
    #endif

    #ifdef GIOD
    case (uint32)GIOD:
        if (GIOx_Clock_1On0Off) {
            GIOD_RegisterClockOn();
        } else {
            GIOD_RegisterClockOff();
        }
        break;
    #endif

    #ifdef GIOE
    case (uint32)GIOE:
        if (GIOx_Clock_1On0Off) {
            GIOE_RegisterClockOn();
        } else {
            GIOE_RegisterClockOff();
        }
        break;
    #endif

    #ifdef GIOF
    case (uint32)GIOF:
        if (GIOx_Clock_1On0Off) {
            GIOF_RegisterClockOn();
        } else {
            GIOF_RegisterClockOff();
        }
        break;
    #endif

    #ifdef GIOG
    case (uint32)GIOG:
        if (GIOx_Clock_1On0Off) {
            GIOG_RegisterClockOn();
        } else {
            GIOG_RegisterClockOff();
        }
        break;
    #endif

    #ifdef GIOH
    case (uint32)GIOH:
        if (GIOx_Clock_1On0Off) {
            GIOH_RegisterClockOn();
        } else {
            GIOH_RegisterClockOff();
        }
        break;
    #endif

    #ifdef GIOI
    case (uint32)GIOI:
        if (GIOx_Clock_1On0Off) {
            GIOI_RegisterClockOn();
        } else {
            GIOI_RegisterClockOff();
        }
        break;
    #endif

    #ifdef GIOJ
    case (uint32)GIOJ:
        if (GIOx_Clock_1On0Off) {
            GIOJ_RegisterClockOn();
        } else {
            GIOJ_RegisterClockOff();
        }
        break;
    #endif

    #ifdef GIOK
    case (uint32)GIOK:
        if (GIOx_Clock_1On0Off) {
            GIOK_RegisterClockOn();
        } else {
            GIOK_RegisterClockOff();
        }
        break;
    #endif

    #ifdef GIOL
    case (uint32)GIOL:
        if (GIOx_Clock_1On0Off) {
            GIOL_RegisterClockOn();
        } else {
            GIOL_RegisterClockOff();
        }
        break;
    #endif

    #ifdef GIOM
    case (uint32)GIOM:
        if (GIOx_Clock_1On0Off) {
            GIOM_RegisterClockOn();
        } else {
            GIOM_RegisterClockOff();
        }
        break;
    #endif



    }  // switch
}
//=========================================================================================
//=========================================================================================
void EMF::GIO::GIO_Init(GIO_TypeDef *GIOx__Ex_GIOA,
                        uint32 GIO_PINS_Mask__Ex_0b1101,
                        uint32 GIO_MODE__Ex_GIO_MODE_OUTPUT_PUSHPULL,
                        uint32 GIO_PULL__Ex_GIO_PULLNO,
                        uint32 GIO_OUTPUT_SPEED__Ex_GIO_OUTPUT_SPEED_FREQ_LOW,
                        uint32 ALTERNATE_FUNCTION__Ex_GPIO_AF0_SPI1) {
    GPIO_InitTypeDef temp;
    temp.Pin = GIO_PINS_Mask__Ex_0b1101;
    temp.Mode = GIO_MODE__Ex_GIO_MODE_OUTPUT_PUSHPULL;
    temp.Pull = GIO_PULL__Ex_GIO_PULLNO;
    temp.Speed = GIO_OUTPUT_SPEED__Ex_GIO_OUTPUT_SPEED_FREQ_LOW;
    temp.Alternate = ALTERNATE_FUNCTION__Ex_GPIO_AF0_SPI1;
    HAL_GPIO_Init((GPIO_TypeDef *)GIOx__Ex_GIOA, &temp);
}
//=========================================================================================
//=========================================================================================
uint8 EMF::GIO::GIO_GetConfigState_1Pin_Return_Mode_0Input1Output2Alternate3Analog(GIO_TypeDef *Ex_GIOA, uint8 PinNumber_0tox) {
    return Get_2Bit_Return_0or3_SubfDef(Ex_GIOA->MODER, (2 * PinNumber_0tox));
}
//=========================================================================================
//=========================================================================================
uint8 EMF::GIO::GIO_GetConfigState_1Pin_Return_OutputMode_0PushPull_1OpenDrain(GIO_TypeDef *Ex_GIOA, uint8 PinNumber_0tox) {
    return Get_2Bit_Return_0or3_SubfDef(Ex_GIOA->OTYPER, PinNumber_0tox);
}
//=========================================================================================
//=========================================================================================
uint8 EMF::GIO::GIO_GetConfigState_1Pin_Return_OutputSpeed_0Low_1Medium_2Low_3High(GIO_TypeDef *Ex_GIOA, uint8 PinNumber_0tox) {
    return Get_2Bit_Return_0or3_SubfDef(Ex_GIOA->OSPEEDR, (2 * PinNumber_0tox));
}
//=========================================================================================
//=========================================================================================
uint8 EMF::GIO::GIO_GetConfigState_1Pin_Return_Pull_0PullNO_1PullUp_2PullDown(GIO_TypeDef *Ex_GIOA, uint8 PinNumber_0tox) {
    return Get_2Bit_Return_0or3_SubfDef(Ex_GIOA->PUPDR, (2 * PinNumber_0tox));
}
//=========================================================================================
//=========================================================================================
void EMF::GIO::GIO_Write_AllPins(GIO_TypeDef *Ex_GIOA, McuRegType Value) {
    GIO_DirectWrite_AllPins_Defsub(Ex_GIOA, Value);
}
//=========================================================================================
//=========================================================================================
void EMF::GIO::GIO_Write_1Pin(GIO_TypeDef *Ex_GIOA, uint8 PinNumber_0tox, bool Value_0or1) {
    GIO_DirectWrite_1Pin_Defsub(Ex_GIOA, PinNumber_0tox, Value_0or1);
}
//=========================================================================================
//=========================================================================================
void EMF::GIO::GIO_Write_Pins_High(GIO_TypeDef *Ex_GIOA, McuRegType Mask_Ex_0b1011) {
    GIO_DirectWrite_Pins_High_WithMask_Defsub(Ex_GIOA, Mask_Ex_0b1011);
}
//=========================================================================================
//=========================================================================================
void EMF::GIO::GIO_Write_Pins_Low(GIO_TypeDef *Ex_GIOA, McuRegType Mask_Ex_0b1011) {
    GIO_DirectWrite_Pins_Low_WithMask_Defsub(Ex_GIOA, Mask_Ex_0b1011);
}
//=========================================================================================
//=========================================================================================
void EMF::GIO::GIO_Write_Pins(GIO_TypeDef *Ex_GIOA, McuRegType Mask_High_Ex_0b1011, McuRegType Mask_Low_Ex_0b1011) {
    GIO_DirectWrite_Pins_WithMask_Defsub(Ex_GIOA, Mask_High_Ex_0b1011, Mask_Low_Ex_0b1011);
}
//=========================================================================================
//=========================================================================================
void EMF::GIO::GIO_Write_Pins_Toggle(GIO_TypeDef *Ex_GIOA, McuRegType Mask_Ex_0b1011) {
    GIO_DirectWrite_Pins_Toggle_WithMask_Defsub(Ex_GIOA, Mask_Ex_0b1011);
}
//=========================================================================================
//=========================================================================================
McuRegType EMF::GIO::GIO_GetWriteState_AllPins(GIO_TypeDef *Ex_GIOA) {
    return GIO_DirectGetWriteState_AllPins(Ex_GIOA);
}
//=========================================================================================
//=========================================================================================
McuRegType EMF::GIO::GIO_Read_AllPins(GIO_TypeDef *Ex_GIOA) {
    return GIO_DirectRead_AllPins_Defsubf(Ex_GIOA);
}
//=========================================================================================
//=========================================================================================
bool EMF::GIO::GIO_Read_1Pin(GIO_TypeDef *Ex_GIOA, uint8 PinNumber_0tox) {
    return GIO_DirectRead_1Pin_Defsubf(Ex_GIOA, PinNumber_0tox);
}
//=========================================================================================
//=========================================================================================
bool EMF::GIO::GIO_Read_PinsIs1(GIO_TypeDef *Ex_GIOA, McuRegType Mask_Ex_0b1000) {
    return GIO_DirectRead_PinsIs1_WithMask_Defsubf(Ex_GIOA, Mask_Ex_0b1000);
}
//=========================================================================================
//=========================================================================================
bool EMF::GIO::GIO_Read_PinsIs0(GIO_TypeDef *Ex_GIOA, McuRegType Mask_Ex_0b1000) {
    return GIO_DirectRead_PinsIs0_WithMask_Defsubf(Ex_GIOA, Mask_Ex_0b1000);
}
//=========================================================================================
//=========================================================================================
bool EMF::GIO::GIO_Read_PinsIs0And1(GIO_TypeDef *Ex_GIOA, McuRegType Mask_High_Ex_0b1000, McuRegType Mask_Low_Ex_0b1000) {
    return GIO_DirectRead_PinsIs0And1_WithMask_Defsubf(Ex_GIOA, Mask_High_Ex_0b1000, Mask_Low_Ex_0b1000);
}
//=========================================================================================
//=========================================================================================
bool EMF::GIO::GIO_ReadUntilDetectValue_AllPins_Return_1Detect_0TimeOut(GIO_TypeDef *Ex_GIOA, McuRegType CheckValue, uint32 TryCount) {
    while ((TryCount) && (GIO_DirectRead_AllPins_Defsubf(Ex_GIOA) != CheckValue)){
        TryCount--;
    };
    return TryCount && 1;
}
//=========================================================================================
//=========================================================================================
bool EMF::GIO::GIO_ReadUntilChangeValue_AllPins_Return_1Detect_0TimeOut(GIO_TypeDef *Ex_GIOA, McuRegType CheckValue, uint32 TryCount) {
    while ((TryCount) && (GIO_DirectRead_AllPins_Defsubf(Ex_GIOA) == CheckValue)){
        TryCount--;
    };
    return TryCount && 1;
}
//=========================================================================================
//=========================================================================================
bool EMF::GIO::GIO_ReadUntilDetectValue_1Pin_Return_1Detect_0TimeOut(GIO_TypeDef *Ex_GIOA, McuRegType Mask_Ex_0b1000, bool CheckValue_0or1, uint32 TryCount) {
    while ((TryCount) && (GIO_DirectRead_PinsIs1_WithMask_Defsubf(Ex_GIOA, Mask_Ex_0b1000) != CheckValue_0or1)){
        TryCount--;
    };
    return TryCount && 1;
}
#endif
