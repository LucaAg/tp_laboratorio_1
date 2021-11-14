#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char* puntero a char(direccion de memoria del archivo).
 * \param pArrayListEmployee LinkedList* puntero a estructura de la lista de empleados LinkedList.
 * \return int todoOk(0) si hay error. En caso de no haber error todoOk(1).
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char* puntero a char, que contiene el nombre del archivo.
 * \param pArrayListEmployee LinkedList* puntero a estructura de la lista de empleados LinkedList.
 * \return int todoOk(0) si hay error. En caso de no haber error todoOk(1).
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);

/** \brief Alta de empleados
 *
 * \param path char*  puntero a char, que contiene el nombre del archivo.
 * \param pArrayListEmployee LinkedList* puntero a estructura de la lista de empleados LinkedList.
 * \return int return todoOk(0) si hay error. todoOk(1) Si no hay error.
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee);

/** \brief Modificar datos de empleado
 *
 * \param pArrayListEmployee LinkedList* puntero a estructura de la lista de empleados LinkedList.
 * \return int return todoOk(0) si hay error. todoOk(1) Si no hay error.
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee);

/** \brief Baja de empleado
 *
 * \param pArrayListEmployee LinkedList* puntero a estructura de la lista de empleados LinkedList.
 * \return int return todoOk(0) si hay error. todoOk(1) Si no hay error.
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee);

/** \brief Listar empleados
 *
 * \param pArrayListEmployee LinkedList* puntero a estructura de la lista de empleados LinkedList.
 * \return int return todoOk(0) si hay error. todoOk(1) Si no hay error.
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee);

/** \brief Ordenar empleados de manera ascendente o descendente segun la opcion elegida.
 *
 * \param pArrayListEmployee LinkedList* puntero a estructura de la lista de empleados LinkedList.
 * \return int return todoOk(0) si hay error. todoOk(1) Si no hay error.
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee);

/**
 * @fn int controller_saveAsText(char*, LinkedList*)
 * @brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * @param path char*  puntero a char, que contiene el nombre del archivo.
 * @param pArrayListEmployee LinkedList* puntero a estructura de la lista de empleados LinkedList.
 * @return return todoOk(0) si hay error. todoOk(1) Si no hay error.
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);

/**
 * @fn int controller_saveAsBinary(char*, LinkedList*)
 * @brief  Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * @param path char*  puntero a char, que contiene el nombre del archivo.
 * @param pArrayListEmployee LinkedList* puntero a estructura de la lista de empleados LinkedList.
 * @return return todoOk(0) si hay error. todoOk(1) Si no hay error.
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);

/**
 * @fn int controller_encontrarId(LinkedList*, int)
 * @brief Recibe una id y la compara en la lista para saber si es una existente.
 *
 * @param pArrayListEmployee puntero a estructura de la lista de empleados LinkedList.
 * @param id entero que guarda el id.
 * @return return indice(-1) si no se encuentra el indice. Si no hay error y encuentra el id, retorna el id encontrado.
 */
int controller_encontrarId(LinkedList* pArrayListEmployee, int id);

/**
 * @fn int controller_validarId(LinkedList*, int)
 * @brief
 *
 * @param pArrayListEmployee puntero a estructura de la lista de empleados LinkedList.
 * @param idEmp entero que recibe el id.
 * @return return idValidada(-1) si hay error. idValidada(1) Si no hay error.
 */
int controller_validarId(LinkedList* pArrayListEmployee, int idEmp);

/**
 * @fn void controller_guardarId(int)
 * @brief Calcula el valor del nuevo id, en base al ultimo id en lista. Si no hay lista, por default id=1001.(funcion que lee y escribe)
 *
 * @param currentId variable entero que recibe el id.
 */
void controller_guardarId(int currentId);

/**
 * @fn int controller_siguienteId()
 * @brief guarda el valor del del ultimo id utlizado para cargar el proximo.
 *
 * @return el valor del ultimo id mas uno.
 */
int controller_siguienteId();

#endif // CONTROLLER_H_INCLUDED
