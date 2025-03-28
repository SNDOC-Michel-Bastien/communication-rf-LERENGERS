#include "Arduino.h"
#include "soc_log.h"
#include "RX_TX.h"
#include <DHT.h>

#define DHTPIN 4        // GPIO utilisé pour le DHT22
#define DHTTYPE DHT22   // Type du capteur

int NUMTRAME=0;

DHT dht(DHTPIN, DHTTYPE);

HardwareSerial mySerial(2);  // UART2 sur l'ESP32

void setupMoniteurSerie(int Baud_moniteur)
{
  Serial.begin(Baud_moniteur);
}

void setupTransmition(int Pin_RX, int Pin_TX, int Baud_transm)
{
    mySerial.begin(200, SERIAL_8N1, Pin_RX, Pin_TX);  // UART2
}

void setupDHT22()
{
    dht.begin();
}

void afficherTrame(){

  if (mySerial.available()) 
  {  
     String trame = mySerial.readStringUntil('\n');  // Lire une ligne complète
     String contenu = trame.substring(1, trame.length() - 2);
     Serial.println(contenu);
  }
}

float capteurTemperature()
{
  float temperature = dht.readTemperature();
  return temperature;
}

float capteurHumidite()
{
  float humidite = dht.readHumidity();
  return humidite;
}

void envoyerTrame(String SERRE_ID, float TEMPERATURE, float HUMIDITE)
{ 

  if (NUMTRAME > 360) 
  {
    NUMTRAME = 0;
  }

  String data = "SERRE" + String(SERRE_ID) + ";" + (NUMTRAME) + ";" + String(TEMPERATURE) + "°C;" + String(HUMIDITE) + "%";
  String trame = "\x02" + data + "\x03\r\n";  // Construction de la trame

  mySerial.print(trame);
  Serial.println(trame);

  NUMTRAME++;

  delay(1000);  // Pause 1s
}