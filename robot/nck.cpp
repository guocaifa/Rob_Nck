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

#include <stdio.h>
#include <string.h>

#include "nck.h"
#include "math_base.h"

static void GetRobParameter(robsys *pSys);

/* 参数说明:连杆长度：ai    连杆扭角：a(afa)i
 *        连杆偏置：di    关节角度：x(xeta)i
*/
static void GetRobParameter(robsys *pSys)
{
	u32   a1 = 150,d1 = 450,a2 = 600,a3 = 200, d4 = 740;

	/* 第一轴 */
	pSys->xParameter.RodDistance[0] = d1;
	pSys->xParameter.RodLength[0]   = a1;
	/* 第二轴 */
	pSys->xParameter.RodDistance[0] = 0;
	pSys->xParameter.RodLength[0]   = a2;
	/* 第三轴 */
	pSys->xParameter.RodDistance[0] = 0;
	pSys->xParameter.RodLength[0]   = a3;
	/* 第四轴 */
	pSys->xParameter.RodDistance[0] = d4;
	pSys->xParameter.RodLength[0]   = 0;
	/* 第五轴 */
	pSys->xParameter.RodDistance[0] = 0;
	pSys->xParameter.RodLength[0]   = 0;
	/* 第六轴 */
	pSys->xParameter.RodDistance[0] = 0;
	pSys->xParameter.RodLength[0]   = 0;

	return;
}

/* 函数说明:
 * 参    数:
 * 返 回 值:
*/
extern void InitRobotParameter(robsys *pSys)
{
	


	GetRobParameter(pSys);

	return;
}

/* 函数说明：获取当前机器人得状态矩阵
 * 参    数：
 * 返 回 值：无
*/
extern void GetRobStatusCrn(matrix4_4 *pStatusCrn, robotpara *pRobPara, double *pAngle)
{
  double *AngleCrn = pAngle;
  matrix4_4  StatusCrn;

	double c1,s1,c2,s2,c3,s3,c4,s4,c5,s5,c6,s6;
	double c23,s23;
	double a1,d1,a2,a3,d4;

	c1  = cos(AngleCrn[0]);     s1 = sin(AngleCrn[0]);
	c2  = cos(AngleCrn[1]);     s2 = sin(AngleCrn[1]);
	c3  = cos(AngleCrn[2]);     s3 = sin(AngleCrn[2]);
	c4  = cos(AngleCrn[3]);     s4 = sin(AngleCrn[3]);
	c5  = cos(AngleCrn[4]);     s5 = sin(AngleCrn[4]);
	c6  = cos(AngleCrn[5]);     s6 = sin(AngleCrn[5]);

	c23 = cos(AngleCrn[1] + AngleCrn[2]);
	s23 = sin(AngleCrn[1] + AngleCrn[2]);

  a1 = pRobPara->RodLength[0];
  d1 = pRobPara->RodDistance[0];
  a2 = pRobPara->RodLength[0];
  a3 = pRobPara->RodLength[0];
  d4 = pRobPara->RodDistance[0];

	StatusCrn.Val[0][0] = s1 * c4 * s5 - c1 * c23 * s4 * s6 + s1 * s4 * c5 *s6 + c1 * c23 * c4 * c5 * c6 - c1 * s23 * s5;
	StatusCrn.Val[1][0] = c1 * c4 * s6 + s1 * c23 * s4 * s6 - c1 * s4 * c5 * c6 + s1 * c23 * c4 * c5 * c6 + s1 * s23 * s5;
	StatusCrn.Val[2][0] = c23 * s5 * c6 + s23 * c4 * c5 * c6 - s23 * s4 * s6;

	StatusCrn.Val[0][1] = s1 * c4 * c6 - c1 * s23 * s5 - c1 * c23 * s4 * c6 - s1 * s4 * c5 * s6 - c1 * c23 * c4 * c5 * c6;
	StatusCrn.Val[1][1] = c1 * s4 * c5 * s6 - c1 * c23 * c4 * s6 + s1 * s23 * s5 - c1 * c4 * c6 - s1 * c23 * s4 * s6;
	StatusCrn.Val[2][1] = -c23 * s5 * s6 - s23 * s4 * c6 - c23 * c4 *c5 * s6;

	StatusCrn.Val[0][2] = s1 * s4 * s5 + c1 * c23 * c4 * s5 + c1 * s23 * c5;
	StatusCrn.Val[1][2] = s1 * s23 * c4 - c1 * c4 * s5 + s1 * c23 * c4 * s5;
	StatusCrn.Val[2][2] = c4 * s5 * s23 - c23 * c5;

	StatusCrn.Val[0][3] = a1 * c1 + a2 * c1 * c2 + a3 * c1 * c23 + d4 * c1 * s23;
	StatusCrn.Val[1][3] = a1 * s1 + a2 * s1 * c2 + a3 * s1 * c23 + d4 * s1 * s23;
	StatusCrn.Val[2][3] = d1 + a2 * s2 + a3 * s23 - d4 * c23;

	StatusCrn.Val[3][0] = 0;
	StatusCrn.Val[3][1] = 0;
	StatusCrn.Val[3][2] = 0;
	StatusCrn.Val[3][3] = 1;

  memcpy(pStatusCrn, &StatusCrn, sizeof(matrix4_4));/* 可重载 */

	return;
}

