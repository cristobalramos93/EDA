#include<iostream>
#include<string>
#include"bintree_eda.h"
using namespace std;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		bintree<int> arbol = leerArbol(0);
		int a = 0;
		int altura = buscarAltura(arbol, a);
		cout << altura << endl;
	}
}

int buscarAltura(bintree<int> arbol, int & altura) {
	int de = buscarAltura(arbol.left(), altura);
	int iz = buscarAltura(arbol.right(), altura);
	return 1 + max(iz, de);


}