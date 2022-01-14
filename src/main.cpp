#include <Arduino.h>

const int trigPin = 12;
const int echoPin = 14;
const float error = 0.5;
//define sound velocity in cm/uS
#define SOUND_VELOCITY 0.034
#define CM_TO_INCH 0.393701

unsigned long Duration = 0;
float currentDistanceCm,previousDistanceCm=0;


void setup() {
  Serial.begin(9600); // Starts the serial communication
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input

}

void loop() {
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  unsigned long duration = pulseIn(echoPin, HIGH);
  //unsigned long currentMillis = millis();
  // Calculate the distance
  currentDistanceCm = duration * SOUND_VELOCITY/2;
  
  if(((previousDistanceCm - error) > currentDistanceCm) || ((previousDistanceCm + error) < currentDistanceCm)){
    previousDistanceCm = currentDistanceCm;
    Serial.print("Distance (cm): ");
    Serial.println(currentDistanceCm);
    Serial.print("Time : ");
    Serial.println(millis()/1000);
  }
  
  // Prints the distance on the Serial Monitor
  
  
  delay(1000);
}