/** 
 * Utilizar LED RGB incorporado con colores básicos
 * 
 * Este ejemplo muestra los colores rojo, verde y azul, 1 segundo cada uno.
 */

#include <Arduino.h>
#include "LevixEduCoreDev.h"

// Crear colores rojo, verde y azul con códigos RGB
uint32_t red   = levix.ledRGB().Color(255, 0, 0);
uint32_t green = levix.ledRGB().Color(0, 255, 0);
uint32_t blue  = levix.ledRGB().Color(0, 0, 255);

void setup() {
  // Inicializar Levix Edu
  levix.init();
}

void loop() {
  // Mostrar color rojo
  levix.ledRGB().setPixelColor(0, red);
  levix.ledRGB().show();
  delay(1000);

  // Mostrar color verde
  levix.ledRGB().setPixelColor(0, green);
  levix.ledRGB().show();
  delay(1000);

  // Mostrar color azul
  levix.ledRGB().setPixelColor(0, blue);
  levix.ledRGB().show();
  delay(1000);
}