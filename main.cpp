#include "MyLib.h"

struct studentas {
    string vardas, pavarde;
    vector<int> paz;
    int egz;
    int gal;
};

bool numeris(string temp) {
    bool tiesa = true;
    for (int i = 0; i < temp.size(); i++) {
        if (isdigit(temp[i]) == 0) {
            tiesa = false;
        }
    }
    return tiesa;
}

void atsitiktinis(vector<studentas> &temp, int m) {
    srand((unsigned int)time(NULL));
    int skaic, sk_kiek = -1;
    string kiek;
    do {
        cout << "Kiek bus pazymiu: ";
        cin >> kiek;
        if (numeris(kiek)) {
            if (stoi(kiek) < 0) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Klaidingas ivedimas!" << endl;
            }
            else {
                sk_kiek = stoi(kiek);
            }
        }
        else {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Klaidingas ivedimas!" << endl;
        }
    } while (sk_kiek < 0);
    for (int i = 0; i < sk_kiek; i++) {
        skaic = (rand() % 10) + 1;
        cout << i + 1 << "-as pazymys: " << skaic << endl;
        temp[m].paz.push_back(skaic);
    }
    skaic = (rand() % 10) + 1;
    cout << "Egzamino pazymys: " << skaic << endl;
    temp[m].egz = skaic;
}

void pild(vector<studentas> &temp, int &m) {
    string t, egz, paz, sk;
    int sk_paz = -1, sk_egz = -1;
    cout << "Jei norite, kad programa sustotu iveskite 'Stop'" << endl;
    cout << "Iveskite varda ir pavarde: ";
    while (cin >> t && t != "Stop") {
        temp.push_back(studentas());
        temp[m].vardas = t;
        cin >> temp[m].pavarde;
        do {
            cout << "Ar norite, kad programa generuotu atsitiktinius pazymius? 1-taip, 0-ne: ";
            cin >> sk;
            cout << endl;
            if (sk != "1" && sk != "0") {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Klaidingas ivedimas" << endl;
            }
        } while (sk != "1" && sk != "0");
        if (sk == "1") {
            atsitiktinis(temp, m);
        }
        else {
            cout << "Kai norite nustoti ivesti pazymius iveskite '0'" << endl;
            cout << "Iveskite pazymius: ";
            while (sk_paz != 0) {
                cin >> paz;
                if (numeris(paz)) {
                    sk_paz = stoi(paz);
                    if (sk_paz > 0 && sk_paz <= 10) {
                        temp[m].paz.push_back(sk_paz);
                    }
                    else if (sk_paz == 0) {
                        continue;
                    }
                    else {
                        cout << "Klaidingas ivedimas!" << endl;
                    }
                }
                else {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "Klaidingas ivedimas!" << endl;
                }
            }
            cout << "Iveskite egzamino bala: ";
            while (sk_egz < 0 or sk_egz > 10) {
                cin >> egz;
                while (numeris(egz) != true) {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "Klaidingas ivedimas!" << endl;
                    cin >> egz;
                }
                sk_egz = stoi(egz);
                if (sk_egz < 0 or sk_egz > 10) {
                    cout << "Klaidingas ivedimas!" << endl;
                }
                else {
                    temp[m].egz = sk_egz;
                }
            }  
        }
        m++;
        cout << "Iveskite varda ir pavarde: ";
    }
}

double vidurkis(vector<studentas> temp, int index) {
    double suma = 0, kiek = 0;
    for (int i = 0; i < temp[index].paz.size(); i++) {
        suma += temp[index].paz[i];
        kiek++;
    }
    return suma / kiek;
}

double mediana(vector<studentas> temp, int index) {
    double mediana = 0;
    if (temp[index].paz.size() % 2 != 0) {
        mediana = (double) (temp[index].paz[temp[index].paz.size() / 2]);
    }
    else {
        mediana = (double) (temp[index].paz[temp[index].paz.size() / 2] + temp[index].paz[temp[index].paz.size() / 2 - 1]) / 2;
    }
    return mediana;
}

void spausd(vector<studentas> temp, vector<double>galutinis) {
    cout << "Pavarde" << setw(20) << "Vardas" << setw(20) << "Galutinis (Vid.)" << "  /  " << "Galutinis (Med.)" << endl;
    cout << setfill('-') << setw(60) << "-" << endl;
    for (int i = 0; i < temp.size(); i++) {
        cout << left << setfill(' ') << setw(20) << temp[i].pavarde << setw(24) << temp[i].vardas;
        if (temp[i].gal == 1) {
            cout << left << setprecision(2) << setw(11) << galutinis[i] << setw(4) << "x.xx" << endl;
        }
        else {
            cout << left << setprecision(2) << setw(11) << "x.xx" << setw(4) << galutinis[i] << endl;
        }
    }
}

int main() {
    vector <studentas> stud;
    vector<double> galutinis;
    int m = 0;
    string skaiciuokle;
    pild(stud, m);
    for (int i = 0; i < stud.size(); i++) {
        cout << "Pasirinkite kokiu budu norite skaiciuoti galutini bala: '1' - vidurkiui, '0' - medianai: ";
        cin >> skaiciuokle;
        while (skaiciuokle != "1" && skaiciuokle != "0") {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Klaidingas ivedimas!" << endl;
            cout << "Pasirinkite kokiu budu norite skaiciuoti galutini bala: '1' - vidurkiui, '0' - medianai: ";
            cin >> skaiciuokle;
        }
        if (skaiciuokle == "1") {
            stud[i].gal = 1;
            galutinis.push_back(vidurkis(stud, i) * 0.4 + stud[i].egz * 0.6);
        }
        else {
            stud[i].gal = 0;
            galutinis.push_back(mediana(stud, i) * 0.4 + stud[i].egz * 0.6);
        }
    }
    spausd(stud, galutinis);
}
