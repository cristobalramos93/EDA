#include<iostream>
#include"bintree_eda.h"
using namespace std;
typedef struct tDiametro{
	int maximo;
	int valor;
};
tDiametro resuelve(bintree<char> arbol);
int main() {
	int casos;
	cin >> casos;
	for (int i = 0; i < casos; i++) {
		bintree<char> arbol = leerArbol('.');
		tDiametro diametro;
		diametro = resuelve(arbol);
		if (diametro.maximo == 0) cout << 0 << endl;
		else cout << diametro.maximo << endl;
	}
}

tDiametro resuelve(bintree<char> arbol) {
	tDiametro diametro;
	if (!arbol.empty()) {

		tDiametro iz = resuelve(arbol.left());
		tDiametro de = resuelve(arbol.right());
			
			diametro.valor = 1 + max(iz.valor,de.valor);
			diametro.maximo = max(iz.maximo, de.maximo);
			if (iz.valor + de.valor >= diametro.maximo) {
				diametro.maximo = iz.valor + de.valor +1 ;
			}
			return diametro;
	}
	else {
		diametro.maximo = 0;
		diametro.valor = 0;
		return diametro;
	}
}