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
#if defined(EMF_TIMER_HT8_PTM_HT66F002_0025_003_004_H)
/************************************************************************************************************
 * @brief      PTM0 initialization function.
 * @param      None
 * @retval     None
 ***********************************************************************************************************/
void PTM0_Init(void) {
    /*====================================== Select PTM0 operating mode ========================================*/
    #ifdef PTM0_TIMER_COUNTER_MODE
    _pt0m1 = 1;
    _pt0m0 = 1;  // Select PTM0 timer/counter Mode

    #elif PTM0_PWM_OUTPUT_MODE
    _pt0m1 = 1;
    _pt0m0 = 0;
    _pt0io1 = 1;
    _pt0io0 = 0;  // Select PTM0 PWM Output Mode

    #elif PTM0_SINGLE_PULSE_OUTPUT_MODE
    _pt0m1 = 1;
    _pt0m0 = 0;
    _pt0io1 = 1;
    _pt0io0 = 1;  // Select PTM0 Single Pulse Output Mode

    #elif PTM0_COMPARE_MATCH_MODE
    _pt0m1 = 0;
    _pt0m0 = 0;  // Select PTM0 Compare Match Output Mode
    #else
        #error "Please Select PTM0 Operating mode Config"
    #endif
    /*================================= The end of Select PTM0 operating mode ==================================*/

    /*======================================= Select PTM0 counter clock ========================================*/
    #ifdef PTM0_FSYS_DIV4
    _pt0ck2 = 0;
    _pt0ck1 = 0;
    _pt0ck0 = 0;  // Select PTM0 Counter clock Fsys/4

    #elif PTM0_FSYS
    _pt0ck2 = 0;
    _pt0ck1 = 0;
    _pt0ck0 = 1;   // Select PTM0 Counter clock Fsys

    #elif PTM0_FH_DIV16
    _pt0ck2 = 0;
    _pt0ck1 = 1;
    _pt0ck0 = 0;  // Select PTM0 Counter clock FH/16

    #elif PTM0_FH_DIV64
    _pt0ck2 = 0;
    _pt0ck1 = 1;
    _pt0ck0 = 1;  // Select PTM0 Counter clock FH/64

    #elif PTM0_FSUB
    _pt0ck2 = 1;
    _pt0ck1 = 0;
    _pt0ck0 = 0;  // Select PTM0 Counter clock Fsub

    #elif PTM0_TCK_RISING_EDGE
    _pt0ck2 = 1;
    _pt0ck1 = 1;
    _pt0ck0 = 0;  // Select PTM0 Counter clock TCKn rising edge clock

    #elif PTM0_TCK_FALLING_EDGE
    _pt0ck2 = 1;
    _pt0ck1 = 1;
    _pt0ck0 = 1;  // Select PTM0 Counter clock TCKn falling edge clock
    #else
        #error "Please Select PTM0 counter clock Config"
    #endif
    /*================================= The end of Select PTM0 counter clock ===================================*/

    /*================================= Select PTM0 counter clear condition ====================================*/
    #ifdef PTM0_CCRA_MATCH
    _pt0cclr = 1;  // PTM0 Counter Clear condition selection PTM0 Comparator A match

    #elif PTM0_CCRP_MATCH
    _pt0cclr = 0;  // PTM0 Counter Clear condition selection PTM0 Comparator P match
    #else
        #error "Please Select PTM0 counter clear condition Config"
    #endif
    /*============================ The end of Select PTM0 counter clear condition ==============================*/
}

/************************************************************************************************************
 * @brief      PTM0 PWM configure function.
 *             Specify the following parameters in HT8_PTM.h:
 *                1. PTP0 output control
 *                2. PTP0 output polarity control
 * @param      None
 * @retval     None
 ***********************************************************************************************************/
void PTM0_PwmOutputConfig(void) {
    /*========================================= PTP0 output control ============================================*/
    #ifdef PTM0_ACTIVE_LOW
    _pt0oc = 0;  // Active low

    #elif PTM0_ACTIVE_HIGH
    _pt0oc = 1;    // Active high

    #endif
    /*==================================== The end of PTP0 output control ======================================*/

    /*===================================== PTP0 output polarity control =======================================*/
    #ifdef PTM0_NON_INVERTED
    _pt0pol = 0;  // No inverted

    #elif PTM0_INVERTED
    _pt0pol = 1;   // Inverted

    #endif
    /*=============================== The end of PTP0 output polarity control ==================================*/
}

