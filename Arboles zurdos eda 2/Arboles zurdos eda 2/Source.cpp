
#include<iostream>
#include"bintree_eda.h"
using namespace std;
int resuelve(bintree<char> arbol);
int main() {
	int casos;
	cin >> casos;
	for (int i = 0; i < casos; i++) {
		bintree<char> arbol = leerArbol('.');
		int a = resuelve(arbol);
		if (a == -1) cout << "NO" << endl;
		else cout << "SI" << endl;
	}
}

int resuelve(bintree<char> arbol) {
	if (!arbol.empty()) {
		int iz = resuelve(arbol.left());
		int de = resuelve(arbol.right());
		if (iz > (iz + de) / 2 && iz != -1 && de != -1 )  {
			return iz + de + 1;
		}
		else if (arbol.left().empty() && arbol.right().empty()) {
			return 1;
		}
		else return -1;
	}
	else return 0;


}

