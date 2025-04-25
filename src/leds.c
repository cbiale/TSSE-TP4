/************************************************************************************************
MIT License

Copyright (c) 2024 Claudio Omar Biale

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

*************************************************************************************************/

/** @file leds.c
 ** @brief Declaraciones de la biblioteca para el control de LEDs.
 **/

/* === Headers files inclusions
 * =============================================================== */

#include "leds.h"

/* === Macros definitions
 * ====================================================================== */

//! @brief Máscara de bits para apagar todos los LEDs.
#define ALL_LEDS_OFF 0x0000
//! @brief Máscara de bits para encender todos los LEDs.
#define ALL_LEDS_ON 0xFFFF
//! @brief Diferencia entre el número de led y el número de bit.
#define LEDS_TO_BITS_OFFSET 1
//! @brief Constante con el primer bit en uno para generar una máscara.
#define FIRST_BIT 1
//! @brief Define que el led se encuentra apagado
#define LED_OFF 0
//! @brief Constate que indica el primer led valido
#define FIRST_LED 1
//! @brief Constate que indica el ultimo led valido
#define LAST_LED 16

/* === Private data type declarations
 * ========================================================== */

/* === Private variable declarations
 * =========================================================== */

//! @brief Variable privada para almacenar la dirección del puerto de salida.
static uint16_t *port_address;

/* === Private function declarations
 * =========================================================== */

/**
 * @brief Función privada que convierte un número de LED a una máscara de bits.
 *
 * @param led Número de LED.
 *
 * @return Máscara de bits a utilizar.
 */
static uint16_t LedToMask(uint8_t led);

/**
 * @brief Función privada que verifica si el número de LED está dentro de los
 * límites válidos.
 *
 * @param led Número de LED.
 *
 * @return true si el número de LED está dentro de los límites, false en caso
 * contrario.
 */
static bool insideLimits(uint8_t led);

/* === Public variable definitions
 * ============================================================= */

/* === Private variable definitions
 * ============================================================ */

/* === Private function implementation
 * ========================================================= */

static uint16_t LedToMask(uint8_t led) {
  return (FIRST_BIT << (led - LEDS_TO_BITS_OFFSET));
}

static bool insideLimits(uint8_t led) {
  return (led >= FIRST_LED) && (led <= LAST_LED);
}
/* === Public function implementation
 * ========================================================== */

void LedsInit(uint16_t *direccion) {
  port_address = direccion;
  LedsOffAll(); // esto agrego como cambio
}

void LedsOnSingle(uint8_t led) { *port_address |= LedToMask(led); }

void LedsOffSingle(uint8_t led) { *port_address &= ~LedToMask(led); }

void LedsOnAll(void) { *port_address = ALL_LEDS_ON; }

void LedsOffAll(void) { *port_address = ALL_LEDS_OFF; }

bool LedsIsOnSingle(uint8_t led) {
  if (insideLimits(led) == false) {
    return false;
  }
  if ((*port_address & LedToMask(led)) != LED_OFF) {
    return true;
  } else {
    return false;
  };
}

/* === End of documentation
 * ==================================================================== */
