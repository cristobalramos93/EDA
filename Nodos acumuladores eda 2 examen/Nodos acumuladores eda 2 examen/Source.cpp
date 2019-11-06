#include<iostream>
#include"bintree_eda.h"
using namespace std;

typedef struct {
	int resultado;
	int cantidad;
}tHola;

tHola resuelve(bintree<int> arbol, tHola & hola);

int main() {
	int casos;
	cin >> casos;
	for (int i = 0; i < casos; i++) {
		tHola hola;
		bintree<int> arbol = leerArbol(-1);
		hola = resuelve(arbol, hola);
		cout << hola.cantidad << endl;
	}
}


tHola resuelve(bintree<int> arbol, tHola & hola) {
	if (!arbol.empty()) {
		tHola iz = resuelve(arbol.left(),hola);
		tHola de = resuelve(arbol.right(),hola);
		
		if (arbol.root() == iz.resultado + de.resultado) {
			hola.cantidad = 1;
		}
		else {
			hola.cantidad = 0;
		}
		hola.resultado = arbol.root() + iz.resultado + de.resultado;
		hola.cantidad = hola.cantidad + iz.cantidad + de.cantidad;
		return hola;
	}
	else {
		hola.cantidad = 0;
		hola.resultado = 0;
		return hola;
	}
}