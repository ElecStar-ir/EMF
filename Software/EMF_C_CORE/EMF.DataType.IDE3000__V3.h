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
* v5.0_14031021            E.Rahmanian    Optimize
******************************************************************************************
*/
#if defined(IDE3000__V3)
#ifndef EMF_DATATYPE_IDE3000__V3_H
#define EMF_DATATYPE_IDE3000__V3_H

    //=========================================================================================
    //=========================================================================================
    #define _R volatile const /*!< Defines 'read only' permissions */
    #define _W volatile       /*!< Defines 'write only' permissions */
    #define _RW volatile      /*!< Defines 'read / write' permissions */
    #define _r volatile const /*!< Defines 'read only' permissions */
    #define _w volatile       /*!< Defines 'write only' permissions */
    #define _rw volatile      /*!< Defines 'read / write' permissions */
    //=========================================================================================
    //=========================================================================================
    /* Fixed size types. These are all optional. */
    #define bool _Bool  // bool type, when the value is not 0, then the result is 1, when the value is 0, then the result is 0. For example: _Bool a = 4; then a=1
    #define true 1
    #define false 0
    typedef char char8; //-128~127
    typedef char int8;
    typedef unsigned char uint8;
    typedef short int16;
    typedef unsigned short uint16;
    typedef long int32;
    typedef unsigned long uint32;
    typedef float float24;
    typedef double float32;
    //=========================================================================================
    //=========================================================================================
    #define Bool _Bool  // bool type, when the value is not 0, then the result is 1, when the value is 0, then the result is 0. For example: _Bool a = 4; then a=1
    #define True 1
    #define False 0
    typedef char Char8; //-128~127
    typedef char Int8;
    typedef unsigned char Uint8;
    typedef short Int16;
    typedef unsigned short Uint16;
    typedef long Int32;
    typedef unsigned long Uint32;
    typedef float Float24;
    typedef double Float32;
    //=========================================================================================
    //=========================================================================================
    #define BOOL_TYPE_Def
    #define CHAR8_TYPE_Def
    #define INT8_TYPE_Def
    #define INT16_TYPE_Def
    #define INT32_TYPE_Def
    #define UINT8_TYPE_Def
    #define UINT16_TYPE_Def
    #define UINT32_TYPE_Def
    #define FLOAT24_TYPE_Def
    #define FLOAT32_TYPE_Def
    //=========================================================================================
    //=========================================================================================

#endif
#endif
