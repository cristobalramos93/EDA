#include<iostream>
#include"bintree_eda.h"
using namespace std;
int main() {
	bintree<int> arbol = leerArbol(-1);
	vector<int> a;
	a = arbol.preorder();
	cout << a.at(0);
}