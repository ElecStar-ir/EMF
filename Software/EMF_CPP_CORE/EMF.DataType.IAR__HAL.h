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
 * v4.0_14020803            E.Rahmanian    Create
 ******************************************************************************************
 */
#ifndef EMF_DATATYPE_IAR__HAL_H
#define EMF_DATATYPE_IAR__HAL_H
#if defined(IAR__HAL)

#include <stdint.h>
namespace EMF::DataType {

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
    // bool Data Type is defined in IAR - Don't Need use typedef
    // bool type, when the value is not 0, then the result is 1, when the value is 0, then the result is 0. For example: _Bool a = 4; then a=1
    #define true 1
    #define false 0
typedef char char8;
typedef char16_t char16;
typedef char32_t char32;
typedef int8_t int8;
typedef uint8_t uint8;
typedef int16_t int16;
typedef uint16_t uint16;
typedef int32_t int32;
typedef uint32_t uint32;
typedef int64_t int64;
typedef uint64_t uint64;
typedef __fp16 float16;
typedef float float32;
typedef double float64;
//=========================================================================================
//=========================================================================================
typedef bool Bool;  // bool type, when the value is not 0, then the result is 1, when the value is 0, then the result is 0. For example: _Bool a = 4; then a=1
    #define True 1
    #define False 0
typedef char Char8;
typedef char16_t Char16;
typedef char32_t Char32;
typedef int8_t Int8;
typedef uint8_t Uint8;
typedef int16_t Int16;
typedef uint16_t Uint16;
typedef int32_t Int32;
typedef uint32_t Uint32;
typedef int64_t Int64;
typedef uint64_t Uint64;
typedef __fp16 Float16;
typedef float Float32;
typedef double Float64;
    //=========================================================================================
    //=========================================================================================
    #define BOOL_TYPE_Def
    #define CHAR8_TYPE_Def
    #define CHAR16_TYPE_Def
    #define CHAR32_TYPE_Def
    #define INT8_TYPE_Def
    #define INT16_TYPE_Def
    #define INT32_TYPE_Def
    #define INT64_TYPE_Def
    #define UINT8_TYPE_Def
    #define UINT16_TYPE_Def
    #define UINT32_TYPE_Def
    #define UINT64_TYPE_Def
    #define FLOAT16_TYPE_Def
    #define FLOAT32_TYPE_Def
    #define FLOAT64_TYPE_Def
//=========================================================================================
//=========================================================================================
}  // namespace EMF::DataType
using namespace EMF::DataType;

#endif
#endif
