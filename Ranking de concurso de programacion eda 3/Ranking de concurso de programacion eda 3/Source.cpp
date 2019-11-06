#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include"treemap_eda.h"
using namespace std;

//33 RANKING DE UN CONCURSO DE PROGRAMACION

int main() {
	int casos;
	cin >> casos;
	typedef struct {
		string ejercicio;
		int tiempo;
		bool correcto;
	}tEjercicios;
	tEjercicios ejercicio;
	string linea;
	string palabra;
	string nombre;
	string juego;
	int t;
	string resultado;

	for (int j = 0; j < casos; j++) {
		map<string, vector<tEjercicios>> mapa;
		cin >> nombre;
		while (nombre != "FIN") {
			cin >> juego;
			cin >> t;
			cin >> resultado;
				bool jugado = false;
				for (int i = 0; i < mapa[nombre].size(); i++) {//recorro todos sus juegos
					if (mapa[nombre][i].ejercicio == juego) {
						jugado = true;
						if (mapa[nombre][i].correcto == false) {
							if (resultado == "AC") {//si es corecto
								mapa[nombre][i].correcto = true;
								mapa[nombre][i].tiempo += t;
							}
							else {//si no es correcto
								mapa[nombre][i].tiempo += 20;
							}
						}
					}
				}
				if (!jugado) {//si es la primera vez que juega a ese juego
					if (resultado == "AC") {
						ejercicio.correcto = true;
						ejercicio.tiempo = t;
						ejercicio.ejercicio = juego;
						mapa[nombre].push_back(ejercicio);
					}
					else {
						ejercicio.correcto = false;
						ejercicio.tiempo = 20;
						ejercicio.ejercicio = juego;
						mapa[nombre].push_back(ejercicio);

					}
				}
			cin >> nombre;
		}

		map<string, vector<tEjercicios>> ::iterator iterador = mapa.begin();
		while (!mapa.empty()) {
			int ti = 0;
			int eje = 0;
			int tiMax = 0;
			int ejeMax = 0;
			string nombre ;
			string nombreMax = "zzzzzzz";
			for (int i = 0; i < mapa.size(); i++) {
				for (int n = 0; n < iterador->valor.size(); n++) {//recorro los juegos del equipo y me quedo con los que ha acertado
					nombre = iterador->clave;
					if (iterador->valor[n].correcto == true) {
						eje++;
						ti += iterador->valor[n].tiempo;
					}
				}
				if (eje > ejeMax) {
					ejeMax = eje;
					tiMax = ti;
					nombreMax = nombre;
				}
				else if (eje == ejeMax) {
					if (ti < tiMax) {
						ejeMax = eje;
						tiMax = ti;
						nombreMax = nombre;
					}
					else if (ti == tiMax) {
						if (mapa.size() == 1) {
							ejeMax = eje;
							tiMax = ti;
							nombreMax = nombre;
						}
						else if (nombre < nombreMax) {
							ejeMax = eje;
							tiMax = ti;
							nombreMax = nombre;
						}
					}
				}
				ti = 0;
				eje = 0;
				++iterador;
			}

			cout << nombreMax << " " << ejeMax << " " << tiMax << endl;
			tiMax = 0;
			ejeMax = 0;
			mapa.erase(nombreMax);
			iterador = mapa.begin();
			nombreMax = "zzzzzz";

		}
		cout << "----" << endl;
	}
}