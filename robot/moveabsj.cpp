/*******************************************************************************
 *                   	       GPCNC
 *           The General-Purposed CNC Software Develop Environment
 *           (c) Copyright 2004-2013, Automation Depatment of NJIT
 *                         All Rights Reserved
 *
 *-----------------------�ļ���Ϣ-----------------------------------------------
 * �ļ���: .c
 * ��  ��:
 *
 * ������:
 * ��  ��:
 * ��  ��:
 *
 * �޸���:
 * ��  ��:
 * �ա���:
 * �޸���Ϣ:
 *
 * ˵��:
 *
 *...
 ******************************************************************************/
#include <math.h>

#include "moveabsj.h"
#include "robot.h"

static double GetJitMaxTime(const double *pAngleCrn, const double *pAngleNxt, const double Vmax);

extern void MoveAbsJoint(double *AngleTarget, double Vmax)
{
  double RunT      = 0, RunTMax,
         dRunCycle = xRobSys.xInpParameter.InpCycle;
  double a[4];

  RunTMax = GetJitMaxTime(xRobSys.xAngleCrn, AngleTarget, Vmax);

  if(RunTMax != 0){/*  */

    if((RunTMax % dRunCycle) >= (dRunCycle / 2))   RunTMax++;

    while(RunT <= RunMax){/* ���е�Ŀ��� */
      for(int i = 0; i < 6; i++){

        a[0] = xRobSys.xAngleCrn[i];
        a[1] = 0;
        a[2] = (3 * (AngleTarget[i] - xRobSys.xAngleCrn[i])) / (RunTMax * RunTMax);
        a[3] = (2 * (AngleTarget[i] - xRobSys.xAngleCrn[i])) / (RunTMax * RunTMax * RunTMax);

        xRobSys.xAngleCrn[i] = a[0] + a[1] + a[2] * RunT * RunT + a[3] * RunT * RunT * RunT;
      }

      RunT += dRunCycle;

      /* ���ͽǶȸ���� */
    }
  }

  return;
}

static double GetJitMaxTime(const double *pAngleCrn, const double *pAngleNxt, const double Vmax)
{
  double  Tmax = 0;
  double  AngleMax = 0;

  double  AngleDiff[6];

  double *AngleNxt = pAngleNxt;
  double *AngleCrn = pAngleCrn;

  for(int i = 0; i < 6; i++){
    AngleDiff[i] = abs(AngleNxt[i] - AngleCrn[i]);
    if(AngleDiff[i] < 0.0000001)    AngleDiff[i] = 0;
  }

  for(int i = 0; i < 6; i++)    AngleMax = MAX(AngleMax, AngleDiff[i]);

  Tmax = AngleMax / Vmax;

  return Tmax;

}
