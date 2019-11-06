
#include <iostream>
using namespace std;



typedef struct Nodo {
	int valor;
	Nodo *siguiente;
};

void algoritmo(Nodo *cola, int pasos, int n) {
	for (int i = 0; i < n; i++) {
		cola = cola->siguiente;
	}
	Nodo * victima;
	while (cola->siguiente != cola) {

		for (int i = 0; i < pasos; i++) {
			cola = cola->siguiente;
		}
		victima = cola->siguiente;
		cola->siguiente = victima->siguiente;
		delete[]victima;

	}
	cout << cola->valor << endl;
	delete[] cola;
}


int main() {

	int n, pasos;
	cin >> n >> pasos;
	while (n != 0 && pasos != 0) {
		Nodo *actual = new Nodo;
		actual->valor = 1;
		actual->siguiente = NULL;
		Nodo *ultimo = actual;
		for (int i = 2; i <= n; i++) {
			Nodo * nuevo = new Nodo;
			nuevo->valor = i;
			ultimo->siguiente = nuevo;
			ultimo = nuevo;
		}
		ultimo->siguiente = actual;
		actual = ultimo;
		algoritmo(actual, pasos,n);
		cin >> n >> pasos;
	}
}
