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
#include "EMF.h"
#include <stdio.h>
#if defined(EMF_TIMER_IAR__HAL__F0__STM32F030X6_H)

void EMF::Timer::Timer_RegisterClockOnOff(TIM_TypeDef *Timerx_Ptr__Ex_TIM1,
                                          bool Timerx_Clock_1On0Off) {
    switch ((uint32)Timerx_Ptr__Ex_TIM1) {
    #ifdef TIM1
        case (uint32)TIM1:
            if (Timerx_Clock_1On0Off) {
                __HAL_RCC_TIM1_CLK_ENABLE();
            } else {
                __HAL_RCC_TIM1_CLK_DISABLE();
            }
            break;
    #endif

    #ifdef TIM2
        case (uint32)TIM2:
            if (Timerx_Clock_1On0Off) {
                __HAL_RCC_TIM2_CLK_ENABLE();
            } else {
                __HAL_RCC_TIM2_CLK_DISABLE();
            }
            break;
    #endif

    #ifdef TIM3
        case (uint32)TIM3:
            if (Timerx_Clock_1On0Off) {
                __HAL_RCC_TIM3_CLK_ENABLE();
            } else {
                __HAL_RCC_TIM3_CLK_DISABLE();
            }
            break;
    #endif

    #ifdef TIM4
        case (uint32)TIM4:
            if (Timerx_Clock_1On0Off) {
                __HAL_RCC_TIM4_CLK_ENABLE();
            } else {
                __HAL_RCC_TIM4_CLK_DISABLE();
            }
            break;
    #endif

    #ifdef TIM5
        case (uint32)TIM5:
            if (Timerx_Clock_1On0Off) {
                __HAL_RCC_TIM5_CLK_ENABLE();
            } else {
                __HAL_RCC_TIM5_CLK_DISABLE();
            }
            break;
    #endif

    #ifdef TIM6
        case (uint32)TIM6:
            if (Timerx_Clock_1On0Off) {
                __HAL_RCC_TIM6_CLK_ENABLE();
            } else {
                __HAL_RCC_TIM6_CLK_DISABLE();
            }
            break;
    #endif

    #ifdef TIM7
        case (uint32)TIM7:
            if (Timerx_Clock_1On0Off) {
                __HAL_RCC_TIM7_CLK_ENABLE();
            } else {
                __HAL_RCC_TIM7_CLK_DISABLE();
            }
            break;
    #endif

    #ifdef TIM8
        case (uint32)TIM8:
            if (Timerx_Clock_1On0Off) {
                __HAL_RCC_TIM8_CLK_ENABLE();
            } else {
                __HAL_RCC_TIM8_CLK_DISABLE();
            }
            break;
    #endif

    #ifdef TIM9
        case (uint32)TIM9:
            if (Timerx_Clock_1On0Off) {
                __HAL_RCC_TIM9_CLK_ENABLE();
            } else {
                __HAL_RCC_TIM9_CLK_DISABLE();
            }
            break;
    #endif

    #ifdef TIM10
        case (uint32)TIM10:
            if (Timerx_Clock_1On0Off) {
                __HAL_RCC_TIM10_CLK_ENABLE();
            } else {
                __HAL_RCC_TIM10_CLK_DISABLE();
            }
            break;
    #endif

    #ifdef TIM11
        case (uint32)TIM11:
            if (Timerx_Clock_1On0Off) {
                __HAL_RCC_TIM11_CLK_ENABLE();
            } else {
                __HAL_RCC_TIM11_CLK_DISABLE();
            }
            break;
    #endif

    #ifdef TIM12
        case (uint32)TIM12:
            if (Timerx_Clock_1On0Off) {
                __HAL_RCC_TIM12_CLK_ENABLE();
            } else {
                __HAL_RCC_TIM12_CLK_DISABLE();
            }
            break;
    #endif

    #ifdef TIM13
        case (uint32)TIM13:
            if (Timerx_Clock_1On0Off) {
                __HAL_RCC_TIM13_CLK_ENABLE();
            } else {
                __HAL_RCC_TIM13_CLK_DISABLE();
            }
            break;
    #endif

    #ifdef TIM14
        case (uint32)TIM14:
            if (Timerx_Clock_1On0Off) {
                __HAL_RCC_TIM14_CLK_ENABLE();
            } else {
                __HAL_RCC_TIM14_CLK_DISABLE();
            }
            break;
    #endif

    #ifdef TIM15
        case (uint32)TIM15:
            if (Timerx_Clock_1On0Off) {
                __HAL_RCC_TIM15_CLK_ENABLE();
            } else {
                __HAL_RCC_TIM15_CLK_DISABLE();
            }
            break;
    #endif

    #ifdef TIM16
        case (uint32)TIM16:
            if (Timerx_Clock_1On0Off) {
                __HAL_RCC_TIM16_CLK_ENABLE();
            } else {
                __HAL_RCC_TIM16_CLK_DISABLE();
            }
            break;
    #endif

    #ifdef TIM17
        case (uint32)TIM17:
            if (Timerx_Clock_1On0Off) {
                __HAL_RCC_TIM17_CLK_ENABLE();
            } else {
                __HAL_RCC_TIM17_CLK_DISABLE();
            }
            break;
    #endif

    #ifdef TIM18
        case (uint32)TIM18:
            if (Timerx_Clock_1On0Off) {
                __HAL_RCC_TIM18_CLK_ENABLE();
            } else {
                __HAL_RCC_TIM18_CLK_DISABLE();
            }
            break;
    #endif

    #ifdef TIM19
        case (uint32)TIM19:
            if (Timerx_Clock_1On0Off) {
                __HAL_RCC_TIM19_CLK_ENABLE();
            } else {
                __HAL_RCC_TIM19_CLK_DISABLE();
            }
            break;
    #endif

    #ifdef TIM20
        case (uint32)TIM20:
            if (Timerx_Clock_1On0Off) {
                __HAL_RCC_TIM20_CLK_ENABLE();
            } else {
                __HAL_RCC_TIM20_CLK_DISABLE();
            }
            break;
    #endif

    #ifdef TIM21
        case (uint32)TIM21:
            if (Timerx_Clock_1On0Off) {
                __HAL_RCC_TIM21_CLK_ENABLE();
            } else {
                __HAL_RCC_TIM21_CLK_DISABLE();
            }
            break;
    #endif

    #ifdef TIM22
        case (uint32)TIM22:
            if (Timerx_Clock_1On0Off) {
                __HAL_RCC_TIM22_CLK_ENABLE();
            } else {
                __HAL_RCC_TIM22_CLK_DISABLE();
            }
            break;
    #endif

    #ifdef TIM23
        case (uint32)TIM23:
            if (Timerx_Clock_1On0Off) {
                __HAL_RCC_TIM23_CLK_ENABLE();
            } else {
                __HAL_RCC_TIM23_CLK_DISABLE();
            }
            break;
    #endif

    #ifdef TIM24
        case (uint32)TIM24:
            if (Timerx_Clock_1On0Off) {
                __HAL_RCC_TIM24_CLK_ENABLE();
            } else {
                __HAL_RCC_TIM24_CLK_DISABLE();
            }
            break;
    #endif

    #ifdef TIM25
        case (uint32)TIM25:
            if (Timerx_Clock_1On0Off) {
                __HAL_RCC_TIM25_CLK_ENABLE();
            } else {
                __HAL_RCC_TIM25_CLK_DISABLE();
            }
            break;
    #endif

    #ifdef TIM26
        case (uint32)TIM26:
            if (Timerx_Clock_1On0Off) {
                __HAL_RCC_TIM26_CLK_ENABLE();
            } else {
                __HAL_RCC_TIM26_CLK_DISABLE();
            }
            break;
    #endif

    #ifdef TIM27
        case (uint32)TIM27:
            if (Timerx_Clock_1On0Off) {
                __HAL_RCC_TIM27_CLK_ENABLE();
            } else {
                __HAL_RCC_TIM27_CLK_DISABLE();
            }
            break;
    #endif

    #ifdef TIM28
        case (uint32)TIM28:
            if (Timerx_Clock_1On0Off) {
                __HAL_RCC_TIM28_CLK_ENABLE();
            } else {
                __HAL_RCC_TIM28_CLK_DISABLE();
            }
            break;
    #endif

    #ifdef TIM29
        case (uint32)TIM29:
            if (Timerx_Clock_1On0Off) {
                __HAL_RCC_TIM29_CLK_ENABLE();
            } else {
                __HAL_RCC_TIM29_CLK_DISABLE();
            }
            break;
    #endif

    #ifdef TIM30
        case (uint32)TIM30:
            if (Timerx_Clock_1On0Off) {
                __HAL_RCC_TIM30_CLK_ENABLE();
            } else {
                __HAL_RCC_TIM30_CLK_DISABLE();
            }
            break;
    #endif

    }  // switch
}
//=========================================================================================
//=========================================================================================
uint32 _Get_APB1TimerxClock_HZ() {
    uint32 a = HAL_RCC_GetPCLK1Freq();
    #ifdef RCC_CFGR_PPRE
    /* Get PCLK1 prescaler */
    if ((RCC->CFGR & RCC_CFGR_PPRE) == 0) {
        /* PCLK1 prescaler equal to 1 => TIMCLK = PCLK1 */
        return (a);
    } else {
        /* PCLK1 prescaler different from 1 => TIMCLK = 2 * PCLK1 */
        return (2 * a);
    }
    #endif

    #ifdef RCC_CFGR_PPRE1
    /* Get PCLK1 prescaler */
    if ((RCC->CFGR & RCC_CFGR_PPRE1) == 0) {
        /* PCLK1 prescaler equal to 1 => TIMCLK = PCLK1 */
        return (PCLK1_Frequency);
    } else {
        /* PCLK1 prescaler different from 1 => TIMCLK = 2 * PCLK1 */
        return (2 * PCLK1_Frequency);
    }
    #endif
}
//=========================================================================================
//=========================================================================================
uint32 _Get_APB2TimerxClock_HZ() {
    #ifdef RCC_CFGR_PPRE2
        uint32 a = HAL_RCC_GetPCLK2Freq();
        /* Get PCLK1 prescaler */
        if ((RCC->CFGR & RCC_CFGR_PPRE2) == 0) {
            /* PCLK2 prescaler equal to 1 => TIMCLK = PCLK2 */
            return (a);
        } else {
            /* PCLK2 prescaler different from 1 => TIMCLK = 2 * PCLK2 */
            return (2 * a);
        }
    #else
        return  _Get_APB1TimerxClock_HZ();
    #endif
}
//=========================================================================================
//=========================================================================================
uint32 EMF::Timer::Get_APBxTimerClock_HZ(TIM_TypeDef *Timerx_Ptr__Ex_TIM1) {
    #ifdef TIM1
        if(Timerx_Ptr__Ex_TIM1 == TIM1){ 
            #ifdef RCC_APB1ENR_TIM1EN
                return _Get_APB1TimerxClock_HZ(); 
            #elif RCC_APB2ENR_TIM1EN  
                return _Get_APB2TimerxClock_HZ(); 
            #endif           
        } 
    #endif

    #ifdef TIM2
        if(Timerx_Ptr__Ex_TIM1 == TIM2){ 
            #ifdef RCC_APB1ENR_TIM2EN
                return _Get_APB1TimerxClock_HZ(); 
            #elif RCC_APB2ENR_TIM2EN  
                return _Get_APB2TimerxClock_HZ(); 
            #endif           
        } 
    #endif
    
    #ifdef TIM3
        if(Timerx_Ptr__Ex_TIM1 == TIM3){ 
            #ifdef RCC_APB1ENR_TIM3EN
                return _Get_APB1TimerxClock_HZ(); 
            #elif RCC_APB2ENR_TIM3EN  
                return _Get_APB2TimerxClock_HZ(); 
            #endif           
        } 
    #endif

    
    #ifdef TIM4
        if(Timerx_Ptr__Ex_TIM1 == TIM4){ 
            #ifdef RCC_APB1ENR_TIM4EN
                return _Get_APB1TimerxClock_HZ(); 
            #elif RCC_APB2ENR_TIM4EN  
                return _Get_APB2TimerxClock_HZ(); 
            #endif           
        } 
    #endif

    
    #ifdef TIM5
        if(Timerx_Ptr__Ex_TIM1 == TIM5){ 
            #ifdef RCC_APB1ENR_TIM5EN
                return _Get_APB1TimerxClock_HZ(); 
            #elif RCC_APB2ENR_TIM5EN  
                return _Get_APB2TimerxClock_HZ(); 
            #endif           
        } 
    #endif

    
    #ifdef TIM6
        if(Timerx_Ptr__Ex_TIM1 == TIM6){ 
            #ifdef RCC_APB1ENR_TIM6EN
                return _Get_APB1TimerxClock_HZ(); 
            #elif RCC_APB2ENR_TIM6EN  
                return _Get_APB2TimerxClock_HZ(); 
            #endif           
        } 
    #endif

    
    #ifdef TIM7
        if(Timerx_Ptr__Ex_TIM1 == TIM7){ 
            #ifdef RCC_APB1ENR_TIM7EN
                return _Get_APB1TimerxClock_HZ(); 
            #elif RCC_APB2ENR_TIM7EN  
                return _Get_APB2TimerxClock_HZ(); 
            #endif           
        } 
    #endif

    
    #ifdef TIM8
        if(Timerx_Ptr__Ex_TIM1 == TIM8){ 
            #ifdef RCC_APB1ENR_TIM8EN
                return _Get_APB1TimerxClock_HZ(); 
            #elif RCC_APB2ENR_TIM8EN  
                return _Get_APB2TimerxClock_HZ(); 
            #endif           
        } 
    #endif

    
    #ifdef TIM9
        if(Timerx_Ptr__Ex_TIM1 == TIM9){ 
            #ifdef RCC_APB1ENR_TIM9EN
                return _Get_APB1TimerxClock_HZ(); 
            #elif RCC_APB2ENR_TIM9EN  
                return _Get_APB2TimerxClock_HZ(); 
            #endif           
        } 
    #endif

    
    #ifdef TIM10
        if(Timerx_Ptr__Ex_TIM1 == TIM10){ 
            #ifdef RCC_APB1ENR_TIM10EN
                return _Get_APB1TimerxClock_HZ(); 
            #elif RCC_APB2ENR_TIM10EN  
                return _Get_APB2TimerxClock_HZ(); 
            #endif           
        } 
    #endif

    
    #ifdef TIM11
        if(Timerx_Ptr__Ex_TIM1 == TIM11){ 
            #ifdef RCC_APB1ENR_TIM111EN
                return _Get_APB1TimerxClock_HZ(); 
            #elif RCC_APB2ENR_TIM11EN  
                return _Get_APB2TimerxClock_HZ(); 
            #endif           
        } 
    #endif

    
    #ifdef TIM12
        if(Timerx_Ptr__Ex_TIM1 == TIM12){ 
            #ifdef RCC_APB1ENR_TIM12EN
                return _Get_APB1TimerxClock_HZ(); 
            #elif RCC_APB2ENR_TIM12EN  
                return _Get_APB2TimerxClock_HZ(); 
            #endif           
        } 
    #endif

    
    #ifdef TIM13
        if(Timerx_Ptr__Ex_TIM1 == TIM13){ 
            #ifdef RCC_APB1ENR_TIM13EN
                return _Get_APB1TimerxClock_HZ(); 
            #elif RCC_APB2ENR_TIM13EN  
                return _Get_APB2TimerxClock_HZ(); 
            #endif           
        } 
    #endif

    
    #ifdef TIM14
        if(Timerx_Ptr__Ex_TIM1 == TIM14){ 
            #ifdef RCC_APB1ENR_TIM14EN
                return _Get_APB1TimerxClock_HZ(); 
            #elif RCC_APB2ENR_TIM14EN  
                return _Get_APB2TimerxClock_HZ(); 
            #endif           
        } 
    #endif

    
    #ifdef TIM15
        if(Timerx_Ptr__Ex_TIM1 == TIM15){ 
            #ifdef RCC_APB1ENR_TIM15EN
                return _Get_APB1TimerxClock_HZ(); 
            #elif RCC_APB2ENR_TIM15EN  
                return _Get_APB2TimerxClock_HZ(); 
            #endif           
        } 
    #endif

    
    #ifdef TIM16
        if(Timerx_Ptr__Ex_TIM1 == TIM16){ 
            #ifdef RCC_APB1ENR_TIM16EN
                return _Get_APB1TimerxClock_HZ(); 
            #elif RCC_APB2ENR_TIM16EN  
                return _Get_APB2TimerxClock_HZ(); 
            #endif           
        } 
    #endif

    
    #ifdef TIM17
        if(Timerx_Ptr__Ex_TIM1 == TIM17){ 
            #ifdef RCC_APB1ENR_TIM17EN
                return _Get_APB1TimerxClock_HZ(); 
            #elif RCC_APB2ENR_TIM17EN  
                return _Get_APB2TimerxClock_HZ(); 
            #endif           
        } 
    #endif

    
    #ifdef TIM18
        if(Timerx_Ptr__Ex_TIM1 == TIM18){ 
            #ifdef RCC_APB1ENR_TIM18EN
                return _Get_APB1TimerxClock_HZ(); 
            #elif RCC_APB2ENR_TIM18EN  
                return _Get_APB2TimerxClock_HZ(); 
            #endif           
        } 
    #endif

    
    #ifdef TIM19
        if(Timerx_Ptr__Ex_TIM1 == TIM19){ 
            #ifdef RCC_APB1ENR_TIM19EN
                return _Get_APB1TimerxClock_HZ(); 
            #elif RCC_APB2ENR_TIM19EN  
                return _Get_APB2TimerxClock_HZ(); 
            #endif           
        } 
    #endif

    
    #ifdef TIM20
        if(Timerx_Ptr__Ex_TIM1 == TIM20){ 
            #ifdef RCC_APB1ENR_TIM20EN
                return _Get_APB1TimerxClock_HZ(); 
            #elif RCC_APB2ENR_TIM20EN  
                return _Get_APB2TimerxClock_HZ(); 
            #endif           
        } 
    #endif

    
    #ifdef TIM21
        if(Timerx_Ptr__Ex_TIM1 == TIM21){ 
            #ifdef RCC_APB1ENR_TIM21EN
                return _Get_APB1TimerxClock_HZ(); 
            #elif RCC_APB2ENR_TIM21EN  
                return _Get_APB2TimerxClock_HZ(); 
            #endif           
        } 
    #endif

    
    #ifdef TIM22
        if(Timerx_Ptr__Ex_TIM1 == TIM22){ 
            #ifdef RCC_APB1ENR_TIM22EN
                return _Get_APB1TimerxClock_HZ(); 
            #elif RCC_APB2ENR_TIM22EN  
                return _Get_APB2TimerxClock_HZ(); 
            #endif           
        } 
    #endif

    
    #ifdef TIM23
        if(Timerx_Ptr__Ex_TIM1 == TIM23){ 
            #ifdef RCC_APB1ENR_TIM23EN
                return _Get_APB1TimerxClock_HZ(); 
            #elif RCC_APB2ENR_TIM23EN  
                return _Get_APB2TimerxClock_HZ(); 
            #endif           
        } 
    #endif

    
    #ifdef TIM24
        if(Timerx_Ptr__Ex_TIM1 == TIM24){ 
            #ifdef RCC_APB1ENR_TIM24EN
                return _Get_APB1TimerxClock_HZ(); 
            #elif RCC_APB2ENR_TIM24EN  
                return _Get_APB2TimerxClock_HZ(); 
            #endif           
        } 
    #endif

    
    #ifdef TIM25
        if(Timerx_Ptr__Ex_TIM1 == TIM25){ 
            #ifdef RCC_APB1ENR_TIM25EN
                return _Get_APB1TimerxClock_HZ(); 
            #elif RCC_APB2ENR_TIM25EN  
                return _Get_APB2TimerxClock_HZ(); 
            #endif           
        } 
    #endif

    
    #ifdef TIM26
        if(Timerx_Ptr__Ex_TIM1 == TIM26){ 
            #ifdef RCC_APB1ENR_TIM26EN
                return _Get_APB1TimerxClock_HZ(); 
            #elif RCC_APB2ENR_TIM26EN  
                return _Get_APB2TimerxClock_HZ(); 
            #endif           
        } 
    #endif

    
    #ifdef TIM27
        if(Timerx_Ptr__Ex_TIM1 == TIM27){ 
            #ifdef RCC_APB1ENR_TIM27EN
                return _Get_APB1TimerxClock_HZ(); 
            #elif RCC_APB2ENR_TIM27EN  
                return _Get_APB2TimerxClock_HZ(); 
            #endif           
        } 
    #endif

    
    #ifdef TIM28
        if(Timerx_Ptr__Ex_TIM1 == TIM28){ 
            #ifdef RCC_APB1ENR_TIM28EN
                return _Get_APB1TimerxClock_HZ(); 
            #elif RCC_APB2ENR_TIM28EN  
                return _Get_APB2TimerxClock_HZ(); 
            #endif           
        } 
    #endif

    
    #ifdef TIM29
        if(Timerx_Ptr__Ex_TIM1 == TIM29){ 
            #ifdef RCC_APB1ENR_TIM29EN
                return _Get_APB1TimerxClock_HZ(); 
            #elif RCC_APB2ENR_TIM29EN  
                return _Get_APB2TimerxClock_HZ(); 
            #endif           
        } 
    #endif

    
    #ifdef TIM30
        if(Timerx_Ptr__Ex_TIM1 == TIM30){ 
            #ifdef RCC_APB1ENR_TIM30EN
                return _Get_APB1TimerxClock_HZ(); 
            #elif RCC_APB2ENR_TIM30EN  
                return _Get_APB2TimerxClock_HZ(); 
            #endif           
        } 
    #endif

   return 0;
}
#endif
