#include "main.h"

okapi::IMU  inertial = IMU(5);

double initAngle = 0;

// double targetF;
double prevPos = 0;
double targetX = 0;
double targetY = 0;
bool on = false;

void roller() {
/*
    leftDrive.moveVelocity(-50);//set the drivetrain to move back at 25rpm
    rightDrive.moveVelocity(-50);//we do 25 rpm to reduce the torque needed to do the roller.
    pros::delay(500);
    intakeMotor.moveVelocity(600); //move the roller at max speed
    pros::delay(200); //wait half a second to allow roller to spin to our color 
    leftDrive.moveVelocity(0);
    rightDrive.moveVelocity(0);
    intakeMotor.moveVelocity(0); //cut everyting besides flywheel
*/
    //new 

  //  prevPos= intakeMotor.getPosition();
   intakeMotor.moveRelative(-230, 600);
   pros::delay(100);
    leftDrive.moveVelocity(0);//set the drivetrain to move back at 25rpm
    rightDrive.moveVelocity(0);
  //  pros::delay(300);
//    while(intakeMotor.getPosition()<prevPos+360){
//     intakeMotor.moveVelocity(600);
//    }
//    intakeMotor.moveVelocity(0);
}
#if 0
void driveForward(double distance) {  
    okapi::IterativePosPIDController drivePID = okapi::IterativeControllerFactory::posPID(0.9, 0., 0.0093); //create a new drive object with specified pid

    const double target = distance; //idk why not just use distance

    drivePID.setTarget(target); //tels PROS: to move the drive using pid to distance

    double orgPosX = drive->getState().x.convert(okapi::foot); //store the orginal position
    double orgPosY = drive->getState().y.convert(okapi::foot);

    double distTravelled = 0;

    while (abs(target-distTravelled) >= 0.2 || abs(leftDrive.getActualVelocity()) > 10) { //pid shit i think idk
    // condition :abs(target-distTravelled) >= 0.2
        double dx = drive->getState().x.convert(okapi::foot) - orgPosX;
        double dy = drive->getState().y.convert(okapi::foot) - orgPosY;

        distTravelled = sqrt(dx * dx + dy * dy);
        
        double vel = drivePID.step(distTravelled);

        drive -> getModel() -> tank(vel, vel);

        pros::delay(10);
        pros::lcd::set_text(1, std::to_string(drive->getState().x.convert(okapi::foot))); //displays the X coordinate on the LCD of the screen per tick
        pros::lcd::set_text(2, std::to_string(drive->getState().y.convert(okapi::foot))); //displays the Y coordinate on the LCD of the screen per tick
    }
}

void driveBlorward(double distance, double scalar=1) {
    printf("here\n");
    okapi::IterativePosPIDController drivePID = okapi::IterativeControllerFactory::posPID(0.75, 0.01, 0.01); //create a new drive object with specified pid

    const double target = distance; //idk why not just use distance

    drivePID.setTarget(target); //tels PROS: to move the drive using pid to distance

    double orgPosX = drive->getState().x.convert(okapi::foot); //store the orginal position
    double orgPosY = drive->getState().y.convert(okapi::foot);

    double distTravelled = 0; 

     while (abs(target-distTravelled) >= 0.2 || abs(leftDrive.getActualVelocity())>15) { //pid shit i think idk 
    // while(true){ 
        double dx = drive->getState().x.convert(okapi::foot) - orgPosX;
        double dy = drive->getState().y.convert(okapi::foot) - orgPosY;

        distTravelled = sqrt(dx*dx + dy*dy);
        
        double vel = drivePID.step(distTravelled);

        printf("distTravelled: %lf, output: %lf\n", distTravelled, vel);

        drive->getModel()->tank(vel * scalar, vel * scalar);

        pros::delay(10);
    }

    drivePID.reset(); //reset everything to move relitive 
    drive -> getModel() -> tank(0, 0); //stop the drive once target is met
}


