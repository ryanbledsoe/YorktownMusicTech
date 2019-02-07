int speaker = 2;   //make sure this matches the pin of your speaker

//music notes. Arduino reads pitch as frequencies in hertz. 
//The following list of variables lets us use letter names of the 
//notes instead of the frequencies.
int C = 1046;
int D = 1175;
int E = 1319;
int Eb = 1245;
int F = 1397;
//int F = 1480;
int G = 1568;
int A = 1760;
int Ab = 1661;
int B = 1976;
int Bb = 1865;
int C1 = 2093;

void setup() {
  // put your setup code here, to run once:
  pinMode(speaker, OUTPUT);  //sets up the speaker as an output
}

void loop() {
  // put your main code here, to run repeatedly:
    tone(speaker, B);
    delay(1000);
    tone(speaker, D);
    delay(1000);
    tone(speaker, A);
    delay(1000);
    tone(speaker, C);
    noTone(speaker);
    delay(1000);
  }
