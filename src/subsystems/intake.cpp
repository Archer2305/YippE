#include "main.h"
#include "okapi/impl/device/controllerUtil.hpp" //random ass import, idk what it does but code breaks without it 
// #include "pros/motors.h"
Motor intakeMotor(19, true, AbstractMotor::gearset::blue, AbstractMotor::encoderUnits::degrees);
void updateIntake(){
    if(!limSwitch.isPressed()){
        intakeMotor.moveVelocity(0);// stop if there is no input

    } else{
    if (controller.getDigital(ControllerDigital::L1 ) == 1 ){
        intakeMotor.moveVelocity(-600); //intake when positive
    } 
    if (controller.getDigital(ControllerDigital::R1 ) == 1 && (limSwitch.isPressed())){
        intakeMotor.moveVelocity(600); //intake when positive
    }
    if(controller.getDigital(ControllerDigital::R1 ) == 0 && (controller.getDigital(ControllerDigital::L1 ) == 0)){
        intakeMotor.moveVelocity(0);// stop if there is no input
    }
}
}