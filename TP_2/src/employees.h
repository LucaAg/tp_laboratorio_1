#ifndef EMPLOYEES_H_
#define EMPLOYEES_H_

/**
 * @struct
 * @brief Estructura de los datos de empleados/as.
 *
 */
struct
{
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;
}typedef eEmployee;


#endif /* EMPLOYEES_H_ */
/**
 * @fn int promedioSalariosTotal(eEmployee[], int)
 * @brief Recorre el array de empleados acumulando los sueldos de los empleados con isEmpty en verdadero.
 * 		  Luego, cuenta la cantidad de empleados que cumplen la condicion anterior.
 * 		  A continuación, calcula el promedio de sueldos, y el total del mismo.
 *		  Por ultimo, compara que cantidad de empleados supera el sueldo promedio y lo muestra
 *
 * @param list Employee* puntero a vector de empleados
 * @param len entero, que brinda la longitud del vector
 * @return int todoOk(0) si existe un error[valor NULL o len menor a 0] - (1) Si no hay error.
 */
int promedioSalariosTotal(eEmployee list[],int len);

/**
 * @fn int initEmployees(eEmployee*, int)
 * @brief Indica que todas las posiciones en el vector estan vacias,
 * 		  esta funcion pone la funcion isEmpty en verdadero
 * 		  en todas las posiciones del vector.
 *
 *
 * @param list	Employee* puntero a vector de empleados.
 * @param len	Entero, que brinda la longitud del vector.
 * @return int todoOk(-1) si existe un error[puntero NULL o len menor a 0] - (0) Si no hay error
 */
int initEmployees(eEmployee* list,int len);

/**
 * @fn int buscarLibre(eEmployee[], int)
 * @brief Busca los indices en el vector estructura list(en isEmpty), en los cuales los valores son 1.
 * 	      Si el valor es 1, significa que en esa posicion hay una posicion libre, y guarda ese indice.
 *
 * @param list Employee* puntero a vector de empleados.
 * @param len  Entero, que brinda la longitud del vector.
 * @return int todoOk(-1) si existe un error[vector NULL o len menor a 0]- (libre) Si no hay error.
 */
int buscarLibre(eEmployee list[],int len);

/**
 * @fn int addEmployees(eEmployee*, int, int, char[], char[], float, int)
 * @brief	Agrega en una lista existentes de empleados los valores que recibe como parametros
 * 	        en la primer posicion de isEmpty
 *
 *
 * @param list	Employee* puntero a vector de empleados.
 * @param len	Entero, que brinda la longitud del vector.
 * @param id	Entero id
 * @param name[]	char vector
 * @param lastName[] char vector
 * @param salary	float salario
 * @param sector	int sector
 * @return int todoOk(-1) si existe un error[puntero list NULL/ vector name NULL / vector lastName NULL]
 *  	   -(0) Si no hay error.
 */
int addEmployees(eEmployee* list,int len, int id, char name[],char lastName[],float salary,int sector);

/**
 * @fn int menu()
 * @brief Muestra el menu de ABM para empleados.
 * 		  Pide una opcion al usuario.
 *
 * @return int opcion(1/2/3/4/5)
 */
int menu();

/**
 * @fn int menuModificar()
 * @brief Muesta el menu para modificar empleados.
 *
 * @return int opcion(1/2/3/4/5)
 */
int menuModificar();

/**
 * @fn int subMenuInformar()
 * @brief Muestra el menu para informar los datos ya ingresados.
 *
 * @return int opcion(1/2/3)
 */
int subMenuInformar();

/**
 * @fn int modifyEmployee(eEmployee[], int)
 * @brief	Muestra un menu de opciones y da la opcion de
 * 			modificar los datos de un empleado/a.
 *
 * @param list Employee* puntero a vector de empleados.
 * @param len  Entero, que brinda la longitud del vector.
 * @return
 */
int modifyEmployee(eEmployee list[],int len);

/**
 * @fn void mostrarEmpleado(eEmployee)
 * @brief Muestra los datos de un empleado/a.
 *
 * @param unaPersona
 */
void mostrarEmpleado(eEmployee unaPersona);

/**
 * @fn int findEmployeeById(eEmployee[], int, int)
 * @brief	Encuentra un empleado/a mediante su id
 * 			y devuelve su posicion en el indice de la matriz.
 *
 *
 * @param list  Employee* puntero a vector de empleados.
 * @param iD	Entero id
 * @param len	Entero, que brinda la longitud del vector.
 * @return
 */
int findEmployeeById(eEmployee list[],int iD,int len);

/**
 * @fn int printEmployees(eEmployee*, int)
 * @brief	Imprime el contenido de una matriz de empleados/as
 *
 * @param list	Employee* puntero a vector de empleados.
 * @param len	Entero, que brinda la longitud del vector.
 * @return
 */
int printEmployees(eEmployee* list,int len);

/**
 * @fn int removeEmployee(eEmployee[], int, int)
 * @brief	Elimina a un/a empleado/a mediante su id.
 * 			A su vez, pone la bandera isEmpty en 1.
 *
 * @param list	Employee* puntero a vector de empleados.
 * @param len	Entero, que brinda la longitud del vector.
 * @param id	Entero que guarda el id.
 * @return
 */
int removeEmployee(eEmployee list[],int len, int id);

/**
 * @fn int sortEmployees(eEmployee*, int, int)
 * @brief	Ordena los elementos en un vector de empleados/as,
 * 			mediante el argument orden en 1(ascendente) o 0(descendente).
 *
 * @param list	Employee* puntero a vector de empleados.
 * @param len	Entero, que brinda la longitud del vector.
 * @param order	Entero, señala el ordenamiento.
 * @return
 */
int sortEmployees(eEmployee* list, int len, int order);

/**
 * @fn int permitirIngreso(eEmployee[], int, int*)
 * @brief	No deja ingresar al usuario al menu, caso 2/3/4,
 * 			sin antes haber ingresado al caso 1.
 *
 * @param lista	Employee* puntero a vector de empleados.
 * @param len	Entero, que brinda la longitud del vector.
 * @param flag	Entero, guarda el valor de la bandera.
 * @return
 */
int permitirIngreso(eEmployee lista[], int len,int* flag);
