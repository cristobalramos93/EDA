#include<iostream>
#include<vector>
//#include"treemap_eda.h"
#include"hashmap_eda.h"
using namespace std;

int main() {
	int numeros;
	cin >> numeros;
	while (!cin.fail()) {
		unordered_map<int, vector<int>> mapa;
		int preguntas;
		int pos;
		cin >> preguntas;
		int caso;
		int n;
		for (int i = 1; i < numeros +1; i++) {
			cin >> n;
			if (mapa.count(n) == 0) {//si elo numero es la primera vez que sale
				mapa.insert(n);
				mapa[n].push_back(i);
			}
			else {
				mapa[n].push_back(i);
			}
		}

		for (int i = 0; i < preguntas; i++) {
			cin >> pos;
			cin >> caso;

			if (mapa.count(caso) == 1) {//si el numero existe
				if (mapa[caso].size() >= pos) {
					cout << mapa[caso][pos-1] << endl;
				}
				else cout << "NO HAY" << endl;
			}
			else cout << "NO HAY" << endl;

		}
		cout << "---" << endl;
		cin >> numeros;

	}
}