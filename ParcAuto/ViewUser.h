#pragma once
#include "controller-vanzari.h"

struct ViewU {


	ControlMasini control;
	ControlVanzari control2;


	Persoana logata;
	ViewU() {

	}
	ViewU(Persoana pers) {
		logata = pers;
	}

	void meniu() {
		cout <<"Bine ai venit " << logata.u << endl;
		cout << "Apasati tasta 1 pentru a afisa toate masinile " << endl;
		cout << "Apasati tasta 2 pentru a afisa masinile disponibile" << endl;
		cout << "Apasati tasta 3 pentru a afisa toate masinile indisponibile" << endl;
		cout << "Apasati tasta 5 pentru a afisa masina cu pretul minim" << endl;
		cout << "Apasati tasta 6 pentru a afisa masina cu pretul maxim" << endl;
		cout << "Apasati tasta 7 pentru a afisa masinile cu numele dorit" << endl;
		cout << "Apasati tasta 8 pentru a afisa masinile cu modelul dorit" << endl;
		cout << "Apasati tasta 9 pentru a afisa masinile in functie de pretul introdus" << endl;
		cout << "Apasati tasta 10 pentru a cumpara o masina" << endl;
		cout << "Apasati tasta 11 pentru a returna o masina" << endl;
		cout << "Apasati tasta 12 pentru a afisa istoricul cumparatorilor" << endl;
	}
	
	void cumparare() {
		string nm, m;
		cout << "Introduceti numele masinii :";
		cin >> nm;
		cout << "Introduceti modelul masinii :";
		cin >> m;

		Vanzare v(nm, logata.u);
		control2.adaugare(v);
		control2.salvareFisier();

		control.stergereMasina(m);
	}
	void istoric() {
		control2.afisareVanzari(logata.u);
	}


	void play() {
		int alegere;
		bool running = true;

		while (running == true) {
			meniu();

			string al;
			cin >> al;
			alegere = stoi(al);

			switch (alegere)
			{
			case 1:

				control.afisareMasini();
				break;

			case 2:
				control.afisareMasiniDisponibile();
				break;

			case 3:
				control.afisareMasiniIndisponibile();
				break;

			case 5:
				control.afisareMasinaPretMinim();
				break;

			case 6:
				control.afisareMasinaPretMaxim();
				break;

			case 7:
				control.afisareMasiniCautate();
				break;

			case 8:
				control.afisareMasiniCautate1();
				break;

			case 9:
				control.afisareMasiniCautate2();
				break;

			case 10:
				cumparare();
				break;

			case 12:
				istoric();
				break;



			default:
				break;
			}

		}
		

		
	}

	
};