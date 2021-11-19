#include "../inc/input.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../inc/Employees.h"

int employee_MostrarEmpleado(Employee* unEmpleado)
{
	int todoOk=0;
	int idEmp;
	char nombreEmp[128];
	int horasTrabajadas;
	int sueldoEmpleado;
	if(unEmpleado !=NULL)
	{
		employee_getId(unEmpleado, &idEmp);
		employee_getNombre(unEmpleado, nombreEmp);
		employee_getHorasTrabajadas(unEmpleado, &horasTrabajadas);
		employee_getSueldo(unEmpleado, &sueldoEmpleado);
		printf("%-6d%-31s%-7d%-8d\n",idEmp,nombreEmp,horasTrabajadas,sueldoEmpleado);
		todoOk=1;
	}
	return todoOk;
}



Employee* employee_new()
{
	Employee* nuevoEmpleado;

	nuevoEmpleado = (Employee*) malloc(sizeof(Employee));
	if(nuevoEmpleado != NULL)
	{
		nuevoEmpleado->id= 0;
		strcpy(nuevoEmpleado->nombre,"--");
		nuevoEmpleado->horasTrabajadas=0;
		nuevoEmpleado->sueldo=0;
	}

	return nuevoEmpleado;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char *sueldoStr)
{
	Employee* nuevoEmpleado;

	nuevoEmpleado = employee_new();
	if(nuevoEmpleado != NULL)
	{
		if(!(employee_setId(nuevoEmpleado,atoi(idStr))
				&& employee_setNombre(nuevoEmpleado,nombreStr)
				&& employee_setHorasTrabajadas(nuevoEmpleado,atoi(horasTrabajadasStr))
				&& employee_setSueldo(nuevoEmpleado,atoi(sueldoStr)) ) )
		{
			free(nuevoEmpleado);
			nuevoEmpleado=NULL;
		}
	}
	return nuevoEmpleado;
}


void employee_delete(Employee* unEmpleado)
{
	if(unEmpleado!=NULL)
	{
		free(unEmpleado);
	}
}

int employee_setId(Employee* unEmpleado,int id)
{
	int todoOk=0;
	if(unEmpleado!=NULL && id>=0)
	{
		unEmpleado->id=id;
		todoOk=1;
	}
	else
	{
		printf("Error al cargar el id del empleado/a.\n");
	}
	return todoOk;
}

int employee_getId(Employee* unEmpleado,int* pId)
{
	int todoOk=0;
	if(unEmpleado!=NULL && pId!=NULL)
	{
		*pId=unEmpleado->id;
		todoOk=1;
	}
	return todoOk;
}

int employee_setNombre(Employee* unEmpleado,char* pNombre)
{
	int todoOk=0;
	if(unEmpleado!=NULL && pNombre!=NULL)
	{
		if(strlen(pNombre) < 128 && strlen(pNombre)>1)
		{
			strcpy(unEmpleado->nombre,pNombre);
			todoOk=1;
		}
		else
		{
			printf("Error al cargar el nombre del empleado/a.\n");
		}
	}
	return todoOk;
}

int employee_getNombre(Employee* unEmpleado,char* pNombre)
{
	int todoOk=0;
	if(unEmpleado!=NULL && pNombre!=NULL)
	{
		strcpy(pNombre,unEmpleado->nombre);
		todoOk=1;
	}
	return todoOk;
}

int employee_setHorasTrabajadas(Employee* unEmpleado,int horasTrabajadas)
{
	int todoOk=0;
	if(unEmpleado!=NULL && horasTrabajadas>=0 && horasTrabajadas<=350)
	{
		unEmpleado->horasTrabajadas=horasTrabajadas;
		todoOk=1;
	}
	else
	{
		printf("Error al cargar las horas trabajadas del empleado/a.\n");
	}
	return todoOk;
}

int employee_getHorasTrabajadas(Employee* unEmpleado,int* pHorasTrabajadas)
{
	int todoOk=0;
	if(unEmpleado!=NULL && pHorasTrabajadas!=NULL)
	{
		*pHorasTrabajadas=unEmpleado->horasTrabajadas;
		todoOk=1;
	}
	return todoOk;
}

