#include "Arduino.h"
#include "soc_log.h"
#include "LED_Bastien.h"

void Led_Chenilard(int Temps, int Nombre_De_LED)
{

int LEDS[Nombre_De_LED] = {BIT18, BIT27, BIT16, BIT17, BIT25, BIT26};

 for (u_int8_t i = 0; i < Nombre_De_LED; i++)
      {
        REG_WRITE(GPIO_OUT_W1TS_REG, LEDS[i]);
        delay(Temps);           
        REG_WRITE(GPIO_OUT_W1TC_REG, LEDS[i]);
      }

      for (u_int8_t i = Nombre_De_LED-1; i > 0; i--)
     {
       REG_WRITE(GPIO_OUT_W1TS_REG, LEDS[i]);
       delay(Temps);           
       REG_WRITE(GPIO_OUT_W1TC_REG, LEDS[i]);
     }

}

void Setup_Entre_Sortie(int Exa_Pin_Leds, int Exa_Pin_Bouton)
{
    REG_WRITE(GPIO_ENABLE_W1TS_REG, Exa_Pin_Leds); 
    REG_WRITE(GPIO_ENABLE_W1TC_REG, Exa_Pin_Bouton);
}

bool Lire_Etat(int Exa_Pin)
{
  return(REG_GET_BIT(GPIO_IN_REG, Exa_Pin));
  
}

void Allume_Led(int Exa_Pin)
{
  REG_WRITE(GPIO_OUT_W1TS_REG, Exa_Pin);
}

void Eteindre_Led(int Exa_Pin)
{
  REG_WRITE(GPIO_OUT_W1TC_REG, Exa_Pin);
}