void driveBackward(double distance, double scalar=1) {    
    okapi::IterativePosPIDController drivePID = okapi::IterativeControllerFactory::posPID(0.75, 0.01, 0.01); //create a new drive object with specified pid

    const double target = distance; //idk why not just use distance

    drivePID.setTarget(target); //tels PROS: to move the drive using pid to distance

    double orgPosX = drive->getState().x.convert(okapi::foot); //store the orginal position
    double orgPosY = drive->getState().y.convert(okapi::foot);

    double distTravelled = 0; 

    while (abs(target-distTravelled) >= 0.2 || abs(leftDrive.getActualVelocity()) > 10){ //pid shit i think idk
    // while(true){
        double dx = drive->getState().x.convert(okapi::foot) - orgPosX;
        double dy = drive->getState().y.convert(okapi::foot) - orgPosY;

        distTravelled = -sqrt(pow(dx,2) + pow(dy,2));
     
        double vel = drivePID.step(distTravelled);

        drive -> getModel() -> tank(vel * scalar, vel * scalar);

        pros::delay(10);
    }

    drivePID.reset(); //reset everything to move relitive 
    drive -> getModel() -> tank(0, 0); //stop the drive once target is met
}
#endif

void drive_dis(double distance, double scalar=1) {                                          //init 0.85
    if (abs(distance) <= 0.01)
        return;

    okapi::IterativePosPIDController drivePID = okapi::IterativeControllerFactory::posPID(0.88, 0.00, 0.0000);
    //prev: okapi::IterativePosPIDController drivePID = okapi::IterativeControllerFactory::posPID(0.86, 0.00, 0.0000);
    //okapi::IterativePosPIDController drivePID = okapi::IterativeControllerFactory::posPID(0.75, 0.01, 0.01); //create a new drive object with specified pid

    double target = distance; 

    drivePID.setTarget(target); 
    //tells PROS: to move the drive using pid to distance

    double orgPosX = drive->getState().x.convert(okapi::foot); 
    double orgPosY = drive->getState().y.convert(okapi::foot);
    printf("\n-->  start    => %10.3lf    : state = (%9.5lf, %9.5lf)\n", distance, orgPosX, orgPosY);

    double distTravelled = 0; 

    //while (abs(target-distTravelled) >= 0.2 || abs(leftDrive.getActualVelocity()) > 10){ //pid shit i think idk
    while (true) {   
        double state_x = drive->getState().x.convert(okapi::foot);
        double state_y = drive->getState().y.convert(okapi::foot);

        double dx = state_x - orgPosX;
        double dy = state_y - orgPosY;

        distTravelled = sqrt(dx * dx + dy * dy);

        if (distance < 0)
            distTravelled = -distTravelled;

        printf("     %10.3lf  => %10.3lf    : state = (%10.3lf, %10.3lf)\n", distTravelled, distance, state_x, state_y);      

        double vel = drivePID.step(distTravelled);
        
        //printf("distTravelled: %lf, cur_x: %lf, cur_y:%lf\n", 
        //   distTravelled, drive->getState().y.convert(okapi::foot), drive->getState().x.convert(okapi::foot));

        drive->getModel()->tank(vel * scalar, vel * scalar);
        pros::delay(16);
    }

    double state_x = drive->getState().x.convert(okapi::foot);
    double state_y = drive->getState().y.convert(okapi::foot);
    printf("-->   end      : state = (%10.3lf, %10.3lf)\n", state_x, state_y);

    drivePID.reset(); //reset everything to move relative 
    drive->getModel()->tank(0, 0); //stop the drive once target is met
}

//remap to -180 to 180
inline double remap(double d) {
    if (d == 0) {
        return 0;
    }

    double fp = d - (int)d;
    int id = (int)d;

    if (d > 0) {
        id = id % 360;
    } else {
        id = (-id % 360) * -1 + 360;
    }

    d = id + fp;
    return (d <= 180) ? d : (d - 360);
}

//shift all angles to relative degree

