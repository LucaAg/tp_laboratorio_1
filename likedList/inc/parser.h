#ifndef PARSER_H_
#define PARSER_H_

/** \brief Parsea los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param pFile char* puntero a char(direccion de memoria del archivo).
 * \param pArrayListEmployee LinkedList* puntero a estructura de la lista de empleados LinkedList.
 * \return int todoOk(0) si hay error. En caso de no haber error todoOk(1).
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);


#endif /* PARSER_H_ */
