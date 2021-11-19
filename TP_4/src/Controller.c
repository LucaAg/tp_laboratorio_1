#include <stdio.h>
#include <stdlib.h>
#include "../inc/LinkedList.h"
#include "../inc/Controller.h"

#include "../inc/Employees.h"
#include "../inc/parser.h"
#include "../inc/input.h"


int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int todoOk=0;
	FILE* f;

	if(path!=NULL && pArrayListEmployee!=NULL)
	{
		f= fopen(path,"r");
		if(f==NULL)
		{
			printf("Error al cargar el archivo en modo texto!\nGracias por usar nuestro sistema.");
		}
		else
		{
			parser_EmployeeFromText(f,pArrayListEmployee);
			printf("El archivo en modo texto se ha cargado exitosamente!\n Gracias por usar nuestro sistema.\n");
			todoOk=1;
		}
		fclose(f);
	}
    return todoOk;
}



int controller_encontrarId(LinkedList* pArrayListEmployee, int id)
{
	int indice=-1;
	Employee* auxEmpId;
	int tam;
	if(pArrayListEmployee!=NULL && id >0)
	{
		tam = ll_len (pArrayListEmployee);

		for(int i=0; i<tam;i++)
		{
			auxEmpId= ll_get(pArrayListEmployee, i);

			if(auxEmpId!=NULL)
			{
				employee_getId(auxEmpId, &indice);

				if(id==indice)
				{
					indice= i;
					break;
				}
			}
		}
	}
	return indice;
}


int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int todoOk=0;
	int cant;
	char nombreEmp[128];
	int sueldoEmpleado;
	int horasTrabajadas;
	char opcion;
	int id;
	Employee* auxEmployee;
	if(pArrayListEmployee!=NULL)
	{
		auxEmployee= employee_new();
		if(auxEmployee!=NULL)
		{
			printf("------------------------------------------------\n");
			printf("                ALTA EMPLEADO                   \n");
			printf("------------------------------------------------\n");
			id=controller_siguienteId();
			employee_setId(auxEmployee,id);

			printf("Ingrese el nombre del empleado/a: \n");
			fflush(stdin);
			gets(nombreEmp);
			validarString(nombreEmp,128);
			employee_setNombre(auxEmployee,nombreEmp);

			pedirEntero(&horasTrabajadas, "Ingrese la cantidad de horas trabajadas(0hs-350hs): "
					,"Error, cantidad no valida. Vuelva a ingresarlo(0hs-350hs): ", 0, 350);
			employee_setHorasTrabajadas(auxEmployee, horasTrabajadas);

			pedirEntero(&sueldoEmpleado, "Ingrese el sueldo del empleado/a(10000-50000): "
					, "Error, sueldo invalido. Vuelva a ingresarlo(10000-50000): ", 10000, 50000);
			employee_setSueldo(auxEmployee, sueldoEmpleado);

			pedirCaracter(&opcion, "Desea cargar los datos del nuevo empleado(s/n): \n",
					"Error, opcion invalida. Vuelva a intentarlo(s/n): \n" , 's', 'n');

			if(opcion=='s')
			{
				cant = ll_add(pArrayListEmployee, auxEmployee);
				if(cant==0)
				{
					printf("Se ha cargado exitosamente al empleado/a!\nGracias por usar nuestro sistema!\n");
					controller_guardarId(id);

					todoOk=1;
				}
				else
				{
					printf("Se ha encontrado un error al intentar cargar al empleado/a!\nGracias por usar nuestro sistema\n");
					employee_delete(auxEmployee);
				}
			}
			else
			{
				printf("Se ha cancelado la carga de datos del empleado/a!\n");
				employee_delete(auxEmployee);
			}
		}
	}
    return todoOk;
}

