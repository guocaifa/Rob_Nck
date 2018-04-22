#include "poseconversion.h"

/*------------------------------------------------------------------*
 |欧拉角是按照ZXZ轴顺序旋转,角度分别为 aerfa ,beta , gama                 |
 *------------------------------------------------------------------*
*/
extern void matrix2euler(matrix3_3 *pMatrixPose, double *pEuler)
{
  double c1,s1,c2,s2,c3,s3;

  double    *Euler  = pEuler;
  matrix3_3 *Matrix = pMatrixPose;

  c1 = cos(Euler[0]);   s1 = sin(Euler[0]);  /* aerfa */
  c2 = cos(Euler[1]);   s2 = sin(Euler[1]);  /* beta */
  c3 = cos(Euler[2]);   s3 = sin(Euler[2]);  /* gama */

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
  double nx,ny,nz,ox,oy,oz,ax,ay,az;

  nx = Matrix->Val[0][0];  ox = Matrix->Val[0][1];  ax = Matrix->Val[0][2];
  ny = Matrix->Val[1][0];  oy = Matrix->Val[1][1];  ay = Matrix->Val[1][2];
  nz = Matrix->Val[2][0];  oz = Matrix->Val[2][1];  az = Matrix->Val[2][2];

  Euler[1] = atan2(sqrt(nz * nz + oz * oz), az);

  if(sin(Euler[1]) != 0){
    Euler[0] = atan2(oz / sin(Euler[1]), -nz / sin(Euler[1]));
    Euler[2] = atan2(ay / sin(Euler[1]), ax / sin(Euler[1]));
  }

  return;
}

/*-----------------------------------------------------------------------*
 |            q = q1 + q2 * i + q3 * j + q4 * k                          |
 |         i:代表X轴和Y轴相交平面中X轴正向向Y轴正向的旋转                        |
 |         j:代表Z轴与X轴相交平面中Z轴正向向X轴正向的旋转                        |
 |         k:代表Y轴与Z轴相交平面中Y轴正向向Z轴正向的旋转                        |
 *-----------------------------------------------------------------------*/
extern void quat2matrix(double *pQuat ,matrix3_3 *pMatriPose)
{
  double *Quat = pQuat;
  matrix3_3 *Matrix = pMatriPose;

  double q0,q1,q2,q3;

  q0 = Quat[0];  q1 = Quat[1];
  q2 = Quat[2];  q3 = Quat[3];

  Matrix->Val[0][0] = q0 * q0 + q1 * q1 - q2 * q2 - q3 * q3;
  Matrix->Val[1][0] = 2 * (q1 * q2 + q0 * q3);
  Matrix->Val[2][0] = 2 * (q1 * q3 - q0 * q2);

  Matrix->Val[0][1] = 2 * (q1 * q2 - q0 * q3);
  Matrix->Val[1][1] = q0 * q0 - q1 * q1 + q2 * q2 - q3 * q3;
  Matrix->Val[2][1] = 2 * (q2 * q3 + q0 * q1);

  Matrix->Val[0][2] = 2 * (q1 * q3 + q0 * q2);
  Matrix->Val[1][2] = 2 * (q2 * q3 - q0 * q1);
  Matrix->Val[2][2] = q0 * q0 - q1 * q1 - q2 * q2 + q3 * q3;

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
