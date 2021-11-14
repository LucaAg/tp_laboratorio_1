#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "input.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.bin (modo binario).
    10. Salir
*****************************************************/

int main()
{
	setbuf(stdout,NULL);
    char option='s';
    int cargaDatosBin=0;
    int cargaDatosTxt=0;
    char option2='s';
    char option3='s';

    LinkedList* listaEmpleados = ll_newLinkedList();
    do{
        switch(menu())
        {
            case 1:
            	if(cargaDatosBin==0 && cargaDatosTxt==0)
            	{
            		controller_loadFromText("data.csv",listaEmpleados);
            		cargaDatosTxt=1;
            	}
            	else if(cargaDatosTxt==1)
            	{
            		printf("Error!\nNo se puede ingresar el mismo archivo dos veces.\n");
            	}
            	else
            	{
            		printf("Error!\nYa se ha ingresado el archivo en modo binario!\n");
            	}
                break;
            case 2:
            	if(cargaDatosTxt==0 && cargaDatosBin==0)
            	{
            		if(controller_loadFromBinary("data.bin", listaEmpleados))
            		{
            			cargaDatosBin=1;
            		}
            	}
            	else if(cargaDatosBin==1)
            	{
            		printf("Error!\nNo se puede ingresar el mismo archivo dos veces.\n");
            	}
            	else
            	{
            		printf("Error!\nYa se ha ingresado el archivo en modo txt!\n");
            	}
            	break;
            case 3:
            	controller_addEmployee(listaEmpleados);
            	break;
            case 4:
            	if(listaEmpleados->size)
            	{
            		controller_editEmployee(listaEmpleados);
            	}
            	else
            	{
            		printf("No se puede ingresar a esta seccion, sin antes cargar un empleado/a");
            	}
            	break;
            case 5:
            	if(listaEmpleados->size)
            	{
            		controller_removeEmployee(listaEmpleados);
            	}
            	else
				{
            		printf("No se puede ingresar a esta seccion, sin antes cargar un empleado/a");
				}
            	break;
            case 6:
            	if(listaEmpleados->size)
            	{
            		controller_ListEmployee(listaEmpleados);
            	}
            	else
            	{
            		printf("No se puede ingresar a esta seccion, sin antes cargar un empleado/a");
            	}
            	break;
            case 7:
            	if(listaEmpleados->size)
            	{
            		controller_sortEmployee(listaEmpleados);
            	}
            	else
            	{
            		printf("No se puede ingresar a esta seccion, sin antes cargar un empleado/a");
            	}
            	break;
            case 8:
            	if(listaEmpleados->size)
            	{
            		pedirCaracter(&option3, "Cuidado! Se van a sobreescribir los datos de la lista!\nSeguro desea continuar? (s/n):\n",
            				"Error opcion no valida. Vuelva a ingresarlo (s/n): \n", 's', 'n');
            		if(option3=='s')
            		{
            			controller_saveAsText("data.csv", listaEmpleados);
            		}
            		else
            		{
            			printf("Carga de texto en modo binario cancelada!\n");
            		}
            	}
            	else
            	{
            		printf("No se puede ingresar a esta seccion, sin antes cargar un empleado/a");
            	}
            	break;
            case 9:
            	if(listaEmpleados->size)
            	{
            		pedirCaracter(&option2, "Cuidado! Se van a sobreescribir los datos de la lista!\nSeguro desea continuar? (s/n):\n",
            				"Error opcion no valida. Vuelva a ingresarlo (s/n): \n", 's', 'n');
            		if(option2=='s')
            		{
            			controller_saveAsBinary("data.bin", listaEmpleados);
            		}
            		else
            		{
            			printf("Carga de datos en modo binario cancelada!\n");
            		}
            	}
            	else
            	{
            		printf("No se puede ingresar a esta seccion, sin antes cargar un empleado/a");
            	}
            	break;
            case 10:
            	pedirCaracter(&option, "Desea continuar en el menu?(s/n)\n", "Opcion invalida. Debe ingresar s/n. Vuelva a intentarlo",
            			's', 'n');
            	if(option=='n')
            	{
            		ll_deleteLinkedList(listaEmpleados);
            	}
            	break;
            default:
            	printf("Opcion invalida(1-10)! Gracias por usar nuestro sistema.\n");
            	break;
        }
    }while(option == 's');
    return 0;
}

