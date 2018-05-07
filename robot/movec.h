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

#ifndef MOVEC_H
#define MOVEC_H

#include <math.h>

#include "robot.h"
#include "linuxtypes.h"

typedef struct
{
  point     xCenter; //圆心
  double    xR;      //半径
  bool      xCycDir; //圆弧方向  true:顺时针  false:逆时针
  double    xAngle;  //运动的角度大小
  matrix4_4 xTran;   //矩阵转化
}cycle;

extern void MoveC(coorquat *pCrn, coorquat *pMid, coorquat *pTgt, double Vmax, double Acc);

#endif // MOVEC_H
