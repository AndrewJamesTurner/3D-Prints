/*
The MIT License (MIT)

Copyright (c) 2014 Andrew James Turner

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include "Arduino.h"
#include "Controller.h"

Controller::Controller(int leftVRx, int leftVRy, int leftSW, int rightVRx, int rightVRy, int rightSW){

	_leftHorizontalPin = leftVRx;
	_rightHorizontalPin = rightVRx;

	_leftVerticalPin = leftVRy;
	_rightVerticalPin = rightVRy;

	_leftClickPin = leftSW;
	_rightClickPin = rightSW;

	pinMode(_leftClickPin, INPUT);
	pinMode(_rightClickPin, INPUT);
	
	digitalWrite(_leftClickPin, HIGH);
	digitalWrite(_rightClickPin, HIGH);
}


int Controller::getLeftHorizontalPos(){
	return map(analogRead(_leftHorizontalPin), 0, 1023, 1023, 0);
}

int Controller::getRightHorizontalPos(){
	return analogRead(_rightHorizontalPin);
}

int Controller::getLeftVerticalPos(){
	return analogRead(_leftVerticalPin);
}

int Controller::getRightVerticalPos(){	
	return map(analogRead(_rightVerticalPin), 0, 1023, 1023, 0);
} 

int Controller::getLeftClickState(){
	return !digitalRead(_leftClickPin);
}

int Controller::getRightClickState(){
	return !digitalRead(_rightClickPin);
}