/* 函数说明：根据机器人的位置跟姿态获得各个关节的角度
 * 参    数：
 * 返 回 值：无
*/
extern void GetRobJointAngle(matrix4_4 *pRobStatus, robotpara *pRobPara, double *pAngle)
{
  matrix4_4 *RobStatus = pRobStatus;
	double *Angle    = pAngle;
	double  Angle23;

//	double m2,k1,k2,a0;

  double a0,nx,ny,nz,ox,oy,oz,ax,ay,az,px,py,pz;
	double a1,d1,a2,a3,d4;
	double s1,c1,s23,c23,c3,s3,c4,s4,s5,c5;

	nx = RobStatus->Val[0][0];  ny = RobStatus->Val[1][0];  nz = RobStatus->Val[2][0];
	ox = RobStatus->Val[0][1];  oy = RobStatus->Val[1][1];  oz = RobStatus->Val[2][1];
	px = RobStatus->Val[0][2];  py = RobStatus->Val[1][2];  pz = RobStatus->Val[2][2];

	a1 = pRobPara->RodLength[0];
	d1 = pRobPara->RodDistance[0];
	a2 = pRobPara->RodLength[0];
	a3 = pRobPara->RodLength[0];
	d4 = pRobPara->RodDistance[0];

	/*-------------------------------------------------------------------------------------------------------*/

	Angle[0] = atan(py / px);
	/*-------------------------------------------------------------------------------------------------------
	m2 = px * px + py * py;
	k1 = d4 * d4 + a3 * a3 + a2 * a2 - a1 * a1 - m2 + sqrt(m2) - (pz - d1) * (pz - d1);
	k2 = d4 * d4 + a3 * a3 + a2 * a2 - a1 * a1 - m2 - sqrt(m2) - (pz - d1) * (pz - d1);

	Angle[2] = -atan(a3 / d4) +- atan(k1 / sqrt(a3 * a3 + d4 * d4 - k1 * k1));
	
	c3 = cos(Angle[2]);    s3 = sin(Angle[2]);

	Angle23 = atan(((d1 - pz) * (a3 + a2 * c3) - (py * s1 + px * c1 - a1) * (a2 * s3 + d4)) 
		           ((py * s1 + px * c1 - a1) * (a3 + a2 * c3) + (d1 - pz) * (a2 * s3 + d4));

	Angle[1] = Angle23 - Angle[2];
	-------------------------------------------------------------------------------------------------------*/

	/*几何法求解避免多解-----------------------------------------------------------------------------------*/
  Angle[1] = 90 - (a2 * a2 - a3 * a3 - d4 * d4 + (sqrt(px * px + py * py) - a1) * (sqrt(px * px + py * py) - a1) + (pz - d1) * (pz - d1)) / (2 * a2 * sqrt((sqrt(px * px + py * py) - a1) * ((sqrt(px * px + py * py) - a1)) + (pz - d1) * (pz - d1)) - atan((pz - d1) / (sqrt(px * px + py * py) - a1)));
	Angle[2] = 180 - (a2 * a2 + a3 * a3 + d4 * d4 - (sqrt(px * px + py * py) - a1) * (sqrt(px * px + py * py) - a1) + (pz - d1) * (pz - d1)) / (2 * a2 * sqrt(a3 * a3 + d4 * d4)) - atan(d4 / a3);

	Angle23 = Angle[1] + Angle[2];

	s1 = sin(Angle[0]);    c1 = cos(Angle[0]);
	s23 = sin(Angle23);    c23 = cos(Angle23);

	Angle[3] = atan((ax * s1 - ay * c1) / (c23 * (ax * c1 + ay * s1) + az * s23));

	c4 = cos(Angle[3]);    s4 = sin(Angle[3]);

	Angle[4] = atan((ax * (c1 * c23 * c4 + s1 * s4) + ay * (s1 * c23 * c4 + c1 * s4) + a2 * s23 * c4)/
		            (ax * c1 * s23 + ay * s1 * s23 - az * c23));

	s5  = sin(Angle[4]);    c5  = cos(Angle[4]);

	a0 = nz * (c23 * s5 + s23 * c4 * c5) - nx * (c1 * s23 * s5 - c1 * c23 * c4 * c5 - s1 * s4 * c5 - ny * (s1 * s23 * s5 - s1 * c23 * c4 *c5 + c1 * s4 * c5));

	Angle[5] = atan((-nx * (c1 * c23 * s4 - s1 * c4) - ny * (s1 * c23 * s4 + c1 * c4) - nz * s23 *s4) / a0);

	return;
}

extern void RodShiftFormula(robsys *pSys)
{
	return;
}
