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
#ifndef MATH_BASE_H
#define MATH_BASE_H

typedef struct
{
	double  Val[4][4];
}matrix;

typedef struct
{
  double  Val[3];
}point;

extern void MultMatrix(matrix *pResult, matrix *pFirst, matrix *pSecond);

extern bool MatrixBackwards(matrix *pMatrix);

#endif
