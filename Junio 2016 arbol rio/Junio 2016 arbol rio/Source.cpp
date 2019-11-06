#include<iostream>
#include"bintree_eda.h"
int resuelve(bintree<int> arbol, int & solucion);

//rios examen

int main() {
	bintree<int> arbol = leerArbol(10);
	int sol = 0;
	int mostrar;
	mostrar = resuelve(arbol, sol);

}

int resuelve(bintree<int> arbol, int & solucion) {
	int devolver = 0;
	if (!arbol.empty()) {

		int iz = resuelve(arbol.left(),solucion);
		int de = resuelve(arbol.right(),solucion);

		if (arbol.root() + iz + de >= 3) {
			solucion++;
		}
		if (!arbol.left().empty() && !arbol.right().empty()) {
			if (iz == 0) iz = 1;
			if (de == 0) de = 1;
		}
		return arbol.root() + iz + de;

	}
	return 0;
}