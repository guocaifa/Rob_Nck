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
#ifndef MATH_BASE_H
#define MATH_BASE_H

typedef struct
{
	double  Val[4][4];
}matrix4_4;

typedef struct
{
  double  Val[3][3];
}matrix3_3;

typedef struct
{
  double  Val[3];
}point;

extern void MultMatrix(matrix4_4 *pResult, matrix4_4 *pFirst, matrix4_4 *pSecond);

extern bool MatrixBackwards(matrix4_4 *pMatrix);

#endif
