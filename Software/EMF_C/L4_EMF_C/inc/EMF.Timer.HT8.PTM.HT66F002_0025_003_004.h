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
#ifndef EMF_TIMER_HT8_PTM_HT66F002_0025_003_004_H
#define EMF_TIMER_HT8_PTM_HT66F002_0025_003_004_H

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Config define
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
/*====================================== Select PTMn operating mode ========================================*/
//      #define PTM0_TIMER_COUNTER_MODE                 (1)
//      #define PTM0_PWM_OUTPUT_MODE                    (1)
     #define PTM0_COMPARE_MATCH_MODE                 (1)
//      #define PTM0_SINGLE_PULSE_OUTPUT_MODE           (1)

//      #define PTM1_TIMER_COUNTER_MODE                 (1)
//      #define PTM1_PWM_OUTPUT_MODE                    (1)
      #define PTM1_COMPARE_MATCH_MODE                 (1)
//      #define PTM1_SINGLE_PULSE_OUTPUT_MODE           (1)

/*================================= The end of Select PTMn operating mode ==================================*/

/*======================================= Select PTMn counter clock ========================================*/
      #define PTM0_FSYS_DIV4                          (1)
//      #define PTM0_FSYS                               (1)
//      #define PTM0_FH_DIV16                           (1)
//      #define PTM0_FH_DIV64                           (1)
//      #define PTM0_FSUB                               (1)
//      #define PTM0_TCK_RISING_EDGE                    (1)
//      #define PTM0_TCK_FALLING_EDGE                   (1)

      #define PTM1_FSYS_DIV4                          (1)
//      #define PTM1_FSYS                               (1)
//      #define PTM1_FH_DIV16                           (1)
//      #define PTM1_FH_DIV64                           (1)
//      #define PTM1_FSUB                               (1)
//      #define PTM1_TCK_RISING_EDGE                    (1)
//      #define PTM1_TCK_FALLING_EDGE                   (1)

/*================================= The end of Select PTMn counter clock ===================================*/

/*================================= Select PTMn counter clear condition ====================================*/
//      #define PTM0_CCRA_MATCH                         (1)
      #define PTM0_CCRP_MATCH                         (1)

//      #define PTM1_CCRA_MATCH                         (1)
      #define PTM1_CCRP_MATCH                         (1)

/*============================ The end of Select PTMn counter clear condition ==============================*/

/*======================================= PWM OUTPUT MODE setting ==========================================*/
#ifdef  PTM0_PWM_OUTPUT_MODE
        
        /* PTP0 output control */
        //      #define PTM0_ACTIVE_LOW                 (1)
        //      #define PTM0_ACTIVE_HIGH                (1)
        /* The end of PTP0 output control */
        
        /* PTP0 output polarity control */
        //      #define PTM0_NON_INVERTED               (1)
        //      #define PTM0_INVERTED                   (1)
        /* The end of PTP0 output polarity control */
#endif

#ifdef  PTM1_PWM_OUTPUT_MODE
        
        /* PTP1 output control */
        //      #define PTM1_ACTIVE_LOW                 (1)
        //      #define PTM1_ACTIVE_HIGH                (1)
        /* The end of PTP1 output control */
        
        /* PTP1 output polarity control */
        //      #define PTM1_NON_INVERTED               (1)
        //      #define PTM1_INVERTED                   (1)
        /* The end of PTP1 output polarity control */
#endif

/*================================== The end of PWM OUTPUT MODE setting ====================================*/

/*=================================== SINGLE PULSE OUTPUT MODE setting =====================================*/
#ifdef  PTM0_SINGLE_PULSE_OUTPUT_MODE
        
        /* PTP0 output control */
        //      #define PTM0_ACTIVE_LOW                 (1)
        //      #define PTM0_ACTIVE_HIGH                (1)
        /* The end of PTP0 output control */
        
        /* PTP0 output polarity control */
        //      #define PTM0_NON_INVERTED               (1)
        //      #define PTM0_INVERTED                   (1)
        /* The end of PTP0 output polarity control */
#endif

