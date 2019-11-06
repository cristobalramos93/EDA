#include<iostream>
#include"hashmap_eda.h"
#include"treemap_eda.h"
using namespace std;



class fecha {
public:


	int getDia() {
		return dia;
	}
	void constructor(int a, int b, int c) {
		dia = a;
		hora = b;
		minutos = c;
	}

	//fecha(int a, int h, int m):dia(a),hora(h),minutos(m){}

private:
	int dia;
	int hora;
	int minutos;

};
	


class error{};


class consultorio {
public:
	void nuevoMedico(string m) {
		if (medico.count(m) == 0) {
			medico.insert(m);
		}
	}


	void pideConsulta(string p, string m, fecha f) {
		if (medico.count(m) == 0) throw error();
		map<fecha, string> aux;
		aux = medico[m];
		auto it = aux.find(f);
		if (it == aux.end()) {//si no existe esa fecha, todo correcto
			medico[m][f] = p;
		}
		else {//esa fecha ya existe
			throw error();
		}
	}

	void siguientePaciente(string m) {
		if (medico.count(m) == 0) throw error();
		map<fecha, string> aux;
		aux = medico[m];
		auto it = aux.begin();
		if (it == aux.end()) {//no tiene pacientes asignados
			throw error();
		}
		else {
			cout << it->valor << endl;//mostramos el paceinte
		}

	}

	void atiendeConsulta(string m) {
		if (medico.count(m) == 0) throw error();
		map<fecha, string> aux;
		aux = medico[m];
		auto it = aux.begin();
		if (it == aux.end()) {//no tiene pacientes asignados
			throw error();
		}
		else {
			medico[m][it->clave].erase();
		}
	}

	void listaPacientes(string m, int d) {
		vector<string> lista;
		if (medico.count(m) == 0) throw error();
		map<fecha, string> aux;
		aux = medico[m];
		auto it = aux.begin();
		for (int i = 0; i < medico[m].size(); i++) {
			fecha as = it->clave;
			if (as.getDia() == d) {
				lista.push_back(it->valor);
			}
			++it;
		}
		
	}


private:

	unordered_map<string, map<fecha, string>> medico;
	map<fecha, string> fechas;
};

bool resuelveCaso();
int main() {
	while (resuelveCaso());
}


bool resuelveCaso() {
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
				fe.constructor(dia,hora, minuto);
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
		catch (error e) {
			cout << "Error ";
		}
	}





	
	std::cout << "---\n";
	return true;
}

