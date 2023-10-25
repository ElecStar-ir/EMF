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
#ifndef EMF_GPIO_HT8_H
#define EMF_GPIO_HT8_H
#if defined(EMF__TYPE_HT8)

#include "EMF.Gpio.HT8.ExternalIntrrupt.h"

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// define
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
#define GpioRegType uint8
//=========================================================================================
typedef struct{
  GpioRegType bit0 : 1;
  GpioRegType bit1 : 1;
  GpioRegType bit2 : 1;
  GpioRegType bit3 : 1;
  GpioRegType bit4 : 1;
  GpioRegType bit5 : 1;
  GpioRegType bit6 : 1;
  GpioRegType bit7 : 1;
}bits_struct_t;

typedef struct {
    union {
        _rw GpioRegType Px;   /*!< Example) PA,PB,PC*/
        _rw bits_struct_t  Px_bits;
    };

    union {
        _rw GpioRegType PxC;  /*!< Example) PAC,PBC,PCC*/
        _rw bits_struct_t  PxC_bits;
    };

    union {
        _rw GpioRegType PxPU; /*!< Example) PAPU,PBPU,PCPU*/
        _rw bits_struct_t  PxPU_bits;
    };
}GPIO_TypeDef;
//=========================================================================================
#ifdef _pa
    #define GPIOA ((GPIO_TypeDef *)&_pa)   
#endif

#ifdef _pb
    #define GPIOB ((GPIO_TypeDef *)&_pb)
#endif

#ifdef _pc
    #define GPIOC ((GPIO_TypeDef *)&_pc)
#endif
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Gpio Configs
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%   
void DigitalIo_Config_Pins(
    GPIO_TypeDef *Ex_GPIOA,
    GpioRegType OutputConfigPinsMask__0NotChangeConfig_1ConfigOutput__Ex_0b1011,
    GpioRegType InputConfigPinsMask__0NotChangeConfig_1ConfigInputt__Ex_0b1011,
    GpioRegType PullUpOnPinsMask__0NotChangePull_1OnPullup__Ex_0b1011,
    GpioRegType NoPullPinsMask__0NotChangePull_1OnPullup__Ex_0b1011);
//=========================================================================================
uint8 DigitalIo_GetConfigState_1Pin_Return_0Input1Output(
    GPIO_TypeDef *Ex_GPIOA,
    uint8 PinNumber_0tox);
//==========================================================================================
uint8 DigitalIo_GetConfigState_1Pin_Return_0NoPull_1Pullup(
    GPIO_TypeDef *Ex_GPIOA,
    uint8 PinNumber_0tox);
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Gpio Write
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%    
#define DigitalIo_DirectWrite_AllPins_Defsub(Ex_GPIOA, Value) \
    (Ex_GPIOA->Px = Value)

void DigitalIo_Write_AllPins(
    GPIO_TypeDef *Ex_GPIOA,
    GpioRegType Value);
//=========================================================================================
#define DigitalIo_DirectWrite_1Pin_Defsub(Ex_GPIOA, PinNumber_0tox, Value_0or1) \
    (Set_1Bit_SubDef((Ex_GPIOA->Px), PinNumber_0tox, Value_0or1))

void DigitalIo_Write_1Pin(
    GPIO_TypeDef *Ex_GPIOA,
    uint8 PinNumber_0tox,
    bool Value_0or1);
//=========================================================================================
#define DigitalIo_DirectWrite_Pins_High_WithMask_Defsub(Ex_GPIOA, Mask_Ex_0b1011) \
    (Set_BitsTo1_WithMask_SubDef((Ex_GPIOA->Px), Mask_Ex_0b1011))

void DigitalIo_Write_Pins_High(
    GPIO_TypeDef *Ex_GPIOA,
    GpioRegType Mask_Ex_0b1011);
//=========================================================================================
#define DigitalIo_DirectWrite_Pins_Low_WithMask_Defsub(Ex_GPIOA, Mask_Ex_0b1011) \
    (Set_BitsTo0_WithMask_SubDef((Ex_GPIOA->Px), Mask_Ex_0b1011))

void DigitalIo_Write_Pins_Low(
    GPIO_TypeDef *Ex_GPIOA,
    GpioRegType Mask_Ex_0b1011);
