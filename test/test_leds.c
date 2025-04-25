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

/** @file test_leds.c
 ** @brief Pruebas unitarias de la biblioteca para el control de LEDs.
 **/

/**
 * @test Con la inicialización todos los LEDs quedan apagados.
 * @test Prender un LED individual.
 * @test Apagar un LED individual.
 * @test Prender y apagar múltiples LEDs.
 * @test Prender todos los LEDs de una vez.
 * @test Apagar todos los LEDs de una vez.
 * @test Consultar el estado de un LED que está encendido
 * @test Consultar el estado de un LED que está apagado
 * @test Revisar limites de los parámetros.
 * @test Revisar parámetros fuera de los limites.
 */

/* === Headers files inclusions
 * =============================================================== */

#include "leds.h"
#include "unity.h"

/* === Macros definitions
 * ====================================================================== */

/* === Private data type declarations
 * ========================================================== */

/* === Private variable declarations
 * =========================================================== */
static uint16_t leds_virtuales = 0xFFFF;

/* === Private function declarations
 * =========================================================== */

/* === Public variable definitions
 * ============================================================= */

/* === Private variable definitions
 * ============================================================ */

/* === Private function implementation
 * ========================================================= */

/* === Public function implementation
 * ========================================================== */

void setUp(void) { LedsInit(&leds_virtuales); }

//! @test Con la inicialización todos los LEDs quedan apagados.
void test_todos_los_leds_inician_apagados(void) {
  uint16_t leds_virtuales = 0xFFFF;

  LedsInit(&leds_virtuales);
  TEST_ASSERT_EQUAL_HEX16(0x0000, leds_virtuales);
}

//! @test Prender un LED individual.
void test_prender_led_individual(void) {
  LedsOnSingle(4);
  TEST_ASSERT_EQUAL_HEX16(0x0008, leds_virtuales);
}

//! @test Apagar un LED individual.
void test_apagar_led_individual(void) {
  LedsOnSingle(4);
  LedsOffSingle(4);
  TEST_ASSERT_EQUAL_HEX16(0x0000, leds_virtuales);
}

//! @test Prender y apagar múltiples LEDs.
void test_prender_y_apagar_algunos_leds(void) {
  LedsOnSingle(4);
  LedsOnSingle(6);
  LedsOffSingle(4);
  LedsOffSingle(8);
  TEST_ASSERT_EQUAL_HEX16(0x0020, leds_virtuales);
}

//! @test Prender todos los LEDs de una vez.
void test_prender_todos_los_leds(void) {
  LedsOnAll();
  TEST_ASSERT_EQUAL_HEX16(0xFFFF, leds_virtuales);
}

//! @test Apagar todos los LEDs de una vez.
void test_apagar_todos_los_leds(void) {
  LedsOnAll();
  LedsOffAll();
  TEST_ASSERT_EQUAL_HEX16(0x0000, leds_virtuales);
}

//! @test Consultar el estado de un LED que está encendido
void test_consultar_estado_led_encendido(void) {
  LedsOnSingle(4);
  TEST_ASSERT_TRUE(LedsIsOnSingle(4));
}

//! @test Consultar el estado de un LED que está apagado
void test_consultar_estado_led_apagado(void) {
  LedsOnSingle(4);
  LedsOffSingle(4);
  TEST_ASSERT_FALSE(LedsIsOnSingle(4));
}
//! @test Revisar limite inferior leds
void test_revisar_limites_inferior(void) {
  LedsOnSingle(1);
  TEST_ASSERT_EQUAL_HEX16(0x0001, leds_virtuales);
}

//! @test Revisar limite superior leds
void test_revisar_limites_superior(void) {
  LedsOnSingle(16);
  TEST_ASSERT_EQUAL_HEX16(0x8000, leds_virtuales);
}
//! @test Revisar leds fuera de limites
void test_revisar_parametros_fuera_de_limites(void) {
  LedsOnSingle(0);
  TEST_ASSERT_EQUAL_HEX16(0x0000, leds_virtuales);
  LedsOnSingle(17);
  TEST_ASSERT_EQUAL_HEX16(0x0000, leds_virtuales);
}

/* === End of documentation
 * ==================================================================== */
