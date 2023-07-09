#include "main.h"

using namespace okapi;

extern int state;

extern Motor rightFront;
extern Motor rightMiddle;
extern Motor rightBack;
extern Motor leftFront;
extern Motor leftMiddle;
extern Motor leftBack;
extern MotorGroup leftDrive;
extern MotorGroup rightDrive;

extern Controller controller;
extern std::shared_ptr<OdomChassisController> drive;
extern std::shared_ptr<AsyncMotionProfileController> profile_controller;

void updateDrive();
void updateSkills();
void motors_init();
void print_state(std::string, const okapi::OdomState&);
void print_cur_state();
