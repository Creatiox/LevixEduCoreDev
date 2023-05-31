/**
 * Arcoíris con LED RGB incorporado
 *
 * Este ejemplo recorre todos los colores con el led RGB en 32 pasos, haciendo un arcoíris. Cambia
 * los colores cada 200ms.
 */

#include <Arduino.h>
#include "LevixEduCoreDev.h"

/**
 * "Hue" es el matiz o color. La variable "hue" es un número entre 0 y 65535 (2^16) utilizada para
 * representar la rueda de colores, explicada aquí:
 * https://learn.adafruit.com/adafruit-neopixel-uberguide/arduino-library-use#hsv-hue-saturation-value-colors-dot-dot-dot-3024464
 */
uint16_t hue = 0;

void setup() {
  // Inicializar Levix Edu
  levix.init();
}

void loop() {
  /**
   * Obtener color según las variables:
   * - Hue: variable "hue", rueda de colores
   * - Saturación: 255, color completamente saturado
   * - Brillo: 100, no tan brillante (255 es el máximo)
   */
  uint32_t color = levix.ledRGB().ColorHSV(hue, 255, 100);

  // Realizar corrección gamma para notar mejor los cambios de color
  uint32_t corrected_color = levix.ledRGB().gamma32(color);

  // Mostrar color
  levix.ledRGB().setPixelColor(0, corrected_color);
  levix.ledRGB().show();

  /**
   * Para hacer el efecto arcoíris, se debe ir recorriendo continuamente la rueda de colores. Para
   * ello, la variable "hue" debe ir incrementándose continuamente con un período de tiempo
   * determinado.
   *
   * El valor de incremento debe ser: (2^16) / N
   * - Donde N es el número de pasos para dar una vuelta completa
   * - N debe ser múltiplo de 2 para sincronizar correctamente la vuelta
   *
   * Por ejemplo: (2^16) / 32: 2048
   * - 32 pasos para dar una vuelta completa
   */
  hue += 2048;

  // Tiempo entre cambios de color
  delay(200);
}