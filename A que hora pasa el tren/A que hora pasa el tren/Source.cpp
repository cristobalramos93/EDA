#include<iostream>
#include"queue_eda.h"
using namespace std;
class queueExa : queue<int> {
public:
	void insertar(int n) {
		push(n);
	}


	void resuelve() {
		Nodo * n = this->prim;
		Nodo * aux = n->sig;
		/*
		cout << n->elem << endl;
		cout << aux->elem;
		cout << aux->sig->elem;
		*/

		n->sig = aux->sig;
		aux->sig = n;
		cout << n->elem << endl;
		cout << aux->elem << endl;



	}
};



int main() {
	int elementos;
	cin >> elementos;
	int numero;
	while (elementos != 0) {
		queueExa * cola = new queueExa();
		for (int i = 0; i < elementos; i++) {
			cin >> numero;
			cola->insertar(numero);
		}
		cola->resuelve();

		cin >> elementos;
	}
}