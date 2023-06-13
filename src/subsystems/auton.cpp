#include "main.h"
int route=10;
pros::ADIDigitalOut pistoNN ('F');

void updateAuton(){
// turnToAngle(90);
if(route==1){
     roller();
    driveForward(0.6);//drive foward to prevent clashing into the wal 
    // pros::delay(300);
    turnToAngle(45); 
    driveForward(2.8);
    turnToAngle(65);
    driveForward(2.2);

    turnToAngle(-30);
    driveBackward(-0.5,1);
    // pros::delay(300);
    Launch=true;
    
    pros::delay(500);
    driveForward(0.75); 
    turnToAngle(-130);
    pros::delay(700);
    intakeMotor.moveVelocity(600);
    driveBackward(-6,0.7);  
    turnToAngle(-160);
    driveBackward(-0.5,1);
    turnToAngle(-90);
   

    leftDrive.moveVelocity(-400);
    rightDrive.moveVelocity(-400);
    pros::delay(400);
roller();
driveForward(1);
turnToAngle(-135);
driveForward(2);
pistoNN.set_value(true);
//  leftDrive.setBrakeMode(AbstractMotor::brakeMode::hold);
//  rightDrive.setBrakeMode(AbstractMotor::brakeMode::hold);
//  leftDrive.moveVelocity(600);
//  rightDrive.moveVelocity(600);
// turnToAngle(-155);
// driveBlorward(3,2);
// Launch=true;
// turnToAngle(-135);
// driveForward(1);
// turnToAngle(45);
// driveForward(1);
//     Launch=true;
//  Launch=true;

}
if(route==2){
     roller();
    shootAtPoint(0.001,1);
    driveToPoint(0,2,false,1);
    driveToPoint(3,3,false,1);
    shootAtPoint(3,5.5);
    driveToPoint(3,6,false,1);
    driveToPoint(5,2,false,1);
    intakeMotor.moveVelocity(600);
    driveToPoint(6,4,true,0.75);
    intakeMotor.moveVelocity(0);
/*
  roller();
    // shootAtPoint(0,0.4);
    // turnToAngle(-5);
    driveForward(0.6); //drive foward to prevent clashing into the wal 
    // turnToAngle(-30);
    // turnToAngle(-5);
    // driveForward(0.3);
    // Launch=true;
    pros::delay(300);
    turnToAngle(63.4); 
    driveForward(4.4);
    turnToAngle(-30);
    // driveForward(0.75); 
    // pros::delay(300);
    Launch=true;*/
}
  if(route==3){ //Right
    driveForward(2);
    turnToAngle(25);
    Launch=true;

    driveForward(0.5);
    pros::delay(300);
    turnToAngle(-30);
    driveBackward(-2.5,0.9);
     leftDrive.moveVelocity(-400);
    rightDrive.moveVelocity(-400);
    pros::delay(600);
    leftDrive.moveVelocity(-25);
    rightDrive.moveVelocity(-25);
    pros::delay(600);
roller();
/*
driveForward(1);
intakeMotor.moveVelocity(600);
driveToPoint(-4,6,true,0.75);
pros::delay(100);
intakeMotor.moveVelocity(0);
turnToAngle(45);
Launch=true;
turnToAngle(0);
intakeMotor.moveVelocity(600);
driveBackward(4,0.75);
shootAtPoint(-3,1);
driveToPoint(-2,2,false,1);
*/
  }
  if(route==4){ //skills
    roller();
    driveToPoint(0,1,false,1); //I would set X o -1 but it would hit barier and screw up 
    intakeMotor.moveVelocity(600);
    driveToPoint(-2,2,true,1);
    driveToPoint(-3,2.5,true,1);
    intakeMotor.moveVelocity(0);
    leftDrive.moveVelocity(-35);
    rightDrive.moveVelocity(-35);
    pros::delay(100);
    roller();
    driveToPoint(-2.5,7.6,false,1);
    Launch=true;
    intakeMotor.moveVelocity(600);
    driveToPoint(0.5,7.8,true,0.75);
    intakeMotor.moveVelocity(0);
    turnToAngle(-45);
    Launch=true;
    intakeMotor.moveVelocity(600);
    driveToPoint(0.5,9.8,true,0.75);
    intakeMotor.moveVelocity(0);
    turnToAngle(-90);
    Launch=true;
    driveToPoint(6,11,true,1);
    turnToAngle(-160);
    leftDrive.moveVelocity(-35);
    rightDrive.moveVelocity(-35);
    roller();

  }
  if(route==5){
    roller();
    pros::delay(100);
driveForward(1);
turnToAngle(120);
intakeMotor.moveVelocity(600);

driveBackward(-1.8,0.75);
intakeMotor.moveVelocity(0);

driveBackward(-1,1);
turnToAngle(90);
 leftDrive.moveVelocity(-100);
 rightDrive.moveVelocity(-100);
 pros::delay(500);
roller();
driveForward(1);
turnToAngle(45);
driveForward(9.285);
turnToAngle(-130);
leftDrive.moveVelocity(-100);
 rightDrive.moveVelocity(-100);
 pros::delay(500);
roller();
pros::delay(100);
driveForward(1);
turnToAngle(-120);
intakeMotor.moveVelocity(600);

driveBackward(-1.8,0.75);
intakeMotor.moveVelocity(0);

driveBackward(-1,1);
turnToAngle(-90);
 leftDrive.moveVelocity(-100);
 rightDrive.moveVelocity(-100);
 pros::delay(500);
// turnToAngle(-90);
// intakeMotor.moveVelocity(600);
// driveBackward(3.3,0.5);
// intakeMotor.moveVelocity(0);
// turnToAngle(-45);

// Launch=true;
// */
  }
  if(route==10){
    // driveBlorward(2, 0.5); 
    //driveToPoint(2 , 2,false,1); 
    //pros::delay(2000);
    //driveToPoint(1 , 1.732,false,1); ///should be 30
    //pros::delay(2000); 
    //driveToPoint(3, 0, false, 1);
    //pros::delay(2000);
    //driveToPoint(-1, -1, false, 1);
    //driveToPoint(1, 1, true, 1);
    driveToPoint(1, 2, false, 1);
    pros::delay(500);
    driveToPoint(0, 2, false, 1);
    //driveToPoint();
    //turnToAngle(-135);
    //pros::delay(2000);
    //turnToAngle(45);
    //pros::delay(2000);
    
  }
  if(route==-1){
Launch=true;

pros::delay(1000);
Launch=true;
pros::delay(5000);
Launch=true;
  }

}  