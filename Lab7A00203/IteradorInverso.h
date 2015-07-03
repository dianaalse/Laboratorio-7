#pragma once

#include "NodoLista.h"

template< typename TIPONODO >
class IteradorInverso {
private:
	NodoLista< TIPONODO > * anterior;
	NodoLista< TIPONODO > * actual;

public:

	IteradorInverso(NodoLista< TIPONODO > * actual) {
		this->anterior = actual;
		this->actual = actual;
	}

	~IteradorInverso() {
	}

	// Preincremento
	TIPONODO& operator++() {

		actual = actual->anteriorPtr;
		return actual->datos;
	}

	// Posincremento
	//	TIPONODO& operator++(){
	//}

	TIPONODO operator*() {
		return actual->datos;
	}

	bool operator!=(IteradorInverso<TIPONODO> & otro) {
		return this->actual != otro.actual;
	}

	bool operator==(IteradorInverso<TIPONODO> & otro) {
		return this->actual == otro.actual;
	}

};
