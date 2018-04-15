#include "poseconversion.h"

/*------------------------------------------------------------------*
 |欧拉角是按照ZXZ轴顺序旋转,角度为 Φ , θ theta, φ phi                     |
 *------------------------------------------------------------------*
*/
extern void matrix2euler(matrix3_3 *pMatrixPose, double *pEuler)
{
  double c1,s1,c2,s2,c3,s3;

  double    *Euler  = pEuler;
  matrix3_3 *Matrix = pMatrixPose;

  c1 = cos(Euler[0]);   s1 = sin(Euler[0]);
  c2 = cos(Euler[1]);   s2 = sin(Euler[1]);
  c3 = cos(Euler[2]);   s3 = sin(Euler[2]);

  Matrix->Val[0][0] =  c3 * c2 * c1 - s3 * s1;
  Matrix->Val[0][1] = -c3 * s1 - c1 * c2 * s3;
  Matrix->Val[0][2] =  c1 * s2;

  Matrix->Val[1][0] =  c1 * s3 + c3 * c2 * s1;
  Matrix->Val[1][1] =  c3 * c1 - c2 * s3 * s1;
  Matrix->Val[1][2] =  s1 * s2;

  Matrix->Val[2][0] = -c3 * s2;
  Matrix->Val[2][1] =  s3 * s2;
  Matrix->Val[2][2] =  c2;

  return;
}

extern void euler2matrix(double *pEuler, matrix3_3 *pMatrixPose)
{
  double    *Euler  = pEuler;
  matrix3_3 *Matrix = pMatrixPose;

//  Euler[0] = ;
//  Euler[1] = ;
//  Euler[2] = ;

  return;
}

extern void quat2matrix(double *pQuat ,matrix3_3 *pMatriPose)
{
  return;
}

extern void matrix2quat(matrix3_3 *pMatriPose ,double *pQuat)
{
  return;
}

extern void euler2quat(double *pEuler, double *pQuat)
{
  return;
}

extern void quat2euler(double *pQuat, double *pEuler)
{
  return;
}
