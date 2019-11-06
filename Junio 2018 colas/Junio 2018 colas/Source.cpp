#include<iostream>
#include"Header.h"
using namespace std;

class colaExa : queue<int> {
public:
	void insertar(int n) {
		push(n);
	}


	void mover(int pos, int lon) {
		Nodo * orig;
		orig = this->prim;
		Nodo * aux;
		Nodo * ulti;
		aux = this->prim;
		for (int i = 0; i < pos-1; i++) {
			orig = orig->sig;
		}
		aux = orig->sig;
		ulti = aux;
		for (int i = 0; i < lon; i++) {
			ulti = ulti->sig;
		}
	}




};

int main() {

	colaExa * cola = new colaExa();
	int nu;
	for (int i = 0; i < 5; i++) {
		cin >> nu;
		cola->insertar(nu);
	}
	cola->mover(4);
}