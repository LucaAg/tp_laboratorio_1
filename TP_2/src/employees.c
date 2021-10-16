#include "employees.h"
#include "input.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAM_S 50

int subMenuInformar()
{
	int opcion;
	system("cls");
	printf("\n");
	printf("------------------------------------------------------\n");
	printf("*              *** MENU INFORMAR ***                 *\n");
	printf("------------------------------------------------------\n");
	printf("      1-Ordenar alfabeticamente por apellido y sector \n");
	printf("      2-Total y promedios salarios.\n"
				  "Empleados que superan el salario promedio\n");
	printf("      3-Salir\n");

	printf("Ingrese la opcion deseada: \n");
	scanf("%d",&opcion);

	return opcion;
}

int menu()
{
	int opcion;

	system("cls");
	printf("\n");
	printf("---------------------------------------------------------\n");
	printf("               *** ABM EMPLEADOS/AS ***                 \n");
	printf("----------------------------------------------------------\n");
	printf("     1-ALTA\n");
	printf("     2-MODIFICAR\n");
	printf("     3-BAJA\n");
	printf("     4-INFORMAR\n");
	printf("     5-Salir\n");

	printf("Ingrese opcion: \n");
	scanf("%d",&opcion);

	return opcion;
}

int menuModificar()
{
	int opcion;
	system("cls");
	printf("--------------------------------------------------------\n");
	printf("              *** MODIFICAR EMPLEADO/A ***                 \n");
	printf("---------------------------------------------------------\n");
	printf("1     -Modificar nombre\n");
	printf("2     -Modificar apellido\n");
	printf("3     -Modificar salario\n");
	printf("4     -Modificar sector\n");
	printf("5     -Salir\n");

	printf("Ingrese opcion: ");
	scanf("%d",&opcion);

	return opcion;
}

int initEmployees(eEmployee* list,int len)
{
	int todoOk=-1;
	if(list!=NULL && len>0)
	{
		for(int i=0; i<len;i++)
		{
			list[i].isEmpty=1;
		}
		todoOk=0;
	}
	return todoOk;
}

int buscarLibre(eEmployee list[],int len)
{
	int libre=-1;
	if(list!=NULL && len > 0)
	{
		for(int i=0;i<len;i++)
		{
			if(list[i].isEmpty==1)
			{
				libre=i;
				break;
			}
		}
	}
	return libre;
}

int addEmployees(eEmployee* list,int len, int id, char name[],char lastName[],float salary,int sector)
{
	int indice;
	int todoOk=-1;
	char aux[100];

	if(list!=NULL && len>0 && name!=NULL && lastName!=NULL)
	{
		indice=buscarLibre(list,len);

		if(indice>=0)
		{
			system("cls");
			printf("*---------------------------------------------------------------------------------------------------------*\n");
			printf("                                        *** ALTA EMPLEADO/A ***                                             \n");
			printf("*---------------------------------------------------------------------------------------------------------*\n");

			list[indice].id=id;
//NOMBRE
			printf("Ingrese el nombre del empleado/a: ");
			fflush(stdin);
			gets(aux);
			validarString(aux,TAM_S);
			strcpy(name,aux);
			strcpy(list[indice].name,name);


//APELLIDO
			 printf("Ingrese el apellido del empleado/a: ");
			 fflush(stdin);
			 gets(aux);
			 validarString(aux,TAM_S);
			 strcpy(lastName,aux);
			 strcpy(list[indice].lastName,lastName);

//SALARIO/
			 pedirFlotante(&salary,"Ingrese el salario del empleado/a(10000-1000000):", "Error al ingresar el salario. Ingrese el salario del empleado/a(10000-1000000):",10000,1000000);
			 list[indice].salary=salary;
//SECTOR
			 pedirEntero(&sector,"Ingrese el sector del empleado/a(1-10): ","Error al ingresar el sector. Ingrese el sector del empleado/a(1 a 10): ",1,10);
			 list[indice].sector=sector;

			list[indice].isEmpty=0;

			 printf("Alta exitosa!!\n");
		}
		else
		{
			printf("Hubo un error al iniciar el alta!\n");
		}
		todoOk=0;
	}
	return todoOk;
}

void mostrarEmpleado(eEmployee unaPersona)
{
	printf("    %4d   %20s   %20s             %15.2f            %7d   \n",
			unaPersona.id,
			unaPersona.name,
			unaPersona.lastName,
			unaPersona.salary,
			unaPersona.sector);
}


int printEmployees(eEmployee* list,int len)
{
	int todoOk=0;
	int flag=1;
	if(list!=NULL && len > 0)
	{
		system("cls");
		printf("       ID                 NOMBRE              APELLIDO                    Salario               Sector \n");
		printf("*----------------------------------------------------------------------------------------------------------*\n");
		for(int i=0;i<len;i++)
		{
			if(list[i].isEmpty==0)
			{
				mostrarEmpleado(list[i]);
				flag=0;
			}
		}
		if(flag==1)
		{
			printf("No hay personas para mostrar\n");
		}
		todoOk=1;
	}
	return todoOk;
}

