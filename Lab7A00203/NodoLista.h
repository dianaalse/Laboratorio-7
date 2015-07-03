#pragma once

template< typename TIPONODO >
class NodoLista
{
template <class TIPONODO>
friend class Lista; // hace de Lista una amiga

template <class TIPONODO>
friend class Iterador; //hace de iterador un amigo

template <class TIPONODO>
friend class IteradorInverso; //hace de iteradorinverso un amigo

public:
	NodoLista< TIPONODO >(const TIPONODO &info){
		this->datos = info;
		this->siguientePtr = 0;
		this->anteriorPtr = 0;
	} // fin del constructor de NodoLista

	TIPONODO obtenerDatos(){
		return datos;
	} // fin de la función obtenerDatos

private:
	        TIPONODO datos; // datos
			NodoLista< TIPONODO > * siguientePtr; // siguiente nodo en la lista
			NodoLista< TIPONODO > * anteriorPtr; //anterior nodo en la lista
	
};

