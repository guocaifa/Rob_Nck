#include "robtest.h"

extern void RobTestQuat(void)
{
  quatinp  xInp;
  int      n;
  double   x;
  coorquat Start,End;
  coorquat xQuat;
  double   xSin1,xSin2;

  Start.xQuat[0] = 0.70711;Start.xQuat[1] = 0;
  Start.xQuat[2] = 0.70711;Start.xQuat[3] = 0;

  End.xQuat[0] = 0.25882;End.xQuat[1] = 0;
  End.xQuat[2] = 0.96593;End.xQuat[3] = 0;

  PostureInp(&xInp, &Start, &End, 0.02, 0.001);

  n = xInp.nCycle;
  x = xInp.xAngle;

  for(int i = 0; i <= n; i++){
    xSin1 = sin(((n - i) * x) / n);
    xSin2 = sin((i * x) / n);

    for(int j = 0; j < 4; j++){
      xQuat.xQuat[j] = (Start.xQuat[j] * xSin1 + End.xQuat[j] * xSin2) / sin(x);
    }
  }

  return;
}

extern void RobTestKinematics(void)
{

}
