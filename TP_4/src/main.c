/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../testing/inc/main_test.h"
#include "../inc/LinkedList.h"
#include "../inc/Controller.h"
#include "../inc/input.h"


int main(void)
{
	setbuf(stdout,NULL);
	/*startTesting(1);   //ll_newLinkedList; // main.c LINE 57/454
	startTesting(2);   //ll_len; C // Controller.c LINE 57 :)
	startTesting(3);  // getNode - test_getNode
	startTesting(4);  // addNode - test_addNode
	startTesting(5);  // ll_add // Controller.c LINE 104
	startTesting(6);  // ll_get // Controller.c LINE 458/317/264
	startTesting(7);  // ll_set //Controller.c LINE 663
	startTesting(8);  // ll_remove  // Controller.c LINE 278
	startTesting(9);  // ll_clear	// main.c LINE 79, case 2
	startTesting(10); // ll_deleteLinkedList // Controller.c LINE 389          // main.c case 10
	startTesting(11); // ll_indexOf  // Controller.c    LINE 541
	startTesting(12); // ll_isEmpty // Controller.c LINE 344
	startTesting(13); // ll_push //Controller.c LINE 736
	startTesting(14); // ll_pop // Controller.c LINE 545
	startTesting(15); // ll_contains // Controller.c LINE 267
	startTesting(16); // ll_containsAll // Controller.c LINE 344
	startTesting(17); // ll_subList // Controller.c LINE 593
	startTesting(18); // ll_clone // Conntroller.c LINE 340
	startTesting(19); // ll_sort  // Controller.c LINE 354/362/370/378 */

	char option='s';
	int cargaDatosTxt=0;
	char option2='s';
	char option3='s';

	LinkedList* listaEmpleados = ll_newLinkedList();
	do{
		switch(menu())
		{
			case 1:
				if(cargaDatosTxt==0)
				{
					controller_loadFromText("dataEmpleados.csv",listaEmpleados);
					cargaDatosTxt=1;
				}
				else if(cargaDatosTxt==1)
				{
					printf("Error!\nNo se puede ingresar el mismo archivo dos veces.\n");
				}
				break;
			case 2:
				if(listaEmpleados -> size)
				{
					pedirCaracter(&option2, "Seguro desea borrar todos los datos de la lista?(s/n)\n",
							"Error, opcion invalida!\nVuelva a intentarlo(s/n): \n", 's', 'n');
					if(option2=='s')
					{
						if(ll_clear(listaEmpleados)==0)
						{
							printf("Se ha borrado la lista de empleados/as correctamente\nGracias por usar nuestro sistema.\n");
							cargaDatosTxt=0;
						}
						else
						{
							printf("Error al borrar la lista!\n");
						}
					}
				}
				else
				{
					printf("No se puede reiniciar la lista sin antes ingresar algun empleado!\nGracias por usar nuestro sistema\n");
				}
				break;
			case 3:
				controller_addEmployee(listaEmpleados);
				break;
			case 4:
				if(listaEmpleados -> size)
				{
					controller_editEmployee(listaEmpleados);
				}
				else
				{
					printf("No se puede ingresar a esta seccion, sin antes cargar un empleado/a");
				}
				break;
			case 5:
				if(listaEmpleados -> size)
				{
					controller_removeEmployee(listaEmpleados);
				}
				else
				{
					printf("No se puede ingresar a esta seccion, sin antes cargar un empleado/a");
				}
				break;
			case 6:
				if(listaEmpleados -> size)
				{
					controller_ListEmployee(listaEmpleados);
				}
				else
				{
					printf("No se puede ingresar a esta seccion, sin antes cargar un empleado/a");
				}
				break;
			case 7:
				if(listaEmpleados -> size)
				{
					controller_sortEmployee(listaEmpleados);
				}
				else
				{
					printf("No se puede ingresar a esta seccion, sin antes cargar un empleado/a");
				}
				break;
			case 8:
				controller_eliminarEmpleadoMenosCaro(listaEmpleados);
				break;
			case 9:
				if(listaEmpleados -> size)
				{
					controller_subList(listaEmpleados);
				}
				else
				{
					printf("Error, primero debe ingresar la opcion 1 \n");
				}
				break;
			case 10:
				if(listaEmpleados -> size)
				{
					controller_reemplazarEmpleado(listaEmpleados);
				}
				else
				{
					printf("No se puede ingresar a esta seccion, sin antes cargar un empleado/a");
				}
				break;
			case 11:
				if(listaEmpleados -> size)
				{
					controller_agregarEmpPosicion(listaEmpleados);
				}
				else
				{
					printf("No se puede ingresar a esta seccion, sin antes cargar un empleado/a");
				}
				break;
			case 12:
				if(listaEmpleados -> size)
				{
					pedirCaracter(&option3, "Cuidado! Se van a sobreescribir los datos de la lista!\nSeguro desea continuar? (s/n):\n",
							"Error opcion no valida. Vuelva a ingresarlo (s/n): \n", 's', 'n');
					if(option3=='s')
					{
						controller_saveAsText("dataEmpleados.csv", listaEmpleados);
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
			case 13:
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

































