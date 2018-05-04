/*******************************************************************************
 *                   	       GPCNC
 *           The General-Purposed CNC Software Develop Environment
 *           (c) Copyright 2004-2013, Automation Depatment of NJIT
 *                         All Rights Reserved
 *
 *-----------------------文件信息-----------------------------------------------
 * 文件名: .c
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
 ******************************************************************************/

#include "movec.h"

static void GetOMatrix(point *pCenter, point *pCrn, point *pMid, point *pTrg);
static void GetCycleO(point *pO, const point *pCrn, const point *pMid, const point *pEnd);

extern void MoveC(coorquat *pCrn, coorquat *pMid, coorquat *pTgt, double Vmax, double Acc)
{
}

/* 函数说明；求圆弧的圆心
 *
*/
static void GetCycleO(point *pO, const point *pCrn, const point *pMid, const point *pEnd)
{

  /* x */
//  pO->Val[0] = ;
  /* y */
//  pO->Val[1] = ;
  /* z */
//  pO->Val[2] = ;

  return;
}

static void GetOMatrix(point *pCenter, point *pCrn, point *pMid, point *pTrg)
{
  double k11,k12,k13,\k14, \
         k21,k22,k23,\k24, \
         k31,k32,k33,\k34; \

  double x1 = pCrn->Val[0], y1 = pCrn->Val[1], z1 = pCrn->Val[2], \
         x2 = pMid->Val[0], y2 = pMid->Val[1], z2 = pMid->Val[2], \
         x3 = pTrg->Val[0], y3 = pTrg->Val[1], z3 = pTrg->Val[2]; \

  double det;

  k11 = (y1 - y3) * (z2 - z3) - (y2 - y3) * (z1 - z3);
  k12 = (x2 - x3) * (z1 - z3) - (x1 - x3) * (z2 - z3);
  k13 = (x1 - x3) * (y2 - y3) - (x2 - x3) * (y1 - y3);
  k14 = -(k11 * x3 + k12 * y3 + k13 * z3);

  k21 = x2 - x3;
  k22 = y2 - y1;
  k23 = z2 - z1;
  k24 = -((x2 * x2 - x1 * x1) + (y2 * y2 - y1 * y1) + (z2 * z2 - z1 * z1)) / 2;

  k31 = x3 - x2;
  k32 = y3 - y2;
  k33 = z3 - z2;
  k34 = -((x3 * x3 - x2 * x2) + (y3 * y3 - y2 * y2) + (z3 * z3 - z2 * z2)) / 2;

  det = k11 * k22 * k33 + k31 * k12 * k23 + k21 * k32 * k13 - \
        k13 * k22 * k31 - k12 * k21 * k33 - k32 * k23 * k11;

  pCenter->Val[0] = ;
  pCenter->Val[1] = ;
  pCenter->Val[2] = ;

  return;
}
