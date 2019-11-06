#include<iostream>
#include"queue_eda.h"
using namespace std;

class cola : queue<int> {
public:
	void insert(int v) {
		push(v);
	}

	void resuelve(int fin, int pri) {
		Nodo * prim = this->prim;
		Nodo * seg = nullptr;
		Nodo * ant = nullptr;
		Nodo * ult = nullptr;
		Nodo * term = nullptr;
		Nodo * aux = prim;
		Nodo * aux2 = aux;


		if(fin == this->nelems){
		
		}


		for (int i = 1; i < fin + pri -1; i++) {
			if (i == pri - 1) {
				prim = aux;
			}
			if (i == fin + pri - 2) ant = aux;
			aux = aux->sig;
		}
		aux = this->prim;
		seg = prim->sig;
		ult = ant->sig;
		prim->sig = ult;
		term = ult->sig;



		int n =0;
		aux = seg;
		for (int j = 0; j < fin-1; j++) {
			for (int i = 0; i < fin -2- n; i++) {
				aux = aux->sig;

			}

			ant = aux;
			ult = ant->sig;
			ult->sig = ant;
			n++;
			aux = seg;
		}


		ant->sig = term;
		
		for (int i = 0; i < this->nelems; i++) {
			cout << aux2->elem << " ";
			aux2 = aux2->sig;
		}


	}


};


int main() {
	cola * ac = new cola();

	int num;
	cin >> num;
	int principio;
	int finale;
	cin >> principio;
	cin >> finale;
	int valor;
	for (int i = 0; i < num; i++) {
		cin >> valor;
		ac->insert(valor);
	}
	ac->resuelve(finale,principio);



}