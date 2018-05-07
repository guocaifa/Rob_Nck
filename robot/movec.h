/*******************************************************************************
 *                   	       GPCNC
 *           The General-Purposed CNC Software Develop Environment
 *           (c) Copyright 2004-2013, Automation Depatment of NJIT
 *                         All Rights Reserved
 *
 *-----------------------�ļ���Ϣ-----------------------------------------------
 * �ļ���: .h
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
*******************************************************************************/

#ifndef MOVEC_H
#define MOVEC_H

#include <math.h>

#include "robot.h"
#include "linuxtypes.h"

typedef struct
{
  point     xCenter; //Բ��
  double    xR;      //�뾶
  bool      xCycDir; //Բ������  true:˳ʱ��  false:��ʱ��
  double    xAngle;  //�˶��ĽǶȴ�С
  matrix4_4 xTran;   //����ת��
}cycle;

extern void MoveC(coorquat *pCrn, coorquat *pMid, coorquat *pTgt, double Vmax, double Acc);

#endif // MOVEC_H
