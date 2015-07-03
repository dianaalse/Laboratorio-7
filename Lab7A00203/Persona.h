#pragma once

using namespace std;

class Persona {

	friend ostream & operator<<(ostream &, Persona &);

	template <class TIPONODO>
	friend class NodoLista;

private:
	string nombre;
	string cedula;
	Persona();

public:
	Persona(string, string);
	~Persona();


	bool operator<(Persona &);
	bool operator>(Persona &);

};

ostream & operator<<(ostream &, Persona &);

