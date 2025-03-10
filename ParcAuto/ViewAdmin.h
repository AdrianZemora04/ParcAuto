#include "ViewUser.h"

struct ViewA
{
	
	ControlMasini c1;
	ControlPersoane c2;
	ControlVanzari c3;

	Persoana logata;
	ViewA() {

	}
	ViewA(Persoana pers) {
		logata = pers;
	}

	void meniu() {
		cout << "Bine ai venit " << logata.u << endl;
		cout << "Apasati tasta 0 pentru a reveni la meniul principal" << endl;
		cout << "Apasati tasta 1 pentru a adauga o masina" << endl;
		cout << "Apasati tasta 2 pentru a sterge o masina" << endl;
		cout << "Apasati tasta 3 pentru a modifica numele masinii" << endl;
		cout << "Apasati tasta 4 pentru a modifica modelul masinii" << endl;
		cout << "Apasati tasta 5 pentru a modifica pretul masinii" << endl;
		cout << "Apasati tasta 6 pentru a afisa toate masinile" << endl;
		//de cine este inchiriata 
		cout << "Apasati tasta 7 pentru a afisa de cine este inchiriata masina dorita" << endl;

		//toate masinile inchiriate de persoana respectiva
		cout << "Apasati tasta 8 pentru a toate masinile inchiriate de o anumita persoana" << endl;
		cout << "Apasati tasta 9 pentru o masina din istoricul unei persoane" << endl;
	}

	void adaugareMasina() {
		cout << "Introduceti numele masinii :";
		string nume;
		cin >> nume;
		cout << "Introduceti modelulu masinii :";
		string model;
		cin >> model;
		cout << "Introduceti pretul masinii :";
		int pret;
		string pr;
		cin >> pr;
		pret = stoi(pr);
		cout << "Introduceti statusul masinii :";
		bool status;
		string st;
		cin >> st;
		if (st == "true") {
			status = true;
		}
		else {
			status = false;
		}
		status = stoi(st);
		Masina a(nume, model, pret, status);
		c1.adaugareMasina1(a);
		c1.salvareFisier();
	}
	void stergereMasina() {
		string nume;
		cout << "Introduceti modelul masini :";
		cin >> nume;
		c1.stergereMasina(nume);
		c1.salvareFisier();
	}
	void modificareNume(){
		string nume;
		cout << "Introduceti noul nume al masinii :";
		cin >> nume;
		string model;
		cout << "Introduceti modelul masinii :";
		cin >> model;
		c1.modificareNumeMasina(model, nume);
		c1.salvareFisier();
	}
	void modificareModel() {
		string m1, m2;
		cout << "Introduceti vechiul model al masinii :";
		cin >> m1;
		cout << "Introduceti noul model al masinii :";
		cin >> m2;

		c1.modificareModel(m1, m2);
		c1.salvareFisier();
	}
	void modificarePret() {
		string model;
		int pr;
		cout << "Introduceti modelulu masinii :";
		cin >> model;
		string p;
		cout << "Introduceti noul pret al masinii :";
		cin >> p;
		pr = stoi(p);


		c1.modificarePretMasina(model, pr);
		c1.salvareFisier();
	}
	void afisareMasiniPers() {
		string nume;
		cout << "Introduceti numele persoanei :";
		cin >> nume;
		c3.afisareMasiniPersoana(nume);
	}
	void stergereMasinaIstoric() {
		string numeC, numeM;
		cout << "Introduceti numele clientului :";
		cin >> numeC;
		cout << "Introduceti numele masinii :";
		cin >> numeM;
		c3.stergereIstoric(numeC, numeM);
		c3.salvareFisier();
	}

	void play() {
		int alegere;
		bool r = true;

		while (r == true) {
			meniu();

			string al;
			cin >> al;
			alegere = stoi(al);

			switch (alegere)
			{
			case 0:
				r = false;
				break;
			case 1:
				adaugareMasina();
				break;
			case 2:
				stergereMasina();
				break;
			case 3:
				modificareNume();
				break;
			case 4:
				modificareModel();
				break;
			case 5:
				modificarePret();
				break;
			case 6:
				c1.afisareMasini();
				break;
			case 8:
				afisareMasiniPers();
				break;
			case 9:
				stergereMasinaIstoric();
				break;
			default:
				break;
			}
		}
	}
};
