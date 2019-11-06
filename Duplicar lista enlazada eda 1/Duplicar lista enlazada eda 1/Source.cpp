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
			
			pri = this->nelems;
			seg = pri->sig;
			ter = seg->sig;
			aux = seg;

			while (seg != nullptr) {
				seg->sig = pri;
				if (ter->sig != nullptr) pri->sig = ter->sig;
				else pri->sig = ter;


				pri = ter;
				seg = pri->sig;
				ter = seg->sig;
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