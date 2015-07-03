#include "stdafx.h"


// constructor

NodoLista::NodoLista(int info)
{
	this->datos = info;
	this->siguientePtr = 0;
	this->anteriorPtr = 0;
} // fin del constructor de NodoLista

// devuelve una copia de los datos en el nodo

int NodoLista::obtenerDatos()
{
	return datos;
} // fin de la función obtenerDatos
