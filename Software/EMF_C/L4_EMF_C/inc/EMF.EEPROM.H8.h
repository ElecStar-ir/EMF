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
#ifndef EMF_EEPROM_H8_H
#define EMF_EEPROM_H8_H
#if defined(EMF__TYPE_HT8)

//HT66F004 Datasheet)
//Note that the devices should not enter the IDLE or SLEEP mode until the EEPROM read or write operation is totally complete. Otherwise, the EEPROM read or write operation will fail.
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Functions
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
/**
 * @code Example Read And Write
#include "EMF.h"
void main() {
    EMF_init();  
    EEPROM_Write(29, 0xAB);
    while (1){
        SoftWareUART_Transmit_Byte(EEPROM_Read(29));
        delay_tick(200000);
    }   
}
 * @endcode
*/
void EEPROM_Write(uint8 Address,uint8 Data);				//EEPROM Write mode,No interrupt
//=========================================================================================
uint8 EEPROM_Read(uint8 Address);							//EEPROM Read mode


#endif
#endif
