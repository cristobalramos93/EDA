/**
Este programa lee �rboles de la entrada est�ndar,
codificados de acuerdo con las siguientes reglas:
(1) El �rbol vac�o se codifica como #
(2) Los �rboles simples se codifican como [v], con
	v el valor del nodo
(3) Los �rboles complejos se codifican como (IvD),
	con I la codificaci�n del hijo izquierdo,
	v el valor de la ra�z, y D la codificaci�n
	del hijo derecho.
Para cada �rbol le�do, escribe en la salida est�ndar
el n�mero de nodos singulares de dicho �rbol.

Algunos casos representativos:

#
[0]
[5]
(([4]3[-3])1[-4])

-El primero representa el �rbol vac�o. Al no tener nodos,
un �rbol vac�o tiene 0 nodos sigulares.
-El segundo representa un �rbol con un �nico nodo, cuyo valor
es 0. Dicho nodo es singular, ya que: (i) como no tiene
ascestros, la suma de los ancestros es 0, (ii) como no
tiene descendientes, la suma de los descendientes es 0.
-El tercero representa otro �rbol con un �nico nodo, cuyo
valor es 5. Por la misma raz�n que en el segundo ejemplo,
este nodo es singular.
-El cuarto representa el siguiente �rbol:

		   1
		 /  \
		  3  -4
		 / \
		4  -3

Este �rbol tiene 2 nodos sigulares: la ra�z, y la ra�z del hijo
izquierdo.

Por tanto, la salida del programa para estos casos ser�:

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


