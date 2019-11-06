#include<iostream>
#include"bintree_eda.h"
using namespace std;


typedef struct tAtrapados{
	int excursionistas;
	int equipos;
};
tAtrapados resuelve(bintree<int> arbol);
int main() {
	int casos;
	cin >> casos;

	for (int i = 0; i < casos; i++) {
		bintree<int> arbol = leerArbol(-1);
		tAtrapados atrapados;
		atrapados = resuelve(arbol);
		cout << atrapados.equipos << " " << atrapados.excursionistas << endl;
	}
}



tAtrapados resuelve(bintree<int> arbol) {
	tAtrapados atrapados;
	if (!arbol.empty()) {

		tAtrapados iz = resuelve(arbol.left());
		tAtrapados de = resuelve(arbol.right());

		atrapados.excursionistas = arbol.root() + max(iz.excursionistas, de.excursionistas);
		if (iz.equipos == 0 && de.equipos == 0 && arbol.root() != 0) {
			atrapados.equipos = 1;
		}
		else atrapados.equipos = 0;
		atrapados.equipos = atrapados.equipos + iz.equipos + de.equipos;
		return atrapados;

	}
	else {
		atrapados.equipos = 0;
		atrapados.excursionistas = 0;
		return atrapados;
	}
}