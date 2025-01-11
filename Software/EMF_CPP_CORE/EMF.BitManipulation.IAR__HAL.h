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
 * v5.0_14031024            E.Rahmanian    Optimize
 ******************************************************************************************
 */
#if defined(IAR__HAL)
#ifndef EMF_BITMANIPULATION_IAR__HAL_H
#define EMF_BITMANIPULATION_IAR__HAL_H

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
    #define MaskBit32 (0x100000000U)
    #define MaskBit33 (0x200000000U)
    #define MaskBit34 (0x400000000U)
    #define MaskBit35 (0x800000000U)
    #define MaskBit36 (0x1000000000U)
    #define MaskBit37 (0x2000000000U)
    #define MaskBit38 (0x4000000000U)
    #define MaskBit39 (0x8000000000U)
    #define MaskBit40 (0x10000000000U)
    #define MaskBit41 (0x20000000000U)
    #define MaskBit42 (0x40000000000U)
    #define MaskBit43 (0x80000000000U)
    #define MaskBit44 (0x100000000000U)
    #define MaskBit45 (0x200000000000U)
    #define MaskBit46 (0x400000000000U)
    #define MaskBit47 (0x800000000000U)
    #define MaskBit48 (0x1000000000000U)
    #define MaskBit49 (0x2000000000000U)
    #define MaskBit50 (0x4000000000000U)
    #define MaskBit51 (0x8000000000000U)
    #define MaskBit52 (0x10000000000000U)
    #define MaskBit53 (0x20000000000000U)
    #define MaskBit54 (0x40000000000000U)
    #define MaskBit55 (0x80000000000000U)
    #define MaskBit56 (0x100000000000000U)
    #define MaskBit57 (0x200000000000000U)
    #define MaskBit58 (0x400000000000000U)
    #define MaskBit59 (0x800000000000000U)
    #define MaskBit60 (0x1000000000000000U)
    #define MaskBit61 (0x2000000000000000U)
    #define MaskBit62 (0x4000000000000000U)
    #define MaskBit63 (0x8000000000000000U)
    //=========================================================================================
    //=========================================================================================
    typedef struct {
        uint64 bit0 : 1;
        uint64 bit1 : 1;
        uint64 bit2 : 1;
        uint64 bit3 : 1;
        uint64 bit4 : 1;
        uint64 bit5 : 1;
        uint64 bit6 : 1;
        uint64 bit7 : 1;
        uint64 bit8 : 1;
        uint64 bit9 : 1;
        uint64 bit10 : 1;
        uint64 bit11 : 1;
        uint64 bit12 : 1;
        uint64 bit13 : 1;
        uint64 bit14 : 1;
        uint64 bit15 : 1;
        uint64 bit16 : 1;
        uint64 bit17 : 1;
        uint64 bit18 : 1;
        uint64 bit19 : 1;
        uint64 bit20 : 1;
        uint64 bit21 : 1;
        uint64 bit22 : 1;
        uint64 bit23 : 1;
        uint64 bit24 : 1;
        uint64 bit25 : 1;
        uint64 bit26 : 1;
        uint64 bit27 : 1;
        uint64 bit28 : 1;
        uint64 bit29 : 1;
        uint64 bit30 : 1;
        uint64 bit31 : 1;
        uint64 bit32 : 1;
        uint64 bit33 : 1;
        uint64 bit34 : 1;
        uint64 bit35 : 1;
        uint64 bit36 : 1;
        uint64 bit37 : 1;
        uint64 bit38 : 1;
        uint64 bit39 : 1;
        uint64 bit40 : 1;
        uint64 bit41 : 1;
        uint64 bit42 : 1;
        uint64 bit43 : 1;
        uint64 bit44 : 1;
        uint64 bit45 : 1;
        uint64 bit46 : 1;
        uint64 bit47 : 1;
        uint64 bit48 : 1;
        uint64 bit49 : 1;
        uint64 bit50 : 1;
        uint64 bit51 : 1;
        uint64 bit52 : 1;
        uint64 bit53 : 1;
        uint64 bit54 : 1;
        uint64 bit55 : 1;
        uint64 bit56 : 1;
        uint64 bit57 : 1;
        uint64 bit58 : 1;
        uint64 bit59 : 1;
        uint64 bit60 : 1;
        uint64 bit61 : 1;
        uint64 bit62 : 1;
        uint64 bit63 : 1;
    } uint64Bits_t;
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
    #define Set_Uint64_SubDef(Main, Uint64Num_0tox,                \
                              ValueUint64_0to18446744073709551615) \
        (((uint64 *)(&Main))[Uint64Num_0tox] = ValueUint64_0to18446744073709551615)

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
    #define Get_Uint64_SubfDef(Main, Uint64Num_0tox) \
        (((uint64 *)(&Main))[Uint64Num_0tox])
    //=========================================================================================
    //=========================================================================================
    // Toggle Bit(s)
    #define Toggle_Bits_WithMask_SubDef(Main, Mask_Ex_0b1011) \
        (Main ^= Mask_Ex_0b1011)

#endif
#endif