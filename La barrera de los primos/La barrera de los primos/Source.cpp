#include<iostream>
#include"bintree_eda.h"
using namespace std;


typedef struct tSol {
	int num;
	int al;
};
tSol resuelve(bintree<int> arbol);
int main() {
	int casos;
	cin >> casos;
	for (int i = 0; i < casos; i++) {
		bintree<int> arbol = leerArbol(-1);
		tSol num;
		num = resuelve(arbol);
		if (num.num != -1)cout << num.num << " " << num.al << endl;
		else cout << "NO HAY" << endl;
	}
}

tSol resuelve(bintree<int> arbol) {
	tSol sol;
	if (!arbol.empty()) {

		tSol iz = resuelve(arbol.left());
		tSol de = resuelve(arbol.right());

		bool primo = true;
		for (int i = 2; i < arbol.root() - 1; i++) {
			if (arbol.root() % i == 0) primo = false;
		}

		if (!primo) { //si no es primo
			if (arbol.root() % 7 == 0) {//si es multiplo de 7
				sol.num = arbol.root();
				sol.al = 1;
				return sol;
			}
			else {//si no es primo ni multiplo de 7
				if (iz.num != -1 && de.num != -1) {//si me llegan dos valores correctos
					if (iz.al <= de.al) {//si el izquierdo esta mas arriba
						sol.num = iz.num;
						sol.al = iz.al + 1;
						return sol;
					}
					else {
						sol.num = de.num;
						sol.al = de.al + 1;
						return sol;
					}
				}
				else if (iz.num != -1) {//si mi hijo izquierdo es valido
					sol.num = iz.num;
					sol.al = iz.al + 1;
					return sol;
				}
				else if (de.num != -1) {//si mi hijo derecho es valido
					sol.num = de.num;
					sol.al = de.al + 1;
					return sol;
				}
				else {
					sol.num = -1;
					sol.al = 0;
					return sol;
				}

			}
		}
		else {//si es primo
			sol.al = 0;
			sol.num = -1;
			return sol;
		}
	}
	else {
		sol.al = 0;
		sol.num = -1;
		return sol;
	}
}