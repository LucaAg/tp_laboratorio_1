#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this= NULL;

    this = (LinkedList*) malloc(sizeof(LinkedList));
    if(this != NULL)
    {
    	this -> size =0;
    	this -> pFirstNode = NULL;
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL)
    {
    	returnAux = this -> size;
    }
    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	Node* pNodo = NULL;
	//Node* auxNode = NULL;
	if(this != NULL && nodeIndex >= 0 && nodeIndex < ll_len(this)) // siempre usar los getters, ya que no es buena practica this -> size.
	{
		/*if(nodeIndex == 0)
		{
			pNodo = this->pFirstNode; // no hace falta, ya que como esta el codigo abajo ya me devuelve el indice 0.
		}
		else
		{*/
			/*auxNode = this->pFirstNode; //VAGON 0 estoy ubicaod en el primer vagon

			auxNode -> pNextNode; //ESTOY EN EL VAGON 1, DIRECCION DE MEMORIA DE VAGON 1

			auxNode = auxNode->pNextNode; // DIRECCION DE VAGON 2, OBTENGO LA DIRECCION DEL PROX VAGON*/
			/*pNodo = this->pFirstNode;
			while(nodeIndex > 0) forma baus
			{
				pNodo = pNodo -> pNextNode;
				nodeIndex--;
			} // PUEDO HACER UN FOR, INCIIA EN NODE INDEX, HASTA QUE INDEX SEA >0 E INDEX--*/
			pNodo = this->pFirstNode;
			for(int i=nodeIndex;i>0;i--)
			{
				pNodo = pNodo -> pNextNode;
				nodeIndex--;
			}
		//}
	}
    return pNodo;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex) // NO SE MODIFICA
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* newNode = NULL;
    Node* nodeAnterior = NULL;
    if(this != NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this) ) // <= PORQUE DEJO 1 ESPEACIO PARA AGREGAR UN NUEVO NODE
    {
    	newNode = (Node*) malloc(sizeof(Node)); // consigo espacio en memoria para una estructura node y lo guardo en nuevo nodo.
    	if(newNode != NULL) //valido que sea distitno a null para conseguitr espacio en memoria
    	{
    		newNode -> pElement = pElement; // mi nuevo cagon apunta a plement

    		newNode -> pNextNode = getNode(this, nodeIndex); // mi nuevo vagon apunta, a lo que apuntaba el vagon que quiero reemplazar

    		if(nodeIndex == 0)
    		{
    			this-> pFirstNode = newNode;
    		}
    		else
    		{
    			nodeAnterior = getNode (this , nodeIndex - 1); // obtengo la direccion dem i nodo anterior
    			nodeAnterior -> pNextNode = newNode;
    		}
    		this -> size++;
    		returnAux = 0;
    	}
    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement) //NO SE MODIFCA
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement) //agregar un vagon al final
{
    return addNode(this, ll_len(this), pElement);
}

