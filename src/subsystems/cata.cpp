#include "main.h"
#include "cata.hpp"

Motor cata(14, true, AbstractMotor::gearset::red, AbstractMotor::encoderUnits::degrees);
ADIButton limSwitch('C', false);
 bool Launch =false;
 
void launch(void *){ //shoot function for auton
while (true){
  okapi::Rate rate;
  if(Launch==true){ //Launch setting launch to true wil trigger the cata 
  if(limSwitch.isPressed()){
            cata.moveVoltage(12000);
            pros::delay(100);
        }
if(!limSwitch.isPressed()){
            cata.moveVoltage(12000); //move down unless button is pressed
         }
        if(limSwitch.isPressed()){
            cata.moveVoltage(0);
            Launch=false;
        }
}
rate.delay(10_Hz);
} 
}
void updateCata(){ 
    if(controller.getDigital(ControllerDigital::R2)==1){
      if(limSwitch.isPressed()){ //lower cata until slip 
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

// static pros::Task my_task (updateCata, NULL, TASK_PRIORITY_DEFAULT,TASK_STACK_DEPTH_DEFAULT, "Cata");
static pros::Task launchCata (launch, NULL, TASK_PRIORITY_DEFAULT,TASK_STACK_DEPTH_DEFAULT, "Launch");