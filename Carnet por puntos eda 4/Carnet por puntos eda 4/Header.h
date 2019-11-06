#include<iostream>
#include"hashmap_eda.h"
using namespace std;

class carnet {
public:

	void nuevo(string dni) {
		if (carnet.count(dni) == 1) throw domain_error("ERROR: Conductor duplicado.");
		carnet[dni] = 15;
	}

	void quitar(string dni, int puntos) {
		if (carnet.count(dni) == 0) throw domain_error("ERROR: Conductor inexistente.");
			if ((carnet[dni] - puntos) <= 0) carnet[dni] = 0;
			else carnet[dni] = carnet[dni] - puntos;
	}

	void consultar(string dni) {
		if (carnet.count(dni) == 0) throw domain_error("ERROR: Conductor inexistente.");
		cout << "Puntos de DNI: " << carnet[dni] << endl;
	}

	void cuantos_con_puntos(int puntos) {
		int con = 0;
		if (puntos >= 0 && puntos <= 15) {
			auto it = carnet.begin();
			for (int i = 0; carnet.size(); i++) {
				if (it->valor == puntos) con++;
			}
		}
		else throw domain_error("ERROR: Puntos no validos.");

		cout << "Con " << puntos << " puntos hay " << con << endl;
	}



private:
	unordered_map<string, int> carnet;

};