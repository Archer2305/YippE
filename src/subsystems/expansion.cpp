#include "main.h"
using namespace okapi;
bool Toggle=false;
bool Lock=true;
pros::ADIDigitalOut piston ('F');

void updateExpansion(){
    if(controller.getDigital(ControllerDigital::left) == 1){  
          if(Lock){
          Toggle=!Toggle;
          Lock=false;
          piston.set_value(Toggle);    
        }
    }
        if(controller.getDigital(ControllerDigital::left) == 0){
          Lock=true;
        }

}