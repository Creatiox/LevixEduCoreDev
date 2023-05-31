/** 
 * Encender/Apagar LED monocromático incorporado (blink)
 * 
 * Este ejemplo es útil para saber si la placa programa correctamente.
 */

#include <Arduino.h>
#include "LevixEduCoreDev.h"

void setup() {
  // Inicializar Levix Edu
  levix.init();
}

void loop() {
  // Parpadear Led 2 veces por segundo
  levix.ledOn();
  delay(100);
  levix.ledOff();
  delay(400);
}