int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int todoOk=0;
	char nuevoNombre[128];
	int nuevoSueldoEmpleado;
	int nuevasHorasEmp;
	int idEmpleado;
	int indiceEmpModificar;
	char opcion='s';
	char confirmarModificacion;
	char opcion2;
	Employee* auxEmpleado;
	if(pArrayListEmployee!=NULL)
	{
		printf("------------------------------------------------\n");
		printf("              MODIFICAR EMPLEADO                \n");
		printf("------------------------------------------------\n");
		controller_ListEmployee(pArrayListEmployee);
		printf("\n");

		printf("Ingrese el id de la persona que desea remover:\n");
		scanf("%d",&idEmpleado);

		indiceEmpModificar=controller_encontrarId(pArrayListEmployee, idEmpleado);

		auxEmpleado= ll_get(pArrayListEmployee, indiceEmpModificar);

		if(auxEmpleado!=NULL)
		{
			todoOk=1;
			printf("----------------------------------------------------\n");
			printf(" ID  |             NOMBRE          |HORAS |SUELDO |\n");
			printf("----------------------------------------------------\n");
			employee_MostrarEmpleado(auxEmpleado);
			pedirCaracter(&opcion2, "Desea modificar los datos de este empleado?(s/n): \n",
					"Error, opcion invalida. Vuelva a intentarlo(s/n): \n", 's', 'n');
			if(opcion2=='s')
			{
				do
				{
					switch(menuModificar())
					{
					case 1:
						printf("Ingrese el nuevo nombre para el/la empleado/a: \n");
						fflush(stdin);
						scanf("%s",nuevoNombre);
						validarString(nuevoNombre, 128);
						pedirCaracter(&confirmarModificacion, "Confirma modificacion?(s/n) \n",
								"Error, opcion invalida. Vuelva a intentarlo(s/n): \n", 's', 'n');
						if(confirmarModificacion=='s')
						{
							employee_setNombre(auxEmpleado, nuevoNombre);
							printf("Modificacion exitosa!\nGracias por usar nuestro sistema. \n");
						}
						else
						{
							printf("Se ha cancelado la modificacion!\nGracias por usar nuestro sistema\n");
						}
						break;
					case 2:
						pedirEntero(&nuevasHorasEmp, "Ingrese las nuevas horas del empleado/a(0-350): \n",
								"Error opcion invalida. Vuelva a intentarlo(0-350): \n", 0, 350);
						pedirCaracter(&confirmarModificacion, "Confirma modificacion?(s/n) \n",
								"Error, opcion invalida. Vuelva a intentarlo(s/n): \n", 's', 'n');
						if(confirmarModificacion=='s')
						{
							employee_setHorasTrabajadas(auxEmpleado, nuevasHorasEmp);
							printf("Modificacion exitosa!\nGracias por usar nuestro sistema. \n");
						}
						else
						{
							printf("Se ha cancelado la modificacion!\nGracias por usar nuestro sistema\n");
						}
						break;
					case 3:
						pedirEntero(&nuevoSueldoEmpleado, "Ingrese el nuevo sueldo del empleado/a(10000-50000):\n",
								"Error, opcion invalida. Vuelva a intentarlo(10000-50000): \n", 10000, 50000);
						pedirCaracter(&confirmarModificacion, "Confirma modificacion?(s/n) \n",
								"Error, opcion invalida. Vuelva a intentarlo(s/n): \n", 's', 'n');
						if(confirmarModificacion=='s')
						{
							employee_setSueldo(auxEmpleado, nuevoSueldoEmpleado);
							printf("Modificacion exitosa!\nGracias por usar nuestro sistema. \n");
						}
						else
						{
							printf("Se ha cancelado la modificacion!\nGracias por usar nuestro sistema\n");
						}
						break;
					case 4:
						pedirCaracter(&opcion, "Desea continuar?(s/n): \n", "Error, opcion invalida. Vuelva a ingresarla(s/n): \n", 's', 'n');
						break;
					}
				}while(opcion=='s');
				printf("Nuevos datos del empleado/a: \n");
				printf("----------------------------------------------------\n");
				printf(" ID  |             NOMBRE          |HORAS |SUELDO |\n");
				printf("----------------------------------------------------\n");
				employee_MostrarEmpleado(auxEmpleado);
			}
			else
			{
				printf("Modificacion cancelada!\nGracias por usar nuestro sistema.\n");
			}


		}
		else
		{
			printf("Error, el id ingresado no existe!\nGracias por usar nuestro sistema.\n");
		}
	}
    return todoOk;
}

