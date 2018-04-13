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
#ifndef ROBOT_H
#define ROBOT_H

#include "linuxtypes.h"
#include "math_base.h"

typedef struct
{
	u32   RodDistance[6]; /* ���˾��� */
	u32   RodLength[6];   /* ���˳��� */
}robotpara;

typedef struct
{
  u8      InpCycle;     /* �岹����  */
  double  JitSpd;       /* �ؽ��˶�����ٶ� */
  double  DcaSpd;       /* �ռ��˶�ָ������ٶ� */
}inppara;

typedef struct
{
	double      xAngleCrn[6];    /* ÿ����ĵ�ǰ�Ƕ�        */
	double      xAngleNxt[6];    /* ÿ�����Ŀ��Ƕ�        */

  robotpara   xParameter;      /* �����˵Ļ�е�ߴ�        */

	matrix      xStatusCrn;      /* ��ǰ�����˵�״̬        */
	matrix      xStatusNxt;      /* ��һ�λ����˵�״̬      */

  inppara     xInpParameter;   /* �������˶��岹����      */

}robsys;

extern robsys  xRobSys;

extern void InitRobSys(robsys *pRobSys);

#endif