#ifdef  PTM1_SINGLE_PULSE_OUTPUT_MODE
        
        /* PTP1 output control */
        //      #define PTM1_ACTIVE_LOW                 (1)
        //      #define PTM1_ACTIVE_HIGH                (1)
        /* The end of PTP1 output control */
        
        /* PTP1 output polarity control */
        //      #define PTM1_NON_INVERTED               (1)
        //      #define PTM1_INVERTED                   (1)
        /* The end of PTP1 output polarity control */
#endif

/*============================= The end of SINGLE PULSE OUTPUT MODE setting ================================*/

/*====================================== TIMER COUNTER MODE setting ========================================*/
#ifdef  PTM0_TIMER_COUNTER_MODE
        
        #define PTM0_GET_COUNTER_VALUE()        (_ptm0dh<<8 | _ptm0dl)
#endif

#ifdef  PTM1_TIMER_COUNTER_MODE
        
        #define PTM1_GET_COUNTER_VALUE()        (_ptm1dh<<8 | _ptm1dl)
#endif

/*================================= The end of TIMER COUNTER MODE setting ==================================*/

/*====================================== COMPARE MATCH MODE setting ========================================*/
#ifdef  PTM0_COMPARE_MATCH_MODE
        
        /* Select PTM0 function in Compare match output mode */
        //      #define PTM0_NO_CHANGE                  (1)
        //      #define PTM0_OUTPUT_LOW                 (1)
        //      #define PTM0_OUTPUT_HIGH                (1)
              #define PTM0_OUTPUT_TOGGLE              (1)
        /* The end of Select PTMn function in Compare match output mode */
        
        /* PTP0 output control */
              #define PTM0_INITIAL_LOW                (1)
        //      #define PTM0_INITIAL_HIGH               (1)
        /* The end of PTP0 output control */
        
        /* PTP0 output polarity control */
              #define PTM0_NON_INVERTED               (1)
        //      #define PTM0_INVERTED                   (1)
        /* The end of PTP0 output polarity control */
#endif

#ifdef  PTM1_COMPARE_MATCH_MODE
        
        /* Select PTM1 function in Compare match output mode */
        //      #define PTM1_NO_CHANGE                  (1)
        //      #define PTM1_OUTPUT_LOW                 (1)
        //      #define PTM1_OUTPUT_HIGH                (1)
              #define PTM1_OUTPUT_TOGGLE              (1)
        /* The end of Select PTMn function in Compare match output mode */
        
        /* PTP1 output control */
              #define PTM1_INITIAL_LOW                (1)
        //      #define PTM1_INITIAL_HIGH               (1)
        /* The end of PTP1 output control */
        
        /* PTP1 output polarity control */
              #define PTM1_NON_INVERTED               (1)
        //      #define PTM1_INVERTED                   (1)
        /* The end of PTP1 output polarity control */
#endif

/*================================= The end of COMPARE MATCH MODE setting ==================================*/


//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Const define
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
#define PTM0_ENABLE()                   (_pt0on = 1)
#define PTM0_DISABLE()                  (_pt0on = 0)
#define PTM0_CCRA_ISR_ENABLE()          (_ptma0e = 1)
#define PTM0_CCRA_ISR_DISABLE()         (_ptma0e = 0)
#define PTM0_SET_CCRA_ISR_FLAG()        (_ptma0f = 1)
#define PTM0_CLEAR_CCRA_ISR_FLAG()      (_ptma0f = 0)
#define PTM0_CCRP_ISR_ENABLE()          (_ptmp0e = 1)
#define PTM0_CCRP_ISR_DISABLE()         (_ptmp0e = 0)
#define PTM0_SET_CCRP_ISR_FLAG()        (_ptmp0f = 1)
#define PTM0_CLEAR_CCRP_ISR_FLAG()      (_ptmp0f = 0)
#define PTM0_PAUSE()                    (_pt0pau = 1)
#define PTM0_RUN()                      (_pt0pau = 0)
#define PTM0_GET_CCRA_ISR_FLAG()        _ptma0f
#define PTM0_GET_CCRP_ISR_FLAG()        _ptmp0f

