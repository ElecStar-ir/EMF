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
* v4.2_14020824            E.Rahmanian    Create
******************************************************************************************
*/
#ifndef EMF_INIT_IDE3000__V3__HT8__HT66F0021_31_41_H
#define EMF_INIT_IDE3000__V3__HT8__HT66F0021_31_41_H

#if defined(IDE3000__V3__HT8__HT66F0021_31_41)

//wait until HIRC ready
//WDT disable
#define EMF_init() \
            do{ \
                while(!_hircf);   \
                WatchDog_Disable(); \
            }while(0)   

#endif

#endif