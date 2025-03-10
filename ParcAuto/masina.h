#pragma once
#include <iostream>
using namespace std;
#include <string>
#include <fstream>

struct Masina {
	//atribute
	string nume;
	string model;
	int pret;
	bool status;
	//constrcutori

	Masina() {

	}

	Masina(string n, string mod, int p, bool st) {

		nume = n;
		model = mod;
		pret = p;
		status = st;
	}

	//metode
	string descriereMasina() {
		string text = "";
		text += "Nume :" + nume + "\n";
		text += "Model :" + model + "\n";
		text += "Pret :" + to_string(pret) + "\n";
		text += "Status :" + to_string(status) + "\n";
		return text;
	}

	string toSave() {
		string text = "";
		text += nume + " ";
		text += model + " ";
		text += to_string(pret) + " ";
		text += to_string(status) + " ";
		return text;
	}

};
