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
#ifndef EMF_INIT_IAR__HAL_H
#define EMF_INIT_IAR__HAL_H
#if defined(IAR__HAL)
    // namespace EMF::Init {
    /**
    * @code
    #include <stdio.h>

    #include "EMF.h"
    #include "main.h"

    int main(void){

      int32 a;
      EMF_init();
      printf("%d\n",a);
      a = SetCoreClockTo_HSI_1MHZ_Return_1Ok_0Failed();
      printf("%d\n",a);
      a =  GetCoreClock_HZ();
      printf("%d\n",a);
      a = SetCoreClockTo_HSI_8MHZ_Return_1Ok_0Failed();
      printf("%d\n",a);
      a =   GetCoreClock_HZ();
      printf("%d\n",a);
      a = SetCoreClockTo_HSI_PLL_24MHZ_Return_1Ok_0Failed();
      printf("%d\n",a);
      a =  GetCoreClock_HZ();
      printf("%d\n",a);
      a = SetCoreClockTo_HSI_PLL_32MHZ_Return_1Ok_0Failed();
      printf("%d\n",a);
      a =  GetCoreClock_HZ();
      printf("%d\n",a);
      a = SetCoreClockTo_HSI_PLL_48MHZ_Return_1Ok_0Failed();
      printf("%d\n",a);
        a =  GetCoreClock_HZ();
      printf("%d\n",a);

    }
    * @endcode
    */

    #define EMF_init() HAL_Init()

// }  // namespace EMF::Init
// using namespace EMF::Init;
#endif
#endif
