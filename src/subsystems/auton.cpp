#include "main.h"
int route=1;
void updateAuton(){
// turnToAngle(90);
  if(route==1){ //Right
    shootAtPoint(0,2.3);
    driveToPoint(0,2.5,false,1);
    driveToPoint(2.1,0,false,1);
    driveToPoint(-4,5.5,false,1);
    shootAtPoint(-2.7,5);
    driveToPoint(-2,5.8,false,1);
  }
  if(route==-1){
shootAtPoint(1,0);
driveToPoint(2,0,false,1);
  }
}  