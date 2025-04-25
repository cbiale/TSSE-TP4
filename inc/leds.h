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

#ifndef LEDS_H
#define LEDS_H

/** @file leds.h
 ** @brief Declaraciones de la biblioteca para el control de LEDs.
 **/

/* === Headers files inclusions
 * ================================================================ */

#include <stdbool.h>
#include <stdint.h>

/* === Cabecera C++
 * ============================================================================
 */

#ifdef __cplusplus
extern "C" {
#endif

/* === Public macros definitions
 * =============================================================== */

/* === Public data type declarations
 * =========================================================== */

/* === Public variable declarations
 * ============================================================ */

/* === Public function declarations
 * ============================================================ */

/**
 * @brief Inicializa la biblioteca para el control de LEDs.
 *
 * @note Esta función debe ser llamada antes de utilizar cualquier otra función
 * de la biblioteca.
 *
 * @param direccion Puntero a un arreglo de enteros sin signo de 16 bits que
 * representa el estado de los LEDs.
 */
void LedsInit(uint16_t *direccion);

/**
 * @brief Enciende un LED individual.
 *
 * @param led Número de LED a encender.
 */
void LedsOnSingle(uint8_t led);

/**
 * @brief Apaga un LED individual.
 *
 * @param led Número de LED a apagar.
 */
void LedsOffSingle(uint8_t led);

/**
 * @brief Enciende todos los LEDs de una vez.
 */
void LedsOnAll(void);

/**
 * @brief Apaga todos los LEDs de una vez.
 */
void LedsOffAll(void);

/**
 * @brief Consulta si un LED está encendido.
 *
 * @param led Número de LED a consultar.
 *
 * @return true si el LED está encendido, false en caso contrario.
 */
bool LedsIsOnSingle(uint8_t led);

/* === End of documentation
 * ==================================================================== */

#ifdef __cplusplus
}
#endif

#endif /* LEDS_H */
