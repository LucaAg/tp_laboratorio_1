#include "input.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int validarString(char frase[],int tam)
{
	int flag;
	int esString;
	int i=0;
	if(frase!=NULL)
	{
		flag=0;

		while(i<strlen(frase))
		{
			esString=isalpha(frase[i]);
			if(esString!=0 || frase[i]==' ')
			{
				i++;
			}
			else
			{
				flag=1;
				printf("Error, no puede ingresar numeros, ni simbolos. \nPor favor vuelva a ingresarlo: \n");
				fflush(stdin);
				gets(frase);
				i=0;
			}
			rangoString(frase,tam);
		}
		if(!validarStringOrdenado(frase))
		{
			flag=1;
		}
	}
	return flag;
}

int rangoString(char frase[],int tam)
{
	int todoOk=0;
	if(frase!= NULL && tam>0)
	{
		while(strlen(frase) > tam)
		{
			printf("Error, lo que usted ingreso supera el maximo de caracteres (%d)."
					"\nPor favor, reingreselo: \n",tam);
			fflush(stdin);
			gets(frase);
		}
		todoOk=1;
	}
	return todoOk;
}

int validarStringOrdenado(char frase[])
{
	int todoOk=0;
	int i=0;
	if(frase!=NULL)
	{
		strlwr(frase);
		frase[0]=toupper(frase[0]);
		while(frase[i]!='\0')
		{
			if(frase[i]==' ')
			{
				frase[i+1]=toupper(frase[i+1]);
			}
			i++;
		}

		todoOk=1;
	}
	return todoOk;
}


int validarNumeros(char numeroIngresado[])
{
	int i=0;
	int flagValidar;
	if(numeroIngresado!=NULL)
	{
		flagValidar=1;
		while(numeroIngresado[i]!='\0')
		{
			if(numeroIngresado[i]<'0' || numeroIngresado[i]>'9')
			{
				flagValidar=0;
			}
			i++;
		}
	}
	return flagValidar;
}

int pedirEntero(int* entero, char* mensaje, char* mensajeError, int min, int max)
{
	int todoOk = -1;
	int numeroIngresado;

	if(entero != NULL && mensaje != NULL && mensajeError != NULL && min < max)
	{
		printf("%s", mensaje);
		fflush(stdin);
		scanf("%d", &numeroIngresado);

		while(numeroIngresado < min || numeroIngresado > max)
		{
			printf("%s", mensajeError);
			fflush(stdin);
			scanf("%d", &numeroIngresado);
		}

		*entero = numeroIngresado;
		todoOk = 0;
	}

	return todoOk;
}

int pedirFlotante(float* flotante, char* mensaje, char* mensajeError, float min, float max)
{
	int todoOk = -1;
	float numeroIngresado;

	if(flotante != NULL && mensaje != NULL && mensajeError != NULL && min < max)
	{
		printf("%s", mensaje);
		fflush(stdin);
		scanf("%f", &numeroIngresado);

		while(numeroIngresado < min || numeroIngresado > max)
		{
			printf("%s", mensajeError);
			fflush(stdin);
			scanf("%f", &numeroIngresado);
		}

		*flotante = numeroIngresado;
		todoOk = 0;
	}

	return todoOk;
}
