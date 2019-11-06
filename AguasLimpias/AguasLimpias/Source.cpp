#include<iostream>
#include"bintree_eda.h"
using namespace std;

typedef struct tRio {
	int caudal;
	int cont;
};

tRio resuelve(bintree<int> arbol);
int main() {
	int casos;
	cin >> casos;
	for (int i = 0; i < casos; i++) {
		bintree<int> arbol = leerArbol(-1);
		tRio rio = resuelve(arbol);
		cout << rio.cont << endl;
	}
}


tRio resuelve(bintree<int> arbol) {
	tRio rio;
	if (!arbol.empty()) {
		tRio iz = resuelve(arbol.left());
		tRio de = resuelve(arbol.right());
		if (arbol.right().empty() && arbol.left().empty()) {
			rio.caudal = 1;
			rio.cont = 0;
			return rio;
		}
		else if (arbol.right().empty()) {
			if (iz.caudal >= 3) {
				iz.cont++;
			}
			iz.caudal -= arbol.root();

			return iz;
		}
		else if (arbol.left().empty()) {
			if (de.caudal >= 3) {
				de.cont++;
			}
			de.caudal -= arbol.root();

			return de;
		}
		else {//si no es una hoja
			rio.cont = iz.cont + de.cont;

			if (iz.caudal >= 3) {
				rio.cont++;
			}
			if (de.caudal >= 3) {
				rio.cont++;
			}
			rio.caudal = iz.caudal + de.caudal - arbol.root();
			return rio;
		}

	}
	else {
		rio.caudal = 0;
		rio.cont = 0;
	}



}


