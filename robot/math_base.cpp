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

#include <string.h>

#include "math_base.h"

/* 函数说明:
 * 参    数:
 * 返 回 值:
 * 说    明:pResult = pFirst * pSexcond
*/
extern void MultMatrix(matrix4_4 *pResult, matrix4_4 *pFirst, matrix4_4 *pSecond)
{
	int     i,j;

  memset(pResult, 0, sizeof(matrix4_4));

	for(j = 0;j < 4;j++){
		for(i = 0; i < 4; i++){
      pResult->Val[j][0] += pFirst->Val[j][i] * pSecond->Val[i][0];
      pResult->Val[j][1] += pFirst->Val[j][i] * pSecond->Val[i][1];
      pResult->Val[j][2] += pFirst->Val[j][i] * pSecond->Val[i][2];
      pResult->Val[j][3] += pFirst->Val[j][i] * pSecond->Val[i][3];
    }
	}

	return;
}
