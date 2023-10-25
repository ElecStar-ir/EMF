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
 ******************************************************************************************
 */
#ifndef EMF_GIO_IAR__HAL__F0__STM32F030X6_H
#define EMF_GIO_IAR__HAL__F0__STM32F030X6_H
#if defined(IAR__HAL__F0__STM32F030X6)
/**
* @code
#include "main.h"
#include <stdio.h>
#include "EMF.h"

int main(void){
    uint8 a;
    uint32 b;
    EMF_init();
    SetCoreClockTo_HSI_8MHZ_Return_1Ok_0Failed();

    GIO_RegisterClockOnOff(GIOA, 1);
    GIO_RegisterClockOnOff(GIOF, 1);

    GIO_Init(GIOA, 0b111, GIO_MODE_OUTPUT_OPENDRAIN, GIO_PULLDOWN, GIO_OUTPUT_SPEED_FREQ_HIGH,0);
    //GIO_Deinit(GIOA, 0b111);

    a = GIO_GetConfigState_1Pin_Return_Mode_0Input1Output2Alternate3Analog(GIOA, 0);
    printf("%d\n", a);
    a = GIO_GetConfigState_1Pin_Return_OutputMode_0PushPull_1OpenDrain(GIOA, 0);
    printf("%d\n", a);
    a = GIO_GetConfigState_1Pin_Return_OutputSpeed_0Low_1Medium_2Low_3High(GIOA, 0);
    printf("%d\n", a);
    a = GIO_GetConfigState_1Pin_Return_Pull_0PullNO_1PullUp_2PullDown(GIOA, 0);
    printf("%d\n", a);

    GIO_Init(GIOF, 0b11, GIO_MODE_OUTPUT_PUSHPULL, GIO_PULLUP, GIO_OUTPUT_SPEED_FREQ_HIGH, 0);
    GIO_Write_AllPins(GIOF, 0b11);
    GIO_Write_1Pin(GIOF, 0, 0);
    GIO_Write_1Pin(GIOF, 1, 0);
    GIO_Write_Pins_High(GIOF, 0b11);
    GIO_Write_Pins_Low(GIOF, 0b10);
    GIO_Write_Pins_Low(GIOF, 0b01);
    GIO_Write_Pins_High(GIOA, 0b111);
    GIO_Write_Pins(GIOA, 0b110, 0b001);
    GIO_Write_Pins_Low(GIOA, 0b111);
    GIO_Write_Pins(GIOA, 0b110, 0b001);
    GIO_Write_Pins_Toggle(GIOF, 0b11);
    GIO_Write_Pins_Toggle(GIOF, 0b10);
    GIO_Write_Pins_Toggle(GIOA, 0b111);
    GIO_Write_Pins_Toggle(GIOA, 0b010);
    GIO_Write_Pins_Toggle(GIOA, 0b010);
    b = GIO_GetWriteState_AllPins(GIOA);
    printf("%d\n", b);

    b = GIO_Read_AllPins(GIOA);
    printf("%d\n", b);
    b = GIO_Read_AllPins(GIOF);
    printf("%d\n", b);
    a = GIO_Read_1Pin(GIOA, 1);
    printf("%d\n", a);
    a = GIO_Read_1Pin(GIOA, 2);
    printf("%d\n", a);
    a = GIO_Read_1Pin(GIOA, 4);
    printf("%d\n", a);
    a = GIO_Read_PinsIs1(GIOA, 0b1);
    printf("%d\n", a);
    a = GIO_Read_PinsIs1(GIOA, 0b11000);
    printf("%d\n", a);
    a = GIO_Read_PinsIs1(GIOA, 0b10000);
    printf("%d\n", a);
     a = GIO_Read_PinsIs0(GIOA, 0b1);
    printf("%d\n", a);
    a = GIO_Read_PinsIs0(GIOA, 0b11000);
    printf("%d\n", a);
    a = GIO_Read_PinsIs0(GIOA, 0b10000);
    printf("%d\n", a);
    a = GIO_Read_PinsIs0And1(GIOA, 0b10, 0b100);
    printf("%d\n", a);
    a = GIO_Read_PinsIs0And1(GIOA, 0b10000, 0b11);
    printf("%d\n", a);
    a = GIO_Read_PinsIs0And1(GIOA, 0b10000, 0b1111);
    printf("%d\n", a);
    
    
    GIO_Init(GIOF, 0b11, GIO_MODE_INPUT, GIO_PULLUP, 0, 0);
    a = GIO_ReadUntilDetectValue_AllPins_Return_1Detect_0TimeOut(GIOF, 0b10, 1000000);
    printf("%d\n", a);
    a = GIO_ReadUntilChangeValue_AllPins_Return_1Detect_0TimeOut(GIOF, 0b11, 1000000);
    printf("%d\n", a);
    a = GIO_ReadUntilDetectValue_1Pins_Return_1Detect_0TimeOut(GIOF, 0b10, 0, 1000000);
    printf("%d\n", a);

    GIO_Deinit(GIOA, 0b111);
    GIO_Deinit(GIOF, 0b11);

    GIO_RegisterClockOnOff(GIOA, 0);
    GIO_RegisterClockOnOff(GIOF, 0);

    while (1);
}
* @endcode
*/

