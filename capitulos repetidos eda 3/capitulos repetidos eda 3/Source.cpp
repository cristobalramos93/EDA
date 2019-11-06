#include<iostream>
#include<string>
#include"Header.h"
using namespace std;
int main() {
	int casos;
	int numero;
	cin >> casos;
	for(int i = 0; i < casos; i++){
		map<int, int> mapa;
		int capitulos;
		cin >> capitulos;
		for (int n = 0; n < capitulos; n++) {
			cin >> numero;
			if (mapa.count(numero) == 0) { //si no existe
				mapa.insert(numero);
				//mapa[numero] = 1;
			}
			map<int, int>::iterator iterador = mapa.begin();
			for (int j = 0; j < mapa.size(); j++) {
				if (iterador->clave != numero) { //si 1 != 6
					mapa[iterador->clave]++;//valor de 1 ++
				}
				else {
					mapa[iterador->clave] = 1;
				}
				++iterador;
			}
		}


		map<int, int>::iterator iterador2 = mapa.begin();
		int max = 0;
		for (int n = 0; n < mapa.size(); n++) {
			if (max < iterador2->valor) max = iterador2->valor;
			++iterador2;
		}

		cout << max << endl;



	}
}