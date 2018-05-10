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
#include "robot.h"
#include "nck.h"
#include "poseconversion.h"

robsys  xRobSys;

static void InitMoveBuff(movebuff *pMoveCmdBuff, int xNum);

extern void InitRobSys(robsys *pRobSys)
{
  InitRobotParameter(pRobSys);
  InitMoveBuff(pRobSys->xMoveBuff, 5);
  return;
}

static void InitMoveBuff(movebuff *pMoveCmdBuff, int xNum)
{
  xNum -= 1;

  for(int i = 0; i < xNum; i++){
    pMoveCmdBuff[i].pNxt = &(pMoveCmdBuff[i + 1]);
  }

  pMoveCmdBuff[xNum].pNxt = pMoveCmdBuff;

  return;
}

extern void Quat2Matrix(matrix4_4 *pMatrix, coorquat *pCoorQuat)
{
  matrix3_3  R;

  quat2matrix(pCoorQuat->xQuat, &R);

  for(int i = 0;i < 3; i++){
    for(int j = 0; j < 3; j++){
      pMatrix->Val[i][j] = R.Val[i][j];
    }
  }

  pMatrix->Val[0][3] = pCoorQuat->xCoor[0];
  pMatrix->Val[1][3] = pCoorQuat->xCoor[1];
  pMatrix->Val[2][3] = pCoorQuat->xCoor[2];

  pMatrix->Val[3][0] = 0;
  pMatrix->Val[3][1] = 0;
  pMatrix->Val[3][2] = 0;
  pMatrix->Val[3][3] = 1;

  return;
}
