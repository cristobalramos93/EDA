#include<iostream>
#include<string>
#include<vector>
#include"hashmap_eda.h"
#include"treemap_eda.h"
#include"list_eda.h"
using namespace std;

//32 ELIGIENDO DEPORTE
typedef struct tNinios {
	bool eliminado;
	list<string>::iterator it;
	string deporte;
};
int main() {
	string deporte;
	string linea;
	cin >> linea;
	while (cin) {
		unordered_map<string, list<string>> lista;
		unordered_map<string, int> cantidad;
		unordered_map<string, tNinios> ninios;
		while (linea != "_FIN_") {


			if (linea[0] < 'A' || linea[0] < 'Z') {//si es un deporte
				deporte = linea;
				cantidad[linea] = 0;
				lista.insert(linea);
			}
			else {//si es un ninio
				if (ninios.count(linea) == 0) { //si es la primera vez que aparece
					lista[deporte].push_front(linea);//meto al niño en su deporte
					tNinios ni;
					ni.eliminado = false;
					ni.it = lista[deporte].begin();
					ni.deporte = deporte;
					ninios[linea] = ni; //meto al niño en la lista de niños
					cantidad[deporte]++;

				}
				else {//si es un repetido
					if (ninios[linea].eliminado == false) {//si no ha sido eliminado
						if (deporte != ninios[linea].deporte) {
							lista[ninios[linea].deporte].erase(ninios[linea].it);//lo borro de la lista de su deporte
							cantidad[ninios[linea].deporte]--;//quito uno al contador de su deporte anterior
							ninios[linea].eliminado = true;
						}
					}
				}
			}
			cin >> linea;
		}

		//empiezo a mostrar
		unordered_map<string, int> ::iterator it = cantidad.begin();
		int maxDeportes = 0;
		string depor = "ZZZZZZZZZ";

		while (it != cantidad.end()) {
			for (int i = 0; i < cantidad.size(); i++) {
				if (it->valor > maxDeportes) {
					maxDeportes = it->valor;
					depor = it->clave;
				}
				else if (it->valor == maxDeportes) {
					if (it->clave < depor) {
						depor = it->clave;
						maxDeportes = it->valor;
					}
				}
				++it;
			}
			cout << depor << " " << maxDeportes << endl;
			cantidad.erase(depor);
			depor = "ZZZZZZZZZZZ";
			maxDeportes = 0;
			it = cantidad.begin();
		}

		cin >> linea;
	}
}