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
#include "movel.h"

extern void MoveL(cooreuler *pStatusCrn, cooreuler *pStatusNxt, double dAcc, double dVmax)
{
  coorquat *Crn = pStatusCrn;
  coorquat *Nxt = pStatusNxt;

  double nInp[3],DetaInp[3];
  int    nInpMax = 0;/* �岹���� */

  for(int i = 0; i < 3; i++)  nInp[i] = (Crn->xCoor[i] - Nxt->xCoor[i]) / xRobSys.xInpParameter.aInpMax;
  for(int i = 0; i < 3; i++)  nInpMax = MAX(nInpMax, abs(nInp[i]));
  for(int i = 0; i < 3; i++)  DetaInp[i] = (Crn->xCoor[i] - Nxt->xCoor[i]) / nInpMax;/* ÿ�εĲ岹�� */

  for(int i = 0;i < 3; i++){}

  return;
}
