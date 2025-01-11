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
* v5.1_14031022            E.Rahmanian    add new mcu
******************************************************************************************
*/
#if defined(EMF_C)
#ifndef EMF_MCU_H
#define EMF_MCU_H

    #include "EMF.MCU.IDE3000__V2__HT8__HT66F002_0025_003_004__HT66F002.h"
    #include "EMF.MCU.IDE3000__V3__HT8__HT66F002_0025_003_004__HT66F004.h"
    #include "EMF.MCU.IDE3000__V3__HT8__HT66F0021_31_41__HT66F0031.h"
    #include "EMF.MCU.IDE3000__V3__HT8__HT66F0021_31_41__HT66F0021.h"


    #if !defined(EMF_MCU_SELECTED)
        #error "Please Uncomment the target MCU define in EMF.Config.h"
    #endif
    
#endif
#endif
