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

#if defined(EMF_TIMER_HT8_PTM_HT66F018_H)

/**
  * @brief PTM initialization function.
  * @param[in] Non.
  * @retval Non.
  */
void PTM_Init(void)
{
/******************** work mode select ********************/
	#ifdef	PTM_TIMER_COUNTER_MODE
		_t1m1 = 1; _t1m0 = 1;	//Select PTM timer/counter Mode
		
	#elif	PTM_PWM_OUTPUT_MODE
		_t1m1 = 1; _t1m0 = 0;	
		_t1io1 = 1; _t1io0 = 0; //Select PTM PWM Output Mode
		_ace6 = 0; _t1cp = 1;
		_pac7 = 0; _pa7 = 0;
		
	#elif	PTM_SINGLE_PULSE_OUTPUT_MODE
		_t1m1 = 1; _t1m0 = 0;	
		_t1io1 = 1; _t1io0 = 1;	//Select PTM Single Pulse Output Mode
		_ace6 = 0; _t1cp = 1;
		_pac7 = 0; _pa7 = 0;
	
	#elif	PTM_COMPARE_MATCH_MODE	//Select PTM Compare Match Output Mode
		_t1m1 = 0; _t1m0 = 0;
		_ace6 = 0; _t1cp = 1;
		_pac7 = 0; _pa7 = 0;
		
	#elif	PTM_CAPTURE_INPUT_MODE	//Select PTM Capture Input Mode
		_t1m1 = 0; _t1m0 = 1;		
	#endif
/**************** end of work mode select ****************/		

/********************* clock select **********************/
	#ifdef	PTM_FSYS_DIV4
		_t1ck2 = 0; _t1ck1 = 0; _t1ck0 = 0;	//Select PTM Counter clock Fsys/4
	
	#elif	PTM_FSYS
		_t1ck2 = 0; _t1ck1 = 0; _t1ck0 = 1;	//Select PTM Counter clock Fsys
	
	#elif	PTM_FH_DIV16
		_t1ck2 = 0; _t1ck1 = 1; _t1ck0 = 0; //Select PTM Counter clock FH/16
		
	#elif	PTM_FH_DIV64
		_t1ck2 = 0; _t1ck1 = 1; _t1ck0 = 1; //Select PTM Counter clock FH/64
		
	#elif	PTM_FTBC
		_t1ck2 = 1; _t1ck1 = 0; _t1ck0 = 0;	//Select PTM Counter clock Ftbc
		
	#elif	PTM_FH
		_t1ck2 = 1; _t1ck1 = 0; _t1ck0 = 1; //Select PTM Counter clock FH
		
	#elif	PTM_TCK_RISING_EDGE
		_t1ck2 = 1; _t1ck1 = 1; _t1ck0 = 0; //Select PTM Counter clock TCKn rising edge clock
		_ace3 = 0; _pac4 = 1; _papu4 =1;
		
	#elif	PTM_TCK_FALLING_EDGE
		_t1ck2 = 1; _t1ck1 = 1; _t1ck0 = 1; //Select PTM Counter clock TCKn falling edge clock
		_ace3 = 0; _pac4 = 1; _papu4 =1;
	#endif	
/********************* end of clock select **********************/
		
/************ TMn Counter Clear condition selection *************/	
	#ifdef	PTM_CCRA_MATCH
		_t1cclr = 1;	//PTM Counter Clear condition selection PTM Comparator A match		
	#else
		_t1cclr = 0;	//PTM Counter Clear condition selection PTM Comparator P match	
	#endif
/********* end of TMn Counter Clear condition selection *********/	
}


/**
  * @brief PTM PWM configure function.
  * Specify the following parameters in HT8_PTM.h, 
  * 1.TP1 pin Output control
  * 2.TP1 Output polarity control
  * @param[in] Non.
  * @retval Non.
  */
void PTM_PwmOutputConfig(void)
{
/************* TP1 Output control **************/		
	#ifdef	PTM_ACTIVE_LOW
		_t1oc = 0;					//active low
	#else
		_t1oc = 1;					//active high
	#endif
/********* end of TP1 Output control **********/	
		
/******** TP1 Output polarity control ********/
	#ifdef	PTM_NON_INVERTED
		_t1pol = 0;					//no inverted
	#else
		_t1pol = 1;					//inverted
	#endif
/******** TP1 Output polarity control ********/	
}


/**
  * @brief PTM PWM update function.
  * @param[in] CCRA value.
  * @param[in] CCRP value.
  * @retval Non.
  */
void PTM_PwmUpdate(uint16 TempCCRA,uint16 TempCCRP)
{
	_tm1al = TempCCRA & 0x00ff;	//
	_tm1ah = TempCCRA >> 8;		//
	_tm1rpl = TempCCRP & 0x00ff;	//
	_tm1rph = TempCCRP >> 8;
}


