#include<iostream>
#include"bintree_eda.h"
using namespace std;

typedef struct tEdad{
	int altura;
	bool cumple;
	int valor;
};
tEdad resuelve(bintree<int> arbol);

int main() {
	int casos;
	cin >> casos;
	for (int i = 0; i < casos; i++) {
		bintree<int> arbol = leerArbol(-1);
		tEdad edad = resuelve(arbol);
		if (edad.cumple) cout << "SI " << edad.altura << endl;
		else cout << "NO" << endl;
	}
}

tEdad resuelve(bintree<int> arbol) {
	tEdad edad;

	if (!arbol.empty()) {
		tEdad iz = resuelve(arbol.left());
		tEdad de = resuelve(arbol.right());

		edad.altura = 1 + max(iz.altura, de.altura);
		edad.valor = arbol.root();
		edad.cumple = true;
			if (iz.valor - de.valor < 2 && (iz.valor != 0 || de.valor != 0)) {
				edad.cumple = false;
			}
		
			if (arbol.root() - max(iz.valor , de.valor) < 18 && !arbol.left().empty() && !arbol.right().empty()) {
				edad.cumple = false;
			}

			edad.cumple = edad.cumple == iz.cumple == de.cumple;
		
			return edad;
		
	}
	else {
		edad.altura = 0;
		edad.cumple = true;
		edad.valor = 0;
		return edad;
	}
}

