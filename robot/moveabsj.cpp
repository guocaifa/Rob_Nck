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
#include <math.h>

#include "moveabsj.h"
#include "robot.h"

static int GetJitMaxTime(double *pAngleCrn, double *pAngleNxt);

extern void MoveAbsJoint(double *AngleTarget, double Vmax)
{
  double RunTMax,RunT = 0;
  double a[4];

  RunTMax = GetJitMaxTime(xRobSys.xAngleCrn, AngleTarget);

  if(RunTMax != 0){/*  */

    for(RunT = 0; RunT <= RunTMax; RunT++){
      for(int i = 0; i < 6; i++){

        a[0] = xRobSys.xAngleCrn[i];
        a[1] = 0;
        a[2] = (3 * (AngleTarget[i] - xRobSys.xAngleCrn[i])) / (RunTMax * RunTMax);
        a[3] = (2 * (AngleTarget[i] - xRobSys.xAngleCrn[i])) / (RunTMax * RunTMax * RunTMax);

        xRobSys.xAngleCrn[i] = a[0] + a[1] + a[2] * RunT * RunT + a[3] * RunT * RunT * RunT;
      }

      for(int i = 0; i < 6 ; i++){
        if(xRobSys.xAngleCrn[i] >= xRobSys.aRange[i][0]&& xRobSys.xAngleCrn[i] <= xRobSys.aRange[i][1])
          continue;
        else{
          xRobSys.xRunStatus = false;
          break;
        }
      }

      /* 发送角度给电机 */
    }
  }

  return;
}

static int GetJitMaxTime(double *pAngleCrn, double *pAngleNxt)
{
  int     nCycle = 0;
  double  AngleMax = 0;

  double  dUpL,dDwnL;
  int     iUpT,iDwnT,iCstT;
  double  UpAcc  = xRobSys.xInpParameter.xJointAccUp,
          DwnAcc = xRobSys.xInpParameter.xJointAccDwn,
          SpdMax = xRobSys.xInpParameter.xJointSpdMax,
          SpdMax2,/* 最大速度的平方 */
          SpdCrn = 0;

  double  AngleDiff[6];

  double *AngleNxt = pAngleNxt;
  double *AngleCrn = pAngleCrn;

  for(int i = 0; i < 6; i++){
    AngleDiff[i] = abs(AngleNxt[i] - AngleCrn[i]);
    if(AngleDiff[i] < 0.0000001)    AngleDiff[i] = 0;
  }

  for(int i = 0; i < 6; i++)    AngleMax = MAX(AngleMax, AngleDiff[i]);

  if(AngleMax == 0)                      nCycle = 0;
  else if(AngleMax <= (UpAcc + DwnAcc))  nCycle = 2;
  else{
    SpdMax2 = SpdMax * SpdMax;
    dUpL    = SpdMax2 / (2 * UpAcc);
    dDwnL   = SpdMax2 / (2 * DwnAcc);

    if(AngleMax < dUpL + dDwnL){
      iUpT = iDwnT = 1;

      AngleMax -= (dUpL + dDwnL);
      iCstT = AngleMax / SpdMax;

    }
    else{
      iUpT  = SpdMax / UpAcc;
      iDwnT = SpdMax / DwnAcc;

      AngleMax -= (dUpL + dDwnL);
      iCstT = AngleMax / SpdMax;
    }

    nCycle = (iUpT + iDwnT + iCstT);/* 加速时间 + 减速时间 + 匀速时间 */
  }

  return nCycle;

}
