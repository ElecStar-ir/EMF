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

#if defined(EMF_GPIO_HT8_H)
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Gpio Configs
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
void DigitalIo_Config_Pins(
    GPIO_TypeDef *Ex_GPIOA,
    GpioRegType OutputConfigPinsMask__0NotChangeConfig_1ConfigOutput__Ex_0b1011,
    GpioRegType InputConfigPinsMask__0NotChangeConfig_1ConfigInputt__Ex_0b1011,
    GpioRegType PullUpOnPinsMask__0NotChangePull_1OnPullup__Ex_0b1011,
    GpioRegType NoPullPinsMask__0NotChangePull_1OnPullup__Ex_0b1011) {
    Set_Bits_WithMask_SubDef(Ex_GPIOA->PxC, InputConfigPinsMask__0NotChangeConfig_1ConfigInputt__Ex_0b1011, OutputConfigPinsMask__0NotChangeConfig_1ConfigOutput__Ex_0b1011);  // in Holtek-8bit 0 is output and 1 is input
    Set_Bits_WithMask_SubDef(Ex_GPIOA->PxPU, PullUpOnPinsMask__0NotChangePull_1OnPullup__Ex_0b1011, NoPullPinsMask__0NotChangePull_1OnPullup__Ex_0b1011);
}
//=========================================================================================
uint8 DigitalIo_GetConfigState_1Pin_Return_0Input1Output(
    GPIO_TypeDef *Ex_GPIOA,
    uint8 PinNumber_0tox){

    return !(Get_1Bit_Return_0or1_SubfDef(Ex_GPIOA->PxC, PinNumber_0tox));    
}
//==========================================================================================
uint8 DigitalIo_GetConfigState_1Pin_Return_0NoPull_1Pullup(
    GPIO_TypeDef *Ex_GPIOA,
    uint8 PinNumber_0tox){

    return Get_1Bit_Return_0or1_SubfDef(Ex_GPIOA->PxPU, PinNumber_0tox);    
}
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Gpio Write
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
void DigitalIo_Write_AllPins(
    GPIO_TypeDef *Ex_GPIOA,
    GpioRegType Value) {
    DigitalIo_DirectWrite_AllPins_Defsub(Ex_GPIOA, Value);
}
//=========================================================================================
void DigitalIo_Write_1Pin(
    GPIO_TypeDef *Ex_GPIOA,
    uint8 PinNumber_0tox,
    bool Value_0or1) {
    DigitalIo_DirectWrite_1Pin_Defsub(Ex_GPIOA, PinNumber_0tox, Value_0or1);
}
//=========================================================================================
void DigitalIo_Write_Pins_High(
    GPIO_TypeDef *Ex_GPIOA,
    GpioRegType Mask_Ex_0b1011) {
    DigitalIo_DirectWrite_Pins_High_WithMask_Defsub(Ex_GPIOA, Mask_Ex_0b1011);
}
//=========================================================================================
void DigitalIo_Write_Pins_Low(
    GPIO_TypeDef *Ex_GPIOA,
    GpioRegType Mask_Ex_0b1011) {
    DigitalIo_DirectWrite_Pins_Low_WithMask_Defsub(Ex_GPIOA, Mask_Ex_0b1011);
}
//=========================================================================================
void DigitalIo_Write_Pins(
    GPIO_TypeDef *Ex_GPIOA,
    GpioRegType Mask_High_Ex_0b1011,
    GpioRegType Mask_Low_Ex_0b1011) {
    DigitalIo_DirectWrite_Pins_WithMask_Defsub(Ex_GPIOA, Mask_High_Ex_0b1011, Mask_Low_Ex_0b1011);
}
//=========================================================================================
void DigitalIo_Write_Pins_Toggle(
    GPIO_TypeDef *Ex_GPIOA,
    GpioRegType Mask_Ex_0b1011) {
    DigitalIo_DirectWrite_Pins_Toggle_WithMask_Defsub(Ex_GPIOA, Mask_Ex_0b1011);
}
//=========================================================================================
/**
 * @brief This function works correct only in output mode
*/
GpioRegType DigitalIo_GetWriteState_AllPins(GPIO_TypeDef *Ex_GPIOA){
    return Ex_GPIOA->Px;
}
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Gpio Read
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
GpioRegType DigitalIo_Read_AllPins(GPIO_TypeDef *Ex_GPIOA) {
    return DigitalIo_DirectRead_AllPins_Defsubf(Ex_GPIOA);
}
//=========================================================================================
bool DigitalIo_Read_1Pin(GPIO_TypeDef *Ex_GPIOA, uint8 PinNumber_0tox) {
    return DigitalIo_DirectRead_1Pin_Defsubf(Ex_GPIOA, PinNumber_0tox);
}
//=========================================================================================
bool DigitalIo_Read_PinsIs1(GPIO_TypeDef *Ex_GPIOA, GpioRegType Mask_Ex_0b1000){
    return DigitalIo_DirectRead_PinsIs1_WithMask_Defsubf(Ex_GPIOA, Mask_Ex_0b1000);
}
//=========================================================================================
bool DigitalIo_Read_PinsIs0(GPIO_TypeDef *Ex_GPIOA, GpioRegType Mask_Ex_0b1000){
    return  DigitalIo_DirectRead_PinsIs0_WithMask_Defsubf(Ex_GPIOA, Mask_Ex_0b1000);
}
//=========================================================================================
bool DigitalIo_Read_PinsIs0And1(GPIO_TypeDef *Ex_GPIOA, GpioRegType Mask_High_Ex_0b1000, GpioRegType Mask_Low_Ex_0b1000){
    return DigitalIo_DirectRead_PinsIs0And1_WithMask_Defsubf(Ex_GPIOA, Mask_High_Ex_0b1000, Mask_Low_Ex_0b1000);
}
//=========================================================================================
bool DigitalIo_ReadUntilDetectValue_AllPins_Return_1Detect_0TimeOut(GPIO_TypeDef *Ex_GPIOA, GpioRegType CheckValue, uint32 TryCount){
    while((TryCount--) && (DigitalIo_DirectRead_AllPins_Defsubf(Ex_GPIOA) != CheckValue));
    return TryCount && 1;    
}
//=========================================================================================
bool DigitalIo_ReadUntilChangeValue_AllPins_Return_1Detect_0TimeOut(GPIO_TypeDef *Ex_GPIOA, GpioRegType CheckValue, uint32 TryCount){

    while((TryCount--) && (DigitalIo_DirectRead_AllPins_Defsubf(Ex_GPIOA) == CheckValue));
    return TryCount && 1;    
}
//=========================================================================================
bool DigitalIo_ReadUntilDetectValue_1Pins_Return_1Detect_0TimeOut(GPIO_TypeDef *Ex_GPIOA, GpioRegType Mask_Ex_0b1000, bool CheckValue_0or1, uint32 TryCount){
    while((TryCount--) && (DigitalIo_Read_PinsIs1(Ex_GPIOA, Mask_Ex_0b1000) != CheckValue_0or1));
    return TryCount && 1;    
}

#endif
