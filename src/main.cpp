/**     // TO DO
 * @file main.cpp
 * @author Bastien michel
 * @brief 
 * @version 0.1
 * @date 2025-02-06
 * 
 * @copyright Copyright (c) 2024
 * 
 */
//////////////////////////////////////////////////////////////////////

#include <Arduino.h>
#include <DHT.h>
#include <DHT_U.h>
#include "RX_TX.h"


#define Tx_Pin 17  // GPIO17 comme TX
#define Rx_Pin 16  // GPIO16 comme RX
#define Baud_Moniteur 9600  //Vitesse du moniteur series
#define Baud_Transmition 200  //vitesse de transmition

//#define RECEPTEUR

String SERRE_ID="1" ;           // ID de la serre

void setup() 
{
  setupMoniteurSerie(Baud_Moniteur);
  setupTransmition(Rx_Pin, Tx_Pin, Baud_Transmition);
  setupDHT22();
}

#ifdef RECEPTEUR 
void loop() {
  afficherTrame();
}
#else
void loop() {
  envoyerTrame(SERRE_ID, capteurTemperature(), capteurHumidite());
}
#endif



