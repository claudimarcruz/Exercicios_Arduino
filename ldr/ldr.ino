// C++ code
//

int pinoLDR = A0;
int intensidade = 0;
//int ledVerm = 8;

void setup()
{
  Serial.begin(9600);
  pinMode(pinoLDR, INPUT);
  //pinMode(ledVerm, OUTPUT);
}

void loop()
{
  intensidade = analogRead(pinoLDR);
  
  Serial.println(intensidade);
/*
  if(intensidade < 500){
    digitalWrite(ledVerm, HIGH);
  }else{
    digitalWrite(ledVerm, LOW);
  }
  */
  delay(500);
}