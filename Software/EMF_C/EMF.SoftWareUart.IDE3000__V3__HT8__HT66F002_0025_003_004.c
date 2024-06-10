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
* v4.2.1_14020829           E.Rahmanian    Create
******************************************************************************************
*/
#include "EMF.h"
#if defined(EMF_SOFTWAREUART_IDE3000__V3__HT8__HT66F002_0025_003_004_H)

/**
  * @brief Simulation UART transmit function.
  * @param[in] transmit data,data bit:8,stop bit:1,parity:none
  * @retval None
  */
void SoftWareUART_Transmit_Byte(uint8 TransmitData){
	TXD = 1; TXC = 0; TXPU = 1;
	delay_tick(BAUDRATE);
	uint8 i;
	TXD = 0;					//start bit
	delay_tick(BAUDRATE);
	
	for(i=0;i<8;i++){			//send 8-bit data
		if(TransmitData & 0x01){
			TXD = 1;
		}else {
			TXD = 0;
		}
		delay_tick(BAUDRATE);
		TransmitData >>= 1;
	}
}
//=========================================================================================
//=========================================================================================
void SoftWareUART_Transmit_Bytes(uint8 *TransmitDataByte0_Ptr, uint8 Lenghh){
	uint8 i;
	for(i = 0 ; i < Lenghh ; i++){
		SoftWareUART_Transmit_Byte(TransmitDataByte0_Ptr[i]);
	} 
}

#endif
