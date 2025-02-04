#ifndef LED_BASTIEN_H_
#define LED_BASTIEN_H_

void Led_Chenilard(int Temps, int Nombre_De_LED) ;
void Setup_Entre_Sortie(int Exa_Pin_entree, int Exa_Pin_Sortie);
bool Lire_Etat(int Exa_Pin);
void Allume_Led(int Exa_Pin);
void Eteindre_Led(int Exa_Pin);

#endif