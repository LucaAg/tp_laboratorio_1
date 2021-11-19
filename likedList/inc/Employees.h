#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

/**
 * @fn int employee_MostrarEmpleado(Employee*)
 * @brief Muestra los datos de un empleado.
 *
 * @param unEmpleado puntero a estructura Employee, para obtener los datos del mismo.
 * @return todoOk(0) si hay error. En caso de no haber error todoOk(1).
 */
int employee_MostrarEmpleado(Employee* unEmpleado);

/**
 * @fn Employee employee_new*()
 * @brief Inicia los datos del empleado en datos genericos, distintos a NULL.
 *
 * @return retorna el empleado.
 */
Employee* employee_new();

/**
 * @fn Employee employee_newParametros*(char*, char*, char*, char*)
 * @brief Carga los datos del empleado en la estructura.
 *
 * @param idStr puntero a char que contiene el id del empleado.
 * @param nombreStr puntero a char, que contiene el nombre del empleado.
 * @param horasTrabajadasStr puntero a char, que contiene las horas trabajadas del empleado.
 * @param sueldoStr puntero a sueldo, que contiene el sueldo del empleado.
 * @return
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char *sueldoStr);

/**
 * @fn void employee_delete(Employee*)
 * @brief borras los datos de un empleado.
 *
 * @param unEmpleado puntero a estructura Employee, contiene los datos del empleado.
 */
void employee_delete(Employee* unEmpleado);

/**
 * @fn int employee_setId(Employee*, int)
 * @brief carga el id de un empleado.
 *
 * @param unEmpleado puntero a estructura Employee de un empleado donde se asigna el id.
 * @param id guarda el valor del id.
 * @return todoOk(0) si hay error. En caso de no haber error todoOk(1).
 */
int employee_setId(Employee* unEmpleado,int id);

/**
 * @fn int employee_getId(Employee*, int*)
 * @brief Busca el empleado segun el id asignado al mismo.
 *
 * @param unEmpleado puntero a estructura Employee de un empleado al cual se le asigno un id.
 * @param pId puntero a entero, que carga el valor del id del empleado.
 * @return todoOk(0) si hay error. En caso de no haber error todoOk(1).
 */
int employee_getId(Employee* unEmpleado,int* pId);

/**
 * @fn int employee_setNombre(Employee*, char*)
 * @brief carga el nombre al empleado.
 *
 * @param unEmpleado puntero a estructura Employee de un empleado donde se asigna el nombre.
 * @param pNombre puntero a char del nombre del empleado.
 * @return todoOk(0) si hay error. En caso de no haber error todoOk(1).
 */
int employee_setNombre(Employee* unEmpleado,char* pNombre);

/**
 * @fn int employee_getNombre(Employee*, char*)
 * @brief Busca el empleado segun el nombre asignado al mismo.
 *
 * @param unEmpleado puntero a estructura Employee de un empleado al cual se le asigno un nombre.
 * @param pNombre puntero a char que contiene el nombre del empleado.
 * @return todoOk(0) si hay error. En caso de no haber error todoOk(1).
 */
int employee_getNombre(Employee* unEmpleado,char* pNombre);

/**
 * @fn int employee_setHorasTrabajadas(Employee*, int)
 * @brief Carga las horas trabajadas del empleado.
 *
 * @param unEmpleado puntero a estructura Employee de un empleado donde se asigna las horas trabajadas.
 * @param horasTrabajadas entero que guarda las horas trabajadas por el empleado.
 * @return todoOk(0) si hay error. En caso de no haber error todoOk(1).
 */
int employee_setHorasTrabajadas(Employee* unEmpleado,int horasTrabajadas);

/**
 * @fn int employee_getHorasTrabajadas(Employee*, int*)
 * @brief Busca un empleado segun las horas trabajadas.
 *
 * @param unEmpleado puntero a estructura Employee de un empleado al cual se le asigno cierta cantidad de horas.
 * @param pHorasTrabajadas puntero a entero que contiene la cantidad de horas trabajadas del empleado.
 * @return todoOk(0) si hay error. En caso de no haber error todoOk(1).
 */
int employee_getHorasTrabajadas(Employee* unEmpleado,int* pHorasTrabajadas);

/**
 * @fn int employee_setSueldo(Employee*, int)
 * @brief Carga el sueldo del empleado.
 *
 * @param unEmpleado puntero a estructura Employee de un empleado donde se asigna el sueldo correspondiente.
 * @param sueldo entero que guarda el sueldo correspondiente al empleado.
 * @return todoOk(0) si hay error. En caso de no haber error todoOk(1).
 */
int employee_setSueldo(Employee* unEmpleado,int sueldo);

/**
 * @fn int employee_getSueldo(Employee*, int*)
 * @brief Busca un empleado segun el sueldo correspondiente.
 *
 * @param unEmpleado puntero a estructura Employee de un empleado al cual se le asigno un sueldo correspondiente.
 * @param pSueldo puntero a entero que contiene la cantidad de horas trabajadas del empleado.
 * @return todoOk(0) si hay error. En caso de no haber error todoOk(1).
 */
int employee_getSueldo(Employee* unEmpleado,int* pSueldo);


/**
 * @fn int employee_compararId(void*, void*)
 * @brief Compara 2 ids de dos empleados para retornar un criterio(orden ascendente y descendente).
 *
 * @param empleado1 puntero a void, para castear un empleado.
 * @param empleado2 puntero a void, para castear un empleado.
 * @return todoOk(0) si hay error. En caso de no haber error todoOk(1).
 */
int employee_compararId(void* empleado1, void* empleado2);

/**
 * @fn int employee_compararNombre(void*, void*)
 * @brief Compara 2 nombres de 2 empleados para retornar un criterio(orden ascendente y descendente).
 *
 * @param empleado1 puntero a void, para castear un empleado.
 * @param empleado2 puntero a void, para castear un empleado.
 * @return todoOk(0) si hay error. En caso de no haber error todoOk(1).
 */
int employee_compararNombre(void* empleado1, void* empleado2);

/**
 * @fn int employee_compararHoras(void*, void*)
 * @brief Compara las horas trabajadas de 2 para retornar un criterio(orden ascendente y descendente).
 *
 * @param empleado1 puntero a void, para castear un empleado.
 * @param empleado2 puntero a void, para castear un empleado.
 * @return todoOk(0) si hay error. En caso de no haber error todoOk(1).
 */
int employee_compararHoras(void* empleado1, void* empleado2);

/**
 * @fn int employee_compararSueldo(void*, void*)
 * @brief Compara 2 sueldos de 2 empleados para retornar un criterio(orden ascendente y descendente).
 *
 * @param empleado1 puntero a void, para castear un empleado.
 * @param empleado2 puntero a void, para castear un empleado.
 * @return todoOk(0) si hay error. Retorna 1 para descendente y 0 para ascendete.
 */
int employee_compararSueldo(void* empleado1, void* empleado2);
#endif // EMPLOYEE_H_INCLUDED

