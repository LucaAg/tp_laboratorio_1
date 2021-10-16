#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "employees.h"
#include "input.h"

#define LEN 1000


int main(void)
{
	setbuf(stdout,NULL);
	char seguir='s';
	char salir='s';
	int nextId=1;
	int order;
	int flagEntro=1;
	eEmployee list[LEN];
	eEmployee unEmployee;

	if( initEmployees(list, LEN)==-1)
	{
		printf("Error, no hay empleados inicializados\n");
	}

	do
	{
		system("cls");
		switch(menu())
		{
			case 1:
				if(addEmployees(list,LEN,nextId,unEmployee.name,unEmployee.lastName,unEmployee.salary,unEmployee.sector)==0)
				{
					nextId++;
					flagEntro=0;
				}
				break;
			case 2:
				if(flagEntro==0){
					modifyEmployee(list,LEN);
				}
				else
				{
					printf("No se puede modificar empleados/as, sin antes ingresar un empleado. Por favor ingrese la opción 1."
							"\nGracias por usar nuestro sistema!\n");
				}

				break;
			case 3:
				if(flagEntro==0)
				{
					removeEmployee(list,LEN,unEmployee.id);
				}
				else
				{
					printf("No se puede remover empleados/as, sin antes ingresar un empleado. Por favor ingrese la opción 1. "
							"Vuelva a intentarlo. \nGracias por usar nuestro sistema!\n");
				}
				permitirIngreso(list,LEN,&flagEntro);

				break;
			case 4:
				if(flagEntro==0)
				{
					do
					{
						switch(subMenuInformar())
						{
							case 1:
								printf("Ingrese la forma en la que desea ordenar a los/las empleados/as"
										" | ** 1(ASCENDENTE [A-Z])** |   | ** 0(DESCENDENTE[Z-A])** | \n");
								scanf("%d",&order);
								while(order!=1 && order!=0)
								{
									printf("Ingrese un orden valido(0 o 1):");
									scanf("%d",&order);
								}
								sortEmployees(list,LEN,order);
								break;

							case 2:
								promedioSalariosTotal(list,LEN);
								break;

							case 3:
								printf("Seguro desea salir?(Presione 's' si desea seguir)\n");
								fflush(stdin);
								scanf("%c",&salir);
								break;
						}
					}while(salir=='s');
				}else
				{
					printf("No se puede entrar al menu informar, sin antes haber ingresado un empleado.\n");
					printf("Por favor ingrese un empleado.\n"
							" Gracias por usar nuestro sistema!\n");
				}
				break;
			case 5:
				printf("Seguro desea salir?(Presione 's' si desea seguir)\n");
				fflush(stdin);
				scanf("%c",&seguir);
				break;
			default:
				printf("Error, opcion no valida!\n");
				break;
		}
		system("pause");
	}while(seguir=='s');


	return EXIT_SUCCESS;
}


