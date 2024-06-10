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
* v4.2_14020824            E.Rahmanian    Add "HT66F0031.h"
******************************************************************************************
*/
#ifndef EMF_DRIVER_H
#define EMF_DRIVER_H
#if defined(EMF_C)
    #if defined(IDE3000__V3)
        #include "STDINT.H"
        #include "STDLIB.H"
        #include "STRING.H"
        #include "build-in.h"
        #include "ctype.h"
        #include "math.h"
        #include "time.h"
    #endif

    #if defined(IDE3000__V3__HT8__HT66F002_0025_003_004__HT66F004)
        #include "HT66F004.h"
    #elif defined(IDE3000__V3__HT8__HT66F0021_31_41__HT66F0031)
        #include "HT66F0031.h"
    #endif

#endif
#endif
