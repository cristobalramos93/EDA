#include<iostream>
#include"hashmap_eda.h"
#include"treemap_eda.h"
using namespace std;

class autoescuela {
public:

	void alta(string a, string p) {
		if (alumno.count(a) == 0) {//si es nuevo
			alumno[a] = p;
			profe[p][a] = 0;
		}
		else {//si es un cambio de profesor
			profe[p][a] = profe[alumno[a]][a];
			profe[alumno[a]].erase(a);
			alumno[a] = p;
		}
	}

	bool es_alumno(string a, string p) {
		if (alumno[a] == p)return true;
		else return false;
	}

	int puntuacion(string a) {
		return profe[alumno[a]][a];
	}

	void actualizar(string a, int n) {
		profe[alumno[a]][a] += n;
	}

	vector<string> examen(string p, int n){
		vector<string> aaa;
		map<string, int> aux;
		aux = profe[p];
		auto it = aux.begin();
		while (it != aux.end()) {
			if (profe[p][it->clave] >= n) {
				aaa.push_back(it->clave);
			}
			++it;
		}
		return aaa;
	}

	void aprobar(string a) {
		profe[alumno[a]].erase(a);
		alumno.erase(a);
	}

private:
	typedef struct tAlumno {
		string nombre;
		int puntos;
	};

	unordered_map<string, string> alumno;
	unordered_map<string, map<string, int>> profe;
};


int main() {
	string acaba;
	cin >> acaba;
	while (cin) {
		autoescuela a;
		string sal;
		string profe;
		string alumno;
		int nota;
		while (acaba != "FIN") {
			try {
				if (acaba == "alta") {
					cin >> alumno;
					cin >> profe;
					a.alta(alumno, profe);
				}
				else if (acaba == "es_alumno") {
					cin >> alumno;
					cin >> profe;
					if (a.es_alumno(alumno, profe)) {
						cout << alumno << " es alumno de " << profe << endl;
					}
					else cout << alumno << " no es alumno de " << profe << endl;

				}
				else if (acaba == "puntuacion") {
					cin >> alumno;
					nota = a.puntuacion(alumno);
					cout << "Puntuacion de " << alumno << ": " << nota << endl;

				}
				else if (acaba == "actualizar") {
					cin >> alumno;
					cin >> nota;
					a.actualizar(alumno, nota);
				}
				else if (acaba == "examen") {
					vector<string> aux;
					cin >> profe;
					cin >> nota;
					aux = a.examen(profe, nota);
					cout << "Alumnos de " << profe << " a examen:" << endl;
					for (int i = 0; i < aux.size(); i++) {
						cout << aux[i] << endl;
					}
				}
				else if (acaba == "aprobar") {
					cin >> alumno;
					a.aprobar(alumno);
				}
			}
			catch (domain_error e) {
				cout << e.what() << endl;
			}
			cin >> acaba;

		}
		cout << "------" << endl;
		cin >> acaba;
	}
}