#include<iostream>
#include"queue_eda.h"
using namespace std;

class cola : queue<int> {
public:
	void insert(int v) {
		push(v);
	}

	void resuelve() {
		cola * ac2 = new cola();
		int num;
		cin >> num;
		while (num != 0) {
			ac2->insert(num);
			cin >> num;
		}
		Nodo * pri = nullptr;
		Nodo * seg = nullptr;
		Nodo * ter = nullptr;
		Nodo * aux = nullptr;

		if (this->nelems == 0) {
			aux = ac2->prim;
			
		}
		else if (ac2->nelems == 0) {
			aux = this->prim;
		}

		else {
			if (this->prim < ac2->prim) {
				pri = this->prim;
				seg = pri->sig;
				ter = ac2->prim;
				aux = this->prim;
			}
			else {
				pri = ac2->prim;
				seg = pri->sig;
				ter = this->prim;
				aux = ac2->prim;
			}

			while (seg != nullptr && ter != nullptr) {
				if (seg->elem < ter->elem) {
					pri = seg;
					seg = seg->sig;
				}
				else {
					pri->sig = ter;
					pri = ter;
					ter = seg;
					seg = pri->sig;
				}
			}
			if (seg == nullptr) {
				pri->sig = ter;
			}
			else pri->sig = seg;



		}

		while (aux != nullptr) {
			cout << aux->elem << " ";
			aux = aux->sig;
		}
		cout << endl;
		

	}


};


int main() {
	int casos;
	cin >> casos;
	for(int i = 0; i < casos; i++){
	cola * ac = new cola();
	cola * ac2 = new cola();

	int num;
	cin >> num;
	while (num != 0) {
		ac->insert(num);
		cin >> num;
	}
	ac->resuelve();
	}


}