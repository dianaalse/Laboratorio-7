#include "stdafx.h"

using std::cout;
using std::endl;


// constructor predeterminado
Lista::Lista(){
	primeroPtr = 0;
	ultimoPtr = 0;
} // fin del constructor de Lista

// destructor
Lista::~Lista()
{
 if (!estaVacia()) // la Lista no est� vac�a
		{
		cout << "Destruyendo nodos ...\n";
		
		NodoLista *actualPtr = primeroPtr;
		NodoLista *tempPtr;
		
			while (actualPtr != 0) // elimina los nodos restantes
			{
			tempPtr = actualPtr;
			cout << tempPtr->datos << "\n";
			actualPtr = actualPtr->siguientePtr;
			delete tempPtr;
			} // fin de while
		} // fin de if
	
		cout << "Se destruyeron todos los nodos\n\n";
	} // fin del destructor de Lista

 // inserta un nodo al frente de la lista

void Lista::insertarAlFrente(int valor)
{
	 NodoLista *nuevoPtr = obtenerNuevoNodo(valor); // define nuevo nodo con parametro
	
	 if (estaVacia()){ // la Lista est� vac�a
		 primeroPtr = ultimoPtr = nuevoPtr;
		 nuevoPtr->anteriorPtr = NULL;
		 nuevoPtr->siguientePtr = NULL;
		 primeroPtr = ultimoPtr = nuevoPtr;
	 }// la nueva lista s�lo tiene un nodo
	else // la Lista no est� vac�a
		 {
			 nuevoPtr->siguientePtr = primeroPtr;
		     primeroPtr -> anteriorPtr = nuevoPtr; // apunta el nuevo nodo al nodo que antes era el primero
			 primeroPtr = nuevoPtr; // orienta primeroPtr hacia el nuevo nodo
			 nuevoPtr->anteriorPtr = NULL;
	 } // fin de else
	 } // fin de la funci�n insertarAlFrente

 // inserta un nodo al final de la lista

void Lista::insertarAlMedio(int valor, int num_nodo){
	

	NodoLista *nuevoPtr = obtenerNuevoNodo(valor); // nuevo nodo

	if (estaVacia()) // la Lista est� vac�a
		primeroPtr = ultimoPtr = nuevoPtr; // la nueva lista s�lo tiene un nodo
	else // la Lista no est� vac�a
	{
		nuevoPtr = primeroPtr;

		for (int i = 1; i < num_nodo; i++){
			nuevoPtr = nuevoPtr->siguientePtr;             //revisar si el nodo es valido

			if (nuevoPtr == NULL){
				cout << num_nodo << "El Nodo no existe" << endl;
				break;
			}
		}

		NodoLista *temp;                            // create a temporary node
		temp = (NodoLista*)malloc(sizeof(NodoLista));    // allocate space for node
		temp->datos = valor;                  // store data(first field)
		temp->anteriorPtr = nuevoPtr;
		temp->siguientePtr = nuevoPtr->siguientePtr;            //transfer the address of temp1->next to temp->next
		temp->siguientePtr->anteriorPtr = temp;
		nuevoPtr->siguientePtr = temp;             //transfer the address of temp to temp1->next
		
	}
}

void Lista::insertarAlFinal(int valor)
{
	NodoLista *nuevoPtr = obtenerNuevoNodo(valor); // nuevo nodo

	if (estaVacia()){ // la Lista est� vac�a
		nuevoPtr->anteriorPtr = ultimoPtr;
		primeroPtr = ultimoPtr = nuevoPtr; // la nueva lista s�lo tiene un nodo
	}
	 else{
		nuevoPtr->anteriorPtr = ultimoPtr; //actualiza el valor del anterior
		ultimoPtr->siguientePtr = nuevoPtr; // actualiza el nodo que antes era el �ltimo
		ultimoPtr = nuevoPtr; // nuevo �ltimo nodo
		 } // fin de else
} // fin de la funci�n insertarAlFinal

 // elimina un nodo de la parte frontal de la lista
bool Lista::eliminarDelFrente(int valor)
 {
	if (estaVacia()) // la Lista est� vac�a
	    return false; // la eliminaci�n no tuvo �xito
	else
		 {
		NodoLista *tempPtr = primeroPtr; // contiene tempPtr a eliminar
		
		if (primeroPtr == ultimoPtr){
			primeroPtr = tempPtr->siguientePtr;
			primeroPtr = ultimoPtr = 0; // no hay nodos despu�s de la eliminaci�n
		}
		else
			primeroPtr = primeroPtr->siguientePtr; // apunta al nodo que antes era el segundo
			primeroPtr->anteriorPtr = NULL;
			valor = tempPtr->datos; // devuelve los datos que se van a eliminar
		    delete tempPtr; // reclama el nodo que antes era el primero
		    return true; // la eliminaci�n tuvo �xito
		 } // fin de else
	 } // fin de la funci�n eliminarDelFrente

