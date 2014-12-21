#include "Controller.h"

const int leftVRx = 2;   // yellow
const int leftVRy = 3;   // white
const int leftSW = 4;    // brown

const int rightVRx = 0;  // green
const int rightVRy = 1;  // blue
const int rightSW = 2;   // purple

Controller controller(leftVRx, leftVRy, leftSW, rightVRx, rightVRy, rightSW);

void setup() {
  Serial.begin(9600);
}


void loop() {
  
  Serial.print("left horizontal: ");
  Serial.println(controller.getLeftHorizontalPos(),DEC);
  
  Serial.print("right horizontal: ");
  Serial.println(controller.getRightHorizontalPos(),DEC);
  
  Serial.print("left Vertical: ");
  Serial.println(controller.getLeftVerticalPos(),DEC);
  
  Serial.print("right Vertical: ");
  Serial.println(controller.getRightVerticalPos(),DEC);
  
  Serial.print("left click: ");
  Serial.println(controller.getLeftClickState(),DEC);
  
  Serial.print("right click: ");
  Serial.println(controller.getRightClickState(),DEC);
   
  Serial.println(" ");
   
  delay(1000);
}
