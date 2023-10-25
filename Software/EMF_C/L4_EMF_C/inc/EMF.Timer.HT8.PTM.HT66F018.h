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
#ifndef EMF_TIMER_HT8_PTM_HT66F018_H
#define EMF_TIMER_HT8_PTM_HT66F018_H


#define	PTM_ENABLE()			(_t1on = 1)
#define	PTM_DISABLE()			(_t1on = 0)
#define	PTM_CCRA_ISR_ENABLE()	(_t1ae = 1)
#define	PTM_CCRA_ISR_DISABLE()	(_t1ae = 0)
#define PTM_SET_FLAG_A()		(_t1af = 1)
#define PTM_CLEAR_FLAG_A()		(_t1af = 0)
#define	PTM_CCRP_ISR_ENABLE()	(_t1pe = 1)
#define	PTM_CCRP_ISR_DISABLE()	(_t1pe = 0)
#define PTM_SET_FLAG_P()		(_t1pf = 1)
#define PTM_CLEAR_FLAG_P()		(_t1pf = 0)
#define	PTM_PAUSE()				(_t1pau = 1)
#define	PTM_RUN()				(_t1pau = 0)
#define	PTM_GET_CCRA_FLAG()		_t1af
#define	PTM_GET_CCRP_FLAG()		_t1pf

#define PTM_RISING_EDGE() 		  	_t1io1 = 0; _t1io0 = 0	/* Input capture at rising edge */
#define PTM_FALLING_EDGE()		  	_t1io1 = 0; _t1io0 = 1 	/* Input capture at falling edge */
#define PTM_RISING_FALLING_EDGE() 	_t1io1 = 1; _t1io0 = 0 	/* Input capture at rising/falling edge */
#define PTM_CAPTURE_DISABLE()	  	_t1io1 = 1; _t1io0 = 1 	/* Input capture Disable */


/******** PTM work mode select ********/

//	#define	PTM_TIMER_COUNTER_MODE			1
//	#define	PTM_PWM_OUTPUT_MODE				1	
//	#define	PTM_COMPARE_MATCH_MODE			1
	#define	PTM_CAPTURE_INPUT_MODE			1
//	#define	PTM_SINGLE_PULSE_OUTPUT_MODE	1

/**** end of PTM work mode select *****/


/************* clock select **************/

	#define		PTM_FSYS_DIV4			1
//	#define		PTM_FSYS				1
//	#define		PTM_FH_DIV16			1
//	#define		PTM_FH_DIV64			1
//	#define		PTM_FTBC				1
//	#define		PTM_FH					1
//	#define		PTM_TCK_RISING_EDGE		1
//	#define		PTM_TCK_FALLING_EDGE	1

/********* end of clock select *********/
	
/** TMn Counter Clear condition selection **/
	
	#define		PTM_CCRA_MATCH			1
//	#define		PTM_CCRP_MATCH			1	

/* end of TMn Counter Clear condition selection */

	
/****** PWM OUTPUT MODE setting ******/
	
#ifdef	PTM_PWM_OUTPUT_MODE		
/* TP1 Output control */
//	#define		PTM_ACTIVE_LOW	 			1
	#define		PTM_ACTIVE_HIGH				1
/* end of TP1 Output control */
	
/***** TP1 Output polarity control *****/
	#define		PTM_NON_INVERTED			1
//	#define		PTM_INVERTED				1
/* end of TP1 Output polarity control */

#endif

/* end of PWM OUTPUT MODE setting */
///////////////////////////////////////////////////////


/****** SINGLE PULSE OUTPUT MODE setting ******/
		
#ifdef	PTM_SINGLE_PULSE_OUTPUT_MODE		
/* TP1 Output control */
//	#define		PTM_ACTIVE_LOW				1
	#define		PTM_ACTIVE_HIGH				1
/* end of TP1 Output control */
	
/***** TP1 Output polarity control *****/
	#define		PTM_NON_INVERTED			1
//	#define		PTM_INVERTED				1
/* end of TP1 Output polarity control */	

/***** TCK1 trigger control *****/
	#define		PTM_TCK1_TRIG_ENABLE		1
//	#define		PTM_TCK1_TRIG_DISABLE		1
/* end of TCK1 trigger control */		
#endif

/* end of SINGLE PULSE OUTPUT MODE setting */
//////////////////////////////////////////////////////


/* TIMER COUNTER MODE setting */

#ifdef	PTM_TIMER_COUNTER_MODE

	#define	PTM_GET_COUNTER_VALUE()	(_tm1dh<<8 | _tm1dl)

#endif
/* end of TIMER COUNTER MODE setting */

///////////////////////////////////////////////////////	


/* COMPARE MATCH MODE setting */

#ifdef	PTM_COMPARE_MATCH_MODE	
	/* Select TP1 pin output function */
//	#define		PTM_NO_CHANGE				1	/* No change */
//	#define		PTM_OUTPUT_LOW				1	/* Output low */
//	#define		PTM_OUTPUT_HIGH				1	/* Output high */
	#define		PTM_OUTPUT_TOGGLE			1	/* Toggle output */
/* end of Select TP1 pin output function */
	
/* TP1 Output initialization status control */
	#define		PTM_INITIAL_LOW				1	/* Initial low */
//	#define		PTM_INITIAL_HIGH			1	/* Initial high */
/* end of TP1 Output control */
	
/***** TP1 Output polarity control *****/
	#define		PTM_NON_INVERTED			1
//	#define		PTM_INVERTED				1
/* end of TP1 Output polarity control */	
#endif

/* end of COMPARE MATCH MODE setting */
//////////////////////////////////////////////////////


/* CAPTURE INPUT MODE setting */

#ifdef	PTM_CAPTURE_INPUT_MODE	
/* Select Trigger Pin function */
	#define		PTM_CAPTURE_TP1				1	/* From TPn pin */
//	#define		PTM_CAPTURE_TCK1			1	/* From TCKn pin */
/* end of Select Trigger Pin function */


/* GET CAPTURE VALUE function */
	#define	PTM_GET_CAPTURE_VALUE()	(_tm1ah<<8 | _tm1al)

#endif
/* end of CAPTURE INPUT MODE setting */
////////////////////////////////////////////



void PTM_Init(void);
void PTM_PwmOutputConfig(void);
void PTM_PwmUpdate(uint16 TempCCRA,uint16 TempCCRP);
void PTM_SinglePulseOutputConfig(void);
void PTM_SinglePulseUpdate(uint16 TempCCRA);
void PTM_CounterModeConfig(uint16 TempPeriod);
void PTM_CompareMatchOutputConfig();
void PTM_CompareMatchOutputUpdate(uint16 TempMatchTime);
void PTM_CaptureInputConfig();

#endif