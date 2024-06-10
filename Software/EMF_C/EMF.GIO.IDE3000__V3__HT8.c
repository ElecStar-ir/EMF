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
* v4.2.1_14020829          E.Rahmanian    Optimize{Change Name:GIO_ReadUntilDetectValue_1Pins_Return_1Detect_0TimeOut to GIO_ReadUntilDetectValue_1Pin_Return_1Detect_0TimeOut}
*                                         Fixed{GIO_DirectWrite_Pins_Low_WithMask}
******************************************************************************************
*/
#include "EMF.h"
#if defined(EMF_GIO_IDE3000__V3__HT8_H)

//=========================================================================================
//=========================================================================================
void GIO_Init(GIO_TypeDef *GIOx__Ex_GIOA,
              McuRegType GIO_PINS_Mask__Ex_0b1101,
              bool GIO_MODE__Ex_GIO_MODE_OUTPUT_PUSHPULL,
              bool GIO_INPUT_PULL__Ex_GIO_INPUT_PULLNO){

    if(GIO_MODE__Ex_GIO_MODE_OUTPUT_PUSHPULL == GIO_MODE_INPUT){
        Set_BitsTo1_WithMask_SubDef(GIOx__Ex_GIOA->PxC, GIO_PINS_Mask__Ex_0b1101);
    }else if(GIO_MODE__Ex_GIO_MODE_OUTPUT_PUSHPULL == GIO_MODE_OUTPUT_PUSHPULL){
        Set_BitsTo0_WithMask_SubDef(GIOx__Ex_GIOA->PxC, GIO_PINS_Mask__Ex_0b1101);
    }

    if(GIO_INPUT_PULL__Ex_GIO_INPUT_PULLNO == GIO_INPUT_PULLLUP){
        Set_BitsTo1_WithMask_SubDef(GIOx__Ex_GIOA->PxPU, GIO_PINS_Mask__Ex_0b1101);
    }else if(GIO_INPUT_PULL__Ex_GIO_INPUT_PULLNO == GIO_INPUT_PULLNO){
        Set_BitsTo0_WithMask_SubDef(GIOx__Ex_GIOA->PxPU, GIO_PINS_Mask__Ex_0b1101);
    }
}
//=========================================================================================
//=========================================================================================
bool GIO_GetConfigState_1Pin_Return_Mode_1Input0Output(GIO_TypeDef *Ex_GIOA, uint8 PinNumber_0tox) {
    return Get_1Bit_Return_0or1_SubfDef(Ex_GIOA->PxC, PinNumber_0tox);
}
//=========================================================================================
//=========================================================================================
bool GIO_GetConfigState_1Pin_Return_Pull_0PullNO_1PullUp(GIO_TypeDef *Ex_GIOA, uint8 PinNumber_0tox) {
    return Get_1Bit_Return_0or1_SubfDef(Ex_GIOA->PxPU, PinNumber_0tox);
}
//=========================================================================================
//=========================================================================================
void GIO_Write_AllPins(GIO_TypeDef *Ex_GIOA, McuRegType Value) {
    GIO_DirectWrite_AllPins_Defsub(Ex_GIOA, Value);
}
//=========================================================================================
//=========================================================================================
void GIO_Write_1Pin(GIO_TypeDef *Ex_GIOA, uint8 PinNumber_0tox, bool Value_0or1) {
    GIO_DirectWrite_1Pin_Defsub(Ex_GIOA, PinNumber_0tox, Value_0or1);
}
//=========================================================================================
//=========================================================================================
void GIO_Write_Pins_High(GIO_TypeDef *Ex_GIOA, McuRegType Mask_Ex_0b1011) {
    GIO_DirectWrite_Pins_High_WithMask_Defsub(Ex_GIOA, Mask_Ex_0b1011);
}
//=========================================================================================
//=========================================================================================
void GIO_Write_Pins_Low(GIO_TypeDef *Ex_GIOA, McuRegType Mask_Ex_0b1011) {
    GIO_DirectWrite_Pins_Low_WithMask_Defsub(Ex_GIOA, Mask_Ex_0b1011);
}
//=========================================================================================
//=========================================================================================
void GIO_Write_Pins(GIO_TypeDef *Ex_GIOA, McuRegType Mask_High_Ex_0b1011, McuRegType Mask_Low_Ex_0b1011) {
    GIO_DirectWrite_Pins_WithMask_Defsub(Ex_GIOA, Mask_High_Ex_0b1011, Mask_Low_Ex_0b1011);
}
//=========================================================================================
//=========================================================================================
void GIO_Write_Pins_Toggle(GIO_TypeDef *Ex_GIOA, McuRegType Mask_Ex_0b1011) {
    GIO_DirectWrite_Pins_Toggle_WithMask_Defsub(Ex_GIOA, Mask_Ex_0b1011);
}
//=========================================================================================
//=========================================================================================
McuRegType GIO_GetWriteState_AllPins(GIO_TypeDef *Ex_GIOA) {
    return GIO_DirectGetWriteState_AllPins(Ex_GIOA);
}
//=========================================================================================
//=========================================================================================
McuRegType GIO_Read_AllPins(GIO_TypeDef *Ex_GIOA) {
    return GIO_DirectRead_AllPins_Defsubf(Ex_GIOA);
}
//=========================================================================================
//=========================================================================================
bool GIO_Read_1Pin(GIO_TypeDef *Ex_GIOA, uint8 PinNumber_0tox) {
    return GIO_DirectRead_1Pin_Defsubf(Ex_GIOA, PinNumber_0tox);
}
//=========================================================================================
//=========================================================================================
bool GIO_Read_PinsIs1(GIO_TypeDef *Ex_GIOA, McuRegType Mask_Ex_0b1000) {
    return GIO_DirectRead_PinsIs1_WithMask_Defsubf(Ex_GIOA, Mask_Ex_0b1000);
}
//=========================================================================================
//=========================================================================================
bool GIO_Read_PinsIs0(GIO_TypeDef *Ex_GIOA, McuRegType Mask_Ex_0b1000) {
    return GIO_DirectRead_PinsIs0_WithMask_Defsubf(Ex_GIOA, Mask_Ex_0b1000);
}
//=========================================================================================
//=========================================================================================
bool GIO_Read_PinsIs0And1(GIO_TypeDef *Ex_GIOA, McuRegType Mask_High_Ex_0b1000, McuRegType Mask_Low_Ex_0b1000) {
    return GIO_DirectRead_PinsIs0And1_WithMask_Defsubf(Ex_GIOA, Mask_High_Ex_0b1000, Mask_Low_Ex_0b1000);
}
//=========================================================================================
//=========================================================================================
bool GIO_ReadUntilDetectValue_AllPins_Return_1Detect_0TimeOut(GIO_TypeDef *Ex_GIOA, McuRegType CheckValue, uint32 TryCount) {
    while ((TryCount) && (GIO_DirectRead_AllPins_Defsubf(Ex_GIOA) != CheckValue)){
        TryCount--;
    };
    return TryCount && 1;
}
//=========================================================================================
//=========================================================================================
bool GIO_ReadUntilChangeValue_AllPins_Return_1Detect_0TimeOut(GIO_TypeDef *Ex_GIOA, McuRegType CheckValue, uint32 TryCount) {
    while ((TryCount) && (GIO_DirectRead_AllPins_Defsubf(Ex_GIOA) == CheckValue)){
        TryCount--;
    };
    return TryCount && 1;
}
//=========================================================================================
//=========================================================================================
bool GIO_ReadUntilDetectValue_1Pin_Return_1Detect_0TimeOut(GIO_TypeDef *Ex_GIOA, McuRegType Mask_Ex_0b1000, bool CheckValue_0or1, uint32 TryCount) {
    while ((TryCount) && (GIO_DirectRead_PinsIs1_WithMask_Defsubf(Ex_GIOA, Mask_Ex_0b1000) != CheckValue_0or1)){
        TryCount--;
    };
    return TryCount && 1;
}

#endif
