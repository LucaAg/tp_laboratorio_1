#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../inc/LinkedList.h"
#include "../inc/Controller.h"
#include "../inc/parser.h"

#include "../inc/Employees.h"

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


