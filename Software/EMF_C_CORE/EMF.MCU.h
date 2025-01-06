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
#if defined(EMF_C)
#ifndef EMF_MCU_H
#define EMF_MCU_H

    #include "EMF.MCU.IDE3000__V2__HT8__HT66F002_0025_003_004__HT66F002.h"
    #include "EMF.MCU.IDE3000__V3__HT8__HT66F002_0025_003_004__HT66F004.h"
    #include "EMF.MCU.IDE3000__V3__HT8__HT66F0021_31_41__HT66F0031.h"


    #if !defined(IDE3000__V2__HT8__HT66F002_0025_003_004__HT66F002) && \
        !defined(IDE3000__V3__HT8__HT66F002_0025_003_004__HT66F004) && \
        !defined(IDE3000__V3__HT8__HT66F0021_31_41__HT66F0031)
        
        #error "Please Uncomment the target MCU define in EMF.Config.h"
    #endif
    
#endif
#endif
