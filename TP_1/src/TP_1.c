/*
 ============================================================================
 Name        : TP_1.c
 Author      : nahue
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "bibliotecaCalcu.h"



int main(void)
{
	setbuf(stdout,NULL);
	char seguir='s';
	int operando1=0;
	int operando2=0;
	int sumaPrueba;
	int restaPrueba;
	float dividirPrueba;
	int multiplicarPrueba;
	int factoPrueba;
	int factoPruebaB;
	int resultadosPrueba;
	int flagOperando1=0;
	int flagOperando2=0;
	int flagOperaciones=0;

	do
	{
		switch(menu(operando1,operando2))
		{
			case 1:
				printf("Ingrese el primer operando: \n");
				scanf("%d",&operando1);
				if(!setFlag(&flagOperando1,1))
				{
					printf("Error al ingresar el primer operando\n");
				}

				break;

			case 2:
				if(flagOperando1)
				{
					if(flagOperando2)
					{
						printf("Ya se ingreso el operando 2!\n\n");
					}
					else
					{
						printf("Ingrese el segundo operando: \n");
						scanf("%d",&operando2);
						if(!setFlag(&flagOperando2,1))
						{
							printf("Error al ingresar el segundo operando\n");
						}
					}
				}
				else
				{
					printf("Antes de ingresar el segundo operando, debe ingresar el primero\n\n");
				}
				break;

			case 3:
				if(flagOperando2)
				{
					sumar(operando1,operando2,&sumaPrueba);
					resta(operando1,operando2,&restaPrueba);
					multiplicacion(operando1,operando2,&multiplicarPrueba);
					division(operando1,operando2,&dividirPrueba);
					factorial(operando1,&factoPrueba);
					factorialB(operando2,&factoPruebaB);
					if(!setFlag(&flagOperaciones,1))
					{
						printf("Error al realizar las operaciones\n");
					}
				}
				else if(flagOperando1)
				{
					printf("No se puede realizar las operaciones sin el operador 2\n");
				}
				else
				{
					printf("No podemos realizar las operaciones sin el operador 1\n");
				}
				break;

			case 4:
				if(flagOperaciones)
				{
					valorFinal(operando1,operando2,&resultadosPrueba);
					if(!setFlag(&flagOperando1,0))
					{
						printf("Error en operando 1\n");
					}
					if(!setFlag(&flagOperando2,0))
					{
						printf("Error en operando 2\n");
					}
				}
				else if(flagOperando2)
				{
					printf("Antes de obtener los resultados, debemos hacer las cuentas\n");
				}
				else if(flagOperando1)
				{
					printf("No se puede realizar las operaciones sin el operador 2\n");
				}
				else
				{
					printf("No se puede calcular, sin antes indicar el operador 1\n");
				}
				break;



			case 5:
				printf("Esta seguro que desea salir?(Presione 's' en caso de querer seguir)");
				fflush(stdin);
				scanf("%c",&seguir);
				break;

			default:
				printf("Opción invalida!\n\n");
				break;
		}

	}while(seguir=='s');



	return EXIT_SUCCESS;
}


