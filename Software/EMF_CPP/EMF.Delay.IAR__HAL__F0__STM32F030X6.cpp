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
 * v4.0_14020803            E.Rahmanian    Create
 ******************************************************************************************
 */
#include "EMF.h"
#if defined(EMF_DELAY_IAR__HAL__F0__STM32F030X6_H)

Delay_Class::Delay_Class() {
    delay_ms = &HAL_Delay;
    _htimx.Instance = 0;
}
//=========================================================================================
//=========================================================================================
Delay_Class::~Delay_Class() {
    //  delay_Timer_Stop();
}
//=========================================================================================
//=========================================================================================
bool Delay_Class::Delay_ConfigState_Return_1Ok_0NotConfiged() {
    return _DelayClass_configState_1Ok_0NotConfiged;
}
//=========================================================================================
//=========================================================================================
bool Delay_Class::Delay_Config_return_0Error_1Ok(TIM_TypeDef *SelectTimerToCreateDelay_Ptr__Ex_TIM1) {
    delay_Timer_Stop();
    _DelayClass_configState_1Ok_0NotConfiged = 0;

    _htimx.Instance = SelectTimerToCreateDelay_Ptr__Ex_TIM1;
    _htimx.Init.Prescaler = (Get_APBxTimerClock_HZ(SelectTimerToCreateDelay_Ptr__Ex_TIM1) / 1000000) - 1;  // The counter clock frequency (CK_CNT) is

    TIM_ClockConfigTypeDef sClockSourceConfig = {0};
    TIM_MasterConfigTypeDef sMasterConfig = {0};

    Timer_RegisterClockOnOff(_htimx.Instance,1);  // Timer Register Control Clock(RCC) on

    _htimx.Init.CounterMode = TIM_COUNTERMODE_UP;
    _htimx.Init.Period = 65535;
    _htimx.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
    _htimx.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_ENABLE;

    if (HAL_TIM_Base_Init(&_htimx) != HAL_OK) {
        return 0;  // Error
    }

    sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
    if (HAL_TIM_ConfigClockSource(&_htimx, &sClockSourceConfig) != HAL_OK) {
        return 0;  // Error
    }

    sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
    sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
    if (HAL_TIMEx_MasterConfigSynchronization(&_htimx, &sMasterConfig) !=HAL_OK) {
        return 0;  // Error
    }

    if (HAL_TIM_Base_Start(&_htimx) != HAL_OK) {
        return 0; /*Error*/
    }


    if (_htimx.Instance->CR1 & 0b1) {  // if CR1.B0(CEN) == 1 =>Counter Enabled
        uint32 _Tick_A, _Tick_B;

        _Timer_CNT_FirstValue = 0;
        _Tick_A = HAL_GetTick();  // ms
        delay_us(10000);                        // 10ms
        _Tick_B = HAL_GetTick();                // ms

        if (_Tick_B < _Tick_A) {      // Repeat if tick is overflow
            _Tick_A = HAL_GetTick();  // ms
            delay_us(10000);                        // 10ms
            _Tick_B = HAL_GetTick();                // ms
        }

        if (((_Tick_B - _Tick_A) / 10) == 1){
            _DelayClass_configState_1Ok_0NotConfiged = true;
            return 1; //OK
        }

        //Error
        _Timer_CNT_FirstValue = ~0;  // Fake Max value
    }
    return 0;  // Error
}
//=========================================================================================
//=========================================================================================
void Delay_Class::delay_us(uint16 Delay_us_0to32767) {
    _htimx.Instance->CNT = _Timer_CNT_FirstValue;  // if Delay is Not Config _Timer_CNT_FirstValue=0xFFFFFFFF and after Config _Timer_CNT_FirstValue=0
    Delay_us_0to32767 = Delay_us_0to32767 & 0b111111111111111;// convert negative num to positive num
    while (_htimx.Instance->CNT < Delay_us_0to32767);
}
//=========================================================================================
//=========================================================================================
// // void Delay_Class::delay_ms(uint32 Delay_ms_0to4294967295) {
// //     while (Delay_ms_0to4294967295) {
// //         _htimx.Instance->CNT = _Timer_CNT_FirstValue;//if Delay is Not Config _Timer_CNT_FirstValue=0xFFFFFFFF and after Config _Timer_CNT_FirstValue=0
// //         while (_htimx.Instance->CNT < 1000);
// //         Delay_ms_0to4294967295--;
// //     }
// // }
//=========================================================================================
//=========================================================================================
void Delay_Class::delay_Timer_Stop() {
    if (_htimx.Instance != 0) {  // pointer Is Not null?
        HAL_TIM_Base_Stop(&_htimx);
        Timer_RegisterClockOnOff(_htimx.Instance, 0);

        _Timer_CNT_FirstValue = ~0;  // Fake Max value
        _htimx.Instance = 0;

        _DelayClass_configState_1Ok_0NotConfiged = false;
    }
}
//=========================================================================================
//=========================================================================================
uint32 Delay_Class::Get_WhileDelayCount(int16 Delay_us_0to32767){
    if(Delay_ConfigState_Return_1Ok_0NotConfiged() == 0){return 0;}
    if(Delay_us_0to32767 == 0){return 0;}

    Delay_us_0to32767 = Delay_us_0to32767 & 0b111111111111111;// convert negative num to positive num

    uint32 a = 0,b;
    _htimx.Instance->CNT = _Timer_CNT_FirstValue;  // if Delay is Not Config _Timer_CNT_FirstValue=0xFFFFFFFF and after Config _Timer_CNT_FirstValue=0
    while (_htimx.Instance->CNT < Delay_us_0to32767){
        a++;
    }

    //Testing and calibration1
    b = a;
    _htimx.Instance->CNT = _Timer_CNT_FirstValue;
    while(b--);
    b = _htimx.Instance->CNT;

    a = b = ((uint64(a) * uint64(Delay_us_0to32767)) / b);
    
    //Testing and calibration2
    _htimx.Instance->CNT = _Timer_CNT_FirstValue;
    while(b--);
    b = _htimx.Instance->CNT;

    return ((uint64(a) * uint64(Delay_us_0to32767)) / b) + 1; //ex)1000.6 -- ToUint --->1000---- +1 --> 1001
}

#endif
