#include "ViewAdmin.h"

struct View {
	ControlPersoane control;

	void meniu() {
		cout << "Apasati tasta 1 pentru a va loga" << endl;
		cout << "Apasati tasta 2 pentru a va inregistra" << endl;
		cout << "Apasati tasta 3 pentru a inchide programul" << endl;
	}

	

	void login() {
		string nume, parola;
		cout << "Introduceti username-ul :";
		cin >> nume;
		cout << "Introduceti parola :";
		cin >> parola;

		Persoana pers = control.getPersoana(nume);

		if (control.verificareUsername(nume) == true && control.verificareCredentiale(nume, parola) == true) {
			if (control.verificareStatus(nume) == true) {
				ViewA a(pers);
				a.play();
			}
			else {
				ViewU u(pers);
				u.play();
				
			}
		}
	}
	void inregistrare() {
		string u, p;
		bool st;
		cout << "Creati un username :";
		cin >> u;
		cout << "Creati o parola :";
		cin >> p;
		cout << "Introduceti statusul :";
		cin >> st;

		Persoana pers(u, p, st);
		control.adaugare(pers);
		control.salvareFisier();
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
			case 1:
				login();
				break;
			case 2:
				inregistrare();
				break;
			case 3:
				r = false;
				break;
			default:
				break;
			}
		}
	}
};
