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
#include "robot.h"
#include "nck.h"

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
