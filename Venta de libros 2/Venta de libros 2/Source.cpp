#include<iostream>
#include"hashmap_eda.h"
#include<vector>
#include"list_eda.h"
using namespace std;

class libreria {
	public:

		void nuevoLibro(int n, string x) {
			tLibro l;
			if (n == 0) {
				l.ejemplares = 0;
				if(lista.size() != 0) lista[0].push_front(x);
				else {
					list<string> aux;
					aux.push_front(x);
					lista.push_back(aux);
				}
				l.it = lista[0].begin();
				l.ventas = 0;
				libros[x] = l;
			}
			else {
				l.ejemplares = n;
				lista[0].push_front(x);
				l.it = lista[0].begin();
				l.ventas = 0;
				libros[x] = l;
			}
		}

		void comprar(string x) {
			tLibro l;
			if (libros.count(x) == 0) throw invalid_argument("Libro no existe");
			if (libros[x].ejemplares == 0) throw out_of_range("No hay ejemplares");
			lista[libros[x].ventas].erase(libros[x].it);
			libros[x].ventas++;
			lista[libros[x].ventas].push_front(x);
			libros[x].it = lista[libros[x].ventas].begin();
		}

		void estaLibro(string x) {
			if (libros.count(x) == 0) cout << "No existe el libro " << x << " en el sistema" << endl;
			else cout << "El libro " << x << " esta en el sistema" << endl;
		}
		void elimLibro(string x) {
			lista[libros[x].ventas].erase(libros[x].it);
			libros.erase(x);
		}

		void numEjemplares(string x) {
			if (libros.count(x) == 0) throw invalid_argument("Libro no existe");
			cout << "Existen " << libros[x].ejemplares << " ejemplares del libro " << x << endl;
		}


		void top10() {
			list<string> l;
			int c = lista.size() -1;
			int cont = 0;
			while (cont != 10) {

				for (int i = 0; i < lista[c].size(); i++) {
					if (cont != 10) {
						l.push_front(lista[c].at(i));
						cont++;
					}
				}
				c--;
			}

			for (int i = 0; i < l.size(); i++) {
				cout << l.at(i) << endl;
			}
			
		}



private:
	typedef struct tLibro {
		int ejemplares;
		int ventas;
		list<string>::iterator it;
	};

	unordered_map<string, tLibro> libros;
	vector<list<string>> lista;
	
};

int main() {
	libreria a;
	int casos;
	cin >> casos;
	int n;
	string x;
	for (int i = 0; i < casos; i++) {
		cin >> x;

		if (x == "nuevoLibro") {
			cin >> n;
			cin >> x;
			a.nuevoLibro(n, x);
		}
		else if (x == "comprar") {
			cin >> x;
			a.comprar(x);
		}
		else if (x == "numEjemplares") {
			cin >> x;
			a.numEjemplares(x);
		}
		else if (x == "top10") {
			a.top10();
		}
		else if (x == "elimLibro") {
			cin >> x;
			a.elimLibro(x);
		}
		else {
			cin >> x;
			a.estaLibro(x);
		}
	}
}