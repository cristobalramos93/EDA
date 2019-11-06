#include<iostream>
#include"Header.h"
using namespace std;

class cola : queue<int> {
public:

	void insertar(int elemento) {
		push(elemento);
	}
	bool empty2() {
		return empty();
	}

	int front2() {
		return front();
	}
	void pop2() {
		pop();
	}

	void insertar(cola * otra, int posicion) {
		if (posicion != 0) {
			Nodo * actual = this->prim;
			for (int i = 0; i < posicion - 1; i++) {
				actual = actual->sig;
			}
			Nodo * continuacion = actual->sig;
			actual->sig = otra->prim;
			otra->ult->sig = continuacion;
			this->nelems = this->nelems + otra->nelems;
		}
	}
};


int main() {
	while (cin) {
		int n, m, pos;
		cin >> n;
		cola * colaOriginal = new cola();
		while (n--) {
			int valor;
			cin >> valor;
			colaOriginal->insertar(valor);
		}
		cin >> m >> pos;
		cola * colaOtra = new cola();
		while (m--) {
			int valor;
			cin >> valor;
			colaOtra->insertar(valor);
		}
		colaOriginal->insertar(colaOtra, pos);

		while (!(colaOriginal->empty2())) {
			cout << colaOriginal->front2();
			colaOriginal->pop2();
		}
	}
	
}