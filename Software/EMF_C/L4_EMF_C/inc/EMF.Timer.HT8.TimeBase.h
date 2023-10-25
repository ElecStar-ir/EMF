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
#ifndef EMF_TIMER_HT8_TIMEBASE_H
#define EMF_TIMER_HT8_TIMEBASE_H

/**
 * @code Time Base0 Intrrupt
// Example in HT66F004
#include "EMF.h"

// Go to HT66F004 Datasheet>Interrupt>Interrupt Operation>Interrupt Structure – HT66F004
DEFINE_ISR(TimeBase0_Intrrupt, 0x08) {
    _pa7 = !_pa7; //Toggle Pa7 Output Value
}

void main() {
    EMF_init();

    _pa7 = 0; //PA7 Output Value = 0
    _pac7 = 0;  // Config PA7 = Output

    //Please Read-> Datasheet>Intrrupt>Time Base Interrupts
    _tbck = 1; //Ftbk = Fsys/4

    //Select Time Base 0 Time-out Period --> 32768/Ftbk
    _tb02 = 1; _tb01 = 1;   _tb00 = 1;

    _tbon = 1; //TimeBase0 and TimeBase1  = Enable
    _emi = 1; //Enable Global interrupt
    _tb0e = 1; //Enable TimeBase0 interrupt


    while (1);
}
* @endcode
 * @code Time Base0 polling Mode
// Example in HT66F004
#include "EMF.h"

void main() {
    EMF_init();

    _pa7 = 0; //PA7 Output Value = 0
    _pac7 = 0;  // Config PA7 = Output

    //Please Read-> Datasheet>Intrrupt>Time Base Interrupts
    _tbck = 1; //Ftbk = Fsys/4

    //Select Time Base 0 Time-out Period --> 32768/Ftbk
    _tb02 = 1; _tb01 = 1;   _tb00 = 1;

    _tbon = 1; //TimeBase0 and TimeBase1  = Enable

    while(1){
        if(_tb0f == 1){ //Check timebase0 counter overflow
            _tb0f = 0;  ////clear timebase0 counter overflow flag
            _pa7 = !_pa7; //Toggle Pa7 Output Value
        }
    }
}
* @endcode
*/

#endif