/**
  * @brief PTM SinglePulse configure function.
  * Specify the following parameters in HT8_PTM.h, 
  * 1.TP1 pin Output control
  * 2.TP1 Output polarity control
  * 3.TCK1 trigger control
  * @param[in] Non.
  * @retval Non.
  */
void PTM_SinglePulseOutputConfig(void)
{
/************* TP1 Output control **************/		
	#ifdef	PTM_ACTIVE_LOW
		_t1oc = 0;					//active low
	#else
		_t1oc = 1;					//active high
	#endif
/********* end of TP1 Output control **********/	
		
/******** TP1 Output polarity control ********/
	#ifdef	PTM_NON_INVERTED
		_t1pol = 0;					//no inverted
	#else
		_t1pol = 1;					//inverted
	#endif
/******** TP1 Output polarity control ********/	

/******** TCK1 trigger control *****/
	#ifdef	PTM_TCK1_TRIG_ENABLE			
		_ace3 = 0; _pac4 = 1; _papu4 =1;				
	#endif
/*** end of TCK1 trigger control ***/
}


/**
  * @brief PTM SinglePulse update function.
  * @param[in] CCRA value.
  * @retval Non.
  */
void PTM_SinglePulseUpdate(uint16 TempCCRA)
{
	_tm1al = TempCCRA & 0x00ff;	//
	_tm1ah = TempCCRA >> 8;		//
}


/**
  * @brief PTM timer/counter mode period config function.
  * @param[in] period value,
  * select CCRA_MATCH,the value is 0~1024;
  * overflow time=TempPeriod * Tclock,
  * select CCRP_MATCH,the value is 0~1024.
  * overflow time=TempPeriod * Tclock, 
  * @retval None.
  */
void PTM_CounterModeConfig(uint16 TempPeriod)
{
#ifdef	PTM_CCRA_MATCH
	_tm1al = TempPeriod & 0x00ff;	//
	_tm1ah = TempPeriod >> 8;		//
#else	
	_tm1rpl = TempPeriod & 0x00ff;	//
	_tm1rph = TempPeriod >> 8;		//
#endif		
}


/**
  * @brief PTM compare match output config function,
  * Specify the following parameters in HT8_PTM.h, 
  * 1.TP1 pin output function select
  * 2.TP1 pin Output initial status control
  * 3.TP1 Output polarity control
  * @param[in] None.
  * @retval None.
  */
void PTM_CompareMatchOutputConfig()
{
/********** Select TP1 pin output function **********/	
	#ifdef	PTM_NO_CHANGE
		_t1io1 = 0; _t1io0 = 0;	//
	
	#elif	PTM_OUTPUT_LOW
		_t1io1 = 0; _t1io0 = 1;	//
	
	#elif	PTM_OUTPUT_HIGH
		_t1io1 = 1; _t1io0 = 0;	//
	
	#elif	PTM_OUTPUT_TOGGLE
		_t1io1 = 1; _t1io0 = 1;	//
	#endif
/********** Select TP1 pin output function **********/	

/***** TP1 Output initialization status control *****/			
	#ifdef	PTM_INITIAL_LOW
		_t1oc = 0;				//
	#else
		_t1oc = 1;	
	#endif			
/** end of TP1 Output initialization status control */		

/*********** TP1 Output polarity control ************/	
	#ifdef	PTM_NON_INVERTED
		_t1pol = 0;				//
	#else
		_t1pol = 1;				//
	#endif
/******* end of TP1 Output polarity control ********/
}


/**
  * @brief PTM compare match output update function,
  * @param[in] MatchTime value,
  * select CCRA_MATCH,the value is 0~1024;
  * match time=TempMatchTime * Tclock,
  * select CCRP_MATCH,the value is 0~1024.
  * match time=TempMatchTime * Tclock, 
  * @retval None.
  */
void PTM_CompareMatchOutputUpdate(uint16 TempMatchTime)
{
#ifdef	PTM_CCRA_MATCH
	_tm1al = TempMatchTime & 0x00ff;	//
	_tm1ah = TempMatchTime >> 8;		//
#else	
	_tm1al = 1;	//
	_tm1ah = 0;		//
	_tm1rpl = TempMatchTime & 0x00ff;	//
	_tm1rph = TempMatchTime >> 8;
#endif	
}


/**
  * @brief PTM Capture Input config function,
  * Specify the following parameters in HT8_PTM.h, 
  *	Select Trigger Pin  
  * @param[in] None.
  * @retval None.
  */
void PTM_CaptureInputConfig()
{
/******** Select Trigger Pin function ********/	
	#ifdef	PTM_CAPTURE_TP1
		_ace6 = 0; _t1cp = 1; _t1capts = 0;	//
		_pac7 = 1; _papu7 = 1;
	
	#elif	PTM_CAPTURE_TCK1
		_ace3 = 0; _t1capts = 1;	//
		_pac4 = 1; _papu4 =1;
	#endif
/******** Select Trigger Pin function ********/	
}


#endif
