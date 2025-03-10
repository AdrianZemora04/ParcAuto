#include "persoane.h"

struct ControlPersoane {
	Persoana persoane[100];
	int nrPersoane = 0;

	ControlPersoane() {
		citireFisier();
	}
	void adaugare(Persoana persoana) {
		persoane[nrPersoane] = persoana;
		nrPersoane++;
	}
	void citireFisier() {
		ifstream f("C:\\Users\\User\\OneDrive\\Desktop\\C++\\StructuriDeDate\\ParcAuto\\ParcAuto\\persoane.txt");
		while (!f.eof()) {
			string u;
			f >> u;
			string p;
			f >> p;
			bool s;
			f >> s;

			//if (u != "") {
				//Persoana p(u, p, s);
				//adaugare(p);
			//}
		}
	}
	string toSave() {
		string text = "";
		for (int i = 0; i < nrPersoane; i++) {
			text += persoane[i].toSave() + "\n";
		}
		return text;
	}
	void salvareFisier() {
		ofstream f("C:\\Users\\User\\OneDrive\\Desktop\\C++\\StructuriDeDate\\ParcAuto\\ParcAuto\\persoane.txt");
		f << toSave();
	}
	int pozPersoane(string nume) {
		for (int i = 0; i < nrPersoane; i++) {
			if (persoane[i].u == nume) {
				return i;
			}
		}
		return -1;
	}
	void stergere(string nume) {
		int p = pozPersoane(nume);
		for (int i = p; i < nrPersoane; i++) {
			persoane[i] = persoane[i + 1];
		}
		nrPersoane--;
	}
	void modificareParola(string nume, string parola) {
		int p = pozPersoane(nume);
		persoane[p].p = parola;
	}
	bool verificareUsername(string username) {
		for (int i = 0; i < nrPersoane; i++) {
			if (persoane[i].u == username) {
				return true;
			}
		}
		return false;
	}

	bool verificareCredentiale(string username, string parola) {
		for (int i = 0; i < nrPersoane; i++) {
			if (persoane[i].u == username && persoane[i].p == parola) {
				return true;
			}
		}
		return false;
	}
	bool verificareStatus(string username) {
		for (int i = 0; i < nrPersoane; i++) {
			if (persoane[i].u == username && persoane[i].s == true) {
				return true;
			}
		}
		return false;
	}
	
	Persoana getPersoana(string username) {
		for (int i = 0; i < nrPersoane; i++) {
			if (persoane[i].u == username) {
				return persoane[i];
			}
		}
		return Persoana();
	}
};
