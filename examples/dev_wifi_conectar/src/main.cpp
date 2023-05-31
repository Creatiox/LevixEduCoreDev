/**
 * Conectarse a una red WiFi y utilizar "callbacks"
 *
 * Este ejemplo muestra cómo conectarse a una red WiFi, y cómo utilizar los "callbacks" o funciones
 * externas para los eventos de conexión y desconexión del mismo. Realiza distintas funciones para
 * ambos LEDs para cada evento.
 */

#include <Arduino.h>
#include "LevixEduCoreDev.h"

#define SSID "mi ssid"
#define PASS "mi password"

uint16_t led_change_time = 1000;

// Función a ejecutar cuando se conecte a la red WiFi
void onConnect() {
  levix.terminal().println("WiFi conectado!");

  // Poner led RGB en verde
  levix.ledRGB().setPixelColor(0, levix.ledRGB().Color(0, 50, 0));
  levix.ledRGB().show();

  // Establecer frecuencia de cambio del led monocromático en 50ms
  led_change_time = 50;
}

// Función a ejecutar cuando se desconecte de la red WiFi
void onDisconnect() {
  levix.terminal().println("WiFi desconectado!");

  // Poner led RGB en rojo
  levix.ledRGB().setPixelColor(0, levix.ledRGB().Color(50, 0, 0));
  levix.ledRGB().show();

  // Establecer frecuencia de cambio del led monocromático en 1s
  led_change_time = 1000;
}

void setup() {
  // Inicializar Levix Edu
  levix.init();

  // Configurar WiFi
  levix.wifiOnConnected(onConnect);
  levix.wifiOnDisconnected(onDisconnect);
  levix.wifiEnable(SSID, PASS);
}

void loop() {
  static uint32_t led_timer = 0;
  static bool led_on        = false;

  if (millis() - led_timer > led_change_time) {
    led_timer = millis();

    if (led_on) {
      levix.ledOff();
      led_on = false;
    } else {
      levix.ledOn();
      led_on = true;
    }
  }
}