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
* v5.0_14031021            E.Rahmanian    Create
******************************************************************************************
*/
#if defined(IDE3000__V2__HT8__HT66F002_0025_003_004)
#ifndef EMF_INIT_IDE3000__V2__HT8__HT66F002_0025_003_004_H
#define EMF_INIT_IDE3000__V2__HT8__HT66F002_0025_003_004_H

//wait until HIRC ready
//WDT disable
#define EMF_init() \
            do{ \
                while(!_hto);   \
                EMF_WatchDog_Disable(); \
            }while(0)   

#endif

#endif