#define TS      1
void turnToAngle(double targetAngle) { //turn non-relative to given target (degrees)       
    okapi::IterativePosPIDController rotatePID = okapi::IterativeControllerFactory::posPID(
                    (double)0.027, 0.00001, 0.00070); 

    //okapi::IterativePosPIDController rotatePID = okapi::IterativeControllerFactory::posPID(
      //              (double)0.0136, (double)0.0532, (double)0.00099); 
    //okapi::IterativePosPIDController rotatePID = okapi::IterativeControllerFactory::posPID(0.025, 0.05, 0.00054); //re-tune PID?
    
    rotatePID.setTarget(0);

    // double initAngle = drive->getState().theta.convert(okapi::degree);
    double initAngle = remap(inertial.controllerGet() - targetAngle); 

//-----------------------------------
    std::stringstream ss;
    //ss << "<offset: " << initAngle;
    printf("<offset: %lf\n", initAngle);

    //pros::lcd::set_text(4, ss.str());
    pros::delay(800);
//-----------------------------------

    while (abs(0 - initAngle) >= 3 || abs(leftDrive.getActualVelocity()) > 15) {
    //while (true) {
        initAngle = remap(inertial.controllerGet() - targetAngle);

        if (initAngle >= 190) {
            printf("uhhhhh this went bad\n");
            break;
        }

     //   printf("<offset: %lf\n", initAngle);        

        double vel = rotatePID.step(initAngle);
        drive->getModel()->tank(vel * TS, -vel * TS);     //turn faster by moving the other side the oppisite way

        pros::delay(20);
    }

    rotatePID.reset();
    drive->getModel()->tank(0, 0);

    printf("IMU: %lf\n", inertial.controllerGet());
}

#define TO_DEG  (180 / 3.14159265359)

inline double normalize(double d) {      //input[0,360] -> output[-180,180]
    if (d > 180)
        d -= 360;
    return d;
}

inline double to_IMU_heading(double d) {
    return normalize(90 - d);
}

void driveToPoint(double posX, double posY, bool backward, double speed){
  double ogXPos = drive->getState().y.convert(okapi::foot); //get starting X position
  double ogYPos = drive->getState().x.convert(okapi::foot); //get starting Y position
  
  double distance = sqrt(pow((posX-ogXPos), 2) + pow((posY-ogYPos), 2)); //calculate distance using distnace formula 

  double targetAngle = 0;

//----------------n_algo-----------
  double dx = posX - ogXPos;
  double dy = posY - ogYPos;

  printf("distance: %lf, dX: %lf, dY: %lf\n", distance, dx, dy);  

  if (!dx && !dy) {
    return;
  }

  if (dx == 0) {
    targetAngle = (dy > 0) ? 90 : -90;
  } else if (dx > 0) {
    targetAngle = atan(dy/dx) * TO_DEG;
  } else if (dx < 0) {
    targetAngle = 180 + (atan(dy/dx)) * TO_DEG;
  }
    
  //normalizing + IMU convert
    targetAngle = to_IMU_heading(normalize(targetAngle));

    std::stringstream ss;                                   //
    ss << "targetAngle: " << targetAngle << std::endl;      //

    std::stringstream xs;                                   //
    std::stringstream ys;                                   //

    xs << "dx: " << dx << "   ";                            //
    xs << "dy: " << dy;                                     //

  pros::lcd::set_text(5, xs.str());                         //
  pros::lcd::set_text(6, ys.str());                         //

  if (!backward){               
    turnToAngle(targetAngle);
    drive_dis(distance,speed);

  } else if (backward) { //If driving intake foward
    if (targetAngle >= 0){
      targetAngle += -180;
    } else if (targetAngle < 0){
      targetAngle += 180;
    }

    turnToAngle(targetAngle);
    drive_dis(-distance,speed);
  }

  pros::lcd::set_text(4, ss.str());
}

