#include<iostream>
#include"bintree_eda.h"
using namespace std;
int resuelve(bintree<int> arbol, int & maxi);

//excursionistas entrada/salida
int main() {
	int casos;
	cin >> casos;
	for (int i = 0; i < casos; i++) {
		bintree<int> arbol = leerArbol(-1);
		int numeros = 0;
		int num;
		num = resuelve(arbol, numeros);
		cout << numeros << " " << num << endl;
	}
}

int resuelve(bintree<int> arbol, int & maxi) {
	if (!arbol.empty()) {
		int iz = resuelve(arbol.left(),maxi);
		int de = resuelve(arbol.right(),maxi);
		if (iz != 0 && de != 0) {
			if (maxi == 0)maxi = 2;
			else maxi++;

		}
		//excursionistas = max(iz,de);
		return max(iz,de) + arbol.root();
	}
	else return 0;
}