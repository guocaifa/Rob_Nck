#include "moveabsj.h"

static double GetJitStepAngle(double AngleCrn, double AngleNxt, const double Vmax, const u8 Cycle);
static double GetJitMaxTime(const double *pAngleCrn, const double *pAngleNxt);

extern void MoveAbsJoint(double *AngleCrn, double *AngleTarget, double Vmax, const u8 Cycle)
{

}

static double GetJitStepAngle(double AngleCrn, double AngleNxt, const double Vmax, const u8 Cycle)
{
  double StepAngle = 0;

//  StepAngle = AngleCrn + 3 *(AngleNxt - AngleCrng) / (Cycle * Cycle)

}

static double GetJitMaxTime(const double *pAngleCrn, const double *pAngleNxt)
{
  double AngleMax = 0;
  for(int i = 0; i < 6; i++){

  }
}