namespace EMF::GIO {
    //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    // define and typedef
    //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    #define McuRegType uint32
    #define McuRegBitsType uint32Bits_t
    #define __AddGIOReg(RegName) \
        _rw McuRegType RegName;  \
        _rw McuRegBitsType RegName##_bits;

//=========================================================================================
typedef struct {
    union {
        __AddGIOReg(MODER) /*!< GPIO port mode register,                     Address offset: 0x00      */
    };
    //=================================================
    union {
        __AddGIOReg(OTYPER) /*!< GPIO port output type register,              Address offset: 0x04      */
    };
    //=================================================
    union {
        __AddGIOReg(OSPEEDR) /*!< GPIO port output speed register,             Address offset: 0x08      */
    };
    //=================================================
    union {
        __AddGIOReg(PUPDR) /*!< GPIO port pull-up/pull-down register,        Address offset: 0x0C      */
    };
    //=================================================
    union {
        __AddGIOReg(IDR) /*!< GPIO port input data register,               Address offset: 0x10      */
    };
    //=================================================
    union {
        __AddGIOReg(ODR) /*!< GPIO port output data register,              Address offset: 0x14      */
    };
    //=================================================
    union {
        __AddGIOReg(BSRR) /*!< GPIO port output data register,              Address offset: 0x14      */
        struct {
            _rw uint32 BSRR0To15_BS0To15 : 16;
            _rw uint32 BSRR16To31_BR0To15 : 16;
        };
    };
    //=================================================
    union {
        __AddGIOReg(LCKR) /*!< GPIO port configuration lock register,       Address offset: 0x1C      */
    };
    //=================================================
    union {
        __AddGIOReg(AFRL) /*!< GPIO alternate function low register,  Address offset: 0x20-0x24 */
    };
    //=================================================
    union {
        __AddGIOReg(AFRH) /*!< GPIO alternate function low register,  Address offset: 0x20-0x24 */
    };
    //=================================================
    union {
        __AddGIOReg(BRR) /*!< GPIO bit reset register,                     Address offset: 0x28      */
    };

} GIO_TypeDef;
    //=========================================================================================
    #ifdef GPIOA_BASE
        #define GIOA ((GIO_TypeDef *)GPIOA_BASE)
        #define GIOA_RegisterClockOn() __HAL_RCC_GPIOA_CLK_ENABLE()
        #define GIOA_RegisterClockOff() __HAL_RCC_GPIOA_CLK_DISABLE()
    #endif

    #ifdef GPIOB_BASE
        #define GIOB ((GIO_TypeDef *)GPIOB_BASE)
        #define GIOB_RegisterClockOn() __HAL_RCC_GPIOB_CLK_ENABLE();
        #define GIOB_RegisterClockOff() __HAL_RCC_GPIOB_CLK_DISABLE();
    #endif

    #ifdef GPIOC_BASE
        #define GIOC ((GIO_TypeDef *)GPIOC_BASE)
        #define GIOC_RegisterClockOn() __HAL_RCC_GPIOC_CLK_ENABLE();
        #define GIOC_RegisterClockOff() __HAL_RCC_GPIOC_CLK_DISABLE();
    #endif

