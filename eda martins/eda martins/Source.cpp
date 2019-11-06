/**
Este programa lee árboles de la entrada estándar,
codificados de acuerdo con las siguientes reglas:
(1) El árbol vacío se codifica como #
(2) Los árboles simples se codifican como [v], con
	v el valor del nodo
(3) Los árboles complejos se codifican como (IvD),
	con I la codificación del hijo izquierdo,
	v el valor de la raíz, y D la codificación
	del hijo derecho.
Para cada árbol leído, escribe en la salida estándar
el número de nodos singulares de dicho árbol.

Algunos casos representativos:

#
[0]
[5]
(([4]3[-3])1[-4])

-El primero representa el árbol vacío. Al no tener nodos,
un árbol vacío tiene 0 nodos sigulares.
-El segundo representa un árbol con un único nodo, cuyo valor
es 0. Dicho nodo es singular, ya que: (i) como no tiene
ascestros, la suma de los ancestros es 0, (ii) como no
tiene descendientes, la suma de los descendientes es 0.
-El tercero representa otro árbol con un único nodo, cuyo
valor es 5. Por la misma razón que en el segundo ejemplo,
este nodo es singular.
-El cuarto representa el siguiente árbol:

		   1
		 /  \
		  3  -4
		 / \
		4  -3

Este árbol tiene 2 nodos sigulares: la raíz, y la raíz del hijo
izquierdo.

Por tanto, la salida del programa para estos casos será:

0
1
1
2

*/


#include "Header.h"
#include <string>
#include<iostream>

void singularesAux(bintree<int> a, int& ancestros, int& descendientes, int& singu) {
	if (a.empty()) {
		descendientes = 0;
	}
	else {
		int ancestrosAux = ancestros + a.root();
		int descendientesIz = 0, descendientesDer = 0;
		singularesAux(a.left(), ancestrosAux, descendientesIz, singu);
		singularesAux(a.right(), ancestrosAux, descendientesDer, singu);
		descendientes = descendientesIz + descendientesDer;
		if (ancestros == descendientes)
			singu++;
		descendientes += a.root();
	}
}

unsigned int numero_singulares(bintree<int> a) {
	int ancestros = 0, descendientes = 0, singu = 0;
	singularesAux(a, ancestros, descendientes, singu);
	return singu;
}

bintree<int> lee_arbol(istream& in){
	char c;
	in >> c;
	switch (c) {
	case '#': return bintree<int>();
	case '[': {
		int raiz;
		in >> raiz;
		in >> c;
		return bintree<int>(raiz);
	}
	case '(': {
		bintree<int> iz = lee_arbol(in);
		int raiz;
		in >> raiz;
		bintree<int> dr = lee_arbol(in);
		in >> c;
		return bintree<int>(iz, raiz, dr);
	}
	default: return bintree<int>();
	}
}


int main() {
	int solucion = 0;
	bintree<int> arbol;
	while (cin.peek() != EOF) {
		cout << numero_singulares(lee_arbol(cin), solucion);
		string resto_linea;
		getline(cin, resto_linea);
		if (cin.peek() != EOF) cout << endl;
	}
	return 0;
}


