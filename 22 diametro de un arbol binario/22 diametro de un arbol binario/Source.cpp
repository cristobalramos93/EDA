#include<iostream>
#include<string>
#include"Header.h"
using namespace std;
int diametro(bintree<char> arbol, int & optimo);


int main() {
	int n;
	cin >> n;
	while (n--) {
		char vacio = '.';
		bintree<char> arbol = leerArbol(vacio);
		int optimo = 0;
		diametro(arbol, optimo);
		cout << optimo << endl;
 	}
	system("pause");
}



int diametro(bintree<char> arbol, int & optimo) {
	if (arbol.empty()) {
		return 0;
	}
	else {
		int izquierdo = diametro(arbol.left(), optimo);
		int derecho = diametro(arbol.right(), optimo);
		optimo = max(optimo, izquierdo + derecho + 1);
		return 1 + max(izquierdo, derecho);
	}
	
}