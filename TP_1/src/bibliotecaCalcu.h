/*
 * bibliotecaCalcu.h
 *
 *  Created on: 14 sep. 2021
 *      Author: Nahue
 */
#include <stdio.h>
#include <stdlib.h>
#ifndef BIBLIOTECACALCU_H_
#define BIBLIOTECACALCU_H_



#endif /* BIBLIOTECACALCU_H_ */
/**
 * @fn int menu(int ,int)
 * @brief La funcion menu no recibe ningun parametro, y nos retorna un menu de opciones. El usuario aquí puede leer y seleccionar la opcion que considere apropiada, aunque debe seguir un orden.
 *
 * @return En fin, la funcion nos retorna la opcion seleccionada por el usuario.
 */
int menu(int a,int b);


/**
 * @fn int suma(int, int, int*)
 * @brief La funcion sumar recibe 2 enteros y un puntero a entero. Luego, nos devuelve un entero.
 * La funcion toma los datos ingresados por el usuario, y luego los suma.
 *
 * @param a Operando1 ingresado por el usuario, obtenido del main.
 * @param b Operando2 ingresado por el usuario, obtenido del main.
 * @param pS Puntero a entero, para guardar el resultado de la suma, y poder llevarlo a un espacio de memoria en main.
 * @return Retorna 1, si la funcion fue valida. Retorna 0 si la funcion reconocio un error.
 */
int sumar(int a, int b,int* pS);


/**
 * @fn int resta(int, int, int*)
 * @brief La funcion sumar recibe 2 enteros y un puntero a entero. Luego, nos devuelve un entero.
 * La funcion toma los datos ingresados por el usuario en main, y luego los resta.
 *
 *
 * @param a Operando1 ingresado por el usuario, obtenido del main.
 * @param b Operando2 ingresado por el usuario, obtenido del main.
 * @param pR Puntero a entero, para guardar el resultado obtenido de la resta. Así poder guardarlo en un espacio de memoria en main.
 * @return Retorna 1, si la funcion fue valida. Retorna 0 si la funcion reconocio un error.
 */
int resta(int a, int b,int* pR);


/**
 * @fn int multiplicacion(int, int, int*)
 * @brief La funcion sumar recibe 2 enteros y un puntero a entero. Luego, nos devuelve un entero.
 * La funcion reconoce los datos ingreados por el usuario en main como parametros, y luego los multiplica.
 *
 * @param a Operando1 ingresado por el usuario, obtenido del main.
 * @param b Operando2 ingresado por el usuario, obtenido del main.
 * @param pM puntero a entero, para poder guardar el resultado de la multiplicacion, y así poder guardarlo en un espacio de memoria en main.
 * @return Retorna 1, si la funcion fue valida. Retorna 0 si la funcion reconocio un error.
 */
int multiplicacion(int a, int b,int *pM);


/**
 * @fn
 * @brief int division(int, int, float*) La funcion sumar recibe 2 enteros y un puntero a flotante. Luego, nos devuelve un entero.
 * La funcion toma los datos ingresados por el usuario en main, y luego los divide. El denominador no puede ser 0.
 *
 * @param a Operando1 ingresado por el usuario, obtenido del main.
 * @param b Operando2 ingresado por el usuario, obtenido del main.
 * @param pD puntero a flotante, que nos permite guardar el resultado obtenido de la division en un espacio de memoria en main.
 * @return Retorna 1, si la funcion fue valida. Retorna 0 si la funcion reconocio un error.
 */
int division(int a,int b,float* pD);


/**
 * @fn int factorial(int, int*)
 * @brief Funcion que recibe un entero, y puntero a entero. Luego nos retorna un entero.
 * Esta funcion toma el valor de operador1 registrado por el usuario y obtiene el factorial del mismo.
 *
 * @param a operador1 ingresado por el usuario.
 * @param pF puntero a flotante que nos permite guardar el resultado obtenido en un espacio de memoria en main.
 * @return Retorna 1, si la funcion fue valida. Retorna 0 si la funcion reconocio un error.
 */
int factorial(int a, int* pF);


/**
 * @fn int factorialB(int, int*)
 * @brief Funcion que recibe un entero, y puntero a entero. Luego nos retorna un entero.
 * Esta funcion toma el valor de operador2 registrado por el usuario y obtiene el factorial del mismo.
 *
 * @param b operador2 ingresado por el usuario.
 * @param pB puntero a flotante que nos permite guardar el resultado obtenido en un espacio de memoria en main.
 * @return Retorna 1, si la funcion fue valida. Retorna 0 si la funcion reconocio un error.
 */
int factorialB(int b,int* pB);


/**
 * @fn void valorFinal(int, int, int*)
 * @brief Esta funcion recibe como parametros 2 enteros y un puntero a entero. No retorna nada.
 * Esta funcion toma los valores de operador1 y operador2, ingresadas en main por el usuario. Y luego, realiza todas las
 * operaciones(suma,resta,division,multiplicacion,factorialA y factorialB).
 *
 * @param a operador1 ingresado por el usuario.
 * @param b operador2 ingresado por el usuario.
 * @param pV puntero a entero, que nos permite guardar los resultados obtenidos en un espacio de memoria en main.
 */
void valorFinal(int a,int b, int* pV);


/**
 * @fn int setFlag(int*, int)
 * @brief Esta funcion recibe un puntero a entero, y un entero. Luego, retorna un entero.
 * Esta funcion valida que la bandera no este igualada a NULL, y que su valor sea entre 0 y 1.
 * Ademas, esta funcion nos permite que el usuario deba respetar cierto orden establecido a la hora de ingresar los datos.
 * Por ende el usuario no podra, por ejemplo, ingresar el operando 2, sin haber ingreasdo el primero. Ingresar la suma de los valores
 * sin haber ingresado el operando 1 y 2. Y además tampoco lograra llamar a la opcion 4, sin antes llamar a las otras 3 opciones.
 *
 * @param bandera Espacio donde se guarda el valor 0 o 1, que valida las acciones del usuario.
 * @param valor Espacio donde ingreso el valor 0 o 1, que se guardará en la bandera.
 * @return Retorna 1, si la funcion fue valida. Retorna 0 si la funcion reconocio un error.
 */
int setFlag(int* bandera,int valor);

