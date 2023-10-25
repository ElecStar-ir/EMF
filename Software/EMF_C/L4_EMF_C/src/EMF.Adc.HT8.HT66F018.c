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
#if defined(EMF_ADC_HT8_HT66F018_H)

/**
  * @brief Initializes the ADC peripheral according to the specified parameters
  * @retval None
  */
void ADC_Init(void)
{
/***************** ADC clock select *****************/
	#ifdef	ADC_CLOCK_FSYS
		{
			/* select ADC clock fsys */
			_adck2 = 0; _adck1 = 0; _adck0 = 0;
		}		
	#elif	ADC_CLOCK_FSYS_DIV2
		{
			/* select ADC clock fsys/2 */
			_adck2 = 0; _adck1 = 0; _adck0 = 1;
		}
	#elif	ADC_CLOCK_FSYS_DIV4
		{
			/* select ADC clock fsys/4 */
			_adck2 = 0; _adck1 = 1; _adck0 = 0;
		}
	#elif	ADC_CLOCK_FSYS_DIV8
		{
			/* select ADC clock fsys/8 */
			_adck2 = 0; _adck1 = 1; _adck0 = 1;
		}
	#elif	ADC_CLOCK_FSYS_DIV16
		{
			/* select ADC clock fsys16 */
			_adck2 = 1; _adck1 = 0; _adck0 = 0;
		}
	#elif	ADC_CLOCK_FSYS_DIV32
		{
			/* select ADC clock fsys/32 */
			_adck2 = 1; _adck1 = 0; _adck0 = 1;
		}
	#elif	ADC_CLOCK_FSYS_DIV64
		{
			/* select ADC clock fsys/64 */
			_adck2 = 1; _adck1 = 1; _adck0 = 0;
		}
	#endif	
/*************** end of ADC clock select ******************/	

						
/******** setting AD convert data alignment type **********/
	#ifdef	ADC_VALUE_ALIGN_RIGHT		
		{
			/* select AD convert data alignment right	*/
			_adrfs = 1;
		}	
	#else		
		{
			/* select 	AD convert data alignment left */	
			_adrfs = 0;
		}	
	#endif
/***** end of setting AD convert data alignment type ******/


/********** setting AD convert reference voltage *********/		
	#ifdef	ADC_REF_VOLTAGE_VDD
		{
			_vrefs = 0;
		}	
	#else
		{
			_vrefs = 1;
		}		
	#endif
/********* end of setting AD convert reference voltage *********/
}



/**
  * @brief select ADC channel.
  * @param[in] ADC_Channel: specifies the ADC channel.
  * can have one of the values of @ref ADC_Channel_TypeDef.
  * @retval  none.
  */
void ADC_SelectChannel(uint8 ADC_Channel)
{
	_acs4 = 0;
	if((ADC_Channel >= 0)&&(ADC_Channel < 8))
	{
		/* clear ADC channel */
		_adcr0 &= 0b11111000;
		
		/* selection external ADC channel */
		_adcr0 |= ADC_Channel;
		
		/* select IO in AD input */
		_acerl = 0x01;
		_acerl <<= 	ADC_Channel;
	}
	else
	{
		/* selection internal ADC channel */
		ADC_VBG_ENABLE();	
		_acs4 = 1;		
	}	
}/* end of ADC_SelectChannel(u8 ADC_Channel) */


/**
  * @brief Get one sample of measured signal.
  * @param[in] None.
  * @retval ConversionValue:  value of the measured signal.
  */
uint16 ADC_GetValue(void)
{
	uint16 Value;
	
	/* start AD converter */
	ADC_START();
	
	/* waitting AD conversion finish */
	while(1 == _eocb);	
	
/* AD conversion data alignment right */
	#ifdef	ADC_VALUE_ALIGN_RIGHT		
		{
			/* get the AD conversion value */
			Value = (_adrh <<8) | _adrl;
		}	
	
/* AD conversion data alignment left */
	#else	
		{
			/* get the AD conversion value */
			Value = (_adrh <<4) | (_adrl >>4);
		}	
	#endif
	return Value;
}



/**
  * @brief Get one sample of measured signal.
  * @param[in] ADC_Channel: specifies the ADC channel.
  * can have one of the values of @ref ADC_Channel_TypeDef.
  * @retval ConversionValue:  value of the measured signal.
  * @par Required preconditions:
  * ADC conversion finished.
  */
uint16 ADC_GetChannelValue(uint8 ADC_Channel)
{
	uint16 AD_ConverterValue;
	
	_acs4 = 0;
	if((ADC_Channel >= 0)&&(ADC_Channel < 8))
	{
		/* clear ADC channel */
		_adcr0 &= 0b11111000;
		
		/* selection external ADC channel */
		_adcr0 |= ADC_Channel;
		
		/* select IO in AD input */
		_acerl = 0x01;
		_acerl <<= 	ADC_Channel;
	}
	else
	{
		/* selection internal ADC channel */
		ADC_VBG_ENABLE();	
		_acs4 = 1;		
	}
	
	/* start AD convert */
	ADC_START();
		
	/* waitting AD conversion finish */	
	while(1 == _eocb);	
	
	/* AD conversion data alignment right */
	#ifdef	ADC_VALUE_ALIGN_RIGHT		
		{
			/* get the AD conversion value */
			AD_ConverterValue = (_adrh <<8) | _adrl;
		}	
			
	/* AD conversion data alignment left */
	#else	
		{
			/* get the AD conversion value */
			AD_ConverterValue = (_adrh <<4) | (_adrl >>4);
		}	
	#endif
	
		return AD_ConverterValue;
}

#endif
