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
#include "RX_TX.h"

#define Tx_Pin 17  // GPIO17 comme TX
#define Rx_Pin 16  // GPIO16 comme RX
#define Baud_Moniteur 9600  //Vitesse du moniteur series
#define Baud_Transmition 200  //vitesse de transmition


void setup() 
{
  Setup_Moniteur_Serie(Baud_Moniteur);
  Setup_transmition(Rx_Pin, Tx_Pin, Baud_Transmition);
}

void loop() {
  Afficher_Tram();
}