    #ifdef GPIOD_BASE
        #define GIOD ((GIO_TypeDef *)GPIOD_BASE)
        #define GIOD_RegisterClockOn() __HAL_RCC_GPIOD_CLK_ENABLE();
        #define GIOD_RegisterClockOff() __HAL_RCC_GPIOD_CLK_DISABLE();
    #endif

    #ifdef GPIOE_BASE
        #define GIOE ((GIO_TypeDef *)GPIOE_BASE)
        #define GIOE_RegisterClockOn() __HAL_RCC_GPIOE_CLK_ENABLE();
        #define GIOE_RegisterClockOff() __HAL_RCC_GPIOE_CLK_DISABLE();
    #endif

    #ifdef GPIOF_BASE
        #define GIOF ((GIO_TypeDef *)GPIOF_BASE)
        #define GIOF_RegisterClockOn() __HAL_RCC_GPIOF_CLK_ENABLE();
        #define GIOF_RegisterClockOff() __HAL_RCC_GPIOF_CLK_DISABLE();
    #endif

    #ifdef GPIOG_BASE
        #define GIOG ((GIO_TypeDef *)GPIOG_BASE)
        #define GIOG_RegisterClockOn() __HAL_RCC_GPIOG_CLK_ENABLE();
        #define GIOG_RegisterClockOff() __HAL_RCC_GPIOG_CLK_DISABLE();
    #endif

    #ifdef GPIOH_BASE
        #define GIOH ((GIO_TypeDef *)GPIOH_BASE)
        #define GIOH_RegisterClockOn() __HAL_RCC_GPIOH_CLK_ENABLE();
        #define GIOH_RegisterClockOff() __HAL_RCC_GPIOH_CLK_DISABLE();
    #endif

    #ifdef GPIOI_BASE
        #define GIOI ((GIO_TypeDef *)GPIOI_BASE)
        #define GIOI_RegisterClockOn() __HAL_RCC_GPIOI_CLK_ENABLE();
        #define GIOI_RegisterClockOff() __HAL_RCC_GPIOI_CLK_DISABLE();
    #endif

    #ifdef GPIOJ_BASE
        #define GIOJ ((GIO_TypeDef *)GPIOJ_BASE)
        #define GIOJ_RegisterClockOn() __HAL_RCC_GPIOJ_CLK_ENABLE();
        #define GIOJ_RegisterClockOff() __HAL_RCC_GPIOJ_CLK_DISABLE();
    #endif

    #ifdef GPIOK_BASE
        #define GIOK ((GIO_TypeDef *)GPIOK_BASE)
        #define GIOK_RegisterClockOn() __HAL_RCC_GPIOK_CLK_ENABLE();
        #define GIOK_RegisterClockOff() __HAL_RCC_GPIOK_CLK_DISABLE();
    #endif

    #ifdef GPIOL_BASE
        #define GIOL ((GIO_TypeDef *)GPIOL_BASE)
        #define GIOL_RegisterClockOn() __HAL_RCC_GPIOL_CLK_ENABLE();
        #define GIOL_RegisterClockOff() __HAL_RCC_GPIOL_CLK_DISABLE();
    #endif

