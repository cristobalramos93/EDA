#include<iostream>
#include"bintree_eda.h"
#include"lista_eda.h"
using namespace std;

template<typename T>
bool coinciden(const bintree<T> & a, const list<T> & pre) {
	bool coi = true;
	int cont = 0;
	comprueba(a, pre, coi, cont);
	if (coi) cout << "SI" << endl;
	else cout << "NO" << endl;

}
template<typename T>
void comprueba(const bintree<T> & a, const list<T> & pre, bool & coi, int & cont) {
	if (!a.empty()) {

		if (a.root() != pre[cont]) coi = false;
		cont++;
		comprueba(a, pre, coi, cont);

	}
}


int main() {
	//llenar arbol
	//llenar vecotr
	comprueba();
}