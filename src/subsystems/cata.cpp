#include "main.h"

int profile=1;

Motor cata(14, true, AbstractMotor::gearset::red, AbstractMotor::encoderUnits::degrees);
ADIButton limSwitch('C', false);
bool Launch =false;

static pros::Task SHOOT (shootAtPointThread);
static pros::Task launchj (launch);


void launch(void *){ //shoot function for auton
while (true){
  okapi::Rate rate;
  if(Launch==true){ //Launch setting launch to true wil trigger the cata 
  while(limSwitch.isPressed()){
            cata.moveVoltage(12000);
            pros::delay(1);
        }
while(!limSwitch.isPressed()){
            cata.moveVoltage(12000); //move down unless button is pressed
            pros::delay(1);
         }

        if(limSwitch.isPressed()){
            pros::delay(10);

            cata.moveVoltage(0);
            Launch=false;
        }
}
rate.delay(10_Hz);
} 
}
void updateCata(){ 
  
  if(controller.getDigital(ControllerDigital::B)==1){
 profile = (profile+1)%2;
  }
  if(profile==1){
    if(controller.getDigital(ControllerDigital::R2)==1){
      while(limSwitch.isPressed()){ //lower cata until slip 
        cata.moveVoltage(12000);
        
       }
    //    cata.moveVoltage(0);//stop the cata 
     
    }
      if((controller.getDigital(ControllerDigital::R2)==0)){
        if(!limSwitch.isPressed()){
            cata.moveVoltage(12000); //move down unless button is pressed
         }
        if(limSwitch.isPressed()){
            cata.moveVoltage(0);
        }
}
  }
  if (profile==0){
    if(controller.getDigital(ControllerDigital::R2)==1){
        cata.moveVoltage(12000);

    }
    if(controller.getDigital(ControllerDigital::R2)==0){
            cata.moveVoltage(0);

    }
  }
}

