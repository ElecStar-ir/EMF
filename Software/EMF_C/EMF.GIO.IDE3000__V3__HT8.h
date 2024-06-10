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
******************************************************************************************
*/
#ifndef EMF_GIO_IDE3000__V3__HT8_H
#define EMF_GIO_IDE3000__V3__HT8_H
#if defined(IDE3000__V3__HT8__HT66F002_0025_003_004) || \
    defined(IDE3000__V3__HT8__HT66F0021_31_41)
/**
* @code
#include "EMF.h"
#include "HT66F004.h"

void main() {
    _rw uint8 a, b, c, d;
    EMF_init();

    a = SetCoreClockTo_HIRC_DIV2_4MHZ_Return_1Ok_0Failed();
    b = SetCoreClockTo_HIRC_DIV64_125KHZ_Return_1Ok_0Failed();
    c = SetCoreClockTo_LIRC_32KHZ_Return_1Ok_0Failed();
    d = SetCoreClockTo_HIRC_DIV1_8MHZ_Return_1Ok_0Failed();
    SoftWareUART_Transmit_Byte(a);
    SoftWareUART_Transmit_Byte(b);
    SoftWareUART_Transmit_Byte(c);
    SoftWareUART_Transmit_Byte(d);
    SoftWareUART_Transmit_Byte('\n');

    GIO_Init(GIOB, 0b1111, GIO_MODE_OUTPUT_PUSHPULL, GIO_INPUT_PULLLUP);
    SoftWareUART_Transmit_Byte(GIOB->PxC);
    SoftWareUART_Transmit_Byte(GIOB->PxPU);
    SoftWareUART_Transmit_Byte('\n');

    GIO_GetConfigState_1Pin_Return_Mode_1Input0Output(GIOB, 0);
    SoftWareUART_Transmit_Byte(GIO_GetConfigState_1Pin_Return_Mode_1Input0Output(GIOB, 7));
    SoftWareUART_Transmit_Byte(GIO_GetConfigState_1Pin_Return_Mode_1Input0Output(GIOB, 6));
    SoftWareUART_Transmit_Byte(GIO_GetConfigState_1Pin_Return_Mode_1Input0Output(GIOB, 5));
    SoftWareUART_Transmit_Byte(GIO_GetConfigState_1Pin_Return_Mode_1Input0Output(GIOB, 4));
    SoftWareUART_Transmit_Byte(GIO_GetConfigState_1Pin_Return_Mode_1Input0Output(GIOB, 3));
    SoftWareUART_Transmit_Byte(GIO_GetConfigState_1Pin_Return_Mode_1Input0Output(GIOB, 2));
    SoftWareUART_Transmit_Byte(GIO_GetConfigState_1Pin_Return_Mode_1Input0Output(GIOB, 1));
    SoftWareUART_Transmit_Byte(GIO_GetConfigState_1Pin_Return_Mode_1Input0Output(GIOB, 0));
    SoftWareUART_Transmit_Byte('\n');

    SoftWareUART_Transmit_Byte(GIO_GetConfigState_1Pin_Return_Pull_0PullNO_1PullUp(GIOB, 7));
    SoftWareUART_Transmit_Byte(GIO_GetConfigState_1Pin_Return_Pull_0PullNO_1PullUp(GIOB, 6));
    SoftWareUART_Transmit_Byte(GIO_GetConfigState_1Pin_Return_Pull_0PullNO_1PullUp(GIOB, 5));
    SoftWareUART_Transmit_Byte(GIO_GetConfigState_1Pin_Return_Pull_0PullNO_1PullUp(GIOB, 4));
    SoftWareUART_Transmit_Byte(GIO_GetConfigState_1Pin_Return_Pull_0PullNO_1PullUp(GIOB, 3));
    SoftWareUART_Transmit_Byte(GIO_GetConfigState_1Pin_Return_Pull_0PullNO_1PullUp(GIOB, 2));
    SoftWareUART_Transmit_Byte(GIO_GetConfigState_1Pin_Return_Pull_0PullNO_1PullUp(GIOB, 1));
    SoftWareUART_Transmit_Byte(GIO_GetConfigState_1Pin_Return_Pull_0PullNO_1PullUp(GIOB, 0));
    SoftWareUART_Transmit_Byte('\n');

    GIO_Write_AllPins(GIOB, 0b101);
    SoftWareUART_Transmit_Byte(GIOB->Px);
    SoftWareUART_Transmit_Byte('\n');

    GIO_Write_1Pin(GIOB, 1, 1);
    SoftWareUART_Transmit_Byte(GIOB->Px);
    SoftWareUART_Transmit_Byte('\n');

    GIO_Write_1Pin(GIOB, 0, 0);
    SoftWareUART_Transmit_Byte(GIOB->Px);
    SoftWareUART_Transmit_Byte('\n');

    GIOB->Px = 0;
    GIO_Write_Pins_High(GIOB, 0b1010);
    SoftWareUART_Transmit_Byte(GIOB->Px);
    SoftWareUART_Transmit_Byte('\n');

    GIOB->Px = 0b1111;
    GIO_Write_Pins_Low(GIOB, 0b1010);
    SoftWareUART_Transmit_Byte(GIOB->Px);
    SoftWareUART_Transmit_Byte('\n');

    GIOB->Px = 0b1111;
    GIO_Write_Pins(GIOB, 0b0101, 0b1010);
    SoftWareUART_Transmit_Byte(GIOB->Px);
    SoftWareUART_Transmit_Byte('\n');

    GIOB->Px = 0;
    GIO_Write_Pins(GIOB, 0b0101, 0b1010);
    SoftWareUART_Transmit_Byte(GIOB->Px);
    SoftWareUART_Transmit_Byte('\n');

    GIO_Write_Pins_Toggle(GIOB, 0b1111);
    SoftWareUART_Transmit_Byte(GIOB->Px);
    SoftWareUART_Transmit_Byte('\n');

    GIO_Write_Pins_Toggle(GIOB, 0b1111);
    SoftWareUART_Transmit_Byte(GIOB->Px);
    SoftWareUART_Transmit_Byte('\n');

    SoftWareUART_Transmit_Byte(GIO_GetWriteState_AllPins(GIOB));
    SoftWareUART_Transmit_Byte('\n');

    GIO_Init(GIOB, 0b1111, GIO_MODE_INPUT, GIO_INPUT_PULLLUP);

    a = 20;
    while(a--){
        SoftWareUART_Transmit_Byte(GIO_Read_AllPins(GIOB));
        SoftWareUART_Transmit_Byte('\n');
        delay_tick(250000);
        delay_tick(250000);
        delay_tick(250000);
    }

    a = 20;
    while(a--){
        SoftWareUART_Transmit_Byte(GIO_Read_1Pin(GIOB, 2));
        SoftWareUART_Transmit_Byte(GIO_Read_1Pin(GIOB, 1));
        SoftWareUART_Transmit_Byte(GIO_Read_1Pin(GIOB, 0));
        SoftWareUART_Transmit_Byte('\n');
        delay_tick(250000);
        delay_tick(250000);
        delay_tick(250000);
    }

    a = 20;
    while(a--){
        SoftWareUART_Transmit_Byte(GIO_Read_PinsIs1(GIOB, 0b100));
        SoftWareUART_Transmit_Byte(GIO_Read_PinsIs1(GIOB, 0b010));
        SoftWareUART_Transmit_Byte(GIO_Read_PinsIs1(GIOB, 0b001));
        SoftWareUART_Transmit_Byte('\n');
        delay_tick(250000);
        delay_tick(250000);
        delay_tick(250000);
    }

    a = 20;
    while(a--){
        SoftWareUART_Transmit_Byte(GIO_Read_PinsIs1(GIOB, 0b110));
        SoftWareUART_Transmit_Byte(GIO_Read_PinsIs1(GIOB, 0b101));
        SoftWareUART_Transmit_Byte(GIO_Read_PinsIs1(GIOB, 0b011));
        SoftWareUART_Transmit_Byte('\n');
        delay_tick(250000);
        delay_tick(250000);
        delay_tick(250000);
    }

    a = 20;
    while(a--){
        SoftWareUART_Transmit_Byte(GIO_Read_PinsIs0(GIOB, 0b100));
        SoftWareUART_Transmit_Byte(GIO_Read_PinsIs0(GIOB, 0b010));
        SoftWareUART_Transmit_Byte(GIO_Read_PinsIs0(GIOB, 0b001));
        SoftWareUART_Transmit_Byte('\n');
        delay_tick(250000);
        delay_tick(250000);
        delay_tick(250000);
    }

    a = 20;
    while(a--){
        SoftWareUART_Transmit_Byte(GIO_Read_PinsIs0(GIOB, 0b110));
        SoftWareUART_Transmit_Byte(GIO_Read_PinsIs0(GIOB, 0b101));
        SoftWareUART_Transmit_Byte(GIO_Read_PinsIs0(GIOB, 0b011));
        SoftWareUART_Transmit_Byte('\n');
        delay_tick(250000);
        delay_tick(250000);
        delay_tick(250000);
    }

    a = 20;
    while(a--){
        SoftWareUART_Transmit_Byte(GIO_Read_PinsIs0And1(GIOB, 0b110, 0b1));
        SoftWareUART_Transmit_Byte(GIO_Read_PinsIs0And1(GIOB, 0b101, 0b10));
        SoftWareUART_Transmit_Byte(GIO_Read_PinsIs0And1(GIOB, 0b011, 0b100));
        SoftWareUART_Transmit_Byte('\n');
        delay_tick(250000);
        delay_tick(250000);
        delay_tick(250000);
    }

    a = 20;
    while (a--) {
        b = GIO_ReadUntilDetectValue_AllPins_Return_1Detect_0TimeOut(GIOB, 0b1001, 32000);
        SoftWareUART_Transmit_Byte(b);
        SoftWareUART_Transmit_Byte('\n');
        delay_tick(250000);
        delay_tick(250000);
        delay_tick(250000);
    }

    a = 20;
    while (a--) {
        b = GIO_ReadUntilChangeValue_AllPins_Return_1Detect_0TimeOut(GIOB, 0b1001, 32000);
        SoftWareUART_Transmit_Byte(b);
        SoftWareUART_Transmit_Byte('\n');
        delay_tick(250000);
        delay_tick(250000);
        delay_tick(250000);
    }

    a = 20;
    while (a--) {
        b = GIO_ReadUntilDetectValue_1Pin_Return_1Detect_0TimeOut(GIOB, 0b10, 0, 320000);
        SoftWareUART_Transmit_Byte(b);
        SoftWareUART_Transmit_Byte('\n');
        delay_tick(250000);
        delay_tick(250000);
        delay_tick(250000);
    }
    while (1);
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
        (Set_BitsTo0_WithMask_SubDef((Ex_GIOA->Px), Mask_Ex_0b1011))

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
bool GIO_ReadUntilDetectValue_1Pin_Return_1Detect_0TimeOut(GIO_TypeDef *Ex_GIOA, McuRegType Mask_Ex_0b1000, bool CheckValue_0or1, uint32 TryCount);


#endif
#endif
