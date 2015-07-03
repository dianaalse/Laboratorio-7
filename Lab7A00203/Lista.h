#pragma once
#include "stdafx.h"

template< typename TIPONODO >
class Lista
{
template <class TIPONODO>
friend class Iterador;

template <class TIPONODO>
friend class IteradorInverso;

public:
	Lista() {
		primeroPtr = 0;
		ultimoPtr = 0;
	} // fin del constructor de Lista
	~Lista(){
		if (!estaVacia()) // la Lista no est� vac�a
		{
			cout << "Destruyendo nodos ...\n";

			NodoLista< TIPONODO >  *actualPtr = primeroPtr;
			NodoLista< TIPONODO >  *tempPtr;

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

	void insertarAlFrente(const TIPONODO &valor){
		NodoLista< TIPONODO > * nuevoPtr = obtenerNuevoNodo(valor); // define nuevo nodo con parametro

		if (estaVacia()){ // la Lista est� vac�a
			primeroPtr = ultimoPtr = nuevoPtr;
			nuevoPtr->anteriorPtr = NULL;
			nuevoPtr->siguientePtr = NULL;
			primeroPtr = ultimoPtr = nuevoPtr;
		}// la nueva lista s�lo tiene un nodo
		else // la Lista no est� vac�a
		{
			nuevoPtr->siguientePtr = primeroPtr;
			primeroPtr->anteriorPtr = nuevoPtr; // apunta el nuevo nodo al nodo que antes era el primero
			primeroPtr = nuevoPtr; // orienta primeroPtr hacia el nuevo nodo
			nuevoPtr->anteriorPtr = NULL;
		} // fin de else
	} // fin de la funci�n insertarAlFrente

	void insertarAlFinal(const TIPONODO &valor){
		NodoLista< TIPONODO > *nuevoPtr = obtenerNuevoNodo(valor); // nuevo nodo

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



	void insertarAlMedio(const TIPONODO &valor, int num_nodo){


		NodoLista< TIPONODO > *nuevoPtr = obtenerNuevoNodo(valor); // nuevo nodo

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

			NodoLista< TIPONODO > *temp;                            // create a temporary node
			temp = (NodoLista< TIPONODO >*)malloc(sizeof(NodoLista< TIPONODO >));    // allocate space for node
			temp->datos = valor;                  // store data(first field)
			temp->anteriorPtr = nuevoPtr;
			temp->siguientePtr = nuevoPtr->siguientePtr;            //transfer the address of temp1->next to temp->next
			temp->siguientePtr->anteriorPtr = temp;
			nuevoPtr->siguientePtr = temp;             //transfer the address of temp to temp1->next

		}
	}
	bool eliminarDelFrente(TIPONODO &valor){
		if (estaVacia()) // la Lista est� vac�a
			return false; // la eliminaci�n no tuvo �xito
		else
		{
			NodoLista< TIPONODO > *tempPtr = primeroPtr; // contiene tempPtr a eliminar

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

	bool eliminarDelMedio(int num_nodo){
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
			NodoLista< TIPONODO > *tempPtr;
			tempPtr = (NodoLista< TIPONODO >*)malloc(sizeof(NodoLista< TIPONODO >)); // allocate space for node
			tempPtr = primeroPtr;


			NodoLista< TIPONODO > *old_temp;                     // create a temporary node
			old_temp = (NodoLista< TIPONODO >*)malloc(sizeof(NodoLista< TIPONODO >));    // allocate space for node
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



			tempPtr->anteriorPtr->siguientePtr = tempPtr->siguientePtr;             // store current node
			tempPtr->siguientePtr->anteriorPtr = tempPtr->anteriorPtr;
			delete tempPtr; // reclama el nodo que antes era el primero
			return true; // la eliminaci�n tuvo �xito 
			cout << " Nodo de la lista eliminado" << endl;

		}
		// fin de else
	} // fin de la funci�n eliminarDelMedio

	bool eliminarDelFinal(TIPONODO &valor){
		if (estaVacia()) // la Lista est� vac�a
			return false; // la eliminaci�n no tuvo �xito
		else
		{
			NodoLista< TIPONODO > *tempPtr = ultimoPtr; // contiene tempPtr a eliminar

			if (primeroPtr == ultimoPtr) {// la Lista tiene un elemento
				ultimoPtr = tempPtr->anteriorPtr;
				primeroPtr = ultimoPtr = 0; // no hay nodos despu�s de la eliminaci�n
			}
			else
			{
				NodoLista< TIPONODO > *actualPtr = primeroPtr;

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

	bool estaVacia()const {
		return primeroPtr == 0;
	} // fin de la funci�n estaVacia

	void imprimir() const {
		if (estaVacia()) // la Lista est� vac�a
		{
			cout << "La lista esta vacia\n\n";
			return;
		} // fin de if

		NodoLista< TIPONODO > *actualPtr = primeroPtr;

		cout << "La lista es: ";

		while (actualPtr != 0) // obtiene los datos del elemento
		{
			cout << actualPtr->datos << " ";
			actualPtr = actualPtr->siguientePtr;
		} // fin de while

		cout << "\n\n";
	} // fin de la funci�n imprimir


	Iterador< TIPONODO > begin(){
		return Iterador< TIPONODO >(primeroPtr);
	}

	Iterador< TIPONODO > end(){
		return Iterador< TIPONODO >(NULL);
	}

	IteradorInverso< TIPONODO > rbegin(){
		return IteradorInverso< TIPONODO >(ultimoPtr);
	}

	IteradorInverso< TIPONODO > rend(){
		return IteradorInverso< TIPONODO >(NULL);
	}
		
	
private:
	NodoLista< TIPONODO > * primeroPtr; // apuntador al primer nodo
	NodoLista< TIPONODO > * ultimoPtr; // apuntador al �ltimo nodo
	// funci�n utilitaria para asignar un nuevo nodo
	NodoLista< TIPONODO > * obtenerNuevoNodo(const TIPONODO &valor){
		return new NodoLista< TIPONODO >(valor);
	} // fin de la funci�n obtenerNuevoNodo
}; // fin de la clase Lista
