#include "movel.h"

extern void MoveL(matrix4_4 *pStatusCrn, matrix4_4 *pStatusNxt, double dAcc, double dVmax)
{
  matrix4_4 *Crn = pStatusCrn;
  matrix4_4 *Nxt = pStatusNxt;

  double nInp[3],DetaInp[3];
  int    nInpMax = 0;/* ฒๅฒนดฮสý */

  for(int i = 0; i < 3; i++)  nInp[i] = (Crn[i][3] - Nxt[i][3]) / xRobSys.xInpParameter.aInpMax;
  for(int i = 0; i < 3; i++)  nInpMax = MAX(nInpMax, abs(nInp[i]));
  for(int i = 0; i < 3; i++)  DetaInp[i] = (Crn[i][3] - Nxt[i][3]) / nInpMax;

  return;
}
