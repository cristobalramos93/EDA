#include<iostream>
#include<vector>
#include"bintree_eda.h"
using namespace std;

int main() {
	bintree<char> arbol = leerArbol('.');
}

vector<int> resuelve(bintree<char> arbol) {
	vector<int> v;
	if (!arbol.empty()) {

		vector<int> iz = resuelve(arbol.left());
		vector<int> de = resuelve(arbol.right());
		if (iz.back() == 0 && de.back() == 0) {
			v.push_back(1);
			return v;
		}

		if (iz.back() == 1) {
			iz.back() = 2;
		}
		
	}
	else {
		v.push_back(0);
		return v;
	}
}