#include<iostream>
#include<string>
#include"bintree_eda.h"
using namespace std;
string resuelvePalabra(bintree<string> arbol);
int resuelve(bintree<int> arbol2);


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

int resuelve(bintree<int> arbol) {

	if (!arbol.empty()) {
		int iz = resuelve(arbol.left());
		int de = resuelve(arbol.right());
		int a = min(iz, de);
		return min(a, arbol.root());
	}
	else return 9999999;

}

string resuelvePalabra(bintree<string> arbol) {
	if (!arbol.empty()) {
		string iz = resuelvePalabra(arbol.left());
		string de = resuelvePalabra(arbol.right());
		string a = min(iz, de);
		return min(a, arbol.root());
	}
	else return "zzzzz";
}