/************************************************************************************************************
 * @brief      PTM0 PWM update function.
 * @param      TempCCRA: CCRA value
 *             the TempCCRA value range is 1 ~ 1023.
 * @param      TempCCRP: CCRP value
 *             the TempCCRP value range is 0 ~ 1023:
 *                [1].when TempCCRP = 0, the PWM Duty = TempCCRA / 1024
 *                [2].when TempCCRP > 0, the PWM Duty = TempCCRA / TempCCRP
 * @retval     None
 ***********************************************************************************************************/
void PTM0_PwmUpdate(uint16 TempCCRA, uint16 TempCCRP) {
    _ptm0al = TempCCRA & 0x00ff;
    _ptm0ah = TempCCRA >> 8;
    _ptm0rpl = TempCCRP & 0x00ff;
    _ptm0rph = TempCCRP >> 8;
}

/************************************************************************************************************
 * @brief      PTM0 SinglePulse configure function.
 *             Specify the following parameters in HT8_PTM.h:
 *                1. PTP0 output control
 *                2. PTP0 output polarity control
 *                3. PTCK0 trigger control
 * @param      None
 * @retval     None
 ***********************************************************************************************************/
void PTM0_SinglePulseOutputConfig(void) {
    /*========================================= PTP0 output control ============================================*/
    #ifdef PTM0_ACTIVE_LOW
    _pt0oc = 0;  // Active low

    #elif PTM0_ACTIVE_HIGH
    _pt0oc = 1;    // Active high

    #endif
    /*==================================== The end of PTP0 output control ======================================*/

    /*===================================== PTP0 output polarity control =======================================*/
    #ifdef PTM0_NON_INVERTED
    _pt0pol = 0;  // No inverted

    #elif PTM0_INVERTED
    _pt0pol = 1;   // Inverted

    #endif
    /*=============================== The end of PTP0 output polarity control ==================================*/
}

/************************************************************************************************************
 * @brief      PTM0 SinglePulse update function.
 * @param      TempCCRA: CCRA value
 *             the TempCCRA value range is 1 ~ 1023, the pulse width = TempCCRA * Tclock.
 * @retval     None
 ***********************************************************************************************************/
void PTM0_SinglePulseUpdate(uint16 TempCCRA) {
    _ptm0al = TempCCRA & 0x00ff;
    _ptm0ah = TempCCRA >> 8;
}

/************************************************************************************************************
 * @brief      PTM0 timer/counter mode period config function.
 * @param      TempPeriod: Period value
 *             1. if select CCRA_MATCH, the TempPeriod value range is 1 ~ 1023, the overflow time = TempPeriod * Tclock.
 *             2. if select CCRP_MATCH, the TempPeriod value range is 0 ~ 1023:
 *                [1].when TempPeriod = 0, the overflow time = 1024 * Tclock
 *                [2].when TempPeriod > 0, the overflow time = TempPeriod * Tclock
 * @retval     None
 ***********************************************************************************************************/
void PTM0_CounterModeConfig(uint16 TempPeriod) {
    #ifdef PTM0_CCRA_MATCH
    _ptm0al = TempPeriod & 0x00ff;
    _ptm0ah = TempPeriod >> 8;

    #elif PTM0_CCRP_MATCH
    _ptm0rpl = TempPeriod & 0x00ff;
    _ptm0rph = TempPeriod >> 8;
    #else
        #error "Please Select PTM0 CounterMatch Mode Config"
    #endif
}

/************************************************************************************************************
 * @brief      PTM0 compare match output config function.
 *             Specify the following parameters in HT8_PTM.h:
 *             1. Select PTM0 function in Compare match output mode
 *             2. PTP0 output control
 *             3. PTP0 output polarity control
 * @param      None
 * @retval     None
 ***********************************************************************************************************/
