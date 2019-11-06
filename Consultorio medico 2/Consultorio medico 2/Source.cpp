#include<iostream>
#include"hashmap_eda.h"
#include"treemap_eda.h"
#include"list_eda.h"
using namespace std;


class fecha {

public:
	int sacarDia() {
		return dia;
	}
	int sacarMinuto() {
		return minuto;
	}
	int sacarHora() {
		return hora;
	}

	 void constructor(int a, int b, int c) {
		this->dia = a;
		this->hora = b;
		this->minuto = c;
	}

private:
	int hora;
	int dia;
	int minuto;

};

class consultorio {

public:

	void nuevoMedico(string m) {
		if (consultas.count(m) == 0) {//si no existe este medico
			throw domain_error("Medico no existente");
		}
		consultas.insert(m);
		medicos.insert(m);
	}


	void pideConsulta(string p, string m, fecha f) {
		if (consultas.count(m) == 0) {//si no existe este medico
			throw domain_error("Medico no existente");
		}
		if (consultas[m].count(f) == 1) throw domain_error("Fecha ocupada");
		tPaciente paciente;

		medicos[m].push_front(p);
		paciente.it = medicos[m].begin();
		paciente.nombrePaciente = p;
		map<fecha, tPaciente> aux;
		aux[f] = paciente;
		consultas[m] = aux;
	}


	void siguientePaciente(string m) {
		if (consultas.count(m) == 0) {//si no existe este medico
			throw domain_error("Medico no existente");
		}
		if (medicos[m].size() == 0) throw domain_error("No hay pacientes");

		map<fecha, tPaciente> aux;
		aux = consultas[m];
		auto it = aux.begin();
		cout << "Siguiente paciente doctor " << m << " "<< it->valor.nombrePaciente << endl;
	}


	void atiendeConsulta(string m) {
		if (consultas.count(m) == 0) {//si no existe este medico
			throw domain_error("Medico no existente");
		}
		if (medicos[m].size() == 0) throw domain_error("No hay pacientes");

		map<fecha, tPaciente> aux;
		aux = consultas[m];
		auto it = aux.begin();
		medicos[m].erase(consultas[m][it->clave].it);
		consultas[m].erase(it->clave);
	}

	void listaPacientes(string m, int d) {
		
		typedef struct tHola{
			string nombre;
			int hora;
			int minuto;
		};
		list<tHola> lista;
		tHola ca;
		map<fecha, tPaciente> aux;
		aux = consultas[m];
		auto it = aux.begin();

		while (it != aux.end()) {
			if (it->clave.sacarDia() == d) {
				ca.nombre = it->valor.nombrePaciente;
				ca.hora = it->clave.sacarHora;
				ca.minuto = it->clave.sacarMinuto;
				lista.push_back(ca);
			}
			++it;
		}
		cout << "Doctor " << m << " dia" << d << endl;
		for (int i = 0; i < lista.size(); i++) {
			cout << lista.at(i).nombre << " " << lista.at(i).hora << ":" << lista.at(i).minuto << endl;
		}
		
	}




private:

	typedef struct tPaciente {
		string nombrePaciente;
		list<string>::iterator it;
	};

	unordered_map<string, map<fecha, tPaciente>> consultas;
	unordered_map < string, list<string>> medicos;


};

int main() {
	consultorio ey;
	string p1;
	string p2;
	int a;
	cin >> a;
	if (!cin) return false;
	for (int i = 0; i < a; i++) {
		try {
			cin >> p1;
			cin >> p2;

			if (p1 == "nuevoMedico") {
				ey.nuevoMedico(p2);
			}
			else if (p1 == "pideConsulta") {
				int dia;
				string p3;
				cin >> p3;
				cin >> dia;
				int hora;
				cin >> hora;
				int minuto;
				cin >> minuto;
				//fecha fe = fecha(dia, hora, minuto);
				fecha fe;
				fe.constructor(dia, hora, minuto);
				ey.pideConsulta(p3, p2, fe);
			}
			else if (p1 == "listaPacientes") {
				int dia;
				cin >> dia;
				ey.listaPacientes(p2, dia);
			}
			else if (p1 == "siguientePaciente") {
				ey.siguientePaciente(p1);
			}
			else if (p1 == "atiendeConsulta") {
				ey.atiendeConsulta(p2);
			}
			else cout << "Error" << endl;
		}
		catch (domain_error e) {
			cout << "Error: " << e.what() << endl;
		}
	}






	std::cout << "---\n";
}