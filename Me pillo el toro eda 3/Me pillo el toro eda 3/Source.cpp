#include<iostream>
#include<string>
#include"Header.h"
using namespace std;

int main() {
	int casos;
	string nombre;
	string nota;
	cin >> casos;

	while (casos != 0) {
		map<string, int> notas;

		for (int i = 0; i < casos; i++) {
			cin >> nombre;
			cin >> nota;
			if (notas.count(nombre) == 0) { // si no existe
				notas.insert(nombre);
				notas[nombre] = 0;
			}
			if (nota == "CORRECTO") notas[nombre] += 1;
			else notas[nombre] -= 1;
		}

		map<string, int>::iterator iterador = notas.begin(); //creo un mapa nuevo en el comienzo del otro

		for (int i = 0; i < notas.size(); i++) {
			if (iterador->valor != 0) {
				cout << iterador->clave << ", " << iterador->valor << endl;
			}
			++iterador; //pasar al siguiente

		}
		cout << "---" << endl;
		/*
		map<string, int>::iterator iterador2 = notas.begin(); //creo un mapa nuevo en el comienzo del otro

		for (int i = 0; i < notas.size(); i++) {
			notas.erase(iterador2->clave);
			++iterador2;
		}
		*/
		cin >> casos;

	}
		
}