/** \brief Permite obtener un elemento de la lista.
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index) //llama a getnode para obtener el vagon que esta en el index y devuelve el pElement del vagon.
{
    void* returnAux = NULL;
    Node* nodeAux = NULL;
    if(this != NULL && index >= 0 && index < ll_len(this) )
    {
    	nodeAux = getNode(this, index);
    	if(nodeAux!=NULL)
    	{
    		returnAux = nodeAux -> pElement;
    	}
    }
    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* nodeAux=NULL;
    if(this != NULL && index >= 0 && index < ll_len(this) )
    {
    	nodeAux = getNode (this, index);
    	if(nodeAux!=NULL)
    	{
    		nodeAux -> pElement = pElement;
    		returnAux=0;
    	}
    }
    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node* auxNodeUno=NULL;
    Node* auxNodeDos=NULL;
    if(this != NULL && index >=0 && index < ll_len(this) )
    {
    	auxNodeUno = getNode(this, index);
    	if (auxNodeUno != NULL)
    	{
    		if( index == 0 )
    		{
    			//auxNodeDos=getNode(this, index+1);
    			//this -> pFirstNode=auxNodeDos; //PREGUNTAR A BAUS ESTE ESCENARIO
    			this -> pFirstNode = auxNodeUno-> pNextNode;
    			free(auxNodeUno);
    			this -> size --;
    			returnAux=0;
    		}
    		else
    		{
    			auxNodeDos = getNode (this , index - 1);
    			if(auxNodeDos != NULL)
    			{
    				auxNodeDos -> pNextNode = auxNodeUno -> pNextNode;
    				free(auxNodeUno);
    				this -> size --;
    				returnAux=0; //repito porque funciona solo si entra aca.
    			}
    		}
    	}

    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL)
    {
    	while(ll_len(this))
    	{
    		returnAux = ll_remove (this,0);
    		if(returnAux)
    		{
    			break;
    		}
    	}
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;
    if(this!=NULL)
    {
    	if(!ll_clear(this))
    	{
    		free(this);
    		returnAux=0;
    	}
    }
    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int tam;
   // Node* auxNode = NULL;
    if(this != NULL)
    {
    	tam = ll_len(this);
    	for(int i=0; i < tam; i++)
    	{
    		if( ll_get(this,i)==pElement)
    		{
    			returnAux=i;
    			break;
    		}
    		/*auxNode = getNode(this, i);
    		if(auxNode != NULL)
    		{
    			if(auxNode -> pElement == pElement)
    			{
    				returnAux = i;
    				break;
    			}
    		}*/
    	}
    }

    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;
    int tam;
    if(this != NULL)
    {
    	tam = ll_len(this);
    	if(tam > 0)
    	{
    		returnAux=0;
    	}
    	else
    	{
    		returnAux=1;
    	}
    }
    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    return addNode(this, index, pElement);
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    //Node* auxElementDelete;
    if( this != NULL && index >=0 && index < ll_len(this) )
    {
    	/*auxElementDelete = getNode(this, index);
    	if( auxElementDelete != NULL)
    	{
    		returnAux = auxElementDelete -> pElement;

    	}*/
    	returnAux = ll_get(this,index);
    	ll_remove(this, index);
    }
    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    if(this != NULL)
    {
    	returnAux = 0;
    	if(ll_indexOf(this, pElement)>=0)
    	{
    		returnAux = 1;
    	}
    }
    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
   // Node* auxListDos=NULL;
    void* aux = NULL;
    int tam;
    if(this != NULL && this2 != NULL)
    {
    	returnAux = 1; // a mi forma debe ser = 0
    	tam = ll_len (this2);
    	for(int j = 0; j < tam ; j++)
    	{
    		/*auxListDos= getNode(this2, j);
   			if (auxListDos != NULL)
   			{
   				if( ll_contains(this, auxListDos ->pElement) )
   				{
    				returnAux = 1;
    			}
    			else
   				{
   					returnAux = 0;
   					break;
   				}

    		}*/
    		aux = ll_get(this2, j);
    		if( !ll_contains(this, aux) )
    		{
    			returnAux = 0;
    			break;
    		}
    	}
    }
    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    //void* pElement = NULL;
    if(this != NULL && from >= 0 && to >= from && to <= ll_len(this) ) // <= porque siempre es 1 valor menos del 1, entocnes si tengo 0-4 a indice en to seria hasta el 5
    {
    	cloneArray=ll_newLinkedList();
    	if(cloneArray!=NULL)
    	{
    		for(int i = from; i < to ; i++) // solo menoir a to porque es 1 valor menso de to, recordar que aca recorre indice ademas.
    		{
    			//pElement = ll_get(this, i);
    			ll_add(cloneArray, ll_get(this, i) );
    		}
    	}
    }
    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this) //devuelve un nuevo linkedlist
{
    return ll_subList(this, 0 , ll_len(this) );	// al this l ovalida mi funcion ll_subList.
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;
    void* pElementUno=NULL;
    void* pElementDos=NULL;
    if( this != NULL && pFunc != NULL && order >= 0 && order <= 1 )
    {
    	for ( int i = 0; i < ll_len(this) - 1; i++ )
    	{
    		for ( int j = i+1; j < ll_len(this); j++)
    		{
    			pElementUno = ll_get(this, i);
    			pElementDos = ll_get(this, j);
    			if(order == 1)
    			{
    				if( pFunc(pElementUno,pElementDos) > 0 )
    				{
    					ll_set(this, i, pElementDos);
    					ll_set(this, j, pElementUno);
    				}
    			}
    			else if(order == 0)
    			{
    				if( pFunc(pElementUno,pElementDos) < 0 )
    				{
    					ll_set(this, j, pElementUno);
    					ll_set(this, i, pElementDos);
    				}
				}
    		}
    	}
    	returnAux=0;
    }
    return returnAux;

}

LinkedList* ll_filter(LinkedList* this, int (*pFunc) (void*) )
{
	LinkedList* filterArray=NULL;
	int tam;
	if(this!=NULL && pFunc !=NULL)
	{
		filterArray=ll_newLinkedList();
		if(filterArray!=NULL)
		{
			tam= ll_len(this);
			for(int i =0; i < tam; i++)
			{
				if(pFunc(ll_get(this,i) ) )
				{
					ll_add(filterArray,ll_get(this,i));
				}
			}
		}
	}
	return filterArray;
}
