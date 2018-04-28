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

typedef  const double    cdouble;

typedef struct
{
  double xCoor[3];  /* xyz */
  double xQuat[4];  /* q1,q2,q3,q4 */
}coorquat;

typedef struct
{
	u32   RodDistance[6]; /* ���˾��� */
	u32   RodLength[6];   /* ���˳��� */
}robotpara;

typedef struct
{
  u8        InpCycle;     /* �岹����  */
  double    xJointAccUp;     /* �ؽڵļ��ٶ�           */
  double    xJointAccDwn;    /* �ؽڵļ��ٶ�           */
  double    xJointSpdMax;    /* �ؽ�����ٶ�           */

  cdouble   aInpMax;         /* �ѿ����µĲ岹��С      */
  double    xDecareAcc;      /* �ѿ����µ�����ϵ���ٶ�   */
}inppara;

typedef struct movebuff
{
  u8        uCmd;    /* �˶�ָ��  */
  u16       uSpd;    /* �ٶ�     */
  u32       uMid[8]; /* �м��   */
  u32       uTrg[8]; /* �յ�     */
  struct    movebuff *pNxt;
}movebuff;

typedef struct
{

  bool        xRunStatus;      /* ϵͳ����״̬           */

	double      xAngleCrn[6];    /* ÿ����ĵ�ǰ�Ƕ�        */
	double      xAngleNxt[6];    /* ÿ�����Ŀ��Ƕ�        */

  robotpara   xParameter;      /* �����˵Ļ�е�ߴ�        */

  matrix4_4   xStatusCrn;      /* ��ǰ�����˵�״̬        */
  matrix4_4   xStatusNxt;      /* ��һ�λ����˵�״̬      */

  inppara     xInpParameter;   /* �������˶��岹����      */

  movebuff    xMoveBuff[5];    /* �����˵��˶�������      */

}robsys;

extern robsys  xRobSys;

extern void InitRobSys(robsys *pRobSys);

extern void Quat2Matrix(matrix4_4 *pMatrix, coorquat *pCoorQuat);

#endif
