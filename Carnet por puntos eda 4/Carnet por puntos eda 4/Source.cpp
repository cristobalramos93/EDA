#include<iostream>
#include"hashmap_eda.h"
#include"list_eda.h"
using namespace std;

class carnet {
public:

	void nuevo(string dni) {
		if (carnet.count(dni) == 1) throw domain_error("Conductor duplicado");
		p pe;
		por_puntos[15].push_front(dni);
		pe.puntos = 15;
		pe.orden = por_puntos[15].begin();
		carnet[dni] = pe;
	}

	void quitar(string dni, int puntos) {
		if (carnet.count(dni) == 0) throw domain_error("Conductor inexistente");
		if (puntos != 0 && carnet[dni].puntos != 0) {
			int x = carnet[dni].puntos - puntos;
			por_puntos[carnet[dni].puntos].erase(carnet[dni].orden);//lo borro de la lista de puntos
			if (x < 0) {
				x = 0;
			}
			por_puntos[x].push_front(dni);
			p pe;
			pe.orden = por_puntos[x].begin();
			pe.puntos = x;
			carnet[dni] = pe;
		}
	}


	void recuperar(string dni, int puntos) {
		if (carnet.count(dni) == 0) throw domain_error("Conductor inexistente");
		if (puntos != 0 && carnet[dni].puntos != 15) {
			int x = carnet[dni].puntos + puntos;
			if (x > 15) x = 15;
			por_puntos[carnet[dni].puntos].erase(carnet[dni].orden);
			por_puntos[x].push_front(dni);
			p pe;
			pe.puntos = x;
			pe.orden = por_puntos[x].begin();
			carnet[dni] = pe;
		}
	}

	void consultar(string dni) {
		if (carnet.count(dni) == 0) throw domain_error("Conductor inexistente");
		cout << "Puntos de " <<dni << ": "  << carnet[dni].puntos << endl;
	}

	void cuantos_con_puntos(int puntos) {//ahora el coste es constante
		if (puntos >= 0 && puntos <= 15) {

			cout << "Con " << puntos << " puntos hay " << por_puntos[puntos].size() << endl;
		}
		else throw domain_error("Puntos no validos");

		
	}


	   void lista_por_puntos(int puntos) {
		if (puntos >= 0 && puntos <= 15) {
			cout << "Tienen " << puntos << " puntos:";
			auto it = por_puntos[puntos].begin();
			for (int i = 0; i < por_puntos[puntos].size(); i++) {
				cout << " "<<it.operator*();//prueba
				++it;
			}
			cout << endl;
		}
		else throw domain_error("Puntos no validos");
	}


private:

	typedef struct p {
		int puntos;
		list<string>::iterator orden;
	};
	unordered_map<string, p> carnet; //cada dni, cuantos puntos tiene y donde esta

	unordered_map<int,list<string>> por_puntos; //lista de dnis por puntos
};

int main() {
	string palabra;
	cin >> palabra;
	while (cin) {
		carnet a = carnet();

		string palabra2;
		int num;
		while (palabra != "FIN") {
			try {

				if (palabra == "nuevo") {
					cin >> palabra2;
					a.nuevo(palabra2);
				}
				else if (palabra == "cuantos_con_puntos") {
					cin >> num;
					a.cuantos_con_puntos(num);
				}
				else if (palabra == "quitar") {
					cin >> palabra2;
					cin >> num;
					a.quitar(palabra2, num);
				}
				else if (palabra == "recuperar") {
					cin >> palabra2;
					cin >> num;
					a.recuperar(palabra2, num);
				}
				else if (palabra == "consultar") {
					cin >> palabra2;
					a.consultar(palabra2);
				}
				else if (palabra == "lista_por_puntos") {
					cin >> num;
					a.lista_por_puntos(num);
				}
			}
			catch (domain_error e) {
				cout << "ERROR: " << e.what() << "\n";
			}

			cin >> palabra;
		}
		cout << "---" << endl;
		cin >> palabra;
	}
}