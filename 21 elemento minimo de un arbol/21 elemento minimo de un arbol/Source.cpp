#include<iostream>
#include<string>
#include"Header.h"
using namespace std;


template <typename T>
void buscarMenor(bintree<T> arbol, T & menor) {
	if (!arbol.empty()) {
		menor = min(menor, arbol.root());//root es el valor del TAD
		 buscarMenor(arbol.left(), menor); //recursivo lado izquierdo
		 buscarMenor(arbol.right(), menor); //recursivo lado derecho

	}
}


int main() {
	while (!cin.fail()) {
		char linea;
		cin >> linea;
		if (linea == 'N') {
			bintree<int> arbol = leerArbol(-1);//menos es el final
			/*
			vector<int> recorrido = arbol.inorder();

			for (int i = 0; i < recorrido.size(); i++)
				cout << recorrido[i] << " "; //esto no se puede hacer, es para ver que funciona
			cout << endl;
			*/
			int menor = arbol.root();//igualamos el menor a la raiz
			buscarMenor(arbol, menor);
			cout << menor << endl;
		}
		else if (linea == 'P') {
			string vacio = "#";
			bintree<string> arbol = leerArbol(vacio);//menos es el final
			string menor = arbol.root();//igualamos el menor a la raiz
			buscarMenor(arbol, menor);
			cout << menor << endl;
		}
	}

	system("pause");
}
