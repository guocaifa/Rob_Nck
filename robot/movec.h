#ifndef MOVEC_H
#define MOVEC_H

#include <math.h>

#include "robot.h"
#include "linuxtypes.h"

extern void MoveC(coorquat *pMid, coorquat *pTgt, double Vmax);

#endif // MOVEC_H