int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int todoOk=0;
	int indice;
	int idEmp;
	char opcionElegida;
	Employee* auxEmpleado;

	if(pArrayListEmployee!=NULL)
	{
		printf("------------------------------------------------\n");
		printf("              REMOVER EMPLEADO/A                \n");
		printf("------------------------------------------------\n\n");
		controller_ListEmployee(pArrayListEmployee);

		auxEmpleado=employee_new();

		printf("Ingrese el id de la persona que desea remover:\n");
		scanf("%d",&idEmp);

		indice=controller_encontrarId(pArrayListEmployee, idEmp);
		auxEmpleado= ll_get(pArrayListEmployee, indice);

		if(auxEmpleado!=NULL && ll_contains(pArrayListEmployee, auxEmpleado) )
		{
			printf("\n");
			printf("Empleado seleccionado: \n");
			printf("----------------------------------------------------\n");
			printf(" ID  |             NOMBRE          |HORAS |SUELDO |\n");
			printf("----------------------------------------------------\n");
			employee_MostrarEmpleado(auxEmpleado);
			pedirCaracter(&opcionElegida, "¿Desea eliminar los datos de este/a empleado/a? Recuerde que sera de forma permanente (s/n): \n",
					"Error, opcion no valida. Ingrese un opcion valida(s/n): \n", 's', 'n');
			if(opcionElegida=='s')
			{
				ll_remove(pArrayListEmployee, indice);
				employee_delete(auxEmpleado);
				printf("Se ha eliminado al empleado de manera exitosa!\nGracias por usar nuestro sistema.\n");
				todoOk=1;
			}
			else
			{
				printf("Se ha cancelado la modificacion de manera exitosa!\nGracias por usar nuestro sistema.\n");
			}
		}
		else
		{
			printf("Error, el id ingresado no existe!\nGracias por usar nuestro sistema.");
		}
		return todoOk;

	}

    return todoOk;
}


int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int todoOk=0;
	int tam;
	Employee* auxEmployee=NULL;
	if(pArrayListEmployee!=NULL)
	{
		tam=ll_len(pArrayListEmployee);
		if(tam>=1)
		{
			todoOk=1;
			printf("----------------------------------------------------\n");
			printf(" ID  |             NOMBRE          |HORAS |SUELDO |\n");
			printf("----------------------------------------------------\n");

			for(int i=0; i<tam; i++)
			{
				auxEmployee= ll_get(pArrayListEmployee,i);
				employee_MostrarEmpleado(auxEmployee);
			}
		}
	}
	else
	{
		employee_delete(auxEmployee);
	}
	return todoOk;
}


