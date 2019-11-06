#include<iostream>
#include"bintree_eda.h"
using namespace std;
int resuelve(bintree<char> arbol, int & nodos, int & hojas, int & altura);
int main() {
	int casos;
	cin >> casos;
	for (int i = 0; i < casos; i++) {
		bintree<char> arbol = leerArbol('.');
		int nodos = 0, altura = 0, hojas = 0;
		altura = resuelve(arbol, nodos, hojas, altura);
		cout << nodos << " " << hojas << " " << altura << endl;

	}
}

int resuelve(bintree<char> arbol, int & nodos, int & hojas, int & altura) {
	if (!arbol.empty()) {
		int iz = resuelve(arbol.left(), nodos, hojas, altura);
		int de = resuelve(arbol.right(), nodos, hojas, altura);
		if(arbol.left().empty() && arbol.right().empty())hojas++;
		nodos++;
		return 1 + max(iz, de);

	}
	else return 0;
}