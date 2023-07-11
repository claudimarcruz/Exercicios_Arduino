
int led_vermelho = 3;
//int led_verde =4;
void setup()
{
  pinMode(led_vermelho, OUTPUT);
 // pinMode(led_verde, OUTPUT);
}

void loop()
{
  	digitalWrite(led_vermelho, HIGH);
 	  //digitalWrite(led_verde,LOW);
  	delay(1000);
  	//digitalWrite(led_verde,HIGH);
  	digitalWrite(led_vermelho,LOW);
  	delay(1000);	
  
}