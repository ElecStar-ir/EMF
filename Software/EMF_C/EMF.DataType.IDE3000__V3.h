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
 * v4.0_14020803            E.Rahmanian    Create
 ******************************************************************************************
 */
#ifndef EMF_DATATYPE_IDE3000__V3_H
#define EMF_DATATYPE_IDE3000__V3_H
#if defined(IDE3000__V3)

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
typedef char char8;
typedef int8_t int8;
typedef uint8_t uint8;
typedef int16_t int16;
typedef uint16_t uint16;
typedef int32_t int32;
typedef uint32_t uint32;
typedef float float24;
typedef double float32;
    //=========================================================================================
    //=========================================================================================
    #define Bool _Bool  // bool type, when the value is not 0, then the result is 1, when the value is 0, then the result is 0. For example: _Bool a = 4; then a=1
    #define True 1
    #define False 0
typedef char Char8;
typedef int8_t Int8;
typedef uint8_t Uint8;
typedef int16_t Int16;
typedef uint16_t Uint16;
typedef int32_t Int32;
typedef uint32_t Uint32;
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
