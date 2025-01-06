/**
******************************************************************************************
* This file is part of EMF(Effective Multi Microcontroller Framework).
*
* @author  Ebrahim Rahmanian (elecstar.ir@gmail.com) (www.elecstar.ir)
* @brief
******************************************************************************************
* @attention
******************************************************************************************
* @RELEASE HISTORY
*
* DATE                     NAME           DESCRIPTION
* v4.1_14020824            E.Rahmanian    Create
* v4.3_14020830            E.Rahmanian    add{EMF.Button.h}
* v5.0_14031021            E.Rahmanian    Optimize
******************************************************************************************
*EMF Targets :
*1)Variable Types
*2)Watchdog
*3)MCU Speed + Restart MCU
*4)BitManipulation
*5)GIO
*6)Delay
*7)Button
*8)EEPROM or Write flash
*9)Math + String + Time + TrueFloat + Convert
*/
#ifndef EMF_H
#define EMF_H

#define EMF_C
#define EMF_VERSION_5_0_0_0
//=========================================================================================
// includes
//=========================================================================================
#include "EMF.Config.h"
#include "EMF.MCU.h"
#include "EMF.DataType.h"
#include "EMF.BitManipulation.h"
#include "EMF.Standards.h"
#include "EMF.Watchdog.h"
#include "EMF.Init.h"
#include "EMF.System.h"
#include "EMF.GIO.h"
#include "EMF.Delay.h"
#include "EMF.SoftWareUart.h"
#include "EMF.Button.h"

#endif
