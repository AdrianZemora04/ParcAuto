#include "controller-persoane.h"

struct Vanzare {
	string nm;
	string nc;

	Vanzare() {

	}
    
	Vanzare(string n1, string n2) {
		nm = n1;
		nc = n2;
	}

	string descriereVanzare() {
		string text = "";
		text += "Nume masina :" + nm + "\n";
		text += "Nume client :" + nc + "\n";
		return text;
	}

	string toSave() {
		string text = "";
		text += nm + " ";
		text += nc + " ";
		return text;
	}
};
