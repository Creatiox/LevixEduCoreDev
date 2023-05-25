/**
 * SPDX-FileCopyrightText: 2023 Creatiox
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef LEVIX_EDU_CORE_DEV_H
#define LEVIX_EDU_CORE_DEV_H

#include "Adafruit_NeoPixel.h"
#include "LevixEduCore.h"
#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>

/// @brief Pines disponibles en Levix Edu Core Dev-board.
namespace Levix {

/// @brief Pines disponibles como entradas y salidas.
namespace GPIOs {
enum {
  GPIO_32 = 32,
  GPIO_33 = 33,
  GPIO_25 = 25,
  GPIO_26 = 26,
  GPIO_27 = 27,
  GPIO_14 = 14,
  GPIO_12 = 12,
  GPIO_13 = 13,
  GPIO_15 = 15,
  GPIO_02 = 2,
  GPIO_04 = 4,
  GPIO_19 = 19,
  GPIO_21 = 21,
  GPIO_22 = 22,
  GPIO_23 = 23
};
}

/// @brief Pines disponibles solo como salidas.
namespace GPIs {
enum { GPI_36 = 36, GPI_39 = 39, GPI_34 = 34, GPI_35 = 35 };
} // namespace GPIs

/// @brief Pines disponibles como entradas analógicas.
namespace AINs {
enum {
  CH0 = GPIs::GPI_36,
  CH3 = GPIs::GPI_39,
  CH6 = GPIs::GPI_34,
  CH7 = GPIs::GPI_35,
  CH4 = GPIOs::GPIO_32,
  CH5 = GPIOs::GPIO_33
};
}

/// @brief Pines disponibles como salidas analógicas.
namespace DACs {
enum { CH1 = GPIOs::GPIO_25, CH2 = GPIOs::GPIO_26 };
}
} // namespace Levix

class LevixEduCoreDev : public LevixEduCore {
  public:
  LevixEduCoreDev();

  /**
   * @brief Inicializar Levix Edu Core Dev-board.
   */
  void init();

  /**
   * @brief Encender LED monocromático.
   */
  void ledOn();

  /**
   * @brief Apagar LED monocromático.
   */
  void ledOff();

  /**
   * @brief Obtener referencia al LED RGB. Ej: levix.ledRGB.show().
   *
   * @return Adafruit_NeoPixel& LED RGB (librería Adafruit_NeoPixel)
   */
  Adafruit_NeoPixel& ledRGB();

  /**
   * @brief Obtener la referencia a la UART 1. Ej: levix.uart1().print().
   *
   * @return HardwareSerial& UART 1
   */
  HardwareSerial& uart1();

  /**
   * @brief Obtener la referencia a la UART 2. Ej: levix.uart2().print().
   *
   * @return HardwareSerial& UART 2
   */
  HardwareSerial& uart2();

  /**
   * @brief Obtener la referencia al puerto I2C 1. Ej: levix.i2c1().setPins().
   *
   * @return HardwareSerial& Puerto I2C 1
   */
  TwoWire& i2c1();

  /**
   * @brief Obtener la referencia al puerto I2C 2. Ej: levix.i2c2().setPins().
   *
   * @return HardwareSerial& Puerto I2C 2
   */
  TwoWire& i2c2();

  /**
   * @brief Obtener la referencia al puerto SPI 1. Ej: levix.spi1().write().
   *
   * @return HardwareSerial& Puerto SPI 1
   */
  SPIClass& spi1();

  /**
   * @brief Obtener la referencia al puerto SPI 2. Ej: levix.spi2().write().
   *
   * @return HardwareSerial& Puerto SPI 2
   */
  SPIClass& spi2();

  private:
  Adafruit_NeoPixel _led_rgb;
  HardwareSerial& _uart_1;
  HardwareSerial& _uart_2;
  TwoWire& _i2c_1;
  TwoWire& _i2c_2;
  SPIClass& _spi_1;
  SPIClass _spi_2;

  enum LEDs { LED_MONO = 5, LED_RGB = 18 };
};

extern LevixEduCoreDev levix;

#endif // LEVIX_EDU_CORE_DEV_H