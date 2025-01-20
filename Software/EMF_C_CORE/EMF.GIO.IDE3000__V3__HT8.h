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
*                                         Fixed{GIO_DirectWrite_Pins_Low_WithMask_Defsub}
*                                         Add{Example code}
* v5.1.1_14031024          E.Rahmanian    Optimize
* v5.2_14031101            E.rahmanian    Bug Fixed!
******************************************************************************************
*/
#if defined(IDE3000__V3__HT8)
#ifndef EMF_GIO_IDE3000__V3__HT8_H
#define EMF_GIO_IDE3000__V3__HT8_H
/**
* @code
#include "HT66F0021.h"
#include "EMF.h"

void main(){
_rw bool a;
_rw uint8 b;

EMF_init();

a = EMF_SetCoreClockTo_HIRC_DIV64_125KHZ_Return_1Ok_0Failed();       // Min Speed in HIRC
a = EMF_SetCoreClockTo_HIRC_DIV1_8MHZ_Return_1Ok_0Failed();          // Max Speed in HSi
a = EMF_SetCoreClockTo_HIRC_DIV2_4MHZ_Return_1Ok_0Failed();          // Max CPU Speed / 2
a = EMF_SetCoreClockTo_LIRC_32KHZ_Return_1Ok_0Failed();              // LIRC

EMF_GIO_Init(GIOA, 0b1, GIO_MODE_INPUT, GIO_INPUT_PULLLUP);
a = EMF_GIO_GetConfigState_1Pin_Return_Mode_1Input0Output(GIOA, 0);
a = EMF_GIO_GetConfigState_1Pin_Return_Pull_0PullNO_1PullUp(GIOA, 0);

EMF_GIO_Write_AllPins(GIOA, 0b10);
EMF_GIO_Write_1Pin(GIOA, 0, 1);
EMF_GIO_Write_Pins_High(GIOA, 0b10);
EMF_GIO_Write_Pins_Low(GIOA, 0b1);
EMF_GIO_Write_Pins(GIOA, 0b11, 0b1100);
EMF_GIO_Write_Pins_Toggle(GIOA, 0b111);
b = EMF_GIO_GetWriteState_AllPins(GIOA);

b = EMF_GIO_Read_AllPins(GIOA);
b = EMF_GIO_Read_1Pin(GIOA, 2);
a = EMF_GIO_Read_PinsIs1(GIOA, 0b11);
a = EMF_GIO_Read_PinsIs0(GIOA, 0b11);
a = EMF_GIO_Read_PinsIs0And1(GIOA, 0b11, 0b1100);
a = EMF_GIO_ReadUntilDetectValue_AllPins_Return_1Detect_0TimeOut(GIOA, 0b101, 10000);
a = EMF_GIO_ReadUntilChangeValue_AllPins_Return_1Detect_0TimeOut(GIOA, 0b111, 10000);
a = EMF_GIO_ReadUntilDetectValue_1Pin_Return_1Detect_0TimeOut(GIOA, 0b1000, 0, 10000);
}
* @endcode
*/

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// define and typedef
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    #define McuRegType uint8
    #define McuRegBitsType uint8Bits_t
//=========================================================================================
typedef struct {
    union {
        _rw McuRegType Px;
        _rw McuRegBitsType Px_bits;
    };
    //=================================================
    union {
        _rw McuRegType PxC;
        _rw McuRegBitsType PxC_bits;
    };
    //=================================================
    union {       
        _rw McuRegType PxPU;
        _rw McuRegBitsType PxPU_bits;
    };
 } GIO_TypeDef;
//=========================================================================================
#ifdef _pa
    #define GIOA ((GIO_TypeDef *)&_pa)
#endif

#ifdef _pb
    #define GIOB ((GIO_TypeDef *)&_pb)
#endif

#ifdef _pc
    #define GIOC ((GIO_TypeDef *)&_pc)
#endif

#ifdef _pd
    #define GIOD ((GIO_TypeDef *)&_pd)
#endif

#ifdef _pe
    #define GIOE ((GIO_TypeDef *)&_pe)
#endif

#ifdef _pf
    #define GIOF ((GIO_TypeDef *)&_pf)
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
void EMF_GIO_Init(GIO_TypeDef *GIOx__Ex_GIOA,
              McuRegType GIO_PINS_Mask__Ex_0b1101,
              bool GIO_MODE__Ex_GIO_MODE_OUTPUT_PUSHPULL,
              bool GIO_INPUT_PULL__Ex_GIO_PULLNO);
//=========================================================================================
bool EMF_GIO_GetConfigState_1Pin_Return_Mode_1Input0Output(GIO_TypeDef *Ex_GIOA, uint8 PinNumber_0tox);
//=========================================================================================
bool EMF_GIO_GetConfigState_1Pin_Return_Pull_0PullNO_1PullUp(GIO_TypeDef *Ex_GIOA, uint8 PinNumber_0tox);
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Gio Write
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
#define EMF_GIO_DirectWrite_AllPins_Defsub(Ex_GIOA, Value) (Ex_GIOA->Px = Value)

void EMF_GIO_Write_AllPins(GIO_TypeDef *Ex_GIOA, McuRegType Value);
//=========================================================================================
#define EMF_GIO_DirectWrite_1Pin_Defsub(Ex_GIOA, PinNumber_0tox, Value_0or1) \
        (Set_1Bit_SubDef((Ex_GIOA->Px), PinNumber_0tox, Value_0or1))

