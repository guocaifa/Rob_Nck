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

static int GetJitMaxTime(double *pAngleCrn, double *pAngleNxt, const double Vmax);

extern void MoveAbsJoint(double *AngleTarget, double Vmax)
{
  double RunT      = 0, RunTMax,
         dRunCycle = (double)xRobSys.xInpParameter.InpCycle;/* 插补周期 */
//  double Cycle1_2  = dRunCycle / 2;
  double a[4];

  RunTMax = GetJitMaxTime(xRobSys.xAngleCrn, AngleTarget, Vmax);

  if(RunTMax != 0){/*  */

//    if(((RunTMax % dRunCycle) >= Cycle2))   RunTMax++;

    while(RunT <= RunTMax){/* 运行到目标点 */
      for(int i = 0; i < 6; i++){

        a[0] = xRobSys.xAngleCrn[i];
        a[1] = 0;
        a[2] = (3 * (AngleTarget[i] - xRobSys.xAngleCrn[i])) / (RunTMax * RunTMax);
        a[3] = (2 * (AngleTarget[i] - xRobSys.xAngleCrn[i])) / (RunTMax * RunTMax * RunTMax);

        xRobSys.xAngleCrn[i] = a[0] + a[1] + a[2] * RunT * RunT + a[3] * RunT * RunT * RunT;
      }

      RunT += dRunCycle;

      /* 发送角度给电机 */
    }
  }

  return;
}

static int GetJitMaxTime(double *pAngleCrn, double *pAngleNxt, const double Vmax)
{
  int     Tmax = 0;
  double  AngleMax = 0;

  int     UpCycle,DwnCycle;

  double  AngleDiff[6];

  double *AngleNxt = pAngleNxt;
  double *AngleCrn = pAngleCrn;

  for(int i = 0; i < 6; i++){
    AngleDiff[i] = abs(AngleNxt[i] - AngleCrn[i]);
    if(AngleDiff[i] < 0.0000001)    AngleDiff[i] = 0;
  }

  for(int i = 0; i < 6; i++)    AngleMax = MAX(AngleMax, AngleDiff[i]);

  if(AngleMax == 0)                                                  Tmax = 0;
  else if(AngleMax <= (xRobSys.xJointAccUp + xRobSys.xJointAccDwn))  Tmax = 2;
  else{
    UpCycle  = xRobSys.xJointSpdMax / xRobSys.xJointAccUp;
    DwnCycle = xRobSys.xJointSpdMax / xRobSys.xJointAccDwn;


  }

  return Tmax;

}
