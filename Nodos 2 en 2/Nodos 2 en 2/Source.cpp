#include<iostream>
#include"queu_eda.h"
using namespace std;

class cola : queue<int> {
public:
	void insert(int v) {
		push(v);
	}

	void resuelve() {
		Nodo * pri = this->prim;
		Nodo * seg = nullptr;
		Nodo * ter = nullptr;
		Nodo * aux = nullptr;
		if (this->nelems == 1) {
			pri = this->prim;
			aux = pri;
		}

		else if (this->nelems == 2) {
			pri = this->prim;
			seg = prim->sig;
			seg->sig = pri;
			aux = seg;
		}
		else {

			pri = this->prim;
			seg = pri->sig;
			ter = seg->sig;
			aux = seg;

			while (seg != nullptr) {
				seg->sig = pri;
				if (ter != nullptr && seg != nullptr){
					pri->sig = ter->sig;
					if (pri->sig == nullptr) {
						pri->sig = ter;
					}
					pri = ter;
					seg = pri->sig;
					ter = seg->sig;
					}
				else if(ter == nullptr) {
					pri->sig = nullptr;
					seg = pri->sig;
				}
				

			}

		}

		while (aux != nullptr) {
			cout << aux->elem << " ";
			aux = aux->sig;
		}
		cout << endl;

	}

	};


	int main() {
		cola * ac = new cola();
		int num;
		int casos;
		cin >> casos;
		for (int i = 0; i < casos; i++) {
			cin >> num;
			ac->insert(num);
		}
		ac->resuelve();



	}