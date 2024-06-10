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
* v4.1_14020824            E.Rahmanian    Create
******************************************************************************************
*/
#ifndef EMF_WATCHDOG_IDE3000__V3__HT8__HT66F002_0025_003_004_H
#define EMF_WATCHDOG_IDE3000__V3__HT8__HT66F002_0025_003_004_H
#if defined(IDE3000__V3__HT8__HT66F002_0025_003_004)

    // HT66F004 DataSheet)
    //  WDTC Register
    //  Bit 7 6 5 4 3 2 1 0
    //  Name WE4 WE3 WE2 WE1 WE0 WS2 WS1 WS0
    //  R/W R/W R/W R/W R/W R/W R/W R/W R/W
    //  POR 0 1 0 1 0 0 1 1
    //  Bit 7~ 3 WE4 ~ WE0: WDT function software control
    //  10101: WDT disable
    //  01010: WDT enable
    //  Other values: Reset MCU
    //  When these bits are changed to any other values by the environmental noise to reset the
    //  microcontroller, the reset operation will be activated after 2~3 LIRC clock cycles and the WRF
    //  bit will be set to 1 to indicate the reset source.
    //  Bit 2~ 0 WS2 ~ WS0: WDT Time-out period selection
    //  000: 28/ fLIRC
    //  001: 29/fLIRC
    //  010: 210/fLIRC
    //  011: 211/fLIRC
    //  100: 212/fLIRC
    //  101: 213/fLIRC
    //  110: 214/fLIRC
    //  111: 215/fLIRC
    //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    //  Commands defines
    //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    #define WatchDog_Enable(WatchDog_TimeOut_0To7_0isfaster) (_wdtc = 0b01010000 | (WatchDog_TimeOut_0To7_0isfaster & 0b111))
    #define WatchDog_Disable() (_wdtc = 0b10101000)
    #define WatchDog_ResetCounter() (_clrwdt())

#endif
#endif
