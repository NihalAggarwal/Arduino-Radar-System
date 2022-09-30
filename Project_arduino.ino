// Includes the Servo library
//Project Arduino
#include <Servo.h> 
const int trigPin = 10;
const int echoPin = 11;
const int led = 3;
const int buzzerPin = 5;
const int photoLED = 8;
const int greenLED = 2;
long duration;
int distance;
Servo myServo; // Creates a servo object for controlling the servo motor
void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  pinMode(led, OUTPUT);   // Sets the red LED as an Output 
  pinMode(buzzerPin, OUTPUT); // Sets the buzzer Pin as an Output
  pinMode(photoLED, OUTPUT);  // Sets the Photo LED as output
  pinMode(greenLED, OUTPUT); // Sets the green LED as output
  Serial.begin(9600);
  myServo.attach(9); // Defines on which pin is the servo motor attached
}
void loop() {  
  firstRotation();//function call to rotate the motor from 15 to 180 degrees  
  lastRotation(); //function call to rotate the motor from 180 to 15 degrees  
}
// Function for calculating the distance measured by the Ultrasonic sensor

int calculateDistance(){ 
  
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); // Reads the echoPin, returns the sound wave travel time in microseconds
  distance= duration*0.034/2;
  return distance;
}
// Function for the first rotation
int firstRotation(){
  
  for(int i=15;i<180;i++){  
  distance = calculateDistance();// Calls a function for calculating the distance measured by the Ultrasonic sensor for each degree
  if(distance<30){
    digitalWrite(led,HIGH);       // Turning on the Red LED
    digitalWrite(buzzerPin,HIGH); // Turning on the Buzzer
    digitalWrite(greenLED,LOW);  // Turning off the Green LED
    myServo.write(i);
    delay(40);
    }
    else{
    digitalWrite(led,LOW);       // Turning off the Red LED
    digitalWrite(buzzerPin,LOW); // Turning off the Buzzer 
    digitalWrite(greenLED,HIGH); // Turning on the green LED
    myServo.write(i);
    delay(30);
      }
  Serial.print(i);
  Serial.print(",");
  Serial.print(distance);
  Serial.print(".");
  myServo.write(i);
  delay(30);
  }
  }
// Function for the last rotation
int lastRotation(){
  for(int i=180;i>15;i--){
    myServo.write(i);  
  distance = calculateDistance(); // function call
  if(distance<30){      
    digitalWrite(led,HIGH);       // Turning on the Red LED
    digitalWrite(buzzerPin,HIGH); // Turning on the Buzzer
    digitalWrite(greenLED,LOW);   // Turning off the Green LED
    myServo.write(i);
    delay(40);
    }
    else{
    digitalWrite(led,LOW);       // Turning off the Red LED
    digitalWrite(buzzerPin,LOW); // Turning off the buzzer
    digitalWrite(greenLED,HIGH); // Turning on the Green LED
    myServo.write(i);
    delay(30);
      }
  Serial.print(i);
  Serial.print(",");
  Serial.print(distance);
  Serial.print(".");
  myServo.write(i);   
  delay(30);
  }
  }
