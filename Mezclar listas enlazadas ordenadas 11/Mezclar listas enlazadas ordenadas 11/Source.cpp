#include<iostream>

#include"Header.h"
using namespace std;
//void mostrar(cola * colaOriginal);
class cola : queue<int> {

public:


	void insertar1(int num) {
		push(num);
	}
	void insertar2(int num) {
		this->push(num);
	}

	void mezclar(cola * colaOriginal, cola * otra) {
		int cont = 0;
		Nodo * aux = colaOriginal->prim;
		Nodo * actual = this->prim;
		Nodo * aux2 = this->prim;

		

		for (int i = 0; i < colaOriginal->size(); i++) {
			aux = colaOriginal->prim;
			aux->sig = aux2;

		}
	}

	void mostrar(cola * colaOriginal,cola * otra) {
		for (int i = 0; i < colaOriginal->size(); i++) {
			cout << colaOriginal->prim->elem;
			colaOriginal->prim = colaOriginal->prim->sig;
		}

		for (int i = 0; i < otra->size(); i++) {
			cout << otra->prim->elem;
			otra->prim = otra->prim->sig;
		}
	}
};

int main() {
	cola * colaOriginal = new cola();
	cola * colaOriginal2 = new cola();

	int casos;
	cin >> casos;
	int num;
	cin >> num;
	if (num != 0) colaOriginal->insertar1(num);
	cin >> num;
	for (int i = 0; i < casos; i++) {

		while (num != 0) {
			colaOriginal->insertar1(num);
			cin >> num;
		}
		cin >> num;
		if (num != 0) colaOriginal2->insertar2(num);
		cin >> num;
		while (num != 0) {
			colaOriginal2->insertar2(num);
			cin >> num;
		}
		colaOriginal->mostrar(colaOriginal,colaOriginal2);
		//mezclar(colaOriginal);
	}
}