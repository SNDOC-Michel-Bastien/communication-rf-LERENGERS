#ifndef RX_TX_H_
#define RX_TX_H_

void setupMoniteurSerie(int Baud);
void setupTransmition(int Pin_RX, int Pin_TX, int Baud_transm);
void setupDHT22();
void afficherTrame();
void envoyerTrame(String SERRE_ID, String TRAME_NUM, float TEMPERATURE, float HUMIDITE);
float capteurTemperature();
float capteurHumidite();

#endif