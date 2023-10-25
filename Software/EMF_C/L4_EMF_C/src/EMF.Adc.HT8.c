/**
 ******************************************************************************************
 * Copyright (c) Electro Pardazesh Daghigh Aria(EPDA).Ltd Corporation. All
 *rights reserved. This software is licensed under the MIT License.
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
#include "EMF.h"
#if defined(EMF_ADC_HT8_H)
//=========================================================================================
//=========================================================================================
void ADC_Init() {
    /***************** ADC clock select *****************/
    #ifdef ADC_CLOCK_FSYS
    {
        /* select ADC clock fsys */
        _sack2 = 0;
        _sack1 = 0;
        _sack0 = 0;
    }
    #elif ADC_CLOCK_FSYS_DIV2
    {
        /* select ADC clock fsys/2 */
        _sack2 = 0;
        _sack1 = 0;
        _sack0 = 1;
    }
    #elif ADC_CLOCK_FSYS_DIV4
    {
        /* select ADC clock fsys/4 */
        _sack2 = 0;
        _sack1 = 1;
        _sack0 = 0;
    }
    #elif ADC_CLOCK_FSYS_DIV8
    {
        /* select ADC clock fsys/8 */
        _sack2 = 0;
        _sack1 = 1;
        _sack0 = 1;
    }
    #elif ADC_CLOCK_FSYS_DIV16
    {
        /* select ADC clock fsys16 */
        _sack2 = 1;
        _sack1 = 0;
        _sack0 = 0;
    }
    #elif ADC_CLOCK_FSYS_DIV32
    {
        /* select ADC clock fsys/32 */
        _sack2 = 1;
        _sack1 = 0;
        _sack0 = 1;
    }
    #elif ADC_CLOCK_FSYS_DIV64
    {
        /* select ADC clock fsys/64 */
        _sack2 = 1;
        _sack1 = 1;
        _sack0 = 0;
    }
    #elif ADC_CLOCK_FSYS_DIV128
    {
        /* select ADC clock fsys/128 */
        _sack2 = 1;
        _sack1 = 1;
        _sack0 = 1;
    }
    #endif
    /*************** end of ADC clock select ******************/

    /******** setting AD convert data alignment type **********/
    #ifdef ADC_VALUE_ALIGN_RIGHT
    {
        /* select AD convert data alignment right	*/
        _adrfs = 1;
    }
    #else
    {
        /* select 	AD convert data alignment left */
        _adrfs = 0;
    }
    #endif
    /***** end of setting AD convert data alignment type ******/

    /********** setting AD convert reference voltage *********/
    #ifdef ADC_REF_VOLTAGE_VDD
    {
        _savrs3 = 0;
        _savrs2 = 0;
        _savrs1 = 0;
        _savrs0 = 0;
    }
    #elif ADC_REF_VOLTAGE_VREF
    {
        _savrs3 = 0;
        _savrs2 = 0;
        _savrs1 = 0;
        _savrs0 = 1;
        ADC_OPA_ENABLE();  // enable PGA
    }
    #elif ADC_REF_VOLTAGE_VREFx2
    {
        _savrs3 = 0;
        _savrs2 = 0;
        _savrs1 = 1;
        _savrs0 = 0;
        ADC_OPA_ENABLE();  // enable PGA
    }
    #elif ADC_REF_VOLTAGE_VREFx3
    {
        _savrs3 = 0;
        _savrs2 = 0;
        _savrs1 = 1;
        _savrs0 = 1;
        ADC_OPA_ENABLE();  // enable PGA
    }
    #elif ADC_REF_VOLTAGE_VREFx4
    {
        _savrs3 = 0;
        _savrs2 = 1;
        _savrs1 = 0;
        _savrs0 = 0;
        ADC_OPA_ENABLE();  // enable PGA
    }
    #elif ADC_REF_VOLTAGE_VBGx2
    {
        _savrs3 = 1;
        _savrs2 = 0;
        _savrs1 = 1;
        _savrs0 = 0;
        ADC_VBG_ENABLE();  // enable Vbg
        ADC_OPA_ENABLE();  // enable PGA
    }
    #elif ADC_REF_VOLTAGE_VBGx3
    {
        _savrs3 = 1;
        _savrs2 = 0;
        _savrs1 = 1;
        _savrs0 = 1;
        ADC_VBG_ENABLE();  // enable Vbg
        ADC_OPA_ENABLE();  // enable PGA
    }
    #elif ADC_REF_VOLTAGE_VBGx4
    {
        _savrs3 = 1;
        _savrs2 = 1;
        _savrs1 = 0;
        _savrs0 = 0;
        ADC_VBG_ENABLE();  // enable Vbg
        ADC_OPA_ENABLE();  // enable PGA
    }
    #endif
    /********* end of setting AD convert reference voltage *********/
}
//=========================================================================================
//=========================================================================================
void ADC_SelectChannel(uint8 ADC_Channel) {
    /* clear ADC channel */
    _sadc0 &= 0b11110000;
    _sadc1 &= 0b00001111;

    /* selection ADC channel */
    _sadc0 |= ADC_Channel;
    _sadc1 |= ADC_Channel;
}
//=========================================================================================
//=========================================================================================
uint16 ADC_GetValue() {
    /* start AD converter */
    ADC_START();

    /* waitting AD conversion finish */
    while (1 == _adbz);

    
    #ifdef ADC_VALUE_ALIGN_RIGHT /* AD conversion data alignment right */
    {
        /* get the AD conversion value */
        return (((uint16)_sadoh << 8) | _sadol);
    }

    
    #else /* AD conversion data alignment left */
    {
        /* get the AD conversion value */
        return (((uint16)_sadoh << 4) | (_sadol >> 4));
    }
    #endif
}
//=========================================================================================
//=========================================================================================
uint16 ADC_GetChannelValue(uint8 ADC_Channel){
    ADC_SelectChannel(ADC_Channel);
    return ADC_GetValue();
}

#endif