void EMF_GIO_Write_1Pin(GIO_TypeDef *Ex_GIOA, uint8 PinNumber_0tox, bool Value_0or1);
//=========================================================================================
#define EMF_GIO_DirectWrite_Pins_High_WithMask_Defsub(Ex_GIOA, Mask_Ex_0b1011) \
        (Set_BitsTo1_WithMask_SubDef((Ex_GIOA->Px), Mask_Ex_0b1011))

void EMF_GIO_Write_Pins_High(GIO_TypeDef *Ex_GIOA, McuRegType Mask_Ex_0b1011);
//=========================================================================================
#define EMF_GIO_DirectWrite_Pins_Low_WithMask_Defsub(Ex_GIOA, Mask_Ex_0b1011) \
        (Set_BitsTo0_WithMask_SubDef((Ex_GIOA->Px), Mask_Ex_0b1011))

void EMF_GIO_Write_Pins_Low(GIO_TypeDef *Ex_GIOA, McuRegType Mask_Ex_0b1011);
//=========================================================================================
#define EMF_GIO_DirectWrite_Pins_WithMask_Defsub(Ex_GIOA, Mask_High_Ex_0b1011, Mask_Low_Ex_0b1011) \
        EMF_GIO_DirectWrite_Pins_High_WithMask_Defsub(Ex_GIOA, Mask_High_Ex_0b1011);                   \
        EMF_GIO_DirectWrite_Pins_Low_WithMask_Defsub(Ex_GIOA, Mask_Low_Ex_0b1011)

void EMF_GIO_Write_Pins(GIO_TypeDef *Ex_GIOA, McuRegType Mask_High_Ex_0b1011, McuRegType Mask_Low_Ex_0b1011);
//=========================================================================================
#define EMF_GIO_DirectWrite_Pins_Toggle_WithMask_Defsub(Ex_GIOA, Mask_Ex_0b1011) \
        (Toggle_Bits_WithMask_SubDef((Ex_GIOA->Px), Mask_Ex_0b1011))

void EMF_GIO_Write_Pins_Toggle(GIO_TypeDef *Ex_GIOA, McuRegType Mask_Ex_0b1011);
//=========================================================================================
#define EMF_GIO_DirectGetWriteState_AllPins(Ex_GIOA) (Ex_GIOA->Px)

/**
 * @brief This function works correct only in output mode
 */
McuRegType EMF_GIO_GetWriteState_AllPins(GIO_TypeDef *Ex_GIOA);
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Gio Read
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
#define EMF_GIO_DirectRead_AllPins_Defsubf(Ex_GIOA) (Ex_GIOA->Px)
McuRegType EMF_GIO_Read_AllPins(GIO_TypeDef *Ex_GIOA);
//=========================================================================================
#define EMF_GIO_DirectRead_1Pin_Defsubf(Ex_GIOA, PinNumber_0tox) \
        (Get_1Bit_Return_0or1_SubfDef((Ex_GIOA->Px), PinNumber_0tox))

bool EMF_GIO_Read_1Pin(GIO_TypeDef *Ex_GIOA, uint8 PinNumber_0tox);
//=========================================================================================
#define EMF_GIO_DirectRead_PinsIs1_WithMask_Defsubf(Ex_GIOA, Mask_Ex_0b1000) \
        (Get_BitsIs1_WithMask_Return_0or1_SubfDef((Ex_GIOA->Px), Mask_Ex_0b1000))

bool EMF_GIO_Read_PinsIs1(GIO_TypeDef *Ex_GIOA, McuRegType Mask_Ex_0b1000);
//=========================================================================================
#define EMF_GIO_DirectRead_PinsIs0_WithMask_Defsubf(Ex_GIOA, Mask_Ex_0b1000) \
        (Get_BitsIs0_WithMask_Return_0or1_SubfDef((Ex_GIOA->Px), Mask_Ex_0b1000))

bool EMF_GIO_Read_PinsIs0(GIO_TypeDef *Ex_GIOA, McuRegType Mask_Ex_0b1000);
//=========================================================================================
#define EMF_GIO_DirectRead_PinsIs0And1_WithMask_Defsubf(Ex_GIOA, Mask_High_Ex_0b1000, Mask_Low_Ex_0b1000) \
       (Get_BitsIs0And1_WithMask_Return_0or1_SubfDef((Ex_GIOA->Px), Mask_High_Ex_0b1000, Mask_Low_Ex_0b1000))

bool EMF_GIO_Read_PinsIs0And1(GIO_TypeDef *Ex_GIOA, McuRegType Mask_High_Ex_0b1000, McuRegType Mask_Low_Ex_0b1000);
//=========================================================================================
bool EMF_GIO_ReadUntilDetectValue_AllPins_Return_1Detect_0TimeOut(GIO_TypeDef *Ex_GIOA, McuRegType CheckValue, uint32 TryCount);
//=========================================================================================
bool EMF_GIO_ReadUntilChangeValue_AllPins_Return_1Detect_0TimeOut(GIO_TypeDef *Ex_GIOA, McuRegType CheckValue, uint32 TryCount);
//=========================================================================================
bool EMF_GIO_ReadUntilDetectValue_1Pin_Return_1Detect_0TimeOut(GIO_TypeDef *Ex_GIOA, McuRegType Mask_Ex_0b1000, bool CheckValue_0or1, uint32 TryCount);


#endif
#endif