// elimina un nodo de la parte final de la lista

bool Lista::eliminarDelMedio(int num_nodo)

{
	if (estaVacia()) // la Lista est� vac�a
		return false; // la eliminaci�n no tuvo �xito
	else
	{
		if (primeroPtr->siguientePtr == NULL)
		{
			primeroPtr = NULL;
			cout << "El ultimo nodo de la lista se ha borrado" << endl;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       
			cout << "La lista esta vacia" << endl;
		}
		NodoLista *tempPtr;
		tempPtr = (NodoLista*)malloc(sizeof(NodoLista)); // allocate space for node
		tempPtr = primeroPtr;


		NodoLista *old_temp;                     // create a temporary node
		old_temp = (NodoLista*)malloc(sizeof(NodoLista));    // allocate space for node
		old_temp = tempPtr;
		if (num_nodo == 1)
		{
			primeroPtr = tempPtr->siguientePtr;                  // transfer the address of 'tempPtr->next' to 'head'
			free(tempPtr);
			cout << num_nodo << " Nodo de la lista fue eliminado" << endl;
		}

		// Go to the node number of the node
		for (int i = 1; i < num_nodo; i++)
		{
			old_temp = tempPtr;               // store previous node
			tempPtr = tempPtr->siguientePtr;             // store current node
			
		}



		tempPtr->anteriorPtr-> siguientePtr = tempPtr->siguientePtr;             // store current node
		tempPtr->siguientePtr->anteriorPtr = tempPtr->anteriorPtr;
		delete tempPtr; // reclama el nodo que antes era el primero
		return true; // la eliminaci�n tuvo �xito 
		cout << " node of the Linked List is deleted" << endl;

	}
	// fin de else
} // fin de la funci�n eliminarDelMedio

// elimina un nodo de la parte final de la lista

bool Lista::eliminarDelFinal(int valor)
{
	if (estaVacia()) // la Lista est� vac�a
		return false; // la eliminaci�n no tuvo �xito
	else
		 {
		 NodoLista *tempPtr = ultimoPtr; // contiene tempPtr a eliminar
		
		 if (primeroPtr == ultimoPtr) {// la Lista tiene un elemento
			 ultimoPtr = tempPtr->anteriorPtr;
			 primeroPtr = ultimoPtr = 0; // no hay nodos despu�s de la eliminaci�n
		 }
		 else
			 {
			 NodoLista *actualPtr = primeroPtr;
			
				 // localiza el pen�ltimo elemento
				 while (actualPtr->siguientePtr != ultimoPtr)
				 actualPtr = actualPtr->siguientePtr; // se desplaza al siguiente nodo
				 ultimoPtr = tempPtr->anteriorPtr;
				 ultimoPtr = actualPtr; // elimina el �ltimo nodo
			     actualPtr->siguientePtr = 0; // ahora �ste es el �ltimo nodo
			 } // fin de else2
		
	     valor = tempPtr->datos; // devuelve el valor del nodo que antes era el �ltimo
		 delete tempPtr; // reclama el nodo que antes era el �ltimo
		 return true; // la eliminaci�n tuvo �xito
		 } // fin de else1
} // fin de la funci�n eliminarDelFinal

 // �est� la Lista vac�a?
 bool Lista::estaVacia()
{
	return primeroPtr == 0;
} // fin de la funci�n estaVacia

// devuelve el apuntador al nodo reci�n asignado
NodoLista * Lista::obtenerNuevoNodo(int valor)
{
	return new NodoLista(valor);
} // fin de la funci�n obtenerNuevoNodo

// muestra el contenido de la Lista
void Lista::imprimir()
{
	if (estaVacia()) // la Lista est� vac�a
		 {
		 cout << "La lista esta vacia\n\n";
		 return;
		 } // fin de if
	
		 NodoLista *actualPtr = primeroPtr;
	
		 cout << "La lista es: ";
	
		 while (actualPtr != 0) // obtiene los datos del elemento
		 {
		 cout << actualPtr->datos << " ";
		 actualPtr = actualPtr->siguientePtr;
		 } // fin de while
	
		 cout << "\n\n";
	 } // fin de la funci�n imprimir

Iterador Lista::begin() {
	return Iterador(primeroPtr);
}

Iterador Lista::end() {
	return Iterador(NULL);
}

IteradorInverso Lista::rbegin() {
	return IteradorInverso(ultimoPtr);
}

IteradorInverso Lista::rend() {
	return IteradorInverso(NULL);
}
