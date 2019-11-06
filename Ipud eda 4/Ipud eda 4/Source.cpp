#include<iostream>
#include"hashmap_eda.h"
#include"list_eda.h"
using namespace std;

class ipud{
public:

	void addSong(string S, string A, int D) {
		if (canciones.count(S) == 1) throw domain_error("ERROR addSong");
		tCancion a;
		a.artista = A;
		a.duracion = D;
		a.enLista = false;
		canciones[S] = a;
	}



	void addToPlaylist(string S) {
		if(canciones.count(S) == 0) throw domain_error("ERROR addToPlaylist");
		if (canciones[S].enLista != true) {
			canciones[S].enLista = true;
			auto it = canciones.find(S);
			lista.push_back(it->clave);
			canciones[S].iterador = lista.begin();
		}
	}

	string current() {
		if (lista.size() == 0) throw domain_error("ERROR current");
		return lista.at(0);
	}

	void play() {
		if (lista.size() > 0) {
			string a = current();
			lista.pop_front();
			canciones[a].enLista = false;
			reproducidas.push_front(a);
			canciones[a].iterador2 = reproducidas.begin();
			cout << "Sonando " << a << endl;
			//hay que poner que ya no esta en la lista?
		}
		else cout << "No hay canciones en la lista" << endl;
	}

	int totalTime() {
		if (lista.size() != 0) {
			int t = 0;
			for (int i = 0; i < lista.size(); i++) {
				t += canciones[lista.at(i)].duracion;
			}
			return t;
		}
		else return 0;
	}
	list<string> recent(int N) {
		list<string> devolver;
		if (reproducidas.size() <= N) return reproducidas;
		else {
			for (int i = 0; i < N; i++) {
				devolver.push_front(reproducidas.at(i));
				canciones[reproducidas.at(i)].iterador2 = devolver.begin();
			}
			return devolver;
		}

	}

	void deleteSong(string S) {
		if(canciones[S].enLista == true)lista.erase(canciones[S].iterador);
		else reproducidas.erase(canciones[S].iterador2);
		canciones.erase(S);

	}

private:

	typedef struct tCancion {
		int duracion;
		string artista;
		bool enLista;
		list<string> ::iterator iterador;
		list<string> ::iterator iterador2;
	};

	typedef struct tCa {
		int duracion;
		string artista;
		bool enLista;
	};

	unordered_map<string, tCancion> canciones;
	list<string> lista;
	list<string> reproducidas;

};



int main() {
	string sigue;
	cin >> sigue;

	while (cin) {
		ipud a;
		string cancion;
		int t;
		string artista;

		while (sigue != "FIN") {
			try {
				if (sigue == "addSong") {
					cin >> cancion;
					cin >> artista;
					cin >> t;
					a.addSong(cancion, artista, t);
				}
				else if (sigue == "addToPlaylist") {
					cin >> cancion;
					a.addToPlaylist(cancion);
				}
				else if (sigue == "play") {
					a.play();
				}
				else if (sigue == "deleteSong") {
					cin >> cancion;
					a.deleteSong(cancion);
				}
				else if (sigue == "recent") {
					list<string> casa;

					cin >> t;
					casa = a.recent(t);
					cout << "Las " << casa.size() << " mas recientes" << endl;
					for (int i = 0; i < casa.size(); i++) {
						cout << "    " << casa.at(i) << endl;
					}
				}
				else if (sigue == "current") {
					a.current();
				}
				else if (sigue == "totalTime") {
					int c = a.totalTime();
					cout << "Tiempo total " << c << endl;
				}
			}
			catch (domain_error e) {
				cout << e.what() << endl;
			}
			cin >> sigue;
		}
		cout << "----" << endl;
		cin >> sigue;
	}
}