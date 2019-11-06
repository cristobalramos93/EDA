#include<iostream>
#include"queue_eda.h"
using namespace std;

class cola : queue<int> {
public:
	void insert(int v) {
		push(v);
	}

	void resuelve() {
		Nodo * pri = this->prim;
		Nodo * seg = pri->sig;
		Nodo * aux = prim;

		while (seg != nullptr) {
			if (seg->sig == nullptr) {
				pri->sig = nullptr;
				seg = nullptr;
			}
			else {
				pri->sig = seg->sig;
				pri = pri->sig;
				seg = pri->sig;
			}
		}


		while (aux != nullptr) {
			cout << aux->elem << " ";
			aux = aux->sig;
		}
	}

	


	};


	int main() {
		cola * ac = new cola();

		int num;
		cin >> num;
		while (num != 0) {
			ac->insert(num);
			cin >> num;
		}
		ac->resuelve();



	}