int employee_setSueldo(Employee* unEmpleado,int sueldo)
{
	int todoOk=0;
	if(unEmpleado!=NULL && sueldo>=10000 && sueldo<=50000)
	{
		unEmpleado->sueldo=sueldo;
		todoOk=1;
	}
	return todoOk;
}


int employee_getSueldo(Employee* unEmpleado,int* pSueldo)
{
	int todoOk=0;
	if(unEmpleado!=NULL && pSueldo!=NULL)
	{
		*pSueldo=unEmpleado->sueldo;
		todoOk=1;
	}
	return todoOk;
}

int employee_compararId(void* empleado1, void* empleado2)
{
	int todoOk=0;
	int id;
	int id2;
	Employee* auxEmpleado1;
	Employee* auxEmpleado2;

	auxEmpleado1= (Employee*) empleado1;
	auxEmpleado2= (Employee*) empleado2;
	if(empleado1!=NULL && empleado2!=NULL)
	{
		employee_getId(auxEmpleado1, &id);
		employee_getId(auxEmpleado2, &id2);
		if(id > id2)
		{
			todoOk=1;
		}
		else
		{
			if(id < id2)
			{
				todoOk=-1;
			}
		}
	}
	return todoOk;
}


int employee_compararNombre(void* empleado1, void* empleado2)
{
	int todoOk=0;
	char nombreUno[128];
	char nombreDos[128];
	Employee* auxEmpleado1;
	Employee* auxEmpleado2;

	auxEmpleado1= (Employee*) empleado1;
	auxEmpleado2= (Employee*)empleado2;
	if(auxEmpleado1!=NULL && auxEmpleado2!=NULL)
	{
		employee_getNombre(auxEmpleado1, nombreUno);
		employee_getNombre(auxEmpleado2, nombreDos);
		if(strcmp(nombreUno, nombreDos)>0)
		{
			todoOk=1;
		}
		else
		{
			if(strcmp(nombreUno,nombreDos)<0)
			{
				todoOk=-1;
			}
		}
	}
	return todoOk;
}

int employee_compararSueldo(void* empleado1, void* empleado2)
{
	int todoOk=0;
	int sueldoUno;
	int sueldoDos;
	Employee* auxEmpleado1;
	Employee* auxEmpleado2;

	auxEmpleado1= (Employee*)empleado1;
	auxEmpleado2= (Employee*)empleado2;
	if(auxEmpleado1!=NULL && auxEmpleado2!=NULL)
	{
		employee_getSueldo(auxEmpleado1, &sueldoUno);
		employee_getSueldo(auxEmpleado2, &sueldoDos);

		if(sueldoUno > sueldoDos)
		{
			todoOk=1;
		}
		else
		{
			if(sueldoUno < sueldoDos)
			{
				todoOk=-1;
			}
		}
	}
	return todoOk;
}

int employee_compararHoras(void* empleado1, void* empleado2)
{
	int todoOk=0;
	int horasUno;
	int horasDos;
	Employee* auxEmpleado1;
	Employee* auxEmpleado2;

	auxEmpleado1= (Employee*)empleado1;
	auxEmpleado2= (Employee*)empleado2;
	if(auxEmpleado1!=NULL && auxEmpleado2!=NULL)
	{
		employee_getHorasTrabajadas(auxEmpleado1, &horasUno);
		employee_getHorasTrabajadas(auxEmpleado2, &horasDos);

		if(horasUno > horasDos)
		{
			todoOk=1;
		}
		else
		{
			if((horasUno < horasDos))
			{
				todoOk=-1;
			}
		}
	}
	return todoOk;
}

int employee_getUltimoId(void)
{
	int idFinal = -1;
	char idFinalStr[128];

	FILE* f = fopen("guardarId.txt", "r");

	if(f != NULL)
	{
		fscanf(f, "%[^\n]", idFinalStr);
		idFinal = atoi(idFinalStr);
	}
	fclose(f);

	return idFinal;
}
