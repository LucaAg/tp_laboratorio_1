/*
 * bibliotecaCalcu.c
 *
 *  Created on: 14 sep. 2021
 *      Author: Nahue
 */
#include <stdio.h>
#include <stdlib.h>
#include "bibliotecaCalcu.h"

int menu(int a,int b)
{
	int opcion;


	system("cls");
	printf("Seleccione la acción que desea realizar, según el numero correspondiente.\n\n");
	printf("1- Ingresar el primer operando(A=%d): \n",a);
	printf("2- Ingresar el segundo operando(B=%d): \n",b);
	printf("3- Realizar todas las operaciones (Suma, resta, division, multiplicacion y factorial(0-12)). \n");
	printf("4- Informar resultados: \n");
	printf("5- Salir\n\n");

	printf("Ingrese una opción: \n");
	scanf("%d",&opcion);

	return opcion;
}

int sumar(int a, int b, int* pS)
{
	int sumar;
	int todoOk=0;

	if(pS!=NULL)
	{
		sumar=a+b;

		*pS=sumar;

		todoOk=1;
	}

	return todoOk;
}

int resta(int a, int b,int* pR)
{
	int restar;
	int todoOk=0;

	if(pR!=NULL)
	{
		restar=a-b;

		*pR=restar;

		todoOk=1;
	}

	return todoOk;
}

int division(int a,int b,float* pD)
{
	int todoOk=0;
	float dividir;
	if(b!=0 && pD!=NULL)
	{
		dividir=(float)a/b;

		*pD=dividir;

		todoOk=1;
	}

	return todoOk;
}


int multiplicacion(int a, int b,int *pM)
{
	int multiplicar;
	int todoOk=0;

	if(pM!=NULL)
	{
		multiplicar=a*b;
		*pM=multiplicar;
		todoOk=1;
	}


	return todoOk;
}

int factorial(int a,int* pF)
{
	int todoOk=0;
	int fact=1;
	int i;

	if(a>=0 && pF!=NULL)
	{
		for(i=1; i<=a; i++)
		{
				fact*=i;
		}

		*pF=fact;
		todoOk=1;
	}
	return todoOk;
}

int factorialB(int b,int* pB)
{
	int fact=1;
	int todoOk=0;

		if(b>=0 && pB!=NULL)
		{
			for(int i=1; i<=b; i++)
			{
				fact*=i;
			}
			*pB=fact;
			todoOk=1;
		}
		return todoOk;
}

void valorFinal(int a,int b, int* pV)
{
	int resultadoSuma;
	int resultadoResta;
	float resultadoDividir;
	int resultadoMulti;
	int resultadoFacto;
	int resultadoFactoB;

	if(sumar(a,b,&resultadoSuma) && pV!=NULL)
	{
		printf(" El resultado de (%d+%d) es: %d \n",a,b,resultadoSuma);
	}


	if(resta(a,b,&resultadoResta) && pV!=NULL)
	{
		printf("El resultado de (%d-%d) es: %d \n",a,b,resultadoResta);
	}


	if(division(a,b,&resultadoDividir) && pV!=NULL)
	{
		printf("El resultado de (%d/%d) es: %.2f \n",a,b,resultadoDividir);
	}
	else
	{
		printf("No se pudo realizar la division \n");
	}


	if(multiplicacion(a,b,&resultadoMulti) && pV!=NULL)
	{
		printf("El resultado de (%d*%d) es: %d \n",a,b,resultadoMulti);
	}


	if(factorial(a,&resultadoFacto) && pV!=NULL)
	{
		printf("El factorial de %d! = %d\n",a,resultadoFacto);
	}
	else
	{
		printf("Error al calcular factorial 1\n");
	}


	if(factorialB(b,&resultadoFactoB) && pV!=NULL)
	{
		printf("El factorial de %d! = %d\n",b,resultadoFactoB);
	}
	else
	{
		printf("Error al calcular factorial 2\n");
	}


}

int setFlag(int* bandera,int valor)
	{
		int todoOk=0;

		if(bandera!=NULL && valor>=0 && valor<=1)
		{
			*bandera=valor;
			todoOk=1;
		}
		return todoOk;
	}