int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int todoOk=0;
	int criterio;
	char opcion;

	LinkedList* auxList;

	if(pArrayListEmployee!=NULL)
	{
		auxList= ll_clone(pArrayListEmployee);
		if(auxList!=NULL)
		{
			if(ll_isEmpty(auxList)==0 && ll_containsAll(auxList, pArrayListEmployee) )
			{
				printf("------------------------------------------------\n");
				printf("              ORDENAR EMPLEADOS/AS                 \n");
				printf("------------------------------------------------\n\n");
				do
				{
					switch(menuOrdenar())
					{
					case 1:
						pedirEntero(&criterio, "Ingrese el criterio en el que quiera ordenar: ascendente 1 (A-Z) / 0 descendente (Z-A) \n",
								"Error, opcion invalida. Vuelva a intentarlo: (0-1) ", 0, 1);
						printf("Aguarde unos segundos(musica de ascensor)\n");
						ll_sort(auxList,employee_compararNombre,criterio);
						controller_ListEmployee(auxList);
						printf("Se ha ordenado exitosamente!\nGracias por usar nuestro sistema.\n");
						break;
					case 2:
						pedirEntero(&criterio, "Ingrese el criterio en el que quiera ordenar: 1 ascendente (0-9)/ 0 descendente (9-0) \n",
								"Error, opcion invalida. Vuelva a intentarlo: (0-1) ", 0, 1);
						printf("Aguarde unos segundos(musica de ascensor)\n");
						ll_sort(auxList,employee_compararId,criterio);
						controller_ListEmployee(auxList);
						printf("Se ha ordenado exitosamente!\nGracias por usar nuestro sistema.\n");
						break;
					case 3:
						pedirEntero(&criterio, "Ingrese el criterio en el que quiera ordenar: 1 ascendente (0-9)/ 0 descendente (9-0) \n",
								"Error, opcion invalida. Vuelva a intentarlo: (0-1) ", 0, 1);
						printf("Aguarde unos segundos(musica de ascensor)\n");
						ll_sort(auxList,employee_compararHoras,criterio);
						controller_ListEmployee(auxList);
						printf("Se ha ordenado exitosamente!\nGracias por usar nuestro sistema.\n");
						break;
					case 4:
						pedirEntero(&criterio, "Ingrese el criterio en el que quiera ordenar: 1 ascendente (0-9) / 0 descendente (9-0) \n",
								"Error, opcion invalida. Vuelva a intentarlo: (0-1) ", 0, 1);
						printf("Aguarde unos segundos(musica de ascensor)\n");
						ll_sort(auxList,employee_compararSueldo,criterio);
						controller_ListEmployee(auxList);
						printf("Se ha ordenado exitosamente!\nGracias por usar nuestro sistema.\n");
						break;
					case 5:
						pedirCaracter(&opcion, "Desea continuar?(s/n)",
								"Error, opcion invalida. Vuelva a intentarlo(s/n): \n", 's', 'n');
						break;

					}
				}while(opcion=='s');
				ll_deleteLinkedList(auxList);
				todoOk=1;
			}
			else
			{
				printf("Error, no hay empleados/as cargados/as en la lista!\nGracias por usar nuestro sistema.\n");
			}

		}
	}
	return todoOk;
}

int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int todoOk=0;
	FILE* f;
	Employee* auxEmpleado;
	int tam;
	int sueldo;
	int horasTrabajadas;
	int id;
	char nombre[128];

	if(path!=NULL && pArrayListEmployee!=NULL)
	{
		//archivo tipo texto
		f=fopen(path,"w");

		auxEmpleado=employee_new();

		tam= ll_len(pArrayListEmployee);

		fprintf(f,"id,nombre,horasTrabajadas,sueldo\n");
		for(int i=0; i<tam;i++)
		{
			auxEmpleado= (Employee*) ll_get (pArrayListEmployee,i);
			if(auxEmpleado!=NULL)
			{
				employee_getId(auxEmpleado,&id);
				employee_getNombre(auxEmpleado,nombre);
				employee_getHorasTrabajadas(auxEmpleado,&horasTrabajadas);
				employee_getSueldo(auxEmpleado,&sueldo);

				fprintf(f,"%d,%s,%d,%d\n",id,nombre,horasTrabajadas,sueldo);
				todoOk=1;
			}
			else
			{
				printf("\nError al guardar el archivo en modo binario!\n\n");
				todoOk=0;
				break;
			}
		}
		printf("\n Se ha guardado el archivo en modo texto exitosamente!\n\n");
		fclose(f);
	}
	return todoOk;
}


int controller_validarId(LinkedList* pArrayListEmployee, int idEmp)
{
	int idEncontrada;
	int idValidada=-1;
	int tam;
	Employee* empleado;

	if(pArrayListEmployee != NULL && idEmp >= 0)
	{
		tam = ll_len(pArrayListEmployee);

		for (int i = 0; i < tam; ++i) {

			empleado = ll_get(pArrayListEmployee, i);

			if(empleado != NULL)
			{
				employee_getId(empleado, &idEncontrada);
				if(idEmp==idEncontrada)
				{
					idValidada= 1;
					break;
				}
			}
		}
	}
	return idValidada;
}


int controller_siguienteId()
{
	FILE* f=fopen("guardarId.txt", "r");
	int* idActual=(int*) malloc(sizeof(int));
    int proxId;

    if(f==NULL)
    {
    	proxId=51;
    }
    else
    {
        fscanf(f, "%d", idActual);
        proxId=*idActual+1;
    }
    fclose(f);

    return proxId;
}