int findEmployeeById(eEmployee list[],int iD,int len)
{
	int indice=-1;

	if(list!=NULL && len >0)
	{
		for(int i=0;i<len;i++)
		{
			if(list[i].isEmpty==0 && list[i].id==iD)
			{
				indice=i;
				break;
			}
		}
	}
	return indice;
}


int modifyEmployee(eEmployee list[],int len)
{
	int todoOk=0;
	int indice;
	int tomarId;
	char respuesta;
	eEmployee auxPersona;
	char aux[100];

	if(list!=NULL && len>0)
	{

		system("cls");
		printf("*---------------------------------------------------------------------------------------------------------*\n");
		printf("                                      ***  MODIFICAR EMPLEADOS/AS  ***                                      \n\n");
		printf("*---------------------------------------------------------------------------------------------------------*\n\n");

		printEmployees(list,len);
		printf("\nIngrese el ID de la persona que desea modificar: \n");
		scanf("%d",&tomarId);
		indice=findEmployeeById(list,tomarId,len);

		if(indice==-1)
		{
			printf("Error, la persona no se ha inicializado en la lista \n");
		}
		else
		{
			system("cls");
			printf("*---------------------------------------------------------------------------------------------------------*\n");
			printf("                                      ***  MODIFICAR EMPLEADOS/AS   ***                                        \n\n");
			printf("*---------------------------------------------------------------------------------------------------------*\n\n");
			printf("*---------------------------------------------------------------------------------------------------------*\n");
			printf("       ID                 NOMBRE               APELLIDO                     SALARIO               SECTOR  \n");
			printf("*----------------------------------------------------------------------------------------------------------*\n");
			mostrarEmpleado(list[indice]);

			printf("Seguro desea modificar los datos de esta persona?(s/n) \n");
			fflush(stdin);
			scanf("%c",&respuesta);
			while(respuesta!='s' && respuesta!='n')
			{
				printf("Error, debe ingresar s o n! \n"
						"Por favor, vuelva a ingresarlo: \n");
				fflush(stdin);
				scanf("%c",&respuesta);
			}

			if(respuesta=='s')
			{
				do
				{
					auxPersona=list[indice];
					switch(menuModificar())
					{
						case 1:
							printf("Ingrese el nuevo nombre: ");
							fflush(stdin);
							gets(aux);
							validarString(aux,TAM_S);
							strcpy(auxPersona.name,aux);
							list[indice]=auxPersona;
							printf("Modificacion exitosa!\n");
							break;

						case 2:
							printf("Ingrese el nuevo apellido: ");
							fflush(stdin);
							gets(aux);
							validarString(aux,TAM_S);
							strcpy(auxPersona.lastName,aux);
							list[indice]=auxPersona;
							printf("Modificacion exitosa!\n");
							break;

						case 3:
							pedirFlotante(&auxPersona.salary,"Ingrese el salario del empleado/a(10000-1000000):", "Error al ingresar el salario. Ingrese el salario del empleado/a(10000-1000000):",10000,1000000);
							list[indice]=auxPersona;
							printf("Modificacion exitosa!\n");
							break;

						case 4:
							pedirEntero(&auxPersona.sector,"Ingrese el sector del empleado/a(1-10): ","Error al ingresar el sector. Ingrese el sector del empleado/a(1 a 10): ",1,10);
							list[indice]=auxPersona;
							printf("Modificacion exitosa!\n");
							break;

						case 5:
							printf("Desea continuar?(Presione 's' si desea seguir)\n");
							fflush(stdin);
							scanf("%c",&respuesta);
							break;

						default:
							printf("Opción incorrecta, seleccione una opción valida.\n Gracias!\n");
							break;
					}

				}while(respuesta=='s');

			}
			else
			{
				printf("Se ha cancelado la modoficación\n");
			}
		}


		todoOk=1;
	}
	return todoOk;
}

int removeEmployee(eEmployee list[],int len, int id)
{
	int todoOk=-1;
	int indice;
	char respuesta;

	if(list!=NULL && len>0)
	{

		system("cls");
		printf("\n");
		printf("*---------------------------------------------------------------------------------------------------------*\n");
		printf("                                       ***  REMOVER EMPLEADO/A   ***                                      \n\n");
		printf("*---------------------------------------------------------------------------------------------------------*\n");
		printEmployees(list,len);
		printf("\nIngrese el ID de la persona a dar de baja: \n");
		scanf("%d",&id);
		indice=findEmployeeById(list,id,len);

		if(indice==-1)
		{
			printf("Error, la persona no se ha inicializado en la list \n");
		}
		else
		{
			system("cls");
			printf("\n");
			printf("*---------------------------------------------------------------------------------------------------------*\n");
			printf("                                       *** LISTADO DE PERSONAS ***                                       \n");
			printf("       ID                 NOMBRE               APELLIDO                     SALARIO               SECTOR  \n");
			printf("*----------------------------------------------------------------------------------------------------------*\n");
			mostrarEmpleado(list[indice]);

			printf("Seguro desea eliminar los datos de esta persona?(s/n) \n");
			fflush(stdin);
			scanf("%c",&respuesta);
			while(respuesta!='s' && respuesta!='n')
			{
				printf("Error, debe ingresar s/n. Por favor vuelva a ingresarlo: \n");
				fflush(stdin);
				scanf("%c",&respuesta);
			}

			if(respuesta=='s')
			{
				list[indice].isEmpty=1;
				printf("Se ha removido al/la empleado/a correctamente!\n"
							"Gracias por usar nuestro sistema!\n");
			}
			else
			{
				printf("No se ha removido al/la empleado/a.\n"
						"Gracias por usar nuestro sistema!\n");
			}
		  }
		todoOk=0;

	}
	return todoOk;
}

