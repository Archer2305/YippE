#include "main.h"

extern bool on;

extern double targetX;
extern double targetY;
extern double invertedSlope;


extern double initAngle;
extern double targetF;
extern double ogXPos;
extern double ogYPost;
extern double distance;
extern double targetAngle;

extern okapi::IMU  inertial;

void roller();
void driveForward(double distance);
void index(int target);
void indexLast(int target); //used to index the last disc which requires extra time
void turnToAngle(double targetAngle);
void driveBlorward(double distance, double scalar);
void bangBang();
void driveBackward(double distance, double scalar);    
void driveToPoint(double posX, double posY,bool backward,double speed);
void drive_dis(double distance, double scalar);    
void shootAtPoint(double targetX,double targetY);
void shootAtPointThread(void*);
