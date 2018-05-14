#include "robot/robot.h"
#include "robot/robtest.h"

int main(int argc, char *argv[])
{

  InitRobSys(&xRobSys);

  RobTestKinematics();

}