void controller_guardarId(int currentId)
{
    FILE* f=fopen("guardarId.txt", "r+");

    if(f==NULL)
    {
        f=fopen("guardarId.txt", "w");
    }

    fprintf(f,"%d", currentId);
    fclose(f);
}

int controller_eliminarEmpleadoMenosCaro(LinkedList* pArrayListEmployee)
{
	int todoOk=0;
	int sueldoMasBarato;
	int tam;
	int indiceMenorSueldo;
	Employee* auxEmpleado=NULL;
	int flagEntro=0;
	if(pArrayListEmployee != NULL)
	{
		tam = ll_len(pArrayListEmployee);
		for(int i = 0; i<tam; i++)
		{
			auxEmpleado = ll_get(pArrayListEmployee, i);
			if(auxEmpleado != NULL)
			{
				if ( flagEntro == 0 || auxEmpleado -> sueldo < sueldoMasBarato)
				{
					sueldoMasBarato = auxEmpleado -> sueldo;
					flagEntro=1;
				}
			}

		}
		for(int j=0;j<tam;j++)
		{
			auxEmpleado=ll_get(pArrayListEmployee, j);
			if(auxEmpleado != NULL)
			{
				if(sueldoMasBarato == auxEmpleado ->sueldo)
				{
					indiceMenorSueldo = ll_indexOf(pArrayListEmployee, auxEmpleado);
					break;
				}
			}
		}
		auxEmpleado = ll_pop(pArrayListEmployee, indiceMenorSueldo);
		if(auxEmpleado!=NULL)
		{
			printf("El empleado que se ha eliminado es el siguiente: \n");
			printf("----------------------------------------------------\n");
			printf(" ID  |             NOMBRE          |HORAS |SUELDO |\n");
			printf("----------------------------------------------------\n");
			employee_MostrarEmpleado(auxEmpleado);
			employee_delete(auxEmpleado);
			printf("Se ha borrado al empleado correctamente! \n");
			todoOk=1;
		}
	}
	else
	{
		printf("Error al eliminar al empleado/a!\n");
	}
	return todoOk;
}

int controller_subList(LinkedList* pArrayListEmployee)
{
	int todoOk=0;
	int from;
	int to;
	int tam=ll_len(pArrayListEmployee);

	LinkedList* auxLista=NULL;
	auxLista = ll_clone(pArrayListEmployee);
	if ( pArrayListEmployee != NULL)
	{
		controller_ListEmployee(auxLista);
		pedirEntero(&from, "Ingrese el id con el que empezará la sublista: \n",
				"Error, id no valido\n", 1, tam );


		pedirEntero(&to, "Ingrese el id final la sublista: \n",
					"Error, id no valido\n", from, tam );

		auxLista = ll_subList(pArrayListEmployee, from-1 , to);
		controller_ListEmployee(auxLista);

		todoOk=1;
	}
	return todoOk;
}

