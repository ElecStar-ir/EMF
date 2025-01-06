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
#ifndef EMF_DELAY_IAR__HAL__F0__STM32F030X6_H
#define EMF_DELAY_IAR__HAL__F0__STM32F030X6_H
#if defined(IAR__HAL__F0__STM32F030X6)

namespace EMF::Delay {

/**
* @code Simple Example
    #include "EMF.h"
    #include "main.h"

    int main(void) {
        EMF_init();
        SetCoreClockTo_HSI_8MHZ_Return_1Ok_0Failed();
        Delay_Class d;
        bool a;
        a = d.Delay_Config_return_0Error_1Ok(TIM1);

        if (a == 1) {
            // USER CODE
            d.delay_ms(1000);
            d.delay_us(30000);
            // USER CODE
        }

        while (1);
    }
* @endcode Simple Example
*
* @code Debug example
    #include <stdio.h>

    #include "EMF.h"
    #include "main.h"

    int main(void){
        uint32 a;
        EMF_init();

        a = SetCoreClockTo_HSI_PLL_48MHZ_Return_1Ok_0Failed();
        printf("SetCoreClock 48MHZ=> 1OK 0Error => %d\n", a);

        Delay_Class d;
        a = d.Delay_Config_return_0Error_1Ok(TIM3);
        printf("Delay_Config with TIM3 And F_cpu=48MHz => 1OK 0Error => %d\n",a);

        a = HAL_GetTick();
        d.delay_ms(1000);
        a = HAL_GetTick() - a;
        printf("Delay_ms Tested With Tick Timer => (ms):%d\n", a);

        a = HAL_GetTick();
        d.delay_us(30000);
        a = HAL_GetTick() - a;
        printf("Delay_us Tested With Tick Timer => (us):%d\n", a * 1000);

        a = SetCoreClockTo_HSI_8MHZ_Return_1Ok_0Failed();
        printf("SetCoreClock 8MHZ=> 1OK 0Error => %d\n", a);

        a = d.Delay_Config_return_0Error_1Ok(TIM3);
        printf("Delay ReConfig with TIM3 F_cpu=8MHz=> 1OK 0Error => %d\n", a);

        a = HAL_GetTick();
        d.delay_ms(1000);
        a = HAL_GetTick() - a;
        printf("Delay_ms Tested With Tick Timer => (ms):%d\n", a);

        a = HAL_GetTick();
        d.delay_us(30000);
        a = HAL_GetTick() - a;
        printf("Delay_us Tested With Tick Timer => (us):%d\n", a * 1000);

        d.delay_Timer_Stop();
    

        while (1);
    }
* @endcode Debug example
*
* @code Create Delay With while example
    #include <stdio.h>

    #include "EMF.h"
    #include "main.h"
    int main(void){
        EMF_init();

        SetCoreClockTo_HSI_8MHZ_Return_1Ok_0Failed();
        static Delay_Class d;
        bool a;
        uint32 a1,b;

        a = d.Delay_Config_return_0Error_1Ok(TIM3);

        if (a == 1) {
            b = d.Get_WhileDelayCount(32000);
            a1 = HAL_GetTick();
            while(b--);
            a1 = HAL_GetTick() - a1;
            printf("Try Create 32000us delay with While ==> %d us \n", a1 * 1000);
        }

        while (1);
    }
* @endcode Create Delay With while example
*
* @brief This Class Need Use Timer to Create Delay_ms Or Delay_us
* @brief Please uncomment "#define HAL_TIM_MODULE_ENABLED" in "stm32f0xx_hal_conf.h"
*/
#if defined(HAL_TIM_MODULE_ENABLED)
class Delay_Class {
   private:
    TIM_HandleTypeDef _htimx = {0};
    uint32 _Timer_CNT_FirstValue = ~0;  // Fake Max value
    bool _DelayClass_configState_1Ok_0NotConfiged = false;

   public:
    Delay_Class();   // Constructor
    ~Delay_Class();  // Distructor
    /**
     * @brief The minimum speed of APBxTimerClock must be 1MHZ
    */
    bool Delay_Config_return_0Error_1Ok(TIM_TypeDef *SelectTimerToCreateDelay_Ptr__Ex_TIM1);
    bool Delay_ConfigState_Return_1Ok_0NotConfiged();

    /**
     * @brief PLZ Delay_Config Before Call This Sub
     */
    void delay_us(uint16 Delay_us_0to32767);

    /**
     * @brief Don't Need Delay_Config Before Call This Sub
     */
    void (*delay_ms)(uint32);

    /**
     * @brief Don't Need Delay_Config Before Call This Sub
     * @brief This function calculates how many iterations of the Weil loop will produce the desired time
     */
    uint32 Get_WhileDelayCount(int16 Delay_us_0to32767);
    void delay_Timer_Stop();
};  // Delay_Class}
#else
    #error "Please uncomment "#define HAL_TIM_MODULE_ENABLED" in "stm32xxxx_hal_conf.h"
#endif


}  // namespace EMF::Delay
using namespace EMF::Delay;

#endif
#endif
