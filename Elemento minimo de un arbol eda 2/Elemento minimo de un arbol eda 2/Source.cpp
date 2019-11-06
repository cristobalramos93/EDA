#include<iostream>
#include<string>
#include"bintree_eda.h"
using namespace std;
string resuelvePalabra(bintree<string> arbol);
int resuelve(bintree<int> arbol2);
template<typename T>
bintree<T> arbol;
int main() {

	string tipo;
	cin >> tipo;
	while (cin) {

		if (tipo == "N") {
			bintree<int> arbol = leerArbol(-1);
			int sol = resuelve(arbol);
			cout << sol << endl;
		}
		else {
			string centinela = "#";
			bintree<string> arbol = leerArbol(centinela);
			string sol = resuelvePalabra(arbol);
			cout << sol << endl;
		}
		cin >> tipo;
	}
		
}

int resuelve(bintree<int> arbol2) {
	if (!arbol2.empty()) {
		int iz = resuelve(arbol2.left());
		int de = resuelve(arbol2.right());
		return min(iz, de, arbol2.root());
	}
	else return 0;
	
}

string resuelvePalabra(bintree<string> arbol) {
	if (!arbol.empty()) {
		string iz = resuelvePalabra(arbol.left());
		string de = resuelvePalabra(arbol.right());
		return min(iz, de, arbol.root());
	}
	else return "z";
}



