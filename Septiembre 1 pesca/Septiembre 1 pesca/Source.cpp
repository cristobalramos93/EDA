#include<iostream>
#include"Header.h"
using namespace std;
int main() {

	barco nuevo = barco(20);
	nuevo.altaPescador("cansecoElFlojo");
	nuevo.nuevaCaptura("cansecoElFlojo", "truchis", 2);
	nuevo.nuevaCaptura("cansecoElFlojo", "ladillas", 1);
	nuevo.altaPescador("charlyElAusente");
	nuevo.nuevaCaptura("charlyElAusente", "pulpo", 5);
	nuevo.nuevaCaptura("charlyElAusente", "truchis", 5);


	cout << "capacidad " << nuevo.bodegaRestante() << endl;
	cout << "truchis capturadas " << nuevo.kilosEspecie("truchis") << endl;
	cout << "camarones capturadas " << nuevo.kilosEspecie("camarones") << endl;
	cout << "canseko ha pescao: " << nuevo.kilosPescador("cansecoElFlojo") << endl;
	
	vector<barco::tLista> pescas;
	pescas = nuevo.capturasPescador("charlyElAusente");

	for (int i = 0; i < pescas.size(); i++)
		cout << pescas[i].es << " " << pescas[i].pe << ",";
		
	cout << endl;
	return 0;
}