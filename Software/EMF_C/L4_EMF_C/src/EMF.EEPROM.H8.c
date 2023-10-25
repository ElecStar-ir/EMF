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
#if defined(EMF_EEPROM_H8_H)

void EEPROM_Write(uint8 Address, uint8 Data) {
    /*config EEPROM init*/
    _rw uint8 a = _emi;  // Backup EMI State(global interrupt)
    _emi = 0;            // disable global interrupt
    _dmbp0 = 1;          // Select Data Memory Banks (Bank 1)
    _mp1 = 0x40;         // in Bank 1, the MP1 Memory Pointer must first be set to the value 40H and the Bank Pointer register,

    /*config EEPROM address*/
    _eea = Address;
    /*Write data*/
    _eed = Data;

    /*config EEPROM Write mode*/
    _iar1 |= 0x08;  // SET IAR1.3 ; set WREN bit, enable write operations
    _iar1 |= 0x04;  // SET IAR1.2 ; start Write Cycle - set WR bit– executed immediately after ; set WREN bit

    /* waitting for EEPROM write finishing */
    while (_iar1 & 0x04)
        ;        // SZ IAR1.2 ; check for write cycle end
    _iar1 = 0;   // CLR IAR1 ; disable EEPROM write
    _dmbp0 = 0;  // CLR BP ; Select Data Memory Banks (Bank 0)
    _emi = a;    // Restore EMI State(global interrupt)
}
//=========================================================================================
//=========================================================================================
uint8 EEPROM_Read(uint8 Address) {
    /* config EEPROM init */
    uint8 EP_Read_Data;
    _dmbp0 = 1;   // Select Data Memory Banks (Bank 1)
    _mp1 = 0x40;  // in Bank 1, the MP1 Memory Pointer must first be set to the value 40H and the Bank Pointer register,

    /*config EEPROM address*/
    _eea = Address;

    /*config EEPROM Read mode*/
    _iar1 |= 0x02;  // SET IAR1.1 ; set RDEN bit, enable read operations
    _iar1 |= 0x01;  // SET IAR1.0 ; start Read Cycle - set RD bit

    /* waitting for EEPROM Read finishing */
    while (_iar1 & 0x01)
        ;        // SZ IAR1.0 ; check for read cycle end
    _iar1 = 0;   // CLR IAR1 ; disable EEPROM write
    _dmbp0 = 0;  // CLR BP ; Select Data Memory Banks (Bank 0)

    EP_Read_Data = _eed;  // Read data
    return EP_Read_Data;
}

#endif
