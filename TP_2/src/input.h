#include "employees.h"
#ifndef INPUT_H_
#define INPUT_H_



#endif /* INPUT_H_ */

/**
 * @fn int validarString(char[], int tam)
 * @brief No permite ingresar numeros en la cadena de caracteres.
 *
 * @param frase char Vector de caracteres.
 * @param tam entero Longitud de caracteres.
 * @return flag(1) Si hay error[vector frase NULL o tam menor a 0 o fallan las conficiones]
 *  - (0) Si no hay error.
 */
int validarString(char frase[],int tam);

/**
 * @fn int ordenarRangoCaracter(char[], int)
 * @brief Valida que la cadena de caracteres no desborde al vector y ordena las mayus y minus.
 *
 * @param frase	char Vector de caracteres.
 * @param tam	entero Longitud de los caracteres.
 * @return	todoOk(0) Si hay error[Vector frase NULL o tam menor a 0] - (1) Si no hay error.
 */
int rangoString(char frase[],int tam);

/**
 * @fn int validarStringOrdenado(char[])
 * @brief	Ordena la cadena de caracteres para que inicie en Mayus, y que por cada espacio se ingrese
 * 			la posicion que sigue al espacio en Mayus.
 *
 * @param frase	char Vector de caracteres.
 * @return
 */
int validarStringOrdenado(char frase[]);

/**
 * @fn int validarNumeros(char[])
 * @brief Verifica si el valor es numerico
 *
 * @param numeroIngresado Array con la cadena a ser analizada.
 * @return 1 si es numerico y 0 si no lo es.
 */
int validarNumeros(char numeroIngresado[]);

/**
 * @fn int pedirEntero(int*, char*, char*, int, int)
 * @brief Pide un entero y valida su rango.
 *
 * @param entero Puntero a entero, retorna el valor del entero ya validado.
 * @param mensaje Mensaje que pide el entero.
 * @param mensajeError Mensaje de error, si ocurre un problema.
 * @param min Valor minimo del entero.
 * @param max Valor maximo del entero.
 * @return todoOk(-1) si hay error, (0) si no hay errores.
 */
int pedirEntero(int* entero, char* mensaje, char* mensajeError, int min, int max);


/**
 * @fn int pedirFlotante(float*, char*, char*, float, float)
 * @brief Pide un flotante y valida su rango
 *
 * @param flotante Puntero a flotante, retorna el valor del flotante ya validado.
 * @param mensaje	Mensaje que pide al flotante.
 * @param mensajeError Mensaje de error, si ocurre un problema.
 * @param min Valor minimo del flotante.
 * @param max Valor maximo del flotante.
 * @return todoOk(-1) si hay error, (0) si no hay errores.
 */
int pedirFlotante(float* flotante, char* mensaje, char* mensajeError, float min, float max);