    #ifdef GPIOM_BASE
        #define GIOM ((GIO_TypeDef *)GPIOM_BASE)
        #define GIOM_RegisterClockOn() __HAL_RCC_GPIOM_CLK_ENABLE();
        #define GIOM_RegisterClockOff() __HAL_RCC_GPIOM_CLK_DISABLE();
    #endif
    //=========================================================================================
    #define GIO_PIN_0 ((uint16_t)0x0001U)   /* Pin 0 selected    */
    #define GIO_PIN_1 ((uint16_t)0x0002U)   /* Pin 1 selected    */
    #define GIO_PIN_2 ((uint16_t)0x0004U)   /* Pin 2 selected    */
    #define GIO_PIN_3 ((uint16_t)0x0008U)   /* Pin 3 selected    */
    #define GIO_PIN_4 ((uint16_t)0x0010U)   /* Pin 4 selected    */
    #define GIO_PIN_5 ((uint16_t)0x0020U)   /* Pin 5 selected    */
    #define GIO_PIN_6 ((uint16_t)0x0040U)   /* Pin 6 selected    */
    #define GIO_PIN_7 ((uint16_t)0x0080U)   /* Pin 7 selected    */
    #define GIO_PIN_8 ((uint16_t)0x0100U)   /* Pin 8 selected    */
    #define GIO_PIN_9 ((uint16_t)0x0200U)   /* Pin 9 selected    */
    #define GIO_PIN_10 ((uint16_t)0x0400U)  /* Pin 10 selected   */
    #define GIO_PIN_11 ((uint16_t)0x0800U)  /* Pin 11 selected   */
    #define GIO_PIN_12 ((uint16_t)0x1000U)  /* Pin 12 selected   */
    #define GIO_PIN_13 ((uint16_t)0x2000U)  /* Pin 13 selected   */
    #define GIO_PIN_14 ((uint16_t)0x4000U)  /* Pin 14 selected   */
    #define GIO_PIN_15 ((uint16_t)0x8000U)  /* Pin 15 selected   */
    #define GIO_PIN_All ((uint16_t)0xFFFFU) /* All pins selected */

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Gio Register Clock ON/OFF
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
void GIO_RegisterClockOnOff(GIO_TypeDef *GIOx_Ptr__Ex_GIOA, bool GIOx_Clock_1On0Off);
    //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    // Gio Configs
    //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    /** @defgroup GIO_mode GIO mode
     * @brief GIO Configuration Mode
     *        Elements values convention: 0x00WX00YZ
     *           - W  : EXTI trigger detection on 3 bits
     *           - X  : EXTI mode (IT or Event) on 2 bits
     *           - Y  : Output type (Push Pull or Open Drain) on 1 bit
     *           - Z  : GIO mode (Input, Output, Alternate or Analog) on 2 bits
     * @{
     */
    #define GIO_MODE_INPUT MODE_INPUT                           /*!< Input Floating Mode                   */
    #define GIO_MODE_OUTPUT_PUSHPULL (MODE_OUTPUT | OUTPUT_PP)  /*!< Output Push Pull Mode                 */
    #define GIO_MODE_OUTPUT_OPENDRAIN (MODE_OUTPUT | OUTPUT_OD) /*!< Output Open Drain Mode                */
    #define GIO_MODE_AF_PUSHPULL (MODE_AF | OUTPUT_PP)          /*!< Alternate Function Push Pull Mode     */
    #define GIO_MODE_AF_OPENDRAIN (MODE_AF | OUTPUT_OD)         /*!< Alternate Function Open Drain Mode    */

    #define GIO_MODE_ANALOG MODE_ANALOG /*!< Analog Mode  */

    #define GIO_MODE_IT_RISING (MODE_INPUT | EXTI_IT | TRIGGER_RISING)                           /*!< External Interrupt Mode with Rising edge trigger detection          */
    #define GIO_MODE_IT_FALLING (MODE_INPUT | EXTI_IT | TRIGGER_FALLING)                         /*!< External Interrupt Mode with Falling edge trigger detection         */
    #define GIO_MODE_IT_RISING_FALLING (MODE_INPUT | EXTI_IT | TRIGGER_RISING | TRIGGER_FALLING) /*!< External Interrupt Mode with Rising/Falling edge trigger detection  */

    #define GIO_MODE_EVT_RISING (MODE_INPUT | EXTI_EVT | TRIGGER_RISING)                                                                                                      /*!< External Event Mode with Rising edge trigger detection             */
    #define GIO_MODE_EVT_FALLING (MODE_INPUT | EXTI_EVT | TRIGGER_FALLING)                                                                                                    /*!< External Event Mode with Falling edge trigger detection            */
    #define GIO_MODE_EVT_RISING_FALLING (MODE_INPUT | EXTI_EVT | TRIGGER_RISING | TRIGGER_FALLING) /*!< External Event Mode with Rising/Falling edge trigger detection    */
//=========================================================================================                                                                                       
    #define GIO_OUTPUT_SPEED_FREQ_LOW      (0x00000000U)  /*!< range up to 2 MHz, please refer to the product datasheet */
    #define GIO_OUTPUT_SPEED_FREQ_MEDIUM   (0x00000001U)                                                                                                                        /*!< range  4 MHz to 10 MHz, please refer to the product datasheet */
    #define GIO_OUTPUT_SPEED_FREQ_HIGH     (0x00000003U)                                                                                                                          /*!< range 10 MHz to 50 MHz, please refer to the product datasheet */
    //=========================================================================================
    #define GIO_PULLNO (0x00000000U)   /*!< No Pull-up or Pull-down activation  */
    #define GIO_PULLUP (0x00000001U)   /*!< Pull-up activation                  */
    #define GIO_PULLDOWN (0x00000002U) /*!< Pull-down activation                */
//=========================================================================================
void GIO_Init(GIO_TypeDef *GIOx__Ex_GIOA,
              uint32 GIO_PINS_Mask__Ex_0b1101,
              uint32 GIO_MODE__Ex_GIO_MODE_OUTPUT_PUSHPULL,
              uint32 GIO_PULL__Ex_GIO_PULLNO,
              uint32 GIO_OUTPUT_SPEED__Ex_GIO_OUTPUT_SPEED_FREQ_LOW,
              uint32 ALTERNATE_FUNCTION__Ex_GPIO_AF0_SPI1);
    //=========================================================================================
    #define GIO_Deinit(GIOx__Ex_GIOA_GIOB, GIO_PINS_Mask__Ex_0b1101) HAL_GPIO_DeInit((GPIO_TypeDef *)GIOx__Ex_GIOA_GIOB, GIO_PINS_Mask__Ex_0b1101)
//=========================================================================================
uint8 GIO_GetConfigState_1Pin_Return_Mode_0Input1Output2Alternate3Analog(GIO_TypeDef *Ex_GIOA, uint8 PinNumber_0tox);
//=========================================================================================
uint8 GIO_GetConfigState_1Pin_Return_OutputMode_0PushPull_1OpenDrain(GIO_TypeDef *Ex_GIOA, uint8 PinNumber_0tox);
//=========================================================================================
uint8 GIO_GetConfigState_1Pin_Return_OutputSpeed_0Low_1Medium_2Low_3High(GIO_TypeDef *Ex_GIOA, uint8 PinNumber_0tox);
//=========================================================================================
uint8 GIO_GetConfigState_1Pin_Return_Pull_0PullNO_1PullUp_2PullDown(GIO_TypeDef *Ex_GIOA, uint8 PinNumber_0tox);
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Gio Write
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    #define GIO_DirectWrite_AllPins_Defsub(Ex_GIOA, Value) (Ex_GIOA->ODR = Value)

void GIO_Write_AllPins(GIO_TypeDef *Ex_GIOA, McuRegType Value);
    //=========================================================================================
    #define GIO_DirectWrite_1Pin_Defsub(Ex_GIOA, PinNumber_0tox, Value_0or1) \
        (Set_1Bit_SubDef((Ex_GIOA->ODR), PinNumber_0tox, Value_0or1))

void GIO_Write_1Pin(GIO_TypeDef *Ex_GIOA, uint8 PinNumber_0tox, bool Value_0or1);
    //=========================================================================================
    #define GIO_DirectWrite_Pins_High_WithMask_Defsub(Ex_GIOA, Mask_Ex_0b1011) \
        (Set_BitsTo1_WithMask_SubDef((Ex_GIOA->BSRR0To15_BS0To15), Mask_Ex_0b1011))

void GIO_Write_Pins_High(GIO_TypeDef *Ex_GIOA, McuRegType Mask_Ex_0b1011);
    //=========================================================================================
    #define GIO_DirectWrite_Pins_Low_WithMask_Defsub(Ex_GIOA, Mask_Ex_0b1011) \
        (Set_BitsTo1_WithMask_SubDef((Ex_GIOA->BSRR16To31_BR0To15), Mask_Ex_0b1011))

void GIO_Write_Pins_Low(GIO_TypeDef *Ex_GIOA, McuRegType Mask_Ex_0b1011);
    //=========================================================================================
    #define GIO_DirectWrite_Pins_WithMask_Defsub(Ex_GIOA, Mask_High_Ex_0b1011, Mask_Low_Ex_0b1011) \
        GIO_DirectWrite_Pins_High_WithMask_Defsub(Ex_GIOA, Mask_High_Ex_0b1011);                   \
        GIO_DirectWrite_Pins_Low_WithMask_Defsub(Ex_GIOA, Mask_Low_Ex_0b1011)

void GIO_Write_Pins(GIO_TypeDef *Ex_GIOA, McuRegType Mask_High_Ex_0b1011, McuRegType Mask_Low_Ex_0b1011);
    //=========================================================================================
    #define GIO_DirectWrite_Pins_Toggle_WithMask_Defsub(Ex_GIOA, Mask_Ex_0b1011) \
        (Toggle_Bits_WithMask_SubDef((Ex_GIOA->ODR), Mask_Ex_0b1011))

void GIO_Write_Pins_Toggle(GIO_TypeDef *Ex_GIOA, McuRegType Mask_Ex_0b1011);
    //=========================================================================================
    #define GIO_DirectGetWriteState_AllPins(Ex_GIOA) (Ex_GIOA->ODR)

/**
 * @brief This function works correct only in output mode
 */
McuRegType GIO_GetWriteState_AllPins(GIO_TypeDef *Ex_GIOA);
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Gio Read
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    #define GIO_DirectRead_AllPins_Defsubf(Ex_GIOA) (Ex_GIOA->IDR)
McuRegType GIO_Read_AllPins(GIO_TypeDef *Ex_GIOA);
    //=========================================================================================
    #define GIO_DirectRead_1Pin_Defsubf(Ex_GIOA, PinNumber_0tox) \
        (Get_1Bit_Return_0or1_SubfDef((Ex_GIOA->IDR), PinNumber_0tox))

bool GIO_Read_1Pin(GIO_TypeDef *Ex_GIOA, uint8 PinNumber_0tox);
    //=========================================================================================
    #define GIO_DirectRead_PinsIs1_WithMask_Defsubf(Ex_GIOA, Mask_Ex_0b1000) \
        (Get_BitsIs1_WithMask_Return_0or1_SubfDef((Ex_GIOA->IDR), Mask_Ex_0b1000))

bool GIO_Read_PinsIs1(GIO_TypeDef *Ex_GIOA, McuRegType Mask_Ex_0b1000);
    //=========================================================================================
    #define GIO_DirectRead_PinsIs0_WithMask_Defsubf(Ex_GIOA, Mask_Ex_0b1000) \
        (Get_BitsIs0_WithMask_Return_0or1_SubfDef((Ex_GIOA->IDR), Mask_Ex_0b1000))

bool GIO_Read_PinsIs0(GIO_TypeDef *Ex_GIOA, McuRegType Mask_Ex_0b1000);
    //=========================================================================================
    #define GIO_DirectRead_PinsIs0And1_WithMask_Defsubf(Ex_GIOA, Mask_High_Ex_0b1000, Mask_Low_Ex_0b1000) \
        (Get_BitsIs0And1_WithMask_Return_0or1_SubfDef((Ex_GIOA->IDR), Mask_High_Ex_0b1000, Mask_Low_Ex_0b1000))

bool GIO_Read_PinsIs0And1(GIO_TypeDef *Ex_GIOA, McuRegType Mask_High_Ex_0b1000, McuRegType Mask_Low_Ex_0b1000);
//=========================================================================================
bool GIO_ReadUntilDetectValue_AllPins_Return_1Detect_0TimeOut(GIO_TypeDef *Ex_GIOA, McuRegType CheckValue, uint32 TryCount);
//=========================================================================================
bool GIO_ReadUntilChangeValue_AllPins_Return_1Detect_0TimeOut(GIO_TypeDef *Ex_GIOA, McuRegType CheckValue, uint32 TryCount);
//=========================================================================================
bool GIO_ReadUntilDetectValue_1Pins_Return_1Detect_0TimeOut(GIO_TypeDef *Ex_GIOA, McuRegType Mask_Ex_0b1000, bool CheckValue_0or1, uint32 TryCount);

}  // namespace EMF::GIO
using namespace EMF::GIO;

#endif
#endif
