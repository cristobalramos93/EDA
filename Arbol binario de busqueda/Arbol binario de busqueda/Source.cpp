#include<iostream>
#include"bintree_eda.h"
using namespace std;

//26 es un arbol binario de busqueda


int resuelve(bintree<int> arbol, bool & busqueda);
int main() {
	int casos;
	cin >> casos;
	for (int i = 0; i < casos; i++) {
		bintree<int> arbol = leerArbol(-1);
		bool busqueda = true;
		 resuelve(arbol, busqueda);
		if (busqueda) cout << "SI" << endl;
		else cout << "NO" << endl;
	}
}

int resuelve(bintree<int> arbol, bool & busqueda) {
	if (!arbol.empty()) {
		int iz = resuelve(arbol.left(), busqueda);
		int de = resuelve(arbol.right(), busqueda);

		if (arbol.root() < iz && iz != 0) {
			busqueda = false;
		}
		if (arbol.root() > de && de != 0) {
			busqueda = false;
		}
		return arbol.root();
	}
	else return 0;
}