void PTM0_CompareMatchOutputConfig(void) {
    /*=========================== Select PTM0 function in Compare match output mode ============================*/
    #ifdef PTM0_NO_CHANGE
    _pt0io1 = 0;
    _pt0io0 = 0;

    #elif PTM0_OUTPUT_LOW
    _pt0io1 = 0;
    _pt0io0 = 1;

    #elif PTM0_OUTPUT_HIGH
    _pt0io1 = 1;
    _pt0io0 = 0;

    #elif PTM0_OUTPUT_TOGGLE
    _pt0io1 = 1;
    _pt0io0 = 1;
    #else
        #error "Please Select PTM0 Compare Match Output Mode Config"
    #endif
    /*===================== The end of Select PTM0 function in Compare match output mode =======================*/

    /*========================================= PTP0 output control ============================================*/
    #ifdef PTM0_INITIAL_LOW
    _pt0oc = 0;

    #elif PTM0_INITIAL_HIGH
    _pt0oc = 1;

    #endif
    /*==================================== The end of PTP0 output control ======================================*/

    /*===================================== PTP0 output polarity control =======================================*/
    #ifdef PTM0_NON_INVERTED
    _pt0pol = 0;

    #elif PTM0_INVERTED
    _pt0pol = 1;

    #endif
    /*=============================== The end of PTP0 output polarity control ==================================*/
}

/************************************************************************************************************
 * @brief      PTM0 compare match output update function.
 * @param      TempMatchTime: MatchTime value
 *             1. if select CCRA_MATCH, the TempMatchTime value range is 1 ~ 1023, the match time = TempMatchTime * Tclock.
 *             2. if select CCRP_MATCH, the TempMatchTime value range is 0 ~ 1023:
 *                [1]. when TempMatchTime = 0, the match time = 1024 * Tclock
 *                [2]. when TempMatchTime > 0, the match time = TempMatchTime * Tclock
 * @retval     None
 ***********************************************************************************************************/
void PTM0_CompareMatchAUpdate(uint16 TempMatchTime) {
    _ptm0al = TempMatchTime & 0x00ff;
    _ptm0ah = TempMatchTime >> 8;
}

void PTM0_CompareMatchPUpdate(uint16 TempMatchTime) {
    _ptm0rpl = TempMatchTime & 0x00ff;
    _ptm0rph = TempMatchTime >> 8;
}
/************************************************************************************************************
 * @brief      PTM1 initialization function.
 * @param      None
 * @retval     None
 ***********************************************************************************************************/
void PTM1_Init(void) {
    /*====================================== Select PTM1 operating mode ========================================*/
    #ifdef PTM1_TIMER_COUNTER_MODE
    _pt1m1 = 1;
    _pt1m0 = 1;  // Select PTM1 timer/counter Mode

    #elif PTM1_PWM_OUTPUT_MODE
    _pt1m1 = 1;
    _pt1m0 = 0;
    _pt1io1 = 1;
    _pt1io0 = 0;  // Select PTM1 PWM Output Mode

    #elif PTM1_SINGLE_PULSE_OUTPUT_MODE
    _pt1m1 = 1;
    _pt1m0 = 0;
    _pt1io1 = 1;
    _pt1io0 = 1;  // Select PTM1 Single Pulse Output Mode

    #elif PTM1_COMPARE_MATCH_MODE
    _pt1m1 = 0;
    _pt1m0 = 0;  // Select PTM1 Compare Match Output Mode
    #else
        #error "Please Select PTM1 Operating mode Config"
    #endif
    /*================================= The end of Select PTM1 operating mode ==================================*/

    /*======================================= Select PTM1 counter clock ========================================*/
    #ifdef PTM1_FSYS_DIV4
    _pt1ck2 = 0;
    _pt1ck1 = 0;
    _pt1ck0 = 0;  // Select PTM1 Counter clock Fsys/4

    #elif PTM1_FSYS
    _pt1ck2 = 0;
    _pt1ck1 = 0;
    _pt1ck0 = 1;   // Select PTM1 Counter clock Fsys

    #elif PTM1_FH_DIV16
    _pt1ck2 = 0;
    _pt1ck1 = 1;
    _pt1ck0 = 0;  // Select PTM1 Counter clock FH/16

    #elif PTM1_FH_DIV64
    _pt1ck2 = 0;
    _pt1ck1 = 1;
    _pt1ck0 = 1;  // Select PTM1 Counter clock FH/64

    #elif PTM1_FSUB
    _pt1ck2 = 1;
    _pt1ck1 = 0;
    _pt1ck0 = 0;  // Select PTM1 Counter clock Fsub

    #elif PTM1_TCK_RISING_EDGE
    _pt1ck2 = 1;
    _pt1ck1 = 1;
    _pt1ck0 = 0;  // Select PTM1 Counter clock TCKn rising edge clock

    #elif PTM1_TCK_FALLING_EDGE
    _pt1ck2 = 1;
    _pt1ck1 = 1;
    _pt1ck0 = 1;  // Select PTM1 Counter clock TCKn falling edge clock
    #else
        #error "Please Select PTM1 counter clock Config"
    #endif
    /*================================= The end of Select PTM1 counter clock ===================================*/

    /*================================= Select PTM1 counter clear condition ====================================*/
    #ifdef PTM1_CCRA_MATCH
    _pt1cclr = 1;  // PTM1 Counter Clear condition selection PTM1 Comparator A match

    #elif PTM1_CCRP_MATCH
    _pt1cclr = 0;  // PTM1 Counter Clear condition selection PTM1 Comparator P match
    #else
        #error "Please Select PTM1 counter clear condition Config"
    #endif
    /*============================ The end of Select PTM1 counter clear condition ==============================*/
}

