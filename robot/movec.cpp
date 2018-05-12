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
#include <string.h>
#include "movec.h"
#include "nck.h"

static void GetCycleProperty(cycle *pCycle, point *pCrn, point *pMid, point *pTrg);

extern void MoveC(coorquat *pCrn, coorquat *pMid, coorquat *pTgt, double Vmax, double Acc)
{
  int      RunTMax,RunT = 0;
  point    PointS,PointM,PointE;
  point    PCrn;

  coorquat xQuat;

  quatinp  Pose;
  double   xAngle;

  double   xSin1,xSin2;

  cycle Property;
  memset(&Property, 0, sizeof(cycle));

  for(int i = 0; i < 3; i++){
    PointS.Val[i] = pCrn->xCoor[i];
    PointM.Val[i] = pMid->xCoor[i];
    PointE.Val[i] = pTgt->xCoor[i];
  }

  GetCycleProperty(&Property, &PointS, &PointM, &PointE);

  PostureInp(&Pose, pCrn, pTgt, Vmax, Acc);
  RunTMax   = Pose.nCycle;
  xAngle    = Pose.xAngle;

  Vmax = Vmax / Property.xR;/* 线速度->角速度 */

  if(Property.xCycDir){/* 获得圆弧方向 */
    PCrn.Val[0] = Property.xR * cos(-Vmax * RunTMax);
    PCrn.Val[1] = Property.xR * sin(-Vmax * RunTMax);;
    PCrn.Val[2] = 0;
  }
  else{
    PCrn.Val[0] = Property.xR * cos(Vmax * RunTMax);
    PCrn.Val[1] = Property.xR * sin(Vmax * RunTMax);;
    PCrn.Val[2] = 0;
  }

  /* 进行插补工作 */
  for(RunT = 0; RunT <= RunTMax; RunT++){

    xSin1 = sin(((RunTMax - RunT) * xAngle) / RunTMax);
    xSin2 = sin((RunT * xAngle) / RunTMax);

    for(int j = 0; j < 4; j++){
      xQuat.xQuat[j] = (pCrn->xQuat[j] * xSin1 + pTgt->xQuat[j] * xSin2) / sin(xAngle);
    }
  }

  /* 转化到工作坐标系 */

  return;
}

static void GetCycleProperty(cycle *pCycle, point *pCrn, point *pMid, point *pTrg)
{
  double k11,k12,k13,k14,
         k21,k22,k23,k24,
         k31,k32,k33,k34;

  double x1 = pCrn->Val[0], y1 = pCrn->Val[1], z1 = pCrn->Val[2], \
         x2 = pMid->Val[0], y2 = pMid->Val[1], z2 = pMid->Val[2], \
         x3 = pTrg->Val[0], y3 = pTrg->Val[1], z3 = pTrg->Val[2]; \

  double x0,y0,z0;  //圆心坐标

  double det;
  double row1,row2,row3;
  double _k;
  double X1,Y1,Z1,X2,Y2,Z2;
  double p21x = x2 - x1,\
         p21y = y2 - y1,\
         p31x = x3 - x1,\
         p31y = y3 - y1;\
  double AngP1OP2,AngP1OP3;

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
        k13 * k22 * k31 - k12 * k21 * k33 - k32 * k23 * k11;/* 逆矩阵的行列式 */

  row1 = -k14 * (k22 * k33 - k23 * k32) + k24 * (k12 * k33 - k13 * k32) - k34 * (k12 * k23 - k22 * k13);

  row2 =  k14 * (k21 * k33 - k23 * k31) - k24 * (k11 * k33 - k31 * k13) + k34 * (k11 * k23 - k21 * k13);

  row3 = -k14 * (k21 * k32 - k31 * k22) + k24 * (k11 * k32 - k31 * k12) - k34 * (k11 * k22 - k21 * k12);

  pCycle->xCenter.Val[0] = x0 =  row1 / det;
  pCycle->xCenter.Val[1] = y0 =  row2 / det;
  pCycle->xCenter.Val[2] = z0 =  row3 / det;

  pCycle->xR = sqrt((x1 - x0) * (x1 - x0) + (y1 - y0) * (y1 - y0) + (z1 - z0) * (z1 - z0));

  /* n1 */
  pCycle->xTran.Val[0][0] = X2 = (x1 - x0) / pCycle->xR;
  pCycle->xTran.Val[1][0] = Y2 = (y1 - y0) / pCycle->xR;
  pCycle->xTran.Val[2][0] = Z2 = (z1 - z0) / pCycle->xR;
  pCycle->xTran.Val[3][0] = 0;
  /* a1 */
  _k = sqrt(k11 * k11 + k12 * k12 + k13 * k13);
  pCycle->xTran.Val[0][2] = X1 = k11 / _k;
  pCycle->xTran.Val[1][2] = Y1 = k12 / _k;
  pCycle->xTran.Val[2][2] = Z1 = k13 / _k;
  pCycle->xTran.Val[3][2] = 0;

  /* o1 = a1 * n1 */
  pCycle->xTran.Val[0][1] = Y1 * Z2 - Y2 * Z1;
  pCycle->xTran.Val[1][1] = Z1 * X2 - Z2 * X1;
  pCycle->xTran.Val[2][1] = X1 * Y2 - X2 * Y1;
  pCycle->xTran.Val[3][1] = 0;

  /* p0 */
  pCycle->xTran.Val[0][3] = x1;
  pCycle->xTran.Val[1][3] = y1;
  pCycle->xTran.Val[2][3] = z1;
  pCycle->xTran.Val[3][3] = 1;

  if(atan2(p21y,p21x) < 0)  AngP1OP2 = atan2(p21y,p21x) + 2 * PI;
  else                      AngP1OP2 = atan2(p21y,p21x);

  if(atan2(p31y,p31x) < 0)  AngP1OP3 = atan2(p31y,p31x) + 2 * PI;
  else                      AngP1OP3 = atan2(p31y,p31x);

  if(AngP1OP2 < AngP1OP3){
    pCycle->xCycDir = false;
    pCycle->xAngle  = AngP1OP3;
  }
  else{
    pCycle->xCycDir = true;
    pCycle->xAngle  = 2 * PI - AngP1OP3;
  }

  return;
}