#define PTM1_ENABLE()                   (_pt1on = 1)
#define PTM1_DISABLE()                  (_pt1on = 0)
#define PTM1_CCRA_ISR_ENABLE()          (_ptma1e = 1)
#define PTM1_CCRA_ISR_DISABLE()         (_ptma1e = 0)
#define PTM1_SET_CCRA_ISR_FLAG()        (_ptma1f = 1)
#define PTM1_CLEAR_CCRA_ISR_FLAG()      (_ptma1f = 0)
#define PTM1_CCRP_ISR_ENABLE()          (_ptmp1e = 1)
#define PTM1_CCRP_ISR_DISABLE()         (_ptmp1e = 0)
#define PTM1_SET_CCRP_ISR_FLAG()        (_ptmp1f = 1)
#define PTM1_CLEAR_CCRP_ISR_FLAG()      (_ptmp1f = 0)
#define PTM1_PAUSE()                    (_pt1pau = 1)
#define PTM1_RUN()                      (_pt1pau = 0)
#define PTM1_GET_CCRA_ISR_FLAG()        _ptma1f
#define PTM1_GET_CCRP_ISR_FLAG()        _ptmp1f

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Functions
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
/**
 * @code Example PTM1 Compare Match Output
//Example in HT66F004
#include "EMF.h"
void main() {
    EMF_init();
    
    //Example Configs :
    //PTM1_COMPARE_MATCH_MODE
    //PTM1_FSYS_DIV4
    //PTM1_CCRP_MATCH (PTM1 counter clear condition)
    //PTM1_OUTPUT_TOGGLE
    //PTM1_INITIAL_LOW
    //PTM1_NON_INVERTED

    _pas7 = 0; _pas6 = 1; //Config A7 to "PTP1 output"(PTM1 CompareMatch Output)[Read Datasheet "Input/Output Ports">"Pin-shared Functions"] 
    PTM1_Init();
    PTM1_CompareMatchOutputConfig();
    PTM1_ENABLE();
    PTM1_CompareMatchAUpdate(500);
    PTM1_CompareMatchPUpdate(1000);
    while(1);
}
* @endcode
 * @code Example PTM1 Compare Match A Intrrupt
// Example in HT66F004
#include "EMF.h"

// Go to HT66F004 Datasheet>Interrupt>Interrupt Operation>Interrupt Structure – HT66F004
DEFINE_ISR(PtmComparematch, 0x10) {
    PTM1_CLEAR_CCRA_ISR_FLAG(); //Clear PTM1.ComperMatchA Intrrupt Flag
    _pa7 = !_pa7; //Toggle Pa7 Output Value
}

void main() {
    EMF_init();

    _pa7 = 0; //PA7 Output Value = 0
    _pac7 = 0;  // Config PA7 = Output

    // Example Configs :
    // PTM1_COMPARE_MATCH_MODE
    // PTM1_FSYS_DIV4
    // PTM1_CCRP_MATCH (PTM1 counter clear condition = CompareMatch P)
    // PTM1_NO_CHANGE


    PTM1_Init();
    PTM1_CompareMatchOutputConfig();
    PTM1_ENABLE();
    PTM1_CompareMatchAUpdate(500);
    PTM1_CompareMatchPUpdate(1000);
    _emi = 1; //Enable Global interrupt
    _mf0e = 1; //Enable Multi Function0 interrupt
    PTM1_CCRA_ISR_ENABLE(); //Enable PTM1.ComperMatchA intrrupt

    while (1);
}
* @endcode
*/
void PTM0_Init(void);
void PTM0_PwmOutputConfig(void);
void PTM0_PwmUpdate(uint16 TempCCRA,uint16 TempCCRP);
void PTM0_SinglePulseOutputConfig(void);
void PTM0_SinglePulseUpdate(uint16 TempCCRA);
void PTM0_CounterModeConfig(uint16 TempPeriod);
void PTM0_CompareMatchOutputConfig(void);
void PTM0_CompareMatchAUpdate(uint16 TempMatchTime);
void PTM0_CompareMatchPUpdate(uint16 TempMatchTime);

void PTM1_Init(void);
void PTM1_PwmOutputConfig(void);
void PTM1_PwmUpdate(uint16 TempCCRA,uint16 TempCCRP);
void PTM1_SinglePulseOutputConfig(void);
void PTM1_SinglePulseUpdate(uint16 TempCCRA);
void PTM1_CounterModeConfig(uint16 TempPeriod);
void PTM1_CompareMatchOutputConfig(void);
void PTM1_CompareMatchAUpdate(uint16 TempMatchTime);
void PTM1_CompareMatchPUpdate(uint16 TempMatchTime);


#endif