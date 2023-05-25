/**
 * SPDX-FileCopyrightText: 2023 Creatiox
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "LevixEduCoreDev.h"

LevixEduCoreDev::LevixEduCoreDev()
    : _led_rgb(/*leds*/ 1, /*gpio*/ LEDs::LED_RGB, /*config*/ NEO_GRB + NEO_KHZ800)
    , _uart_1(Serial1)
    , _uart_2(Serial2)
    , _i2c_1(Wire)
    , _i2c_2(Wire1)
    , _spi_1(SPI)
    , _spi_2(HSPI) {}

void LevixEduCoreDev::init() {
  // Inicializar UART terminal
  terminal().begin(115200);

  pinMode(LEDs::LED_MONO, OUTPUT);
  digitalWrite(LEDs::LED_MONO, LOW);

  _led_rgb.begin();
  _led_rgb.clear();
  _led_rgb.show();

  wifiInit();
}

void LevixEduCoreDev::ledOn() { digitalWrite(LEDs::LED_MONO, HIGH); }
void LevixEduCoreDev::ledOff() { digitalWrite(LEDs::LED_MONO, LOW); }
Adafruit_NeoPixel& LevixEduCoreDev::ledRGB() { return _led_rgb; }
HardwareSerial& LevixEduCoreDev::uart1() { return _uart_1; }
HardwareSerial& LevixEduCoreDev::uart2() { return _uart_2; }
TwoWire& LevixEduCoreDev::i2c1() { return _i2c_1; }
TwoWire& LevixEduCoreDev::i2c2() { return _i2c_2; }
SPIClass& LevixEduCoreDev::spi1() { return _spi_1; }
SPIClass& LevixEduCoreDev::spi2() { return _spi_2; }

LevixEduCoreDev levix;