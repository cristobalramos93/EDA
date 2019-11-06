#include"hashmap_eda.h"
#include<vector>
using namespace std;
class error{};
class errorPeso{};
class barco {

public:
	/*
	void nuevo(int k) {
		pesoMaximo = k;
	}
	*/
	barco(int v) : pesoMaximo(v) {}

	//o(1)
	void altaPescador(string pescador) {
		pescadores.insert(pescador);
	}


	//o(1)
	void nuevaCaptura(string pescador, string especie, int kilos) {
		if (pesoActual + kilos > pesoMaximo) throw errorPeso();
		if (pescadores.count(pescador) == 0) throw error();
		unordered_map<string, int> aux;
		aux = pescadores[pescador];
		if (aux.count(especie) == 0) { //si es la primera vez que pesca esta especie
			aux[especie] = kilos;
		}
		else {
			aux[especie] += kilos;
		}
		pesoActual += kilos;
		pescadores[pescador] = aux;
	}


	typedef struct {
		string es;
		int pe;
	}tLista;
	//o(n)
	vector<tLista> capturasPescador(string pescador) {
		unordered_map<string, int> ::iterator iterador = pescadores[pescador].begin();
		tLista lista;
		vector<tLista> listaFinal;
		for (int i = 0; i < pescadores[pescador].size(); i++) {
			if (iterador->valor > 0) {
				
				lista.es = iterador->clave;
				lista.pe = iterador->valor;
				listaFinal.push_back(lista);
			}
			++iterador;
		}
		return listaFinal;
	}

	int kilosEspecie(string especie) {
		unordered_map < string, unordered_map<string, int>> ::iterator iterador = pescadores.begin();
		int k = 0;
		for (int i = 0; i < pescadores.size(); i++) {
			unordered_map<string, int> aux;
			aux = pescadores[iterador->clave];
			if (aux.count(especie) == 1) {
				k += aux[especie];
			}
			++iterador;
		}
		return k;
	}

	int kilosPescador(string pescador) {
		int k = 0;
		unordered_map<string, int> aux;
		aux = pescadores[pescador];
		unordered_map<string, int>::iterator  iterador = aux.begin();

		for (int i = 0; i < aux.size(); i++) {
			k += iterador->valor;
			++iterador;
		}
		return k;
	}


	int bodegaRestante() {
		return pesoMaximo - pesoActual;
	}





private:
	int pesoMaximo;
	int pesoActual;



	unordered_map < string, unordered_map<string, int>> pescadores;

	
};