

const int rightHorizontalPin = 0;
const int rightVerticalPin = 1;
const int rightClickPin = 2;

const int leftHorizontalPin = 2;
const int leftVerticalPin = 3;
const int leftClickPin = 4;

void setup() {
  
  Serial.begin(9600);        
  
  pinMode(rightClickPin, INPUT);
  digitalWrite(rightClickPin, HIGH);
  
  pinMode(leftClickPin, INPUT);
  digitalWrite(leftClickPin, HIGH);

}

void loop() {
  
  Serial.print("right horizontal: ");
  Serial.println(analogRead(rightHorizontalPin) ,DEC); 
  Serial.print("right vertical: ");
  Serial.println(analogRead(rightVerticalPin) ,DEC);
  Serial.print("right click: ");
  Serial.println(digitalRead(rightClickPin) ,DEC); 
  
  Serial.print("left horizontal: ");
  Serial.println(analogRead(leftHorizontalPin) ,DEC); 
  Serial.print("left vertical: ");
  Serial.println(analogRead(leftVerticalPin) ,DEC);
  Serial.print("left click: ");
  Serial.println(digitalRead(leftClickPin) ,DEC); 
      
    
  delay(1000);
  
}
