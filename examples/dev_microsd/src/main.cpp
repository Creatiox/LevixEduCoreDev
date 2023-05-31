/**
 * Mostrar directorio de tarjeta microSD
 *
 * Este ejemplo muestra cómo utilizar uno de los puertos SPI de la placa con un módulo de tarjeta
 * microSD. Muestra el directorio de la tarjeta microSD en el monitor serie, en formato tabulado.
 */

#include "LevixEduCoreDev.h"
#include <Arduino.h>
#include <SD.h>

// Mostrar contenido directorio "dir_name" con "num_tabs" tabulaciones de separación
void printDirectory(File dir_name, uint8_t num_tabs);

void setup() {
  // Inicializar Levix Edu
  levix.init();

  // Inicializar SPI 2 con pines escogidos
  levix.spi2().begin(/*SCK*/ Levix::GPIOs::GPIO_14,
                     /*MISO*/ Levix::GPIOs::GPIO_27,
                     /*MOSI*/ Levix::GPIOs::GPIO_13,
                     /*CS*/ Levix::GPIOs::GPIO_15);

  // Si no puede inicializar SD, detener programar y encender led RGB rojo
  if (!SD.begin(Levix::GPIOs::GPIO_15, levix.spi2())) {
    log_e("No se pudo inicializar la SD! Verifica que se encuentre bien conectada");

    levix.ledRGB().setPixelColor(0, levix.ledRGB().Color(50, 0, 0));
    levix.ledRGB().show();

    while (1)
      ;
  }

  // Encender led RGB verde si hubo éxito
  levix.ledRGB().setPixelColor(0, levix.ledRGB().Color(0, 50, 0));
  levix.ledRGB().show();

  // Mostrar tipo de tarjeta
  switch (SD.cardType()) {
    case sdcard_type_t::CARD_NONE: log_i("Tipo de tarjeta: NONE"); break;
    case sdcard_type_t::CARD_MMC: log_i("Tipo de tarjeta: MMC"); break;
    case sdcard_type_t::CARD_SD: log_i("Tipo de tarjeta: SD"); break;
    case sdcard_type_t::CARD_SDHC: log_i("Tipo de tarjeta: SDHC"); break;
    default: log_i("Tipo de tarjeta: Desconocida");
  }

  // Mostrar tamaños de tarjeta
  // 1048576 = 2^20 = 1MB
  log_i("Tamano de la tarjeta: %lluMB", SD.cardSize() / 1048576);
  log_i("Total utilizable: %lluMB", SD.totalBytes() / 1048576);
  log_i("Utilizado: %lluMB", SD.usedBytes() / 1048576);
}

void loop() {
  log_i("Directorio SD:");
  File dir = SD.open("/");
  printDirectory(dir, 0);

  delay(10000);
}

void printDirectory(File dir, uint8_t num_tabs) {
  while (true) {

    File entry = dir.openNextFile();

    if (!entry) {
      break;
    }

    for (uint8_t i = 0; i < num_tabs; i++) {
      levix.terminal().print('\t');
    }

    levix.terminal().print(entry.name());

    if (entry.isDirectory()) {
      levix.terminal().println("/");
      printDirectory(entry, num_tabs + 1);
    }

    else {
      // Imprimir tamaño archivo en kB
      levix.terminal().printf("\t%ukB", entry.size() / 1024);

      time_t last_write = entry.getLastWrite();
      tm* tmstruct      = localtime(&last_write);

      // Imprimir última fecha de modificación
      levix.terminal().printf("\tModificado: %02d/%02d/%02d %02d:%02d:%02d\n",
                              tmstruct->tm_mday,
                              tmstruct->tm_mon + 1,
                              tmstruct->tm_year + 1900,
                              tmstruct->tm_hour,
                              tmstruct->tm_min,
                              tmstruct->tm_sec);
    }

    entry.close();
  }
}