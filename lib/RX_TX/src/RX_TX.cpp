#include "Arduino.h"
#include "soc_log.h"
#include "RX_TX.h"

HardwareSerial mySerial(2);  // UART2 sur l'ESP32

void Setup_Moniteur_Serie(int Baud_moniteur)
{
  Serial.begin(Baud_moniteur);
}

void Setup_transmition(int Pin_RX, int Pin_TX, int Baud_transm)
{
    mySerial.begin(200, SERIAL_8N1, Pin_RX, Pin_TX);  // UART2
}

void Afficher_Tram(){

  if (mySerial.available()) {  
        String trame = mySerial.readStringUntil('\n');  // Lire une ligne complète

            String contenu = trame.substring(2, trame.length() - 3);  // Extraire les données sans STX/ETX
            Serial.println("Trame reçue : " + contenu);
    }
}