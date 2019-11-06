#include<iostream>
#include<string>
#include<sstream>
#include"Header.h"
using namespace std;

int main() {
	int casos;
	cin >> casos;
	cin.ignore();
	for (int s = 0; s < casos; s++) {
		map<string, int> mapa;
		int num;
		string linea;
		string letra;
		getline(cin, linea);
		stringstream ss(linea);
		while (ss >> letra) {
			ss >> num;
			mapa.insert(letra);
			mapa[letra] = num;
		}

		




		map<string, int> mapa2;
		getline(cin, linea);
		stringstream aa(linea);
		while (aa >> letra) {
			aa>> num;
			mapa2.insert(letra);
			mapa2[letra] = num;
		}

		map<string, int> ::iterator iterador = mapa2.begin();
		bool primero = false;
		bool cambios = false;
		for (int i = 0; i < mapa2.size(); i++) {
			if (mapa.count(iterador->clave) == 0) {
				if (!primero) {
					cout << "+ ";
					primero = true;
					cambios = true;
				}
				cout << iterador->clave << " ";
			}
			++iterador;
		}
		if (primero)cout << endl;


		map<string, int> ::iterator iterador2 = mapa.begin();
		primero = false;
		for (int i = 0; i < mapa.size(); i++) {
			if (mapa2.count(iterador2->clave) == 0) {
				if (!primero) {
					cout << "- ";
					primero = true;
					cambios = true;
				}
				cout << iterador2->clave << " ";
			}
			++iterador2;
		}
		if (primero)cout << endl;

		primero = false;
		map<string, int> ::iterator iterador3 = mapa2.begin();
		for (int i = 0; i < mapa2.size(); i++) {
			if (mapa.count(iterador3->clave) != 0 && mapa[iterador3->clave] != iterador3->valor) {
				if (!primero) {
					cout << "* ";
					primero = true;
					cambios = true;
				}
				cout << iterador3->clave << " ";

			}
			++iterador3;
		}
		if (primero)cout << endl;

		if (cambios == false) cout << "Sin cambios" << endl;
		cout << "----" << endl;
	}
}