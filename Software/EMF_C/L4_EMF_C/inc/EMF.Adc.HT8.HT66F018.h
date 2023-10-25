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
#ifndef EMF_ADC_HT8_HT66F018_H
#define EMF_ADC_HT8_HT66F018_H
#if defined(EMF__TYPE_HT8)


#define		ADC_ENABLE()			_adoff = 0
#define		ADC_DISABLE()			_adoff = 1

#define		ADC_ISR_ENABLE()		_ade = 1
#define		ADC_ISR_DISABLE()		_ade = 0
#define		ADC_CLEAR_ISR_FLAG()	_adf = 0
#define		ADC_SET_ISR_FLAG()		_adf = 1

#define		ADC_VBG_ENABLE()		{_vbgen = 1;GCC_DELAY(800);}
#define		ADC_VBG_DISABLE()		(_vbgen = 0)

#define		ADC_START()				{_start = 0; _start = 1; _start = 0;}


/* attention：ADC clock is 0.1 to 2MHz,such as FSYS=8MHz，
 * ADC clock from FSYS/64 ~ FSYS/8 is OK.
 */
/******************* select ADC clock **********************/
//	#define		ADC_CLOCK_FSYS				(1)
//	#define		ADC_CLOCK_FSYS_DIV2			(1)
//	#define		ADC_CLOCK_FSYS_DIV4			(1)
//	#define		ADC_CLOCK_FSYS_DIV8			(1)
//	#define		ADC_CLOCK_FSYS_DIV16		(1)
//	#define		ADC_CLOCK_FSYS_DIV32		(1)
	#define		ADC_CLOCK_FSYS_DIV64		(1)
/* end of select ADC clock */


/*************** select ADC reference voltage **************/ 
	#define		ADC_REF_VOLTAGE_VDD			(1)
//	#define		ADC_REF_VOLTAGE_VREF		(1)
/* end of select ADC reference voltage */


/***************** select ADC data format ******************/
//	#define		ADC_VALUE_ALIGN_LEFT		(1)
	#define		ADC_VALUE_ALIGN_RIGHT		(1)
//end of select ADC data format



/**
  * @brief ADC analog channel selection list
  */
typedef enum 
{
	ADC_CH0  = (uint8)0x00, /**< Analog channel 0 */
	ADC_CH1  = (uint8)0x01, /**< Analog channel 1 */
	ADC_CH2  = (uint8)0x02, /**< Analog channel 2 */
	ADC_CH3  = (uint8)0x03, /**< Analog channel 3 */
	ADC_CH4  = (uint8)0x04, /**< Analog channel 4 */
	ADC_CH5  = (uint8)0x05, /**< Analog channel 5 */
	ADC_CH6  = (uint8)0x06, /**< Analog channel 6 */
	ADC_CH7  = (uint8)0x07, /**< Analog channel 7 */
	ADC_CH_INTERNAL_VBG		 = (uint8)0x20, 
} ADC_Channel_TypeDef;


/* READ ADC VALUE function */

#ifdef	ADC_VALUE_ALIGN_LEFT
	
	#define	ADC_READ_VALUE()	(_adrh << 4) | (_adrl >> 4)
	
#else 

	#define	ADC_READ_VALUE()	(_adrh << 8) | _adrl

#endif



/** ADC initialization function，you can select 
  * ADC clock,ADC reference voltage and AD converter
  * data format in ADC.h **/
void ADC_Init(void);

/** ADC channel select function，you can select 
  * the channel that you want to use **/
void ADC_SelectChannel(uint8 ADC_Channel);

/** ADC converter function， when you have already
  * select one channel，you can get the AD converter
  * value by this function **/
uint16 ADC_GetValue(void);

/** ADC channel select and get AD converter data
  * function **/
uint16 ADC_GetChannelValue(uint8 ADC_Channel);


#endif
#endif
