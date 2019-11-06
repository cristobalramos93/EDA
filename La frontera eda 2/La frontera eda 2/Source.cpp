#include<iostream>
#include"bintree_eda.h"
using namespace std;
void resuelve(bintree<int> arbol);
int main() {
	int casos;
	cin >> casos;
	for (int i = 0; i < casos; i++) {
		bintree<int> arbol = leerArbol(-1);
		resuelve(arbol);
		cout << endl;
	}
}



void resuelve(bintree<int> arbol) {
	if (!arbol.empty()) {
		resuelve(arbol.left());
		resuelve(arbol.right());
		if (arbol.left().empty() && arbol.right().empty()) cout << arbol.root() << " ";
	}
}