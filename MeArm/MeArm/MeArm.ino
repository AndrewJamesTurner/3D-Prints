// Sweep
// by BARRAGAN <http://barraganstudio.com> 
// This example code is in the public domain.


#include <Servo.h> 
 
Servo gripper;  
Servo moveX; 
Servo moveY;
Servo rot;  
         
const int griperControlPin = 2;  // pint for grip from joystick     
const int xPosControlPin = 0;  // pint for grip from joystick 
const int rotationControlPin = 1;  // pint for grip from joystick
const int yPosControlPin = 2;  // pint for grip from joystick
 

void setup() 
{ 
  
  pinMode(griperControlPin,INPUT);
  digitalWrite(griperControlPin,HIGH);
  
  gripper.attach(3);  // attaches the gripper servo on pin 3
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

  joyStickGripperState = digitalRead(griperControlPin);
  joyStickXpos = analogRead(xPosControlPin);
  joyStickrotation = analogRead(rotationControlPin);
  joyStickYpos = analogRead(yPosControlPin);
  
  // toggle on press
  if(joyStickGripperState == LOW){
    toggleGripper();
  }
  
  //
  if(joyStickXpos > 800){
    moveXPos(1);
  }
  else if(joyStickXpos < 300){
    moveXPos(-1);
  }
  
  //
  if(joyStickYpos > 800){
    moveYPos(1);
  }
  else if(joyStickYpos < 300){
    moveYPos(-1);
  }
  
  //
  if(joyStickrotation > 800){
    moveRotation(1);
  }
  
  else if(joyStickrotation < 300){
    moveRotation(-1);
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
  gripper.write(79); 
}

void openGripper(void){
  gripper.write(50); 
}