//=========================================================================================
#define DigitalIo_DirectWrite_Pins_WithMask_Defsub(Ex_GPIOA, Mask_High_Ex_0b1011, Mask_Low_Ex_0b1011) \
    (Set_Bits_WithMask_SubDef((Ex_GPIOA->Px), Mask_High_Ex_0b1011, Mask_Low_Ex_0b1011))

void DigitalIo_Write_Pins(
    GPIO_TypeDef *Ex_GPIOA,
    GpioRegType Mask_High_Ex_0b1011,
    GpioRegType Mask_Low_Ex_0b1011);
//=========================================================================================
#define DigitalIo_DirectWrite_Pins_Toggle_WithMask_Defsub(Ex_GPIOA, Mask_Ex_0b1011) \
    (Toggle_Bits_WithMask_SubDef((Ex_GPIOA->Px), Mask_Ex_0b1011))

void DigitalIo_Write_Pins_Toggle(
    GPIO_TypeDef *Ex_GPIOA,
    GpioRegType Mask_Ex_0b1011);
//=========================================================================================
/**
 * @brief This function works correct only in output mode
*/
GpioRegType DigitalIo_GetWriteState_AllPins(GPIO_TypeDef *Ex_GPIOA);
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Gpio Read
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%     
#define DigitalIo_DirectRead_AllPins_Defsubf(Ex_GPIOA) \
    (Ex_GPIOA->Px)

GpioRegType DigitalIo_Read_AllPins(GPIO_TypeDef *Ex_GPIOA);
//=========================================================================================
#define DigitalIo_DirectRead_1Pin_Defsubf(Ex_GPIOA, PinNumber_0tox) \
    (Get_1Bit_Return_0or1_SubfDef((Ex_GPIOA->Px), PinNumber_0tox))

bool DigitalIo_Read_1Pin(GPIO_TypeDef *Ex_GPIOA,uint8 PinNumber_0tox);
//=========================================================================================
#define DigitalIo_DirectRead_PinsIs1_WithMask_Defsubf(Ex_GPIOA, Mask_Ex_0b1000) \
    (Get_BitsIs1_WithMask_Return_0or1_SubfDef((Ex_GPIOA->Px), Mask_Ex_0b1000))

bool DigitalIo_Read_PinsIs1(GPIO_TypeDef *Ex_GPIOA, GpioRegType Mask_Ex_0b1000);
//=========================================================================================
#define DigitalIo_DirectRead_PinsIs0_WithMask_Defsubf(Ex_GPIOA, Mask_Ex_0b1000) \
    (Get_BitsIs0_WithMask_Return_0or1_SubfDef((Ex_GPIOA->Px), Mask_Ex_0b1000))

bool DigitalIo_Read_PinsIs0(GPIO_TypeDef *Ex_GPIOA, GpioRegType Mask_Ex_0b1000);
//=========================================================================================
#define DigitalIo_DirectRead_PinsIs0And1_WithMask_Defsubf(Ex_GPIOA, Mask_High_Ex_0b1000, Mask_Low_Ex_0b1000) \
    (Get_BitsIs0And1_WithMask_Return_0or1_SubfDef((Ex_GPIOA->Px), Mask_High_Ex_0b1000, Mask_Low_Ex_0b1000))

bool DigitalIo_Read_PinsIs0And1(GPIO_TypeDef *Ex_GPIOA, GpioRegType Mask_High_Ex_0b1000, GpioRegType Mask_Low_Ex_0b1000);
//=========================================================================================
bool DigitalIo_ReadUntilDetectValue_AllPins_Return_1Detect_0TimeOut(GPIO_TypeDef *Ex_GPIOA, GpioRegType CheckValue, uint32 TryCount);
//=========================================================================================
bool DigitalIo_ReadUntilChangeValue_AllPins_Return_1Detect_0TimeOut(GPIO_TypeDef *Ex_GPIOA, GpioRegType CheckValue, uint32 TryCount);
//=========================================================================================
bool DigitalIo_ReadUntilDetectValue_1Pins_Return_1Detect_0TimeOut(GPIO_TypeDef *Ex_GPIOA, GpioRegType Mask_Ex_0b1000, bool CheckValue_0or1, uint32 TryCount);

#endif
#endif
