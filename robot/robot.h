/*******************************************************************************
 *                   	       GPCNC
 *           The General-Purposed CNC Software Develop Environment
 *           (c) Copyright 2004-2013, Automation Depatment of NJIT
 *                         All Rights Reserved
 *
 *-----------------------文件信息-----------------------------------------------
 * 文件名: .h
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
	u32   RodDistance[6]; /* 连杆距离 */
	u32   RodLength[6];   /* 连杆长度 */
}robotpara;

typedef struct
{
  u8        InpCycle;     /* 插补周期  */
  double    xJointAccUp;     /* 关节的加速度           */
  double    xJointAccDwn;    /* 关节的减速度           */
  double    xJointSpdMax;    /* 关节最大速度           */

  cdouble   aInpMax;         /* 笛卡尔下的插补大小      */
  double    xDecareAcc;      /* 笛卡尔下的坐标系加速度   */
}inppara;

typedef struct movebuff
{
  u8        uCmd;    /* 运动指令  */
  u16       uSpd;    /* 速度     */
  u32       uMid[8]; /* 中间点   */
  u32       uTrg[8]; /* 终点     */
  struct    movebuff *pNxt;
}movebuff;

typedef struct
{

  bool        xRunStatus;      /* 系统运行状态           */

	double      xAngleCrn[6];    /* 每个轴的当前角度        */
	double      xAngleNxt[6];    /* 每个轴的目标角度        */

  robotpara   xParameter;      /* 机器人的机械尺寸        */

  matrix4_4   xStatusCrn;      /* 当前机器人的状态        */
  matrix4_4   xStatusNxt;      /* 下一次机器人的状态      */

  inppara     xInpParameter;   /* 机器人运动插补参数      */

  movebuff    xMoveBuff[5];    /* 机器人的运动缓冲区      */

}robsys;

extern robsys  xRobSys;

extern void InitRobSys(robsys *pRobSys);

extern void Quat2Matrix(matrix4_4 *pMatrix, coorquat *pCoorQuat);

#endif
