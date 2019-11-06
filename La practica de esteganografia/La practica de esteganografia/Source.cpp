#include<iostream>
using namespace std;


typedef struct Nodo {
	int valor;
	Nodo * siguiente;
	};


void resuelveCaso(Nodo * actual, int numeros, int n);

int main() {
	int numeros, n;
	cin >> numeros >> n;
	while (numeros != 0 && n != 0) {
		Nodo * actual = new Nodo;
		cin >> actual->valor;
		Nodo * aux = new Nodo;

		
		for (int i = 1; i < numeros; i++) {
			Nodo * nuevo = new Nodo;
			cin >> nuevo->valor;
			aux->siguiente = nuevo;
			aux = nuevo;
			if (i == 1) actual->siguiente = aux;
		
		}
		/*
		for (int i = 0; i < numeros; i++) {
			cout << actual->valor << endl;
			actual = actual->siguiente;
		}
		*/
		resuelveCaso(actual, numeros, n);
		cin >> numeros >> n;


	}
	
}

void resuelveCaso(Nodo * actual, int numeros, int n) {
	Nodo * aux = new Nodo;
	int mayor = 0;
	for (int i = 0; i < (numeros - n + 1); i++) {
		aux = actual;//aux = 8
		for (int j = 0; j < n; j++) {
			if (actual->valor > mayor) mayor = actual->valor;
			actual = actual->siguiente;
		}
		actual = aux->siguiente; //actual = 5
		cout << mayor << " ";
		mayor = 0;

	}
}

