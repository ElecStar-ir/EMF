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
#ifndef EMF_ADC_HT8_HT66F002_0025_003_004_H
#define EMF_ADC_HT8_HT66F002_0025_003_004_H
#if defined(EMF__TYPE_HT8)

    //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    // Config defines
    //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    /* attention：ADC clock is 0.1 to 2MHz,such as FSYS=8MHz，
     * ADC clock from FSYS/64 ~ FSYS/8 is OK.
     */
    /******************* select ADC clock **********************/
    //	#define		ADC_CLOCK_FSYS				(1)
    //	#define		ADC_CLOCK_FSYS_DIV2			(1)
    //	#define		ADC_CLOCK_FSYS_DIV4			(1)
    //  #define     ADC_CLOCK_FSYS_DIV8         (1)
    //	#define		ADC_CLOCK_FSYS_DIV16		(1)
    //	#define		ADC_CLOCK_FSYS_DIV32		(1)
    //	#define		ADC_CLOCK_FSYS_DIV64		(1)
    	#define		ADC_CLOCK_FSYS_DIV128		(1)
    //=========================================================================================
    /*************** select ADC reference voltage **************/
    #define ADC_REF_VOLTAGE_VDD (1)
    //	#define		ADC_REF_VOLTAGE_VREF		(1)
    //	#define		ADC_REF_VOLTAGE_VREFx2		(1)
    //	#define		ADC_REF_VOLTAGE_VREFx3		(1)
    //	#define		ADC_REF_VOLTAGE_VREFx4		(1)
    //	#define		ADC_REF_VOLTAGE_VBGx2		(1)
    //	#define		ADC_REF_VOLTAGE_VBGx3		(1)
    //	#define		ADC_REF_VOLTAGE_VBGx4		(1)
    /* end of select ADC reference voltage */
    //=========================================================================================
    /***************** select ADC data format ******************/
    //	#define		ADC_VALUE_ALIGN_LEFT		(1)
    #define ADC_VALUE_ALIGN_RIGHT (1)
    /* end of select ADC data format */

    //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    // Commands and Const defines
    //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

    #define ADC_ENABLE_CONTROL_REGISTER() _enadc = 1
    #define ADC_DISABLE_CONTROL_REGISTER() _enadc = 0
    //=========================================================================================
    #define ADC_ISR_ENABLE() _ade = 1
    #define ADC_ISR_DISABLE() _ade = 0
    #define ADC_CLEAR_ISR_FLAG() _adf = 0
    #define ADC_SET_ISR_FLAG() _adf = 1
    //=========================================================================================
    #define ADC_OPA_ENABLE() (_enopa = 1)
    #define ADC_OPA_DISABLE() (_enopa = 0)
    //=========================================================================================
    #define ADC_VBG_ENABLE() (_vbgen = 1)
    #define ADC_VBG_DISABLE() (_vbgen = 0)
    //=========================================================================================
    #define ADC_START() \
        {               \
            _start = 0; \
            _start = 1; \
            _start = 0; \
        }
    //=========================================================================================
    /* READ ADC VALUE function */
    #ifdef ADC_VALUE_ALIGN_LEFT

        #define ADC_READ_VALUE() ((u16)_sadoh << 4) | (_sadol >> 4)

    #else

        #define ADC_READ_VALUE() ((u16)_sadoh << 8) | _sadol;

    #endif
    //=========================================================================================
    /**
     * @brief ADC analog channel selection list
     */
    #define ADC_CHANNEL_AN0 (uint8)0
    #define ADC_CHANNEL_AN1 (uint8)1
    #define ADC_CHANNEL_AN2 (uint8)2
    #define ADC_CHANNEL_AN3 (uint8)3
    #define ADC_CHANNEL_AN4 (uint8)4
    #define ADC_CHANNEL_AN5 (uint8)5
    #define ADC_CHANNEL_AN6 (uint8)6
    #define ADC_CHANNEL_AN7 (uint8)7

    #ifdef _sains3  //_sains is 4 bit
        #define ADC_CHANNEL_VDD (uint8)0b00010000
        #define ADC_CHANNEL_VDD_DIV2 (uint8)0b00100000
        #define ADC_CHANNEL_VDD_DIV4 (uint8)0b00110000
        #define ADC_CHANNEL_VREF (uint8)0b01010000
        #define ADC_CHANNEL_VREF_DIV2 (uint8)0b01100000
        #define ADC_CHANNEL_VREF_DIV4 (uint8)0b01110000
        #define ADC_CHANNEL_GROUND (uint8)0b10000000
    #else  //_sains is 3 bit
        #define ADC_CHANNEL_VDD (uint8)0b00100000
        #define ADC_CHANNEL_VDD_DIV2 (uint8)0b01000000
        #define ADC_CHANNEL_VDD_DIV4 (uint8)0b01100000
        #define ADC_CHANNEL_VREF (uint8)0b10100000
        #define ADC_CHANNEL_VREF_DIV2 (uint8)0b11000000
        #define ADC_CHANNEL_VREF_DIV4 (uint8)0b11100000
    #endif
    //=========================================================================================
    // Rename _sacksx -> _sackx
    #ifdef _sacks0
        #define _sack0 _sacks0
        #define _sack1 _sacks1
        #define _sack2 _sacks2
    #endif

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Functions
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
/**
* @code Example1)Pollinge ADC | HT66F004 | ADC_VREF is not External Vref
//Example in HT66F004
#include "EMF.h"

void main() {
    EMF_init();

    uint16 value;

    //Please Edit "Config defines" in "EMF.Adc.HT8.h" as below:
    //#define ADC_CLOCK_FSYS_DIV8 (1)
    //#define ADC_REF_VOLTAGE_VDD (1)
    //#define ADC_VALUE_ALIGN_RIGHT (1)
    
    _pas7 = 1; _pas6 = 1; //Gpio A7 alternate Select AN6 Mode[Read Datasheet "Input/Output Ports">"Pin-shared Functions"]

    ADC_Init();

	ADC_ENABLE_CONTROL_REGISTER();
    delay_tick(2000); //wait system stable

    ADC_SelectChannel(ADC_CHANNEL_AN6);
    
    while(1){
        value = ADC_GetValue();                   
        SoftWareUART_Transmit_Byte(0xAA);       //send head code to PCs
        delay_tick(100);                            
		SoftWareUART_Transmit_Byte(value>>8);		//send AD conversion value high byte to PC
		delay_tick(100);
		SoftWareUART_Transmit_Byte(value&0xff);		//send AD conversion value low byte to PC
        delay_tick(200000);
    }
}
* @endcode
* @code Example2)Pollinge ADC | HT66F004 | ADC_VREF = External Vref
//Example in HT66F004
#include "EMF.h"

void main() {
    EMF_init();

    uint16 value;

    //Please Edit "Config defines" in "EMF.Adc.HT8.h" as below:
    //#define  ADC_CLOCK_FSYS_DIV8   (1)
    //#define  ADC_REF_VOLTAGE_VREF	 (1)
    //#define  ADC_VALUE_ALIGN_RIGHT (1)

    _pas7 = 1; _pas6 = 1; //Gpio A7 alternate Select AN6 Mode[Read Datasheet "Input/Output Ports">"Pin-shared Functions"]

    _pas3 = 1; _pas2 = 0; //Config A5 to Vref Mode[Read Datasheet "Input/Output Ports">"Pin-shared Functions"]

    ADC_Init();

	ADC_ENABLE_CONTROL_REGISTER();
    delay_tick(2000); //wait system stable

    ADC_SelectChannel(ADC_CHANNEL_AN6);
    
    while(1){
        value = ADC_GetValue();                   
        SoftWareUART_Transmit_Byte(0xAA);       //send head code to PCs
        delay_tick(100);                            
		SoftWareUART_Transmit_Byte(value>>8);		//send AD conversion value high byte to PC
		delay_tick(100);
		SoftWareUART_Transmit_Byte(value&0xff);		//send AD conversion value low byte to PC
        delay_tick(200000);
    }
}
* @endcode
* @code Example3)Singel ADC | HT66F004 | ADC_VREF = External Vref
//Example in HT66F004
#include "EMF.h"

void main() {
    EMF_init();

    uint16 value;

    //Please Edit "Config defines" in "EMF.Adc.HT8.h" as below:
    //#define  ADC_CLOCK_FSYS_DIV8   (1)
    //#define  ADC_REF_VOLTAGE_VREF	 (1)
    //#define  ADC_VALUE_ALIGN_RIGHT (1)

    _pas7 = 1; _pas6 = 1; //Config A7 to AN6 Mode[Read Datasheet "Input/Output Ports">"Pin-shared Functions"]
    _pas5 = 1; _pas4 = 1; //Config A6 to AN5 Mode[Read Datasheet "Input/Output Ports">"Pin-shared Functions"]
    _pas3 = 1; _pas2 = 0; //Config A5 to Vref Mode[Read Datasheet "Input/Output Ports">"Pin-shared Functions"]

    ADC_Init();

	ADC_ENABLE_CONTROL_REGISTER();
    delay_tick(2000); //wait system stable
   
    while(1){
        value = ADC_GetChannelValue(ADC_CHANNEL_AN6);                   
        SoftWareUART_Transmit_Byte(0xAA);       //send head code to PCs
        delay_tick(100);                            
		SoftWareUART_Transmit_Byte(value>>8);		//send AD conversion value high byte to PC
		delay_tick(100);
		SoftWareUART_Transmit_Byte(value&0xff);		//send AD conversion value low byte to PC

        delay_tick(100);
        value = ADC_GetChannelValue(ADC_CHANNEL_AN5);                   
        SoftWareUART_Transmit_Byte(0xBB);       //send head code to PCs
        delay_tick(100);                            
		SoftWareUART_Transmit_Byte(value>>8);		//send AD conversion value high byte to PC
		delay_tick(100);
		SoftWareUART_Transmit_Byte(value&0xff);		//send AD conversion value low byte to PC
        delay_tick(200000);
    }
}
 * @endcode
*/
void ADC_Init();
//=========================================================================================
void ADC_SelectChannel(uint8 ADC_Channel);
//=========================================================================================
uint16 ADC_GetValue();
//=========================================================================================
uint16 ADC_GetChannelValue(uint8 ADC_Channel);

#endif
#endif
