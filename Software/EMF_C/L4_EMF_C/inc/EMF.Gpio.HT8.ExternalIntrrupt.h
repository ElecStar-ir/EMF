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
#ifndef EMF_GPIO_HT8_EXTERNALINTRRUPT_H
#define EMF_GPIO_HT8_EXTERNALINTRRUPT_H

/**
 * @code External intrrupt Example
// Example in HT66F004
#include "EMF.h"

// Go to HT66F004 Datasheet>Interrupt>Interrupt Operation>Interrupt Structure – HT66F004
DEFINE_ISR(INT0_Intrrupt, 0x04) {
    _pa7 = !_pa7; //Toggle Pa7 Output Value
}

void main() {
    EMF_init();

    _pa7 = 0; //PA7 Output Value = 0
    _pac7 = 0;  // Config PA7 = Output

    _pbs0 = 0; //Config B0 to "PB0/INT0"[Read Datasheet "Input/Output Ports">"Pin-shared Functions"] 
    _pbc0 = 1; //PB0 Config input
    _pbpu0 = 1; //Internal Pullup Active (This code is not necessary)

    //Defines INT0 interrupt active edge = Rising Edge Interrupt (Go to HT66F004 Datasheet>Interrupt>Interrupt registers>INTEG Register – HT66F004)
    _int0s1 = 0;  _int0s0 = 1; 

    _emi = 1; //Enable Global interrupt
    _int0e = 1; //Enable INT0 interrupt


    while (1);
* @endcode
*/

#endif