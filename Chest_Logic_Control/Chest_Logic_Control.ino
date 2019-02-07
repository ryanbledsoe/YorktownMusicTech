#include <CapacitiveSensor.h>

//Pin name declaration
#define pinLightSensor 11
#define pinSpeaker A2

CapacitiveSensor mySensor(A5, A3);

//Other variables
const int lightThreshold = 30;
const int octave = 2;
bool isOpen = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(pinLightSensor, INPUT);
  pinMode(pinSpeaker, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  
  Serial.println(analogRead(pinLightSensor));
  Serial.println(mySensor.capacitiveSensorRaw(1));
  delay(1);
  if(analogRead(pinLightSensor) > lightThreshold && isOpen == false)
  {
      isOpen = true;
      tone(pinSpeaker, 196*(2*octave));
      delay(200);
      tone(pinSpeaker, 185*(2*octave));
      delay(200);
      tone(pinSpeaker, 155*(2*octave));
      delay(200);
      tone(pinSpeaker, 147*(2*octave));
      delay(200);
      tone(pinSpeaker, 104*(2*octave));
      delay(200);
      tone(pinSpeaker, 147*(2*octave));
      delay(200);
      tone(pinSpeaker, 185*(2*octave));
      delay(200);
      tone(pinSpeaker, 262*(2*octave));
      delay(400);
      noTone(pinSpeaker);
      delay(400);
  }
  if(analogRead(pinLightSensor) <= lightThreshold && isOpen)
  {
    isOpen = false;
    delay(1000);
  }
  if(mySensor.capacitiveSensorRaw(1) >= 6)
  {
     //G, A, Bb, B
     tone(pinSpeaker, 196*(2*octave));
     delay(300);
     tone(pinSpeaker, 220*(2*octave));
     delay(300);
     tone(pinSpeaker, 233*(2*octave));
     delay(300);
     tone(pinSpeaker, 247*(2*octave));
     delay(800);
     noTone(pinSpeaker);
     delay(400);
  }
}
