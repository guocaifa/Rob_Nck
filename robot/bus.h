/*******************************************************************************
 *                   	       GPCNC
 *           The General-Purposed CNC Software Develop Environment
 *           (c) Copyright 2004-2013, Automation Depatment of NJIT
 *                         All Rights Reserved
 *
 *-----------------------文件信息-----------------------------------------------
 * 文件名: .h
 * 描  述:
 *
 * 创建人:
 * 版  本:
 * 日  期:
 *
 * 修改人:
 * 版  本:
 * 日　期:
 * 修改信息:
 *
 * 说明:
 *
 *...
*******************************************************************************/
#ifndef BUS_H
#define BUS_H

#include "linuxtypes.h"

typedef struct
{
  u8   aHeard;
  u8   cType;

  u8   aCmd[4];
  u8   aSub[4];
  union{
    u16  uData[4];
    u16  iData[4];
  };

  u16  aAxis[8];

  u16  nCRC;
}nck;

#define NCK_MOVENONE    0x00

#define NCK_MOVE        0x01
  #define SUB_MOVEABSJ  0x01
  #define SUB_MOVEJ     0x02
  #define SUB_MOVEL     0x03
  #define SUB_MOVEC     0x04

#define  MOVE_ITP       0x02
  #define SUB_

#define NCK_DATA        0xFF
  #define  DATA_FALSE   0x00
  #define  DATA_TRUE    0x01

#endif
