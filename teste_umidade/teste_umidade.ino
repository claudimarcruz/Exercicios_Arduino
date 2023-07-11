const int pino_umidade = A1;
int umidade = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(pino_umidade, INPUT);
  Serial.begin(9600);

}

void loop() {

  umidade = analogRead(pino_umidade);
  Serial.println(umidade);
  delay(500);
  // put your main code here, to run repeatedly:

}
