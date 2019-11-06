#include<iostream>
#include"bintree_eda.h"
using namespace std;

typedef struct tNumero{
	int valor;
	int max;
};
tNumero resuelve(bintree<int> arbol);

int main() {
	int casos;
	cin >> casos;
	for (int i = 0; i < casos; i++) {
		tNumero n;
		bintree<int> arbol = leerArbol(-1);
		n = resuelve(arbol);
		cout << n.max << endl;
	}
}

tNumero resuelve(bintree<int> arbol) {
	tNumero numero;
	if (!arbol.empty()) {

		tNumero iz = resuelve(arbol.left());
		tNumero de = resuelve(arbol.right());

		if (arbol.root() % 2 == 0) {//si soy par
			numero.valor = 1 + max(iz.valor,de.valor);
			if ((iz.valor + de.valor + 1 > de.max) && (iz.valor + de.valor + 1 > iz.max)) {
				numero.max = iz.valor + de.valor +1;
				return numero;
			}
			else {
				numero.max = max(de.max, iz.max);
				return numero;
			}

		}
		else {
			numero.valor = 0;
			numero.max = max(de.max, iz.max);
			return numero;

		}

	}
	else {
		numero.max = 0;
		numero.valor = 0;
		return numero;
	}
}
