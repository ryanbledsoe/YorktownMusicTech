int speaker = 7;
//int sensorValue = A0;

//notes
int C = 1046;
int D = 1175;
int E = 1319;
int F = 1397;
int G = 1568;
int A = 1760;
int B = 1976;
int C1 = 2093;




void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(speaker, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:


  // these constants won't change. They are the
  // lowest and highest readings you get from your sensor:
  const int sensorMin = 45;      // sensor minimum, discovered through experiment
  const int sensorMax = 300;    // sensor maximum, discovered through experiment
    int sensorValue = analogRead(A6);
   // map the sensor range to a range of four options:
  int range = map(sensorValue, sensorMin, sensorMax, 0, 3);
  
// do something different depending on the
  // range value:
  switch (range) {
    case 0:    // your hand is on the sensor
      Serial.println("dark");
      tone(speaker, C);
      break;
    case 1:    // your hand is close to the sensor
      Serial.println("dim");
      tone(speaker, F);
      break;
    case 2:    // your hand is a few inches from the sensor
      Serial.println("medium");
      tone(speaker, A);
      break;
    case 3:    // your hand is nowhere near the sensor
      Serial.println("bright");
      tone(speaker, B);
      break;
    default:
      noTone(speaker);
  }
  delay(1);        // delay in between reads for stability
}
