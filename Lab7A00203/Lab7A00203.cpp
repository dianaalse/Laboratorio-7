// Lab7A00203.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	
	cout << "-------Probando con Int-------" << endl;
  Lista<int> numInt;
  for (int i = 0; i < 5; ++i) {
		numInt.insertarAlFrente(i);
		numInt.imprimir();	
	}
  numInt.eliminarDelMedio(2);
  numInt.imprimir();

  cout << "-------Iterador hacia Adelante-------" << endl;
  Iterador<int> it = numInt.begin();
  while (it != numInt.end()) {
	  cout << *it << endl;
	  ++it;
  }

  cout << "-------Iterador Inverso-------" << endl;
  IteradorInverso<int> it2 = numInt.rbegin();
  while (it2 != numInt.rend()) {
	  cout << *it2 << endl;
	  ++it2;
  }

  cout << "-------Probando con Double-------" << endl;
  Lista<double> numDou;
  for (int i = 0; i < 5; ++i) {
	  numDou.insertarAlFrente(i/2.22);
	  numDou.imprimir();
  }
  numDou.eliminarDelMedio(2);
  numDou.imprimir();

  cout << "-------Iterador hacia Adelante-------" << endl;
  Iterador<double> it3 = numDou.begin();
  while (it3 != numDou.end()) {
	  cout << *it3 << endl;
	  ++it3;
  }

  cout << "-------Iterador Inverso-------" << endl;
  IteradorInverso<double> it4 = numDou.rbegin();
  while (it4 != numDou.rend()) {
	  cout << *it4 << endl;
	  ++it4;
  }

  cout << "-------Probando con Char-------" << endl;
  Lista<char> numChar;
  for (char i = 'a'; i < 'a' + 5; ++i) {
	  numChar.insertarAlFrente(i);
	  numChar.imprimir();
  }
  numChar.eliminarDelMedio(2);
  numChar.imprimir();

  cout << "-------Iterador hacia Adelante-------" << endl;
  Iterador<char> it5 = numChar.begin();
  while (it5 != numChar.end()) {
	  cout << *it5 << endl;
	  ++it5;
  }

  cout << "-------Iterador Inverso-------" << endl;
  IteradorInverso<char> it6 = numChar.rbegin();
  while (it6 != numChar.rend()) {
	  cout << *it6 << endl;
	  ++it6;
  }

  cout << "-------Probando con Clase Persona-------" << endl;
  Lista<Persona> numPersona;
  Persona p1("Arbol", "1");
  Persona p2("Hoja", "2");
  Persona p3("Zeta", "3");

  numPersona.insertarAlFinal(p2);
  numPersona.imprimir();
  numPersona.insertarAlFinal(p1);
  numPersona.imprimir();
  numPersona.insertarAlFinal(p3);
  numPersona.imprimir();
  numPersona.insertarAlFinal(p3);
  numPersona.imprimir();
  numPersona.insertarAlFinal(p2);
  numPersona.imprimir();
  numPersona.insertarAlFinal(p1);
  numPersona.imprimir();

  numChar.eliminarDelMedio(2);
  numChar.imprimir();

  cout << "-------Iterador hacia Adelante-------" << endl;
  Iterador<Persona> it7 = numPersona.begin();
  while (it7 != numPersona.end()) {
	  cout << *it7 << endl;
	  ++it7;
  }

  cout << "-------Iterador Inverso-------" << endl;
  IteradorInverso<Persona> it8 = numPersona.rbegin();
  while (it8 != numPersona.rend()) {
	  cout << *it8 << endl;
	  ++it8;
  }

	system("pause");
	return 0;
}

