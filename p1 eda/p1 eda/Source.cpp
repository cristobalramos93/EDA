#include<iostream>
#include"queue_eda.h"
using namespace std;

class original : queue<int> {
public:
	void insertar(int n) {
		push(n);
	}

	void resolver(int s) {
		Nodo * actual = this->prim;
		Nodo * aux = actual->sig;
		Nodo * ult = aux->sig;

		for (int i = 0; i < s / 2; i++) {
			if (ult->sig != NULL) {
				actual->sig = ult->sig;
			}
			else actual->sig = ult;
			aux->sig = actual;
				actual = ult;
				aux = ult->sig;
				ult = aux->sig;
			
		}


		for (int i = 0; i < this->size(); i++) {
			cout << this->prim;
		}
	}

};


int main() {

	original * cola = new original();
	int n;
	cin >> n;
	int num;
	while (n != 0) {
		for (int i = 0; i < n; i++) {
			cin >> num;
			cola->insertar(num);
		}
		cola->resolver(n);

		



		cin >> n;
	}

}