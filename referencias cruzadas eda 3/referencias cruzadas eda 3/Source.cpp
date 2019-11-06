#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include"treemap_eda.h"
using namespace std;
int main() {
	int n;
	cin >> n;
	while (n != 0) {
		map <string, vector<int>> mapa;
		cin.ignore();
		for (int i = 0; i < n; i++) {
			string linea;
			string palabra;
			getline(cin, linea);
			stringstream ss(linea);
			while (ss >> palabra) {
				if (palabra.length() > 2) {
					for (int n = 0; n < palabra.length(); n++) {//las paso a minusculas
						palabra[n] = tolower(palabra[n]);
					}
					if (mapa.count(palabra) == 0) {
						mapa.insert(palabra);
						mapa[palabra].push_back(i + 1);
					}
					if (mapa[palabra].back() != i + 1) { //si no existe esa linea ya en el vector
						mapa[palabra].push_back(i + 1);

					}
				}
			}


		}



		map<string, vector<int>>::iterator iterador = mapa.begin();

		for (int i = 0; i < mapa.size(); i++) {
			cout << iterador->clave << " ";
			for (int n = 0; n < iterador->valor.size(); n++) {
				cout << iterador->valor[n] << " ";
			}
			cout << endl;
			++iterador;
		}
		cout << "----" << endl;
		cin >> n;
	}
}