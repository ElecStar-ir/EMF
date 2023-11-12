/**
 ******************************************************************************************
 * Copyright (c) Electro Pardazesh Daghigh Aria(EPDA).Ltd Corporation. All rights reserved.
 * This software is licensed under the MIT License.
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
 * v4.1_14020824            E.Rahmanian    Create
 ******************************************************************************************
 */
#ifndef EMF_STANDARDS_H
#define EMF_STANDARDS_H
#if defined(EMF_C)
/*
    EMF Code Style is Google C/C++ Format + { BasedOnStyle: Google, IndentWidth: 4, TabWidth: 4 }
    ============================EMF Prefix and suffix========================================
    _DEF			=>		Define   ex)#define EMMF_MCUTYPE_DEF STM32
    _sub			=>		subroutine  ex)Void GetIp_sub();
    _subf			=>		subFunction  ex)char GetIp_subf();
    _SUBDEF			=>		subroutine Define
    _SUBFDEF		=>		subFunction Define
    _DEFSUB 		=>		subroutine Define
    _DEFSUBF		=>		subFunction Define
    _psub			=>		Pointer subroutine  ex)Void (*GetIp_psub)();
    _psubf			=>		Pointer subFunction  ex)char (*GetIp_psubf)();
    _				=>		Local(private) ex) bool _b5;
    _				=>		in c Language This character Equivalent  name space ! ex)EMMF_Uart__test_sub();
    __				=>		in c Language This characters means end of the name space and begim main sub or subf name start ! ex)EMMF_Uart__test_sub(); ->>name space is EMMF>Uart and sub name is est_sub in cpp language
    _t				=>		Type     ex)uint32_t a;
    _T				=>		Type     ex)uint32_T a;
    _DataType		=>		Type     ex)uint32_DataType a;
    _L				=>		Step     ex)void Uart_L1_init_sub();   char_t Uart_L2_Read_subf();
    _class			=>		class
    _enum			=>		Enum
    _ptr			=>		Pointer
    _p				=>		pointer
    _ns				=>		namespace
    _struct			=>		struct
    _m				=>		method  ex)Void GetIp_sub_m1();  Void GetIp_sub_m2();
    _r				=>		volatile const		=>		Defines 'read only' permissions
    _w				=>		volatile		=>		 Defines 'write only' permissions
    _rw				=>		volatile		=>		 Defines 'read / write' permissions
    _const			=>		const
    inlin			=>		inline
    _array			=>		array
    array			=>		array
    ex)N9			=>		-9
    ex)N90P6		=>		-9.6
    array_2_2		=>		array[2][2]
    Lx		        =>		Level Ex) L1_init(); L2_SetValue(255);
//=========================================================================================
//=========================================================================================
    doxygen: https://www.doxygen.nl/manual/commands.html
    @file
    @author
    @brief
    @attention
    @param			=>		ex) @param[out] a1 The memory area to copy to.
    @version		=>		ex) @version 990201_1
    @return
    @returns
    @code
    @endcode
//=========================================================================================
//=========================================================================================
    Data Types:
        bool
        char8
        char16         //is not supported in all types of microcontrollers
        char32         //is not supported in all types of microcontrollers
        uint8
        int16
        uint16
        int32
        uint32
        int64          //is not supported in all types of microcontrollers
        uint64         //is not supported in all types of microcontrollers
        float16        //is not supported in all types of microcontrollers
        float24        //is not supported in all types of microcontrollers
        float32
        float64        //is not supported in all types of microcontrollers

        Bool
        Char8
        Char16         //is not supported in all types of microcontrollers
        Char32         //is not supported in all types of microcontrollers
        Uint8
        Int16
        Uint16
        Int32
        Uint32
        Int64          //is not supported in all types of microcontrollers
        Uint64         //is not supported in all types of microcontrollers
        Float16        //is not supported in all types of microcontrollers
        Float24        //is not supported in all types of microcontrollers
        Float32
        Float64        //is not supported in all types of microcontrollers

        #define true 1
        #define false 0
        #define True 1
        #define False 0
//=========================================================================================
//=========================================================================================
    IDE Settings:

    Visual Studio Code Settings:
    CLang Format :
    { BasedOnStyle: Google,
    IndentWidth: 4,
    TabWidth: 4,
    AllowShortIfStatementsOnASingleLine: false,
    ColumnLimit: 0,
    IndentPPDirectives: BeforeHash }

    C_Cpp › Default: Intelli Sense Mode : clang-windows-x64
    C_Cpp: Intelli Sense Engine : Tag parser Or default

    Add include paths :
    1)Ctrl + Shift + P
    2)Select "C/C++:Edif Configuration (Ui)"
    3)Add Include paths
*/
#endif
#endif
