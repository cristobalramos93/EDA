#include<iostream>
#include<string>
#include"hashmap_eda.h"
#include"treemap_eda.h"

using namespace std;

int main() {

	map<string, map<string, double>> alumnos;
	unordered_map<string, double> pesos;
	map<string, double> p;
	p["mates"] = 5;
	alumnos["cristobal"] = p;
	p["lengua"] = 6;
	alumnos["manu"] = p;
	cout << alumnos["cristobal"]["mates"];

	alumnos["cristobal"]["caca"] = 2;
	cout << alumnos["cristobal"]["mates"];

	
}