#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "Controller.h"

int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int todoOk=0;
	Employee* auxEmpleado;
	char buffer[3][5];
	char auxNombre[128];
	char* id;
	if(pFile!=NULL && pArrayListEmployee!=NULL)
	{
		id="1";
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],auxNombre,buffer[1],buffer[2]);
		do
		{
			if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],auxNombre,buffer[1],buffer[2])==4)
			{
				id=buffer[0];
				auxEmpleado= employee_newParametros(buffer[0], auxNombre, buffer[1], buffer[2]);

				if(auxEmpleado!=NULL)
				{
					if(ll_add(pArrayListEmployee, auxEmpleado)==-1)
					{
						employee_delete(auxEmpleado);
						todoOk=0;
					}
					else
					{
						todoOk=1;
					}
				}
			}
			else
			{
				break;
			}

		}while(!feof(pFile));

		controller_guardarId(atoi(id));

	}
    return todoOk;
}


int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	Employee* auxEmpleado;
	int todoOk=0;
	int id;
	if(pFile!=NULL && pArrayListEmployee!=NULL)
	{
		do
		{
			auxEmpleado=employee_new();
			fread(auxEmpleado,sizeof(Employee),1,pFile);

			if(!feof(pFile))
			{
				if(ll_add(pArrayListEmployee, auxEmpleado)!=0)
				{
					employee_delete(auxEmpleado);
					todoOk=0;
					break;
				}
				else
				{
					id=auxEmpleado->id;
					todoOk=1;
				}
			}
			else
			{
				break;
			}
		}while(!feof(pFile));
		controller_guardarId(id);
	}
	printf("\n\n");
    return todoOk;
}
