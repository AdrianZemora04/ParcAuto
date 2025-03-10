#include "controller-masini.h"

struct Persoana {
	string u="nedefinit";
	string p="nedefinit";
	bool s="false";

	Persoana() {

	}

	Persoana(string us, string pa, bool st) {
		u = us;
		p = pa;
		s = st;
	}

	string descrierePersoana() {
		string text = "";
		text += "Introduceti username-ul :" + u + "\n";
		text += "Introduceti parola :" + p + "\n";
		text += "Introduceti statusul :" + to_string(s) + "\n";
		return text;
	}

	string toSave() {
		string text = "";
		text += u + " ";
		text += p + " ";
		text += to_string(s) + " ";
		return text;
	}
};
