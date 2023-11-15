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
#ifndef EMF_GIO_IDE3000__V3__HT8__HT66F0021_31_41_H
#define EMF_GIO_IDE3000__V3__HT8__HT66F0021_31_41_H
#if defined(IDE3000__V3__HT8__HT66F0021_31_41)
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

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// define and typedef
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    #define McuRegType uint8
    #define McuRegBitsType uint8Bits_t
    #define __AddGIOReg(RegName) \
        _rw McuRegType RegName;  \
        _rw McuRegBitsType RegName##_bits;

//=========================================================================================
typedef struct {
    union {
        __AddGIOReg(Px) /*!< GPIO port Read Or Write,                     Address offset: 1      */
    };
    //=================================================
    union {
        __AddGIOReg(PxC) /*!< GPIO port mode register,              Address offset: 2      */
    };
    //=================================================
    union {
        __AddGIOReg(PxPU) /*!< GPIO port Input Pullup register,             Address offset: 3      */
    };
 } GIO_TypeDef;
//=========================================================================================
#ifdef _pa
    #define GIOA ((GIO_TypeDef *)_pa)
#endif

#ifdef _pb
    #define GIOB ((GIO_TypeDef *)_pb)
#endif

#ifdef _pc
    #define GIOC ((GIO_TypeDef *)_pc)
#endif

#ifdef _pd
    #define GIOD ((GIO_TypeDef *)_pd)
#endif

#ifdef _pe
    #define GIOE ((GIO_TypeDef *)_pe)
#endif

#ifdef _pf
    #define GIOF ((GIO_TypeDef *)_pf)
#endif

//=========================================================================================
#define GIO_PIN_0 ((McuRegType)0x0001U)   /* Pin 0 selected    */
#define GIO_PIN_1 ((McuRegType)0x0002U)   /* Pin 1 selected    */
#define GIO_PIN_2 ((McuRegType)0x0004U)   /* Pin 2 selected    */
#define GIO_PIN_3 ((McuRegType)0x0008U)   /* Pin 3 selected    */
#define GIO_PIN_4 ((McuRegType)0x0010U)   /* Pin 4 selected    */
#define GIO_PIN_5 ((McuRegType)0x0020U)   /* Pin 5 selected    */
#define GIO_PIN_6 ((McuRegType)0x0040U)   /* Pin 6 selected    */
#define GIO_PIN_7 ((McuRegType)0x0080U)   /* Pin 7 selected    */
#define GIO_PIN_All ((McuRegType)~0x0U) /* All pins selected */

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Gio Configs
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
/** 
 * @brief GIO Configuration Mode
 * Elements values convention: 0b0000000A
 * - A  : GIO mode (MODE_INPUT or MODE_OUTPUT_PUSHPULL) on 1 bit 
 */
#define GIO_MODE_INPUT true             /*!< Input Floating Mode                   */
#define GIO_MODE_OUTPUT_PUSHPULL false   /*!< Output Push Pull Mode                 */                                                                                                                     /*!< range 10 MHz to 50 MHz, please refer to the product datasheet */
//=========================================================================================
#define GIO_INPUT_PULLNO false    /*!< No Pull-up or Pull-down activation  */
#define GIO_INPUT_PULLLUP true   /*!< Pull-up activation                  */
//=========================================================================================
void GIO_Init(GIO_TypeDef *GIOx__Ex_GIOA,
              McuRegType GIO_PINS_Mask__Ex_0b1101,
              bool GIO_MODE__Ex_GIO_MODE_OUTPUT_PUSHPULL,
              bool GIO_INPUT_PULL__Ex_GIO_PULLNO);
//=========================================================================================
bool GIO_GetConfigState_1Pin_Return_Mode_1Input0Output(GIO_TypeDef *Ex_GIOA, uint8 PinNumber_0tox);
//=========================================================================================
bool GIO_GetConfigState_1Pin_Return_Pull_0PullNO_1PullUp(GIO_TypeDef *Ex_GIOA, uint8 PinNumber_0tox);
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Gio Write
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
#define GIO_DirectWrite_AllPins_Defsub(Ex_GIOA, Value) (Ex_GIOA->Px = Value)

void GIO_Write_AllPins(GIO_TypeDef *Ex_GIOA, McuRegType Value);
//=========================================================================================
#define GIO_DirectWrite_1Pin_Defsub(Ex_GIOA, PinNumber_0tox, Value_0or1) \
        (Set_1Bit_SubDef((Ex_GIOA->Px), PinNumber_0tox, Value_0or1))

void GIO_Write_1Pin(GIO_TypeDef *Ex_GIOA, uint8 PinNumber_0tox, bool Value_0or1);
//=========================================================================================
#define GIO_DirectWrite_Pins_High_WithMask_Defsub(Ex_GIOA, Mask_Ex_0b1011) \
        (Set_BitsTo1_WithMask_SubDef((Ex_GIOA->Px), Mask_Ex_0b1011))

