#include "Arduino.h"
#include "soc_log.h"
#include "RX_TX.h"
#include <DHT.h>

#define DHTPIN 4        // GPIO utilisé pour le DHT22
#define DHTTYPE DHT22   // Type du capteur

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
     String contenu = trame.substring(2, trame.length() - 3);  // Extraire les données sans STX/ETX
     Serial.println("Trame recu : " + contenu);
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

void envoyerTrame(String SERRE_ID, String TRAME_NUM, float TEMPERATURE, float HUMIDITE)
{
  String TRAME = "SERRE;" + String(SERRE_ID) + ";" + String(TRAME_NUM) + ";" + String(TEMPERATURE) + ";C;" + String(HUMIDITE) + ";%";
  mySerial.print(TRAME);  // Envoi via UART
  Serial.println("Trame envoyée : " + TRAME);  // Debug via USB
}