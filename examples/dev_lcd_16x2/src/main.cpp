/**
 * Escribir en LCD 16x2
 *
 * Este ejemplo muestra cómo utilizar uno de los puertos I2C de la placa con una LCD de 16x2
 * caracteres con comunicación I2C, utilizada comúnmente. Muestra números en la pantalla escritos
 * con una frecuencia relativamente alta.
 */

#include <Arduino.h>
#include "LevixEduCoreDev.h"
#include "LiquidCrystal_PCF8574.h"

// Crear objeto LCD
// 0x27 es la dirección predeterminada. Se puede utilizar otra en caso que sea distinta.
LiquidCrystal_PCF8574 lcd(0x27);

// Números para mostrar en la LCD
uint8_t num1 = 0;
uint8_t num2 = 0;

void setup() {
  // Inicializar Levix Edu
  levix.init();

  // Configurar I2C
  levix.i2c1().setPins(Levix::GPIOs::GPIO_19, Levix::GPIOs::GPIO_04);
  levix.i2c1().begin();

  // Inicializar LCD (16 columnas, 2 filas, I2C 1 de Levix Edu)
  lcd.begin(16, 2, levix.i2c1());

  // Establecer brillo de la pantalla al máximo
  lcd.setBacklight(255);
}

void loop() {
  /**
   * - Poner cursor al inicio de la fila 1
   * - Escribir en la fila el número con 3 caracteres fijos
   * - Sumar 1 a num1
   */
  lcd.setCursor(0, 0);
  lcd.printf("Numero 1: %3u", num1);
  num1++;

  /**
   * - Poner cursor al inicio de la fila 2
   * - Escribir en la fila el número con 3 caracteres fijos
   * - Sumar 2 a num2
   */
  lcd.setCursor(0, 1);
  lcd.printf("Numero 2: %3u", num2++);
  num2 += 2;

  delay(250);
}