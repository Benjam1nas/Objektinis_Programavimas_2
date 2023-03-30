#include "header.h"
#include "MyLib.h"

void generavimas(string &pav, double &generavimo_laikas) {
	time_point<high_resolution_clock> start, end;
	duration<double> laikas;
	srand((unsigned int)time(NULL));
	int n = -1, p = -1;
	string vardas = "Vardas", pavarde = "Pavarde", sk, tikr;
	char eilut[100];
	ofstream file(pav);
	stringstream(buffer);
	do {
		cout << "Kiek bus studentu: ";
		cin >> tikr;
		if (numeris(tikr)) {
			if (stoi(tikr) < 0) {
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Klaidingas ivedimas!" << endl;
			}
			else {
				n = stoi(tikr);
			}
		}
		else {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Klaidingas ivedimas!" << endl;
		}
	} while (n < 0);
	do {
		cout << "Kiek bus pazymiu: ";
		cin >> tikr;
		if (numeris(tikr)) {
			if (stoi(tikr) < 0) {
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Klaidingas ivedimas!" << endl;
			}
			else {
				p = stoi(tikr);
			}
		}
		else {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Klaidingas ivedimas!" << endl;
		}
	} while (p < 0);
	start = high_resolution_clock::now();
	buffer << vardas << setw(22) << pavarde;
	for (int i = 0; i < p; i++) {
		sk = to_string(i + 1);
		buffer << setw(8) << "ND" << sk;
	}
	buffer << setw(8) << "Egz" << endl;
	for (int i = 0; i < n; i++) {
		sk = to_string(i);
		vardas = "Vardas" + sk;
		pavarde = "Pavarde" + sk;
		sprintf_s(eilut, "% *s % *s", -20, vardas.c_str(), -8, pavarde.c_str());
		buffer << eilut;
		for (int q = 0; q < p; q++) {
			buffer << setw(8) << (rand() % 10) + 1;
		}
		buffer << setw(8) << (rand() % 10) + 1 << endl;
	}
	file << buffer.str();
	file.close();
	end = high_resolution_clock::now();
	laikas = end - start;
	generavimo_laikas = laikas.count();
}