#include "stdafx.h"
#include "Persona.h"

Persona::Persona() {
}

Persona::Persona(string nombre, string cedula){
	this->nombre = nombre;
	this->cedula = cedula;
}

Persona::~Persona()
{
}

ostream & operator<<(ostream & out, Persona & p) {
	return out << p.nombre << endl;
}

bool Persona::operator<(Persona & otra) {
	return this->nombre.compare(otra.nombre) < 0;
}

bool Persona::operator>(Persona & otra) {
	return this->nombre.compare(otra.nombre) < 0;
}

