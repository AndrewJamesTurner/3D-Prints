#include "Controller.h"

#include <Servo.h> 
 
Servo gripper;  
Servo moveX; 
Servo moveY;
Servo rot;  
         
const int griperControlPin = 3;  // pint for grip from joystick     
const int xPosControlPin = 0;  // pint for grip from joystick 
const int rotationControlPin = 1;  // pint for grip from joystick
const int yPosControlPin = 2;  // pint for grip from joystick
 
const int leftVRx = 2;   // yellow
const int leftVRy = 3;   // white
const int leftSW = 4;    // brown

const int rightVRx = 0;  // green
const int rightVRy = 1;  // blue
const int rightSW = 2;   // purple 
 
Controller controller(leftVRx, leftVRy, leftSW, rightVRx, rightVRy, rightSW);

void setup() 
{ 
  
  pinMode(griperControlPin,INPUT);
  digitalWrite(griperControlPin,HIGH);
  
  gripper.attach(griperControlPin);  // attaches the gripper servo on pin 3
  moveX.attach(5);    // attaches the xMove servo on pin 5
  moveY.attach(9);
  rot.attach(6);
  
  toggleGripper();
  moveXPos(0);
  moveYPos(0);
  moveRotation(0);
} 
 
 
void loop() 
{ 
  int joyStickGripperState;
  int joyStickrotation;
  int joyStickXpos;
  int joyStickYpos;

  
  
  // toggle on press
  if(controller.getRightClickState() == 1){
    toggleGripper();
  }
  
    // toggle on press
  if(controller.getLeftClickState() == 1){
    toggleGripper();
  }
  
  
  //
  if(controller.getLeftVerticalPos() < 300){
    moveXPos(1);
  }
  else if(controller.getLeftVerticalPos() > 800){
    moveXPos(-1);
  }
  

  //
  if(controller.getRightVerticalPos() > 800){
    moveYPos(1);
  }
  else if(controller.getRightVerticalPos() < 300){
    moveYPos(-1);
  }
  
  //
  if(controller.getRightHorizontalPos() > 800){
    moveRotation(-1);
  }
  
  else if(controller.getRightHorizontalPos() < 300){
    moveRotation(1);
  }
  
   //
  if(controller.getLeftHorizontalPos() > 800){
    moveRotation(-1);
  }
  
  else if(controller.getLeftHorizontalPos() < 300){
    moveRotation(1);
  }
                          
  
} 


void moveXPos(int delta){
  
  static int xPos = 30;
  
  if(delta > 0){
    xPos = xPos - 1;
  }
  else if(delta < 0){
    xPos = xPos + 1;
  }
  
  if(xPos > 180){
    xPos = 180;
  }
  else if(xPos < 0){
   xPos = 0; 
  }
    
  moveX.write(xPos);
  
  delay(20);
}

void moveYPos(int delta){
  
  static int yPos = 90;
  
  if(delta > 0){
    yPos = yPos + 1;
  }
  else if(delta < 0){
    yPos = yPos - 1;
  }
  
  if(yPos > 180){
    yPos = 180;
  }
  else if(yPos < 0){
   yPos = 0; 
  }
    
  moveY.write(yPos);
  
  delay(20);
}

void moveRotation(int delta){
  
  static int rotation = 90;
  
  if(delta > 0){
    rotation = rotation + 1;
  }
  else if(delta < 0){
    rotation = rotation - 1;
  }
  
  if(rotation > 180){
    rotation = 180;
  }
  else if(rotation < 0){
   rotation = 0; 
  }
  
  rot.write(rotation);
  
  delay(20);
}




int toggleGripper(void){
    
  static int gripperState = 1;
  
  gripperState = !gripperState;
  
  if(gripperState){
    closeGripper();
    delay(200);
    return 1;
  } 
  else{
    openGripper();
    delay(200);
    return 0;
  }
  
}

void closeGripper(void){
  gripper.write(80); 
}

void openGripper(void){
  gripper.write(50); 
}
