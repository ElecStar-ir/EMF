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
 *
 ******************************************************************************************
 */
#ifndef EMF_BITMANIPULATION_IDE3000__V3_H
#define EMF_BITMANIPULATION_IDE3000__V3_H
#if defined(IDE3000__V3)

    #define MaskBit0 (0x1U)
    #define MaskBit1 (0x2U)
    #define MaskBit2 (0x4U)
    #define MaskBit3 (0x8U)
    #define MaskBit4 (0x10U)
    #define MaskBit5 (0x20U)
    #define MaskBit6 (0x40U)
    #define MaskBit7 (0x80U)
    #define MaskBit8 (0x100U)
    #define MaskBit9 (0x200U)
    #define MaskBit10 (0x400U)
    #define MaskBit11 (0x800U)
    #define MaskBit12 (0x1000U)
    #define MaskBit13 (0x2000U)
    #define MaskBit14 (0x4000U)
    #define MaskBit15 (0x8000U)
    #define MaskBit16 (0x10000U)
    #define MaskBit17 (0x20000U)
    #define MaskBit18 (0x40000U)
    #define MaskBit19 (0x80000U)
    #define MaskBit20 (0x100000U)
    #define MaskBit21 (0x200000U)
    #define MaskBit22 (0x400000U)
    #define MaskBit23 (0x800000U)
    #define MaskBit24 (0x1000000U)
    #define MaskBit25 (0x2000000U)
    #define MaskBit26 (0x4000000U)
    #define MaskBit27 (0x8000000U)
    #define MaskBit28 (0x10000000U)
    #define MaskBit29 (0x20000000U)
    #define MaskBit30 (0x40000000U)
    #define MaskBit31 (0x80000000U)
    //=========================================================================================
    //=========================================================================================
    typedef struct {
        uint32 bit0 : 1;
        uint32 bit1 : 1;
        uint32 bit2 : 1;
        uint32 bit3 : 1;
        uint32 bit4 : 1;
        uint32 bit5 : 1;
        uint32 bit6 : 1;
        uint32 bit7 : 1;
        uint32 bit8 : 1;
        uint32 bit9 : 1;
        uint32 bit10 : 1;
        uint32 bit11 : 1;
        uint32 bit12 : 1;
        uint32 bit13 : 1;
        uint32 bit14 : 1;
        uint32 bit15 : 1;
        uint32 bit16 : 1;
        uint32 bit17 : 1;
        uint32 bit18 : 1;
        uint32 bit19 : 1;
        uint32 bit20 : 1;
        uint32 bit21 : 1;
        uint32 bit22 : 1;
        uint32 bit23 : 1;
        uint32 bit24 : 1;
        uint32 bit25 : 1;
        uint32 bit26 : 1;
        uint32 bit27 : 1;
        uint32 bit28 : 1;
        uint32 bit29 : 1;
        uint32 bit30 : 1;
        uint32 bit31 : 1;
    } uint32Bits_t;
    //=========================================================================================
    //=========================================================================================
    typedef struct {
        uint16 bit0 : 1;
        uint16 bit1 : 1;
        uint16 bit2 : 1;
        uint16 bit3 : 1;
        uint16 bit4 : 1;
        uint16 bit5 : 1;
        uint16 bit6 : 1;
        uint16 bit7 : 1;
        uint16 bit8 : 1;
        uint16 bit9 : 1;
        uint16 bit10 : 1;
        uint16 bit11 : 1;
        uint16 bit12 : 1;
        uint16 bit13 : 1;
        uint16 bit14 : 1;
        uint16 bit15 : 1;
    } uint16Bits_t;
    //=========================================================================================
    //=========================================================================================
    typedef struct {
        uint8 bit0 : 1;
        uint8 bit1 : 1;
        uint8 bit2 : 1;
        uint8 bit3 : 1;
        uint8 bit4 : 1;
        uint8 bit5 : 1;
        uint8 bit6 : 1;
        uint8 bit7 : 1;
    } uint8Bits_t;
    //=========================================================================================
    //=========================================================================================
    // Set nBitx to 0
    #define Set_1BitTo0_SubDef(Main, BitNum_0tox_uint8) \
        (Main = Main & (~((typeof(Main))1 << (uint8)BitNum_0tox_uint8)))
    #define Set_2BitTo0_SubDef(Main, BitNum_0tox_uint8) \
        (Main = Main & (~((typeof(Main))0b11 << (uint8)BitNum_0tox_uint8)))
    #define Set_3BitTo0_SubDef(Main, BitNum_0tox_uint8) \
        (Main = Main & (~((typeof(Main))0b111 << (uint8)BitNum_0tox_uint8)))
    #define Set_4BitTo0_SubDef(Main, BitNum_0tox_uint8) \
        (Main = Main & (~((typeof(Main))0b1111 << (uint8)BitNum_0tox_uint8)))
    #define Set_5BitTo0_SubDef(Main, BitNum_0tox_uint8) \
        (Main = Main & (~((typeof(Main))0b11111 << (uint8)BitNum_0tox_uint8)))
    #define Set_6BitTo0_SubDef(Main, BitNum_0tox_uint8) \
        (Main = Main & (~((typeof(Main))0b111111 << (uint8)BitNum_0tox_uint8)))
    #define Set_7BitTo0_SubDef(Main, BitNum_0tox_uint8) \
        (Main = Main & (~((typeof(Main))0b1111111 << (uint8)BitNum_0tox_uint8)))

    #define Set_BitsTo0_WithMask_SubDef(Main, Mask_Ex_0b1011) \
        (Main &= (~Mask_Ex_0b1011))
    //=========================================================================================
    //=========================================================================================
    // Set nBitx to 1
    #define Set_1BitTo1_SubDef(Main, BitNum_0tox_uint8) \
        (Main = Main | ((typeof(Main))1 << (uint8)BitNum_0tox_uint8))
    #define Set_2BitTo1_SubDef(Main, BitNum_0tox_uint8) \
        (Main = Main | ((typeof(Main))0b11 << (uint8)BitNum_0tox_uint8))
    #define Set_3BitTo1_SubDef(Main, BitNum_0tox_uint8) \
        (Main = Main | ((typeof(Main))0b111 << (uint8)BitNum_0tox_uint8))
    #define Set_4BitTo1_SubDef(Main, BitNum_0tox_uint8) \
        (Main = Main | ((typeof(Main))0b1111 << (uint8)BitNum_0tox_uint8))
    #define Set_5BitTo1_SubDef(Main, BitNum_0tox_uint8) \
        (Main = Main | ((typeof(Main))0b11111 << (uint8)BitNum_0tox_uint8))
    #define Set_6BitTo1_SubDef(Main, BitNum_0tox_uint8) \
        (Main = Main | ((typeof(Main))0b111111 << (uint8)BitNum_0tox_uint8))
    #define Set_7BitTo1_SubDef(Main, BitNum_0tox_uint8) \
        (Main = Main | ((typeof(Main))0b1111111 << (uint8)BitNum_0tox_uint8))

    #define Set_BitsTo1_WithMask_SubDef(Main, Mask_Ex_0b1011) \
        (Main |= Mask_Ex_0b1011)
    //=========================================================================================
    //=========================================================================================
    // Set Bit(s)
    #define Set_1Bit_SubDef(Main, BitNum_0tox_uint8, ValueBit_0_1_bool)    \
        (Main = (bool)ValueBit_0_1_bool                                    \
                    ? Main | ((typeof(Main))1 << (uint8)BitNum_0tox_uint8) \
                    : Main & (~((typeof(Main))1 << (uint8)BitNum_0tox_uint8)))
    #define Set_2Bit_SubDef(Main, FirstBitNum_0tox_uint8, ValueBit_0to3_uint8)      \
        (Main = (Main & (~((typeof(Main))0b11 << (uint8)FirstBitNum_0tox_uint8))) | \
                (((typeof(Main))((uint8)ValueBit_0to3_uint8 & 0b11)                 \
                  << (uint8)FirstBitNum_0tox_uint8)))
    #define Set_3Bit_SubDef(Main, FirstBitNum_0tox_uint8, ValueBit_0to7_uint8)    \
        (Main =                                                                   \
             (Main & (~((typeof(Main))0b111 << (uint8)FirstBitNum_0tox_uint8))) | \
             (((typeof(Main))((uint8)ValueBit_0to7_uint8 & 0b111)                 \
               << (uint8)FirstBitNum_0tox_uint8)))
    #define Set_4Bit_SubDef(Main, FirstBitNum_0tox_uint8,                          \
                            ValueBit_0to15_uint8)                                  \
        (Main =                                                                    \
             (Main & (~((typeof(Main))0b1111 << (uint8)FirstBitNum_0tox_uint8))) | \
             (((typeof(Main))((uint8)ValueBit_0to15_uint8 & 0b1111)                \
               << (uint8)FirstBitNum_0tox_uint8)))
    #define Set_5Bit_SubDef(Main, FirstBitNum_0tox_uint8,                           \
                            ValueBit_0to31_uint8)                                   \
        (Main =                                                                     \
             (Main & (~((typeof(Main))0b11111 << (uint8)FirstBitNum_0tox_uint8))) | \
             (((typeof(Main))((uint8)ValueBit_0to31_uint8 & 0b11111)                \
               << (uint8)FirstBitNum_0tox_uint8)))
    #define Set_6Bit_SubDef(Main, FirstBitNum_0tox_uint8,                        \
                            ValueBit_0to63_uint8)                                \
        (Main = (Main &                                                          \
                 (~((typeof(Main))0b111111 << (uint8)FirstBitNum_0tox_uint8))) | \
                (((typeof(Main))((uint8)ValueBit_0to63_uint8 & 0b111111)         \
                  << (uint8)FirstBitNum_0tox_uint8)))
    #define Set_7Bit_SubDef(Main, FirstBitNum_0tox_uint8,                         \
                            ValueBit_0to127_uint8)                                \
        (Main = (Main &                                                           \
                 (~((typeof(Main))0b1111111 << (uint8)FirstBitNum_0tox_uint8))) | \
                (((typeof(Main))((uint8)ValueBit_0to127_uint8 & 0b1111111)        \
                  << (uint8)FirstBitNum_0tox_uint8)))

    #define Set_Bits_WithMask_SubDef(Main, Mask_High_Ex_0b1011, Mask_Low_Ex_0b1011) \
        (Main = (Main | Mask_High_Ex_0b1011) & (~Mask_Low_Ex_0b1011))
    //=========================================================================================
    //=========================================================================================
    // set uint8,uint16,uint32,uint64
    #define Set_Uint8_SubDef(Main, uint8Num_0tox, ValueUint8_0to255) \
        (((uint8 *)(&Main))[uint8Num_0tox] = ValueUint8_0to255)
    #define Set_Uint16_SubDef(Main, Uint16Num_0tox, ValueUint16_0to65535) \
        (((uint16 *)(&Main))[Uint16Num_0to x] = ValueUint16_0to65535)
    #define Set_Uint32_SubDef(Main, Uint32Num_0tox, ValueUint32_0to4294967295) \
        (((uint32 *)(&Main))[Uint32Num_0tox] = ValueUint32_0to4294967295)
    //=========================================================================================
    //=========================================================================================
    // Get Bit(s)
    #define Get_1Bit_Return_0or1_SubfDef(Main, BitNum_0tox_uint8) \
        ((Main >> BitNum_0tox_uint8) & (bool)0b1)
    #define Get_2Bit_Return_0or3_SubfDef(Main, FirstBitNum_0tox_uint8) \
        ((Main >> FirstBitNum_0tox_uint8) & (uint8)0b11)
    #define Get_3Bit_Return_0or7_SubfDef(Main, FirstBitNum_0tox_uint8) \
        ((Main >> FirstBitNum_0tox_uint8) & (uint8)0b111)
    #define Get_4Bit_Return_0or15_SubfDef(Main, FirstBitNum_0tox_uint8) \
        ((Main >> FirstBitNum_0tox_uint8) & (uint8)0b1111)
    #define Get_5Bit_Return_0or31_SubfDef(Main, FirstBitNum_0tox_uint8) \
        ((Main >> FirstBitNum_0tox_uint8) & (uint8)0b11111)
    #define Get_6Bit_Return_0or63_SubfDef(Main, FirstBitNum_0tox_uint8) \
        ((Main >> FirstBitNum_0tox_uint8) & (uint8)0b111111)
    #define Get_7Bit_Return_0or127_SubfDef(Main, FirstBitNum_0tox_uint8) \
        ((Main >> FirstBitNum_0tox_uint8) & (uint8)0b1111111)

    #define Get_1Bit_WithMask_Return_0or1_SubfDef(Main, Mask_Ex_0b1000) \
        ((Main & Mask_Ex_0b1000) && 1)

    #define Get_BitsIs1_WithMask_Return_0or1_SubfDef(Main, Mask_Ex_0b1000) \
        ((Main & Mask_Ex_0b1000) == Mask_Ex_0b1000)

    #define Get_BitsIs0_WithMask_Return_0or1_SubfDef(Main, Mask_Ex_0b1000) \
        ((Main & Mask_Ex_0b1000) == 0)

    #define Get_BitsIs0And1_WithMask_Return_0or1_SubfDef(Main, Bits1_Mask_Ex_0b1000, Bits0_Mask_Ex_0b1000) \
        (((Main & Bits1_Mask_Ex_0b1000) == Bits1_Mask_Ex_0b1000) && ((Main & Bits0_Mask_Ex_0b1000) == 0))
    //=========================================================================================
    //=========================================================================================
    // Get uint8,uint16,uint32,uint64
    #define Get_Uint8_SubfDef(Main, uint8Num_0tox) \
        (((uint8 *)(&Main))[uint8Num_0tox])
    #define Get_Uint16_SubfDef(Main, Uint16Num_0tox) \
        (((uint16 *)(&Main))[Uint16Num_0tox])
    #define Get_Uint32_SubfDef(Main, Uint32Num_0tox) \
        (((uint32 *)(&Main))[Uint32Num_0tox])
    //=========================================================================================
    //=========================================================================================
    // Toggle Bit(s)
    #define Toggle_Bits_WithMask_SubDef(Main, Mask_Ex_0b1011) \
        (Main ^= Mask_Ex_0b1011)

#endif
#endif