int sortEmployees(eEmployee* list, int len, int order)
{
	eEmployee auxEmpleado;
	int todoOk=-1;
	if(list!=NULL && len>0 && order>=0 && order<=1)
	{
		for(int i=0;i<len-1;i++)
		{
			for(int j=i+1;j<len;j++)
			{
				if(( (strcmp(list[i].lastName,list[j].lastName)<0) ||
				(strcmp(list[i].lastName,list[j].lastName)==0  &&  list[i].sector>list[j].sector)  )&& order==0)
				{

					auxEmpleado=list[i];
					list[i]=list[j];
					list[j]=auxEmpleado;

				}else if(( (strcmp(list[i].lastName,list[j].lastName)>0)
					|| (strcmp(list[i].lastName,list[j].lastName)==0 && list[i].sector<list[j].sector)  )&& order==1)
				{
					auxEmpleado=list[i];
					list[i]=list[j];
					list[j]=auxEmpleado;
				}
			}

		}
		if(order==1)
		{
			printf("*---------------------------------------------------------------------------------------------------------*\n");
			printf("                                  ***  EMPLEADOS/AS ORDENADOS/AS ASCENDENTE   ***                        \n\n");
			printf("*---------------------------------------------------------------------------------------------------------*\n");
		}
		else if(order==0)
		{
			printf("*---------------------------------------------------------------------------------------------------------*\n");
			printf("                                   ***  EMPLEADOS/AS ORDENADOS/AS DESCENDENTE  ***                        \n\n");
			printf("*---------------------------------------------------------------------------------------------------------*\n");

		}
		printEmployees(list,len);
		printf("Ordenamiento exitoso!\n");

		todoOk=0;
	}
	return todoOk;
}

int promedioSalariosTotal(eEmployee list[],int len)
{
	int todoOk=0;
	float acumuladorSalarios=0;
	float promedioSalario=0;
	int contadorEmpleados=0;
	int contadorSuperaProm=0;
	if(list!=NULL && len>0)
	{
		system("cls");
printf("\n------------------------------------------------------------\n");
		printf("-***     INFORME PROMEDIO/TOTAL SALARIOS      ***-\n\n");
printf("--------------------------------------------------------------\n");
		for(int i=0; i<len; i++)
		{
			if(list[i].isEmpty==0)
			{
				acumuladorSalarios+=list[i].salary;
				contadorEmpleados++;
			}
		}
		if(contadorEmpleados!=0)
		{
			promedioSalario=acumuladorSalarios/contadorEmpleados;
			printf("El promedio de salarios es de: %.2f \n\n",promedioSalario);
		}
		else
		{
			printf("Error al calcular el promedio, debe haber empleados/as ingresados/as para poder calcularlo\n");
		}

		printf("El total de salarios es de: %.2f \n",acumuladorSalarios);

		for(int j=0;j<len;j++)
		{
			if(promedioSalario<list[j].salary && list[j].isEmpty==0)
			{
				contadorSuperaProm++;
			}
		}
		printf("\nLa cantidad de empleados/as que supera el salario promedio es de: %d\n\n",contadorSuperaProm);
		printf("*---------------------------------------------------------------------------------------------------------*\n");
		printf("                                 *** EMPLEADOS/AS SUPERAN PROMEDIO ***                                      \n");
		printf("*---------------------------------------------------------------------------------------------------------*\n");
		printf("       ID                 NOMBRE               APELLIDO                     SALARIO               SECTOR \n");
		printf("*----------------------------------------------------------------------------------------------------------*\n");
		for(int j=0;j<len;j++)
		{
			if(promedioSalario<list[j].salary && list[j].isEmpty==0)
			{
				mostrarEmpleado(list[j]);
			}
		}

		todoOk=1;
	}
	return todoOk;
}


int permitirIngreso(eEmployee lista[], int len,int* flag)
{
	int todoOk;

	if(lista!=NULL && len>0)
	{
		for(int i=0;i<len;i++)
		{
			if(lista[i].isEmpty==0)
			{
				*flag=0;
				break;
			}
			else
			{
				*flag=1;
			}
		}
		todoOk=1;
	}
	return todoOk;
}