/************************************************************************************************************
 * @brief      PTM1 PWM configure function.
 *             Specify the following parameters in HT8_PTM.h:
 *                1. PTP1 output control
 *                2. PTP1 output polarity control
 * @param      None
 * @retval     None
 ***********************************************************************************************************/
void PTM1_PwmOutputConfig(void) {
    /*========================================= PTP1 output control ============================================*/
    #ifdef PTM1_ACTIVE_LOW
    _pt1oc = 0;  // Active low

    #elif PTM1_ACTIVE_HIGH
    _pt1oc = 1;    // Active high

    #endif
    /*==================================== The end of PTP1 output control ======================================*/

    /*===================================== PTP1 output polarity control =======================================*/
    #ifdef PTM1_NON_INVERTED
    _pt1pol = 0;  // No inverted

    #elif PTM1_INVERTED
    _pt1pol = 1;   // Inverted

    #endif
    /*=============================== The end of PTP1 output polarity control ==================================*/
}

/************************************************************************************************************
 * @brief      PTM1 PWM update function.
 * @param      TempCCRA: CCRA value
 *             the TempCCRA value range is 1 ~ 1023.
 * @param      TempCCRP: CCRP value
 *             the TempCCRP value range is 0 ~ 1023:
 *                [1].when TempCCRP = 0, the PWM Duty = TempCCRA / 1024
 *                [2].when TempCCRP > 0, the PWM Duty = TempCCRA / TempCCRP
 * @retval     None
 ***********************************************************************************************************/
void PTM1_PwmUpdate(uint16 TempCCRA, uint16 TempCCRP) {
    _ptm1al = TempCCRA & 0x00ff;
    _ptm1ah = TempCCRA >> 8;
    _ptm1rpl = TempCCRP & 0x00ff;
    _ptm1rph = TempCCRP >> 8;
}

/************************************************************************************************************
 * @brief      PTM1 SinglePulse configure function.
 *             Specify the following parameters in HT8_PTM.h:
 *                1. PTP1 output control
 *                2. PTP1 output polarity control
 *                3. PTCK1 trigger control
 * @param      None
 * @retval     None
 ***********************************************************************************************************/
void PTM1_SinglePulseOutputConfig(void) {
    /*========================================= PTP1 output control ============================================*/
    #ifdef PTM1_ACTIVE_LOW
    _pt1oc = 0;  // Active low

    #elif PTM1_ACTIVE_HIGH
    _pt1oc = 1;    // Active high

    #endif
    /*==================================== The end of PTP1 output control ======================================*/

    /*===================================== PTP1 output polarity control =======================================*/
    #ifdef PTM1_NON_INVERTED
    _pt1pol = 0;  // No inverted

    #elif PTM1_INVERTED
    _pt1pol = 1;   // Inverted

    #endif
    /*=============================== The end of PTP1 output polarity control ==================================*/
}

