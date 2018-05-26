//sensor1
int Trig1 = 9;
int Echo1 = 8;

//sensor2
int Trig2 = 10;
int Echo2 = 11;

//sensor1
long duracion1 = 0;
long distancia1 = 0;

//sensor2
long duracion2 = 0;
long distancia2 = 0;

void setup() {
  Serial.begin(9600);
  pinMode(Trig1, OUTPUT);
  pinMode(Echo1, INPUT);
  //
  pinMode(Trig2, OUTPUT);
  pinMode(Echo2, INPUT);
}

void loop() {


  //sensor1
  digitalWrite(Trig1, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig1, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig1, LOW);

  duracion1 = pulseIn(Echo1, HIGH);
  distancia1 = (duracion1 / 2) / 28;

  ////////sensor2

  digitalWrite(Trig2, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig2, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig2, LOW);

  duracion2 = pulseIn(Echo2, HIGH);
  distancia2 = (duracion2 / 2) / 28;

  //sensor1
  //Serial.print(" A: ");
  // Serial.print(distancia1);


  int Residuo [4];


  for (int i = 0; i <= 3; i++) {
    Residuo[i] = distancia1 % 10;
    distancia1 = distancia1 / 10;
  }
  Serial.write('d');
  for (int i = 3; i >= 0; i--) {
    Serial.write(Residuo[i]);
  }
  Serial.write('e');


  for (int i = 0; i <= 3; i++) {
    Residuo[i] = distancia2 % 10;
    distancia2 = distancia2 / 10;
  }
  Serial.write('a');
  for (int i = 3; i >= 0; i--) {
    Serial.write(Residuo[i]);
  }
  Serial.write('c');



  //sensor2
 // Serial.print(" B: ");
 // Serial.println(distancia2);
}
