#pragma once

#include "NodoLista.h"

template< typename TIPONODO >
class Iterador {
private:
	NodoLista< TIPONODO > * anterior;
	NodoLista< TIPONODO > * actual;

public:

	Iterador(NodoLista< TIPONODO > * actual) {
		this->anterior = actual;
		this->actual = actual;
	}

	~Iterador() {
	}

	// Preincremento
	TIPONODO& operator++() {

		actual = actual->siguientePtr;
		return actual->datos;
	}

	// Posincremento
	//	TIPONODO& operator++(){
	//}

	TIPONODO operator*() {
		return actual->datos;
	}

	bool operator!=(Iterador<TIPONODO> & otro) {
		return this->actual != otro.actual;
	}

	bool operator==(Iterador<TIPONODO> & otro) {
		return this->actual == otro.actual;
	}

};

