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

#ifndef NCK_H
#define NCK_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "linuxtypes.h"
#include "math_base.h"
#include "robot.h"

/*---------------------------------------------------------------------------------*
 |                             机器人的D-H参数表                                   |
 | 连杆i     | 轴转角bi    | 连杆长度ai   | 连杆偏距di   | 关节角   | 关节变量范围 |
 |   1            90             a1              d1          x1         -170~170   |
 |   2             0             a2               0          x2         -85 ~120   |
 |   3            90             a3               0          x3         -170~85    |
 |   4           -90              0              d4          x4         -180~180   |
 |   5            90              0               0          x5         -135~135   |
 |   6             0              0               0          x6         -360~360   |
 *---------------------------------------------------------------------------------*/
extern void InitRobotParameter(robsys *pSys);

extern void RodShiftFormula(robsys *pSys);

/*-----------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------*/

extern void GetRobStatusCrn(matrix4_4 *pStatusCrn,robotpara *pRobPara, double *pAngle);
extern void GetRobJointAngle(matrix4_4 *pRobStatus, robotpara *pRobPara, double *pAngle);

#endif