/************************************************************************************************************
 * @brief      PTM1 SinglePulse update function.
 * @param      TempCCRA: CCRA value
 *             the TempCCRA value range is 1 ~ 1023, the pulse width = TempCCRA * Tclock.
 * @retval     None
 ***********************************************************************************************************/
void PTM1_SinglePulseUpdate(uint16 TempCCRA) {
    _ptm1al = TempCCRA & 0x00ff;
    _ptm1ah = TempCCRA >> 8;
}

/************************************************************************************************************
 * @brief      PTM1 timer/counter mode period config function.
 * @param      TempPeriod: Period value
 *             1. if select CCRA_MATCH, the TempPeriod value range is 1 ~ 1023, the overflow time = TempPeriod * Tclock.
 *             2. if select CCRP_MATCH, the TempPeriod value range is 0 ~ 1023:
 *                [1].when TempPeriod = 0, the overflow time = 1024 * Tclock
 *                [2].when TempPeriod > 0, the overflow time = TempPeriod * Tclock
 * @retval     None
 ***********************************************************************************************************/
void PTM1_CounterModeConfig(uint16 TempPeriod) {
    #ifdef PTM1_CCRA_MATCH
    _ptm1al = TempPeriod & 0x00ff;
    _ptm1ah = TempPeriod >> 8;

    #elif PTM1_CCRP_MATCH
    _ptm1rpl = TempPeriod & 0x00ff;
    _ptm1rph = TempPeriod >> 8;
    #else
        #error "Please Select PTM1 CounterMatch Mode Config"
    #endif
}

/************************************************************************************************************
 * @brief      PTM1 compare match output config function.
 *             Specify the following parameters in HT8_PTM.h:
 *             1. Select PTM1 function in Compare match output mode
 *             2. PTP1 output control
 *             3. PTP1 output polarity control
 * @param      None
 * @retval     None
 ***********************************************************************************************************/
void PTM1_CompareMatchOutputConfig(void) {
    /*=========================== Select PTM1 function in Compare match output mode ============================*/
    #ifdef PTM1_NO_CHANGE
    _pt1io1 = 0;
    _pt1io0 = 0;

    #elif PTM1_OUTPUT_LOW
    _pt1io1 = 0;
    _pt1io0 = 1;

    #elif PTM1_OUTPUT_HIGH
    _pt1io1 = 1;
    _pt1io0 = 0;

    #elif PTM1_OUTPUT_TOGGLE
    _pt1io1 = 1;
    _pt1io0 = 1;
    #else
        #error "Please Select PTM1 Compare Match Output Mode Config"
    #endif
    /*===================== The end of Select PTM1 function in Compare match output mode =======================*/

    /*========================================= PTP1 output control ============================================*/
    #ifdef PTM1_INITIAL_LOW
    _pt1oc = 0;

    #elif PTM1_INITIAL_HIGH
    _pt1oc = 1;

    #endif
    /*==================================== The end of PTP1 output control ======================================*/

    /*===================================== PTP1 output polarity control =======================================*/
    #ifdef PTM1_NON_INVERTED
    _pt1pol = 0;

    #elif PTM1_INVERTED
    _pt1pol = 1;

    #endif
    /*=============================== The end of PTP1 output polarity control ==================================*/
}

/************************************************************************************************************
 * @brief      PTM1 compare match output update function.
 * @param      TempMatchTime: MatchTime value
 *             1. if select CCRA_MATCH, the TempMatchTime value range is 1 ~ 1023, the match time = TempMatchTime * Tclock.
 *             2. if select CCRP_MATCH, the TempMatchTime value range is 0 ~ 1023:
 *                [1]. when TempMatchTime = 0, the match time = 1024 * Tclock
 *                [2]. when TempMatchTime > 0, the match time = TempMatchTime * Tclock
 * @retval     None
 ***********************************************************************************************************/
void PTM1_CompareMatchAUpdate(uint16 TempMatchTime){
    _ptm1al = TempMatchTime & 0x00ff;
    _ptm1ah = TempMatchTime >> 8;
}

void PTM1_CompareMatchPUpdate(uint16 TempMatchTime){
    _ptm1rpl = TempMatchTime & 0x00ff;
    _ptm1rph = TempMatchTime >> 8;
}
#endif
