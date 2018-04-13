/*******************************************************************************
 *                   	       GPCNC
 *           The General-Purposed CNC Software Develop Environment
 *           (c) Copyright 2004-2013, Automation Depatment of NJIT
 *                         All Rights Reserved
 *
 *-----------------------�ļ���Ϣ-----------------------------------------------
 * �ļ���: .c
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
 ******************************************************************************/

#include <string.h>

#include "math_base.h"

/* ����˵��:
 * ��    ��:
 * �� �� ֵ:
 * ˵    ��:pResult = pFirst * pSexcond
*/
extern void MultMatrix(matrix *pResult, matrix *pFirst, matrix *pSecond)
{
	int     i,j;

	memset(pResult, 0, sizeof(matrix));

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