void shootAtPointThread(void*){  
    okapi::Rate rate;
    while(true){
      // controller.rumble(".");
    if(on){
       
    double xPos = drive->getState().y.convert(okapi::foot); //get starting X position //initialize
    double yPos = drive->getState().x.convert(okapi::foot);//get starting Y position   /swap the X and Y to make it match the cartesian plane.
    int ogSignX = (signbit(xPos-targetX)); //store the original sign of bot-target so that we can detect a change in sign
    int ogSignY = (signbit(yPos-targetY));

      //shoot at point tells the bot to trigger cata once it reaches the specified point, this is usefull for moving and shooting at the same time while also using PID and Odom
      //this function will not move the bot at all, and should be used before driveToPoint.
    while(on){
      pros::lcd::set_text(1, std::to_string(drive->getState().x.convert(okapi::foot))); //displays the X coordinate on the LCD of the screen per tick
      pros::lcd::set_text(2, std::to_string(drive->getState().y.convert(okapi::foot))); //displays the Y coordinate on the LCD of the screen per tick

     xPos=drive->getState().y.convert(okapi::foot); //get starting X position //update
     yPos=drive->getState().x.convert(okapi::foot);//get starting Y position   /swap the X and Y to make it match the cartesian plane.
     if(targetX==0||targetY==0){
    if(signbit((xPos-targetX)) != ogSignX ||  signbit((yPos-targetY)) != ogSignY ){//if both X and Y have changed signs, it has passed the point
      Launch=true;
      on=false; //stop refreshing once it detects the sign change
     }
     }else{
     if (signbit((xPos - targetX)) != ogSignX &&  signbit((yPos-targetY)) != ogSignY ){//if both X and Y have changed signs, it has passed the point
      Launch=true;
      on=false; //stop refreshing once it detects the sign change
     }
     }
    pros::delay(1);
    }

    } 
    rate.delay(10_Hz);
    }
}

void shootAtPoint(double TARGETX, double TARGETY){
  targetX=TARGETX;
  targetY=TARGETY;
  on=true;
}

#if 0
void turnToAngle(double targetAngle){ //turn non-relitive to given target (degrees)
   // angle in degrees

    //okapi::IterativePosPIDController rotatePID = okapi::IterativeControllerFactory::posPID(0.4553769998, 0.01,0.01049997);
    okapi::IterativePosPIDController rotatePID = okapi::IterativeControllerFactory::posPID(0.025, 0.05,0.00054);
    //ani: 0.4553769998, 0.001, 0.01049997
    // 00159
    
    rotatePID.setTarget(targetAngle);

    // double initAngle = drive->getState().theta.convert(okapi::degree);
    double initAngle = inertial.controllerGet(); 

    while (abs(targetAngle - initAngle) >= 3 || abs(leftDrive.getActualVelocity())>15) {
        //condition: abs(targetAngle - initAngle) >= 3 || abs(leftDrive.getActualVelocity())>300
        // initAngle = drive->getState().theta.convert(okapi::degree);
        initAngle = inertial.controllerGet();
        double vel = rotatePID.step(initAngle);
        drive -> getModel() -> tank(vel, -vel);//turn faster by moving the other side the oppisite way
        pros::delay(20);
    }

    rotatePID.reset();

    drive -> getModel() -> tank(0, 0);
}

void turnToAngle(double targetAngle){ //turn non-relitive to given target (degrees)
   // angle in degrees

    okapi::IterativePosPIDController rotatePID = okapi::IterativeControllerFactory::posPID(0.025, 0.05,0.00054);
    //ani: 0.4553769998, 0.001, 0.01049997
    // 00159
    
    bool dangerous = (targetAngle < -160 || targetAngle > 160);
    
    targetAngle = (dangerous) ? (remap(targetAngle)) : targetAngle;

    rotatePID.setTarget(targetAngle);

    // double initAngle = drive->getState().theta.convert(okapi::degree);
    double initAngle = (dangerous) ? remap(inertial.controllerGet()) : inter; 

    while (abs(targetAngle - initAngle) >= 3 || abs(leftDrive.getActualVelocity())>15) {
        //condition: abs(targetAngle - initAngle) >= 3 || abs(leftDrive.getActualVelocity())>300
        // initAngle = drive->getState().theta.convert(okapi::degree);
    //    initAngle = inertial.controllerGet();

        if (dangerous) {                  
            initAngle = remap(inertial.controllerGet());
        } else {
            initAngle = inertial.controllerGet();
        }

        double vel = rotatePID.step(initAngle);

        drive -> getModel() -> tank(vel, -vel);//turn faster by moving the other side the oppisite way
        pros::delay(20);
    }

    rotatePID.reset();


    drive -> getModel() -> tank(0, 0);
}
#endif 

