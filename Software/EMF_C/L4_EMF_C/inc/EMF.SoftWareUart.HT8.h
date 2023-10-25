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
#ifndef EMF_SOFTWAREUART_HT8_H
#define EMF_SOFTWAREUART_HT8_H
#if defined(EMF__TYPE_HT8)

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Config define
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
#define TXD  GPIOA->Px_bits.bit5     // TX pin mapping on PA7 ex) GPIOC->Px_bits.bit0
#define TXC  GPIOA->PxC_bits.bit5    // TX pin input/output control ex) GPIOC->PxC_bits.bit0
#define TXPU GPIOA->PxPU_bits.bit5  // TX pin pull-high control ex) GPIOC->PxPU_bits.bit0

/**** select simulation uart baud for 8MHz system clock ****/
//	#define BAUDRATE	404		// baud rate 4800,395~413
#define BAUDRATE 193  // baud rate 9600,191~195
//	#define BAUDRATE	96		// baud rate 19200,93~99
//	#define BAUDRATE	43		// baud rate 38400,41~45

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Functions
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
/**
* @brief PLZ set Config Defines Befor Call Functions
* @code
#include "EMF.h"
void main() {
    EMF_init();

    while(1){
        SoftWareUART_Transmit_Byte('x');
        SoftWareUART_Transmit_Byte('\n');
        delay_tick(200000);
    }
	
}
* @endcode
*/
void SoftWareUART_Transmit_Byte(uint8 TransmitData);
//=========================================================================================
//=========================================================================================
/**
* @code
#include "EMF.h"
void main() {
    EMF_init();

    const uint8 Msg[] = "Salam\n";

    while(1){
        SoftWareUART_Transmit_Bytes(&Msg[0], 6); 
        delay_tick(200000);
    }
} 
* @endcode
*/
void SoftWareUART_Transmit_Bytes(uint8 *TransmitDataByte0_Ptr, uint8 Lenghh);
//=========================================================================================
//=========================================================================================

#endif
#endif
