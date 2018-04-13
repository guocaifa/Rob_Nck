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

typedef struct
{
	u32   RodDistance[6]; /* 连杆距离 */
	u32   RodLength[6];   /* 连杆长度 */
}robotpara;

typedef struct
{
  u8      InpCycle;     /* 插补周期  */
  double  JitSpd;       /* 关节运动最大速度 */
  double  DcaSpd;       /* 空间运动指令最大速度 */
}inppara;

typedef struct
{
	double      xAngleCrn[6];    /* 每个轴的当前角度        */
	double      xAngleNxt[6];    /* 每个轴的目标角度        */

  robotpara   xParameter;      /* 机器人的机械尺寸        */

	matrix      xStatusCrn;      /* 当前机器人的状态        */
	matrix      xStatusNxt;      /* 下一次机器人的状态      */

  inppara     xInpParameter;   /* 机器人运动插补参数      */

}robsys;

extern robsys  xRobSys;

extern void InitRobSys(robsys *pRobSys);

#endif
