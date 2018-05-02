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

#ifndef MOVEL_H
#define MOVEL_H

#include <math.h>

#include "robot.h"

extern void MoveL(cooreuler *pStatusCrn, cooreuler *pStatusNxt, double dAcc, double dVmax);

#endif // MOVEL_H
