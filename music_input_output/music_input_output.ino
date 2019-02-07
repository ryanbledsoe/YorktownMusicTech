int speaker = 7;   //make sure this matches the pin of your speaker
int button = 5;   //make sure this matches the pin of your button
int sensorValue;   
int led = 13;

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
  pinMode(speaker, OUTPUT);  //sets up the speaker as an output
  pinMode(button, INPUT);   //sets up the button as an input
  digitalWrite(button, HIGH);  //initializes the sensor
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorValue = digitalRead(button);  //reads information from the sensor
  if (sensorValue==LOW)
  {
    digitalWrite(led, HIGH);
    tone(speaker, A);
  }
  else
  {
    digitalWrite(led, LOW);
    noTone(speaker);
  }
}
