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
#if defined(IDE3000__V2)
#ifndef EMF_DATATYPE_IDE3000__V2_H
#define EMF_DATATYPE_IDE3000__V2_H

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
    // Bit type, the least significant bit is valid. For example, if bit a = 4; then a=0
    #define bit bit  
    #define true 1
    #define false 0
    typedef char char8; //-128~127
    typedef signed char int8;
    typedef unsigned char uint8;
    typedef int int16;
    typedef unsigned int uint16;
    typedef long int32;
    typedef unsigned long uint32;
    typedef float float32;
    //=========================================================================================
    //=========================================================================================
    #define True 1
    #define False 0
    typedef char Char8; //-128~127
    typedef signed char Int8;
    typedef unsigned char Uint8;
    typedef int Int16;
    typedef unsigned int Uint16;
    typedef long Int32;
    typedef unsigned long Uint32;
    typedef float Float32;
    //=========================================================================================
    //=========================================================================================
    #define CHAR8_TYPE_Def
    #define INT8_TYPE_Def
    #define INT16_TYPE_Def
    #define INT32_TYPE_Def
    #define UINT8_TYPE_Def
    #define UINT16_TYPE_Def
    #define UINT32_TYPE_Def
    #define FLOAT32_TYPE_Def
    //=========================================================================================
    //=========================================================================================

#endif
#endif