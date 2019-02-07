/*
HC-SR04 Ping distance sensor]
VCC to arduino 5v GND to arduino GND
Echo to Arduino pin 12 Trig to Arduino pin 13
Red POS to Arduino pin 11
Green POS to Arduino pin 10
Original code improvements to the Ping sketch sourced from Trollmaker.com
Some code and wiring inspired by http://en.wikiversity.org/wiki/User:Dstaub/robotcar
*/

int speaker = 7;
float Xz = 0.0f;

#define trigPin 10
#define echoPin 11

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(speaker, OUTPUT);
}

void loop() {
  long duration, distance; //These are variables. duration: how long to receive echo; distance: measurement in cm
  digitalWrite(trigPin, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin, HIGH);
//  delayMicroseconds(1000); - Removed this line
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); //Number of microseconds it takes to receive the ping back
  distance = (duration/2) / 29.1; //Arduino calculates the distance. 29.1 is a magic number determined by the speed of sound and other stuff.

  float frequency = 0.0f;
  if (distance >= 50 || distance <= 0){
    Serial.println("Out of range");
  }
  else {
    //Serial.print(distance);
    //Serial.println(" cm");
    frequency = 1000.0f;
    frequency += (float) distance * 50.0f;
  }

  int f = (int) (frequency*0.01f + 0.99*Xz);
  Xz = frequency;

  Serial.println(frequency);
  if (f<400)
  {
    noTone(speaker);
  }
  else
  {
    tone(speaker, f);
  }
  
  delay(1);
}