void GIO_Write_Pins_High(GIO_TypeDef *Ex_GIOA, McuRegType Mask_Ex_0b1011);
//=========================================================================================
#define GIO_DirectWrite_Pins_Low_WithMask_Defsub(Ex_GIOA, Mask_Ex_0b1011) \
        (Set_BitsTo1_WithMask_SubDef((Ex_GIOA->Px), Mask_Ex_0b1011))

void GIO_Write_Pins_Low(GIO_TypeDef *Ex_GIOA, McuRegType Mask_Ex_0b1011);
//=========================================================================================
#define GIO_DirectWrite_Pins_WithMask_Defsub(Ex_GIOA, Mask_High_Ex_0b1011, Mask_Low_Ex_0b1011) \
        GIO_DirectWrite_Pins_High_WithMask_Defsub(Ex_GIOA, Mask_High_Ex_0b1011);                   \
        GIO_DirectWrite_Pins_Low_WithMask_Defsub(Ex_GIOA, Mask_Low_Ex_0b1011)

void GIO_Write_Pins(GIO_TypeDef *Ex_GIOA, McuRegType Mask_High_Ex_0b1011, McuRegType Mask_Low_Ex_0b1011);
//=========================================================================================
#define GIO_DirectWrite_Pins_Toggle_WithMask_Defsub(Ex_GIOA, Mask_Ex_0b1011) \
        (Toggle_Bits_WithMask_SubDef((Ex_GIOA->Px), Mask_Ex_0b1011))

void GIO_Write_Pins_Toggle(GIO_TypeDef *Ex_GIOA, McuRegType Mask_Ex_0b1011);
//=========================================================================================
#define GIO_DirectGetWriteState_AllPins(Ex_GIOA) (Ex_GIOA->Px)

/**
 * @brief This function works correct only in output mode
 */
McuRegType GIO_GetWriteState_AllPins(GIO_TypeDef *Ex_GIOA);
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Gio Read
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
#define GIO_DirectRead_AllPins_Defsubf(Ex_GIOA) (Ex_GIOA->Px)
McuRegType GIO_Read_AllPins(GIO_TypeDef *Ex_GIOA);
//=========================================================================================
#define GIO_DirectRead_1Pin_Defsubf(Ex_GIOA, PinNumber_0tox) \
        (Get_1Bit_Return_0or1_SubfDef((Ex_GIOA->Px), PinNumber_0tox))

bool GIO_Read_1Pin(GIO_TypeDef *Ex_GIOA, uint8 PinNumber_0tox);
//=========================================================================================
#define GIO_DirectRead_PinsIs1_WithMask_Defsubf(Ex_GIOA, Mask_Ex_0b1000) \
        (Get_BitsIs1_WithMask_Return_0or1_SubfDef((Ex_GIOA->Px), Mask_Ex_0b1000))

bool GIO_Read_PinsIs1(GIO_TypeDef *Ex_GIOA, McuRegType Mask_Ex_0b1000);
//=========================================================================================
#define GIO_DirectRead_PinsIs0_WithMask_Defsubf(Ex_GIOA, Mask_Ex_0b1000) \
        (Get_BitsIs0_WithMask_Return_0or1_SubfDef((Ex_GIOA->Px), Mask_Ex_0b1000))

bool GIO_Read_PinsIs0(GIO_TypeDef *Ex_GIOA, McuRegType Mask_Ex_0b1000);
//=========================================================================================
#define GIO_DirectRead_PinsIs0And1_WithMask_Defsubf(Ex_GIOA, Mask_High_Ex_0b1000, Mask_Low_Ex_0b1000) \
       (Get_BitsIs0And1_WithMask_Return_0or1_SubfDef((Ex_GIOA->Px), Mask_High_Ex_0b1000, Mask_Low_Ex_0b1000))

bool GIO_Read_PinsIs0And1(GIO_TypeDef *Ex_GIOA, McuRegType Mask_High_Ex_0b1000, McuRegType Mask_Low_Ex_0b1000);
//=========================================================================================
bool GIO_ReadUntilDetectValue_AllPins_Return_1Detect_0TimeOut(GIO_TypeDef *Ex_GIOA, McuRegType CheckValue, uint32 TryCount);
//=========================================================================================
bool GIO_ReadUntilChangeValue_AllPins_Return_1Detect_0TimeOut(GIO_TypeDef *Ex_GIOA, McuRegType CheckValue, uint32 TryCount);
//=========================================================================================
bool GIO_ReadUntilDetectValue_1Pins_Return_1Detect_0TimeOut(GIO_TypeDef *Ex_GIOA, McuRegType Mask_Ex_0b1000, bool CheckValue_0or1, uint32 TryCount);


#endif
#endif
