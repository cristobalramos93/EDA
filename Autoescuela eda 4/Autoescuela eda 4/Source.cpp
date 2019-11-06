#include<iostream>
#include"hashmap_eda.h"
#include"treemap_eda.h"
#include"list_eda.h"
using namespace std;

class autoescuela {


public:

	void alta(string A, string P) {
		tAlumno al;
		if (alumnos.count(A) == 0) {//si el alumno es nuevo
			profes[P][A] = 0;
			al.puntuacion = 0;
			al.profe = P;
			alumnos[A] = al;


		}
		else {
			profes[alumnos[A].profe].erase(A);
			profes[P][A] = alumnos[A].puntuacion;
			alumnos[A].profe = P;
		}
	}

	bool es_alumno(string A, string P) {

		if (alumnos[A].profe == P) return true;
		else return false;
	}

	int puntuacion(string A) {
		if (alumnos.count(A) == 0) throw domain_error("ERROR");
		return alumnos[A].puntuacion;
	}

	void actualizar(string A, int N) {
		if (alumnos.count(A) == 0) throw domain_error("ERROR");
		if (N != 0) {
			alumnos[A].puntuacion += N;
			map<string, int> aux;

			aux = profes[alumnos[A].profe];
			aux[A] += N;
			profes[alumnos[A].profe] = aux;
		}
	}

	vector<string> examen(string P, int N) {
		vector<string> aa;
		map<string, int> aux;
		aux = profes[P];
		auto it = aux.begin();
		for (int i = 0; i < profes[P].size(); i++) {
			if (it->valor >= N) {
				aa.push_back(it->clave);
			}
			++it;
		}
		return aa;
	}

	void aprobar(string A) {
		if (alumnos.count(A) == 0) throw domain_error("ERROR");

		profes[alumnos[A].profe].erase(A);
		alumnos.erase(A);
	}

private:

	typedef struct tAlumno {
		string profe;
		int puntuacion;
	};

	unordered_map<string, tAlumno> alumnos;
	unordered_map<string, map<string, int>> profes;

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