#include"hashmap_eda.h"
#include"treemap_eda.h"
using namespace std;

class errorCurso {};

class curso {
public:
	void cursoVacio() {

	}

	void addStudent(string SId) {
		if (estudiantes.count(SId) == 1) throw errorCurso();
		estudiantes.insert(SId);
		map<string, double> tareaNotas;
		estudiantes[SId] = tareaNotas;
	}

	void addAssignment(string A, double W) {
		if (pesoTareas.count(A) == 1) throw errorCurso();
		pesoTareas[A] = W;
	}

	void setMark(string SId, string A, double M) {
		if (estudiantes.count(SId) == 0 || pesoTareas.count(A) == 0) throw errorCurso();
		estudiantes[SId][A] = M;//en el mapa de estudiantes,, en mapa de tareas, en la tarea A la nota M

		/*	
		map<string, map<string, double>>::iterator it = alumnos.find(alumno);
		unordered_map<string, double>::iterator t = pesos.find(tarea);
		if (t== pesos.end() || it == alumnos.end()) throw errorCurso();
		it->valor[tarea] = nota*t->valor;*/
	}
	void getFinalMark(string SId, double & M) {
		map<string, double> tareasAlumno;
		tareasAlumno = estudiantes[SId];
		map<string, double>::iterator iterador = tareasAlumno.begin();
		for (int i = 0; i < tareasAlumno.size(); i++) {
			M += iterador->valor * pesoTareas[iterador->clave];
			++iterador;
		}


	}


	void setAssignmentWeight(string A, double W) { //en el mapa de tareas, cambias el peso de la tarea A
		if (pesoTareas.count(A) == 0) throw errorCurso();
		pesoTareas[A] = W;

		/*
		unordered_map<string, double>::iterator algo= pesos.find(tarea);
		if (algo == pesos.end()) throw errorCurso();
		algo->valor = peso;
		*/
	}

	void listOfStudents(vector<string> L) {
		map<string, map<string, double>>::iterator iterador = estudiantes.begin();
		for (int i = 0; i < estudiantes.size(); i++) {
			L.push_back(iterador->clave);
			++iterador;
		}
	}

	vector<string> getEmpollomes() {
		vector<string> empollones;
		map<string, map<string, double>>::iterator iterador = estudiantes.begin();
		for (int i = 0; i < estudiantes.size(); i++) {
			if (iterador->valor.size() == pesoTareas.size()) empollones.push_back(iterador->clave);
			++iterador;
		}
		return empollones;
	}


private:
	map<string, map<string, double>> estudiantes;
	unordered_map<string, double> pesoTareas;
};