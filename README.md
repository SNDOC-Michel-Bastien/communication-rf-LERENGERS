

# tp-gestionIO

**Objectifs :** 	On désire piloter un ensemble de 6 à 8 dels traversantes lors d’un appui sur un bouton poussoir nommé BP1. Chaque appui allume une del et éteint la précédente.

---

## Nomenclature

- une carte Az-Delivery [D1 R32](https://www.az-delivery.de/fr/products/esp32-d1-r32-board)

<img src="images/AzD1R32.jpg" height="100" width="100">

- de 6 à 8 DELs <img src="images/led_rouge.png" height="50" width="50">

- un bouton poussoir <img src="images/bp.png" height="50" width="50">

---

Cette activité est à réaliser avec **PlatformIO** pour une carte ESP32 avec le _framework_ **Arduino**.

Le fichier de projet `platformio.ini` :

```ini
[env:esp32dev]
platform = espressif32
board = esp32dev
framework = arduino
```
Le fichier `src/main.cpp` initial :

```cpp

/**     // TO DO
 * @file main.cpp
 * @author your name
 * @brief 
 * @version 0.1
 * @date 2024-11-22
 * 
 * @copyright Copyright (c) 2024
 * 
 */
//////////////////////////////////////////////////////////////////////

#include <Arduino.h>

//////////////////////////////////////////////////////////////////////
void setup() {
   // TO DO
 }
//////////////////////////////////////////////////////////////////////
void loop() {
  // TO DO
}

```

&copy; 2024 LICENCE SN-DOC Lasalle Avignon - J.BEAUMONT

