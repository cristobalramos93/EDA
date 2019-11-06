#include<iostream>
#include"hashmap_eda.h"
#include"treemap_eda.h"
#include"list_eda.h"
using namespace std;

int main() {
	int casos;
	cin >> casos;
	while (casos != 0) {

		int numActores;
		int tiempoEnPelicula;
		string peli;
		string actor;
		unordered_map<string, int> peliculas;
		unordered_map<string, int> orden;
		map<string, int> actores;
		unordered_map < string, list<string>> actoresEnPelicula;
		unordered_map<string, unordered_map<string, int>> tiempoActorEnPeli;
		for (int i = 0; i < casos; i++) {
			cin >> peli;
			peliculas[peli] = 0;
			orden[peli] = 0;
			cin >> numActores;
			for (int n = 0; n < numActores; n++) {
				cin >> actor;
				actores[actor] = 0;
				cin >> tiempoEnPelicula;
				tiempoActorEnPeli[actor][peli] = tiempoEnPelicula;
				actoresEnPelicula[peli].push_back(actor);
			}

		}
		int cont = 0;
		int x;
		cin >> x;
		for (int i = 0; i < x; i++) {
			cin >> peli;
			peliculas[peli]++;
			orden[peli] = cont;
			cont++;
			for (int n = 0; n < actoresEnPelicula[peli].size(); n++) {
				actores[actoresEnPelicula[peli].at(n)] += tiempoActorEnPeli[actoresEnPelicula[peli].at(n)][peli];
			}

		}
		int max = 0;
		string peliMax;
		auto it = peliculas.begin();
		for (int i = 0; i < peliculas.size(); i++) {
			if (it->valor > max) {
				peliMax = it->clave;
				max = it->valor;
			}
			else if (it->valor == max) {
				if (orden[peliMax] < orden[it->clave]) {
					peliMax = it->clave;
					max = it->valor;
				}
			}
			++it;
		}


		auto it2 = actores.begin();
		int tiempoMaximo = 0;
		for (int i = 0; i < actores.size(); i++) {
			if (it2->valor > tiempoMaximo) {
				tiempoMaximo = it2->valor;
			}
			++it2;
		}

		cout << max << " " << peliMax << endl;
		cout << tiempoMaximo << " ";


		 it2 = actores.begin();
		for (int i = 0; i < actores.size(); i++) {
			if (it2->valor == tiempoMaximo) {
				cout << it2->clave << " ";
			}
			++it2;
		}

		cout << endl;
		cin >> casos;
	}
}