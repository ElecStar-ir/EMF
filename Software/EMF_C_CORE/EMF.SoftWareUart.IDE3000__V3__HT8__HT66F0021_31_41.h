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
* v5.2_14031101            E.rahmanian    Create
******************************************************************************************
*/
#if defined(IDE3000__V3__HT8__HT66F0021_31_41)
#ifndef EMF_SOFTWAREUART_IDE3000__V3__HT8__HT66F0021_31_41_H
#define EMF_SOFTWAREUART_IDE3000__V3__HT8__HT66F0021_31_41_H

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Config define
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
#define TXD  _pa1     // TX pin mapping              ex) GIOA->Px_bits.bit6  or _pa6
#define TXC  _pac1    // TX pin input/output control ex) GIOA-->PxC_bits.bit6 or _pac6
#define TXPU _papu1  // TX pin pull-high control     ex) GIOA-->PxPU_bits.bit6 or _papu6

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
*/
void EMF_SoftWareUART_Transmit_Byte(uint8 TransmitData);
//=========================================================================================
//=========================================================================================
/**
* @code
#include "HT66F0021.h"
#include "EMF.h"

void main(){
    EMF_init();
    EMF_SetCoreClockTo_HIRC_DIV1_8MHZ_Return_1Ok_0Failed();

    const uint8 Msg[] = "Salam\n";

    while(1){
        EMF_SoftWareUART_Transmit_Bytes(&Msg[0], 6); 
        EMF_delay_tick(200000);
    }
}
* @endcode
*/
void EMF_SoftWareUART_Transmit_Bytes(uint8 *TransmitDataByte0_Ptr, uint8 Lenghh);
//=========================================================================================
//=========================================================================================

#endif
#endif
