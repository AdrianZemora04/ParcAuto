#pragma once
#include "masina.h"

struct ControlMasini
{
	Masina masini[100];
	int  nrMasini = 0;
	


	ControlMasini() {
		citireFisier();
	}

	//functie afisare masini
	void afisareMasini() {
		for (int i = 0; i < nrMasini; i++) {
			cout << masini[i].descriereMasina() << endl;
		}
	}
	//read
	void adaugareMasina1(Masina masina) {

		masini[nrMasini] = masina;

		nrMasini++;
	}
	//functie ce returneaza pozitia masinii dupa marca
	int pozitieMasina(string model) {
		for (int i = 0; i < nrMasini; i++) {
			if (masini[i].model == model) {
				return i;
			}
		}
		return -1;
	}
	void stergereMasina(string model) {
		int p = pozitieMasina(model);
		for (int i = p; i < nrMasini - 1; i++) {
			masini[i] = masini[i + 1];
		}

		nrMasini--;

	}
	//functie ce primeste modelul masinii si pretul nou
	void modificarePretMasina(string model, int pret) {

		int poz = pozitieMasina(model);

		masini[poz].pret = pret;
	}
	//functie care modifica statusul
	void modificareStatusMasina(string model, bool status) {

		int p = pozitieMasina(model);

		masini[p].status = status;
	}
	void modificareNumeMasina(string model, string nume) {
		int p = pozitieMasina(model);
		masini[p].nume = nume;
	}
	void modificareModel(string model, string mode) {
		int p = pozitieMasina(model);
		masini[p].model = mode;
	}
	void citireFisier() {
		ifstream f("C:\\Users\\User\\OneDrive\\Desktop\\C++\\StructuriDeDate\\ParcAuto\\ParcAuto\\masini.txt");
		while (!f.eof()) {
			string nume;
			f >> nume;
			string model;
			f >> model;
			int pret;
			f >> pret;
			bool status;
			f >> status;

			if (nume != "") {

				Masina mas(nume, model, pret, status);

				adaugareMasina1(mas);
			}
			
		}
	}
	string toSave() {

		string text = "";

		for (int i = 0; i < nrMasini; i++) {


			text += masini[i].toSave() + "\n";
		}
		return text;
	}
	void salvareFisier() {
		ofstream f("C:\\Users\\User\\OneDrive\\Desktop\\C++\\StructuriDeDate\\ParcAuto\\ParcAuto\\masini.txt");
		f << toSave();

	}
	void afisareMasiniDisponibile() {
		for (int i = 0; i < nrMasini; i++) {
			if (masini[i].status == true) {
				cout << masini[i].descriereMasina() << endl;
			}
		}
	}
	void afisareMasiniIndisponibile() {
		for (int i = 0; i < nrMasini; i++) {
			if (masini[i].status == false) {
				cout << masini[i].descriereMasina() << endl;
			}
		}
	}
	int pretMinim() {
		int min = INT_MAX;
		for (int i = 0; i < nrMasini; i++) {
			if (masini[i].pret < min) {
				min = masini[i].pret;
			}
		}
		return min;
	}
	void afisareMasinaPretMinim() {
		int min = pretMinim();
		for (int i = 0; i < nrMasini; i++) {
			if (masini[i].pret == min) {
				cout << masini[i].descriereMasina() << endl;
				break;
			}
		}
	}
	int pretMaxim() {
		int max = INT_MIN;
		for (int i = 0; i < nrMasini; i++) {
			if (masini[i].pret > max) {
				max = masini[i].pret;
			}
		}
		return max;
	}
	void afisareMasinaPretMaxim() {
		int max = pretMaxim();
		for (int i = 0; i < nrMasini; i++) {
			if (masini[i].pret == max) {
				cout << masini[i].descriereMasina() << endl;
			}
		}
	}
	void afisareMasiniCautate() {
		int contor = 0;
		cout << "Introduceti numele masinii :";
		string Nume;
		cin >> Nume;
		for (int i = 0; i < nrMasini; i++) {
			if (masini[i].nume == Nume) {
				cout << masini[i].descriereMasina() << endl;
				contor++;
			}
		}
		if (contor == 0) {
			cout << "Nu exista" << endl;
		}
    }
	void afisareMasiniCautate1() {
		int contor = 0;
		cout << "Introduceti modelul cautat :";
		string Model;
		cin >> Model;
		for (int i = 0; i < nrMasini; i++) {
			if (masini[i].model == Model) {
				cout << masini[i].descriereMasina() << endl;
				contor++;
			}
		}
		if (contor == 0) {
			cout << "Nu exista" << endl;
		}
	}
	void afisareMasiniCautate2() {
		int min, max, contor = 0;
		cout << "Se introduce pretul minim :";
		cin >> min;
		cout << "Se introduce pretul maxim :";
		cin >> max;
		for (int i = 0; i < nrMasini; i++) {
			if (masini[i].pret >= min && masini[i].pret <= max) {
				cout << masini[i].descriereMasina() << endl;
				contor++;
			}
		}
		if (contor == 0) {
			cout << "Nu exista" << endl;
		}
	}

	
};