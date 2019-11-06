#include<iostream>
#include"hashmap_eda.h"
#include"treemap_eda.h"
#include"list_eda.h"
using namespace std;

class libreria {

public:
	void nuevoLibro(int n, string x) {
		tLibros l;
		if (n == 0) {//si la cantidad es 0
			cantidad[0].push_front(x);
			l.ejemplares = 0;
			l.it = cantidad[0].begin();
			libros[x] = l;
		}
		else if (libros.count(x) == 0) {//si el libro es nuevo
			cantidad[n].push_front(x);
			l.ejemplares = n;
			l.it = cantidad[n].begin();
			libros[x] = l;
		}
		else {//si ya existia y has añadido mas ejemplares
			cantidad[libros[x].ejemplares].erase(libros[x].it);
			cantidad[n + libros[x].ejemplares].push_front(x);
			l.ejemplares = n + libros[x].ejemplares;
			l.it = cantidad[l.ejemplares].begin();
			libros[x] = l;
		}
	}

	void comprar(string x) {
		tLibros l;
		if (libros.count(x) == 0) throw invalid_argument("Libro no existente");
		if (libros[x].ejemplares == 0) throw out_of_range("No hay ejemplares");
		cantidad[libros[x].ejemplares].erase(libros[x].it);
		cantidad[libros[x].ejemplares - 1].push_front(x);
		l.ejemplares = libros[x].ejemplares - 1;
		l.it = cantidad[l.ejemplares].begin();
		libros[x] = l;


	}

	bool estaLibro(string x) {
		if (libros.count(x) == 0) return false;
		else return true;
	}

	void elimLibro(string x) {
		if (libros.count(x) == 1) {
			cantidad[libros[x].ejemplares].erase(libros[x].it);
			libros.erase(x);
		}
	}

	int numEjemplares(string x) {
		if (libros.count(x) == 0) throw invalid_argument("Libro no existente");
		return libros[x].ejemplares;
	}

	list<string> top10() {
		list<string> lista;
		int n = 0;
		auto it = cantidad.end();
		--it;
		cout << it->clave;
		int t = 0;
		while (n != 10 || it != cantidad.end()) {
			if (t != cantidad[it->clave].size()-1) {
				lista.push_back(it->valor.at(t));
				n++;
				t++;

			}
			else {
				t = 0;
				++it;
				
			}
		}
		return lista;
	}
	

	

private:

	typedef struct tLibros {
		int ejemplares;
		list<string>::iterator it;
	};

	unordered_map<string, tLibros> libros;
	map<int, list<string>> cantidad;
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
			int h;
			cin >> x;
			h = a.numEjemplares(x);
			cout << "Existen " << h << "ejemplares del libro " << x << endl;
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