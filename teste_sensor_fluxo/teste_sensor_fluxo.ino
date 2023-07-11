// configuração do blynk
#define BLYNK_TEMPLATE_ID "TMPL2UkI9WW2F"
#define BLYNK_TEMPLATE_NAME "Projeto de Irrigação com Arduino "
#define BLYNK_AUTH_TOKEN "euoAhb63ZsAgcodx_FaT_8DVa_JReav_"

#define BLYNK_PRINT Serial
#include "ESP8266_Lib.h"
#include "BlynkSimpleShieldEsp8266.h"

char auth[] = BLYNK_AUTH_TOKEN;

// nome da rede e senha para a conexão do ESP8266
char ssid[] = "BAR Clientes";
char pass[] = "22441727";


#include "SoftwareSerial.h"
SoftwareSerial EspSerial(10,11); // RX, TX

#define ESP8266_BAUD 9600

ESP8266 wifi(&EspSerial);

//sensor de fluxo

//definicao do pino do sensor e de interrupcao
const int INTERRUPCAO_SENSOR = 0; //interrupt = 0 equivale ao pino digital 2
const int PINO_SENSOR = 2;

//definicao da variavel de contagem de voltas
unsigned long contador = 0;

//definicao do fator de calibracao para conversao do valor lido
const float FATOR_CALIBRACAO = 4.5;

//definicao das variaveis de fluxo e volume
float fluxo = 0;
float volume = 0;
float volume_total = 0;

//definicao da variavel de intervalo de tempo
unsigned long tempo_antes = 0;


void setup()
{
  
  Serial.begin(9600);
	delay(10);

	// Set ESP8266 baud rate
	EspSerial.begin(ESP8266_BAUD);
	delay(10);
	
	Blynk.begin(auth, wifi, ssid, pass);

  //mensagem de inicializacao
  Serial.println("Medidor de Fluxo e Volume de Liquidos\n");

  //configuracao do pino do sensor como entrada em nivel logico alto
  pinMode(PINO_SENSOR, INPUT_PULLUP);
  
}

void loop()
{
  if((millis() - tempo_antes) > 1000){

    //desabilita a interrupcao para realizar a conversao do valor de pulsos
    detachInterrupt(INTERRUPCAO_SENSOR);

    //conversao do valor de pulsos para L/min
    fluxo = ((1000.0 / (millis() - tempo_antes)) * contador) / FATOR_CALIBRACAO;

    //exibicao do valor de fluxo
    Serial.print("Fluxo de: ");
    Serial.print(fluxo);
    Serial.println(" L/min");

    //calculo do volume em L passado pelo sensor
    volume = fluxo / 60;

    //armazenamento do volume
    volume_total += volume;

    //exibicao do valor de volume
    Serial.print("Volume: ");
    Serial.print(volume_total);
    Serial.println(" L");
    Serial.println();
   
    //reinicializacao do contador de pulsos
    contador = 0;

    //atualizacao da variavel tempo_antes
    tempo_antes = millis();

    //contagem de pulsos do sensor
    attachInterrupt(INTERRUPCAO_SENSOR, contador_pulso, FALLING);

    
    
  }
  
	Blynk.run();
}


//funcao chamada pela interrupcao para contagem de pulsos
void contador_pulso() {
  
  contador++;
  
}