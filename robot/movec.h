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

extern void MoveC(coorquat *pCrn, coorquat *pMid, coorquat *pTgt, double Vmax, double Acc);

#endif // MOVEC_H
