/**
******************************************************************************************
* Copyright (c) Electro Pardazesh Daghigh Aria(EPDA).Ltd Corporation. All rights
*reserved. This software is licensed under the MIT License.
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
#ifndef EMF_INIT_HT8_H
#define EMF_INIT_HT8_H

#if defined(EMF__TYPE_HT8)

//wait until HIRC ready
//WDT disable
#define EMF_init() \
            do{ \
                while(!_hto);   \
                WatchDog_Disable(); \
            }while(0)   

#endif

#endif