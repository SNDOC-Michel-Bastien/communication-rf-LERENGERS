/**     // TO DO
 * @file main.cpp
 * @author Bastien michel
 * @brief 
 * @version 0.1
 * @date 2024-19-22
 * 
 * @copyright Copyright (c) 2024
 * 
 */
//////////////////////////////////////////////////////////////////////

#include <Arduino.h>
#include "LED_Bastien.h"

#define Nombre_De_Led 6
#define Exa_Pin_Leds 0x0E070000 //1110000001110000000000000000
#define Exa_Pin_Bouton 0x00001000 //1000000000000
#define Temps 500 //rapidité des LEDS en ms

bool Etat = LOW ; //machine a etat
bool Etat_Bouton = LOW ;

void setup() 
{
  Setup_Entre_Sortie(Exa_Pin_Leds, Exa_Pin_Bouton);
}

//Partie chenillard
void loop() {

  Etat_Bouton = Lire_Etat(Exa_Pin_Bouton);

  if (Etat_Bouton == HIGH) {
    do
    {
     Led_Chenilard(Temps, Nombre_De_Led);
     Etat_Bouton = Lire_Etat(Exa_Pin_Bouton);
    }while (Etat_Bouton == LOW);
  }
    else 
  {
    Eteindre_Led(Exa_Pin_Leds);
  }
}


//Partie Allumage simple
// void loop() 
// {
//   Etat_Bouton = Lire_Etat(Exa_Pin_Bouton);

//   if (Etat_Bouton == HIGH & Etat == LOW) 
//   {
//     Allume_Led(Exa_Pin_Leds);
//     delay(Temps);
//     Etat = HIGH;
//     Etat_Bouton = Lire_Etat(Exa_Pin_Bouton);
//   }

//   if (Etat_Bouton == HIGH & Etat == HIGH) 
//   {
//     Eteindre_Led(Exa_Pin_Leds);
//     delay(Temps);
//     Etat = LOW;
//     Etat_Bouton = Lire_Etat(Exa_Pin_Bouton);
//   }
// }