int controller_reemplazarEmpleado(LinkedList* pArrayListEmployee)
{
	int todoOk=0;
	char nombreEmp[128];
	int sueldoEmpleado;
	int horasTrabajadas;
	int id;
	int tam=ll_len(pArrayListEmployee);
	int idReemplazar;
	int indiceReemplazar;
	Employee* auxEmployee=NULL;
	Employee* aux2=NULL;
	if(pArrayListEmployee != NULL)
	{
		auxEmployee= employee_new();
		if(auxEmployee!=NULL)
		{
			printf("------------------------------------------------\n");
			printf("                REEMPLAZAR EMPLEADO               \n");
			printf("------------------------------------------------\n");
			id=controller_siguienteId();
			employee_setId(auxEmployee,id);

			printf("Ingrese el nombre del nuevo empleado: \n");
			fflush(stdin);
			gets(nombreEmp);
			validarString(nombreEmp,128);
			employee_setNombre(auxEmployee,nombreEmp);

			pedirEntero(&horasTrabajadas, "Ingrese la cantidad de horas trabajadas(0hs-350hs): "
					,"Error, cantidad no valida. Vuelva a ingresarlo(0hs-350hs): ", 0, 350);
			employee_setHorasTrabajadas(auxEmployee, horasTrabajadas);

			pedirEntero(&sueldoEmpleado, "Ingrese el sueldo del empleado/a(10000-50000): "
							, "Error, sueldo invalido. Vuelva a ingresarlo(10000-50000): ", 10000, 50000);
			employee_setSueldo(auxEmployee, sueldoEmpleado);

			controller_ListEmployee(pArrayListEmployee);

			printf("Ingrese el id del empleado a reemplazar: \n");
			scanf("%d",&idReemplazar);
			while(controller_validarId(pArrayListEmployee, idReemplazar) < 0 )
			{
				printf( "Error, id no valida. Vuelva a ingresarlo: \n");
				scanf("%d",&idReemplazar);
			}

			for(int i=0;i<tam;i++)
			{
				aux2=ll_get(pArrayListEmployee, i);
				if(aux2!=NULL)
				{
					if(aux2 ->id == idReemplazar)
					{
						indiceReemplazar = ll_indexOf(pArrayListEmployee, aux2);
						break;
					}
				}
			}
			if(!ll_set(pArrayListEmployee, indiceReemplazar, auxEmployee))
			{
				controller_ListEmployee(pArrayListEmployee);
				printf("Se ha reemplazado al empleado correctamente!\n");
				free(aux2);
				free(auxEmployee);
				todoOk=1;
			}
			else
			{
				printf("Error al reemplazar al empleado\n");
			}
		}
	}
	return todoOk;
}

int controller_agregarEmpPosicion(LinkedList* pArrayListEmployee)
{
	int todoOk=0;
	char nombreEmp[128];
	int sueldoEmpleado;
	int horasTrabajadas;
	int id;
	int tam=ll_len(pArrayListEmployee);
	int idInsertar;
	int indiceInsertar;
	Employee* auxEmployee=NULL;
	Employee* aux2=NULL;
	if(pArrayListEmployee != NULL)
	{
		auxEmployee= employee_new();
		if(auxEmployee!=NULL)
		{
			printf("------------------------------------------------\n");
			printf("                INSERTAR EMPLEADO               \n");
			printf("------------------------------------------------\n");
			id=controller_siguienteId();
			employee_setId(auxEmployee,id);

			printf("Ingrese el nombre del nuevo empleado: \n");
			fflush(stdin);
			gets(nombreEmp);
			validarString(nombreEmp,128);
			employee_setNombre(auxEmployee,nombreEmp);

			pedirEntero(&horasTrabajadas, "Ingrese la cantidad de horas trabajadas(0hs-350hs): "
					,"Error, cantidad no valida. Vuelva a ingresarlo(0hs-350hs): ", 0, 350);
			employee_setHorasTrabajadas(auxEmployee, horasTrabajadas);

			pedirEntero(&sueldoEmpleado, "Ingrese el sueldo del empleado/a(10000-50000): "
					, "Error, sueldo invalido. Vuelva a ingresarlo(10000-50000): ", 10000, 50000);
			employee_setSueldo(auxEmployee, sueldoEmpleado);

			controller_ListEmployee(pArrayListEmployee);

			printf("Ingrese el id en donde quiere ubicar al empleado/a: \n");
			scanf("%d",&idInsertar);
			while(controller_validarId(pArrayListEmployee, idInsertar) < 0 )
			{
				printf( "Error, id no valida. Vuelva a ingresarlo: \n");
				scanf("%d",&idInsertar);
			}

			for(int i=0;i<tam;i++)
			{
				aux2=ll_get(pArrayListEmployee, i);
				if(aux2!=NULL)
				{
					if(aux2 ->id == idInsertar)
					{
						indiceInsertar = ll_indexOf(pArrayListEmployee, aux2);
						break;
					}
				}
			}

			if(!ll_push(pArrayListEmployee, indiceInsertar, auxEmployee))
			{
				controller_ListEmployee(pArrayListEmployee);
				printf("Se ha ubicado al nuevo empleado correctamente!\n");
				free(aux2);
				free(auxEmployee);
				todoOk=1;
			}
			else
			{
				printf("Error al ubicar al nuevo empleado\n");
			}
		}
	}
	return todoOk;
}
