int vermelho = 7;
int verde = 2;
int amarelo = 4;

int pinoLDR = A0;
int intensidade = 0;

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(vermelho, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(amarelo, OUTPUT);

  Serial.begin(9600);
  pinMode(pinoLDR, INPUT);
}

void loop()
{
      digitalWrite(verde, LOW);
      delay(0); 

  if(intensidade >= 680 and intensidade <= 1017){
      digitalWrite(vermelho, HIGH);
      delay(150); 
      digitalWrite(vermelho, LOW);
      delay(150); 

  }else if(intensidade >= 400 and intensidade <= 899){
      digitalWrite(amarelo, HIGH);
      delay(300); 
      digitalWrite(amarelo, LOW);
      delay(300); 
  }else{
      digitalWrite(verde, HIGH);
      delay(0);

  }

  intensidade = analogRead(pinoLDR);

  Serial.println(intensidade);

  delay(200);

}
