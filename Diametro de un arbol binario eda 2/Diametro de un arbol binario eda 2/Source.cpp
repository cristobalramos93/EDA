#include<iostream>
#include"bintree_eda.h"
using namespace std;
int resuelve(bintree<char> arbol, int & maxi, int & maximo);
int main() {
	int casos;
	cin >> casos;
	for (int i = 0; i < casos; i++) {
		int maximo = 0;
		bintree<char> arbol = leerArbol('.');
		int a = 0;
		resuelve(arbol, a,maximo);
		cout << maximo<< endl;
	}
}



int resuelve(bintree<char> arbol, int & maxi, int & maximo) {
	if (!arbol.empty()) {
		int iz = resuelve(arbol.left(), maxi,maximo);
		int de = resuelve(arbol.right(), maxi, maximo);
		maxi = max(iz, de);
		if (iz + de >= maximo) maximo = iz + de + 1;
		return  maxi + 1;
	}
	else return 0;
}