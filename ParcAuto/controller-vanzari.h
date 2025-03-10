#include "vanzari.h"

struct ControlVanzari {
	Vanzare vanzari[100];
	int nrVanzari = 0;

	ControlVanzari() {
		citireFisier();
	}
	void adaugare(Vanzare vanzare) {
		vanzari[nrVanzari] = vanzare;
		nrVanzari++;
	}
	void citireFisier() {
		ifstream f("C:\\Users\\User\\OneDrive\\Desktop\\C++\\StructuriDeDate\\ParcAuto\\ParcAuto\\vanzari.txt");
		while (!f.eof()) {
			string nm;
			f >> nm;
			string nc;
			f >> nc;

			if (nm != "") {
				Vanzare v(nm, nc);
				adaugare(v);
			}
		}
	}
	string toSave() {
		string text = "";
		for (int i = 0; i < nrVanzari; i++) {
			text += vanzari[i].toSave() + " \n";
		}
		return text;
	}
	void salvareFisier() {
		ofstream f("C:\\Users\\User\\OneDrive\\Desktop\\C++\\StructuriDeDate\\ParcAuto\\ParcAuto\\vanzari.txt");
		f << toSave();
	}
	int pozVanzare(string nc) {
		for (int i = 0; i < nrVanzari; i++) {
			if (vanzari[i].nc == nc) {
				return i;
			}
		}
		return -1;
	}
	void stergere(string nc) {
		int p = pozVanzare(nc);
		for (int i = p; i < nrVanzari; i++) {
			vanzari[i] = vanzari[i + 1];
		}
		nrVanzari--;
	}

	void afisareVanzari(string nume) {
		for (int i = 0; i < nrVanzari; i++) {
			if (vanzari[i].nc == nume) {
				cout << vanzari[i].nm << endl;
			}
		}
	}
	void afisareNume(int i) {
		cout << vanzari[i].nc << endl;
	}
	void afisareMasiniPersoana(string nume) {
		int c = 0;
		for (int i = 0; i < nrVanzari; i++) {
			if (vanzari[i].nc == nume) {
				cout << vanzari[i].nm << endl;
				c++;
			}
		}
		if (c == 0) {
			cout << "Nu exista" << endl;
		}
	}
	int pozC(string numeC, string numeM) {
		for (int i = 0; i < nrVanzari; i++) {
			if (vanzari[i].nc == numeC && vanzari[i].nm == numeM) {
				return i;
			}
		}
		return -1;
	}
	void stergereC(string numeC, string numeM) {
		int p = pozC(numeC, numeM);
		for (int i = p; i < nrVanzari; i++) {
			vanzari[i] = vanzari[i + 1];
		}
		nrVanzari--;
	}
	void stergereIstoric(string numeC, string numeM) {
		for (int i = 0; i < nrVanzari; i++) {
			if (vanzari[i].nc == numeC && vanzari[i].nm == numeM) {
				stergereC(numeC,numeM);
			}
		}
	}
};
