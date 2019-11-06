#include<iostream>
#include<string>
#include"bintree_eda.h"
using namespace std;
int resuelve(bintree<string> arbol, int & buenPadre, int & malPadre, int & altura);
int main() {
	string a = ".";
	int buenPadre = 0;
	int malPadre = 0;
	int altura = 0;
	bintree<string> arbol = leerArbol(a);
	resuelve(arbol, buenPadre, malPadre, altura);
	cout << buenPadre;
}

int resuelve(bintree<string> arbol, int & buenPadre, int & malPadre, int & altura) {
	if (!arbol.empty()) {

		int iz = (resuelve(arbol.left(),buenPadre,malPadre,altura));
		int de = resuelve(arbol.right(),buenPadre,malPadre,altura);
		cout << arbol.root();
		if (iz != 0 || de != 0) {
			if (abs(iz - de) <= 1) {
				buenPadre++;
			}
			else malPadre++;
		}

		return 1 + max(iz,de);
	}
	else return 0;
}