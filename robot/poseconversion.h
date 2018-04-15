#ifndef POSECONVERSION_H
#define POSECONVERSION_H

#include <math.h>

#include "math_base.h"

extern void matrix2euler(matrix3_3 *pMatrixPose, double *pEuler);
extern void euler2matrix(double *pEuler, matrix3_3 *pMatrixPose);

extern void quat2matrix(double *pQuat ,matrix3_3 *pMatrixPose);
extern void matrix2quat(matrix3_3 *pMatrixPose ,double *pQuat);

extern void euler2quat(double *pEuler, double *pQuat);
extern void quat2euler(double *pQuat, double *pEuler);

#endif // POSECONVERSION_H
