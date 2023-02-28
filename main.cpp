#include "MyLib.h"

struct studentas {
    string vardas, pavarde;
    int paz[100];
    int paz_sk;
    int egz;
    int gal;
    double gal_paz;
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

void atsitiktinis(studentas& temp, int m) {
    srand((unsigned int)time(NULL));
    int skaic, sk_kiek = -1;
    string kiek;
    do {
        cout << "Kiek bus pazymiu (Ne daugiau 100): ";
        cin >> kiek;
        if (numeris(kiek)) {
            if (stoi(kiek) < 0 or stoi(kiek) > 100) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Klaidingas ivedimas!" << endl;
            }
            else {
                sk_kiek = stoi(kiek);
                temp.paz_sk = sk_kiek;
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
        temp.paz[i] = skaic;
    }
    skaic = (rand() % 10) + 1;
    cout << "Egzamino pazymys: " << skaic << endl;
    temp.egz = skaic;
}

void pild(studentas& temp, int m) {
    m = -1;
    string t, egz, paz, sk, kiek;
    int sk_paz = -1, sk_egz = -1;
    cout << "Iveskite varda ir pavarde: ";
    cin >> temp.vardas;
    cin >> temp.pavarde;
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
        do {
            cout << "Iveskite kiek bus pazymiu (Ne daugiau 100): ";
            cin >> kiek;
            if (numeris(kiek)) {
                if (stoi(kiek) < 0 or stoi(kiek) > 100) {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "Klaidinga ivestis" << endl;
                }
                else {
                    m = stoi(kiek);
                }
            }
            else {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Klaidinga ivestis" << endl;
            }
        } while (m < 0);
        temp.paz_sk = m;
        cout << "Iveskite pazymius: ";
        for (int i = 0; i < m; i++) {
            cin >> paz;
            if (numeris(paz)) {
                sk_paz = stoi(paz);
                if (sk_paz > 0 && sk_paz <= 10) {
                    temp.paz[i] = sk_paz;
                }
                else {
                    cout << "Klaidingas ivedimas!" << endl;
                    i--;
                }
            }
            else {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Klaidingas ivedimas!" << endl;
                i--;
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
                temp.egz = sk_egz;
            }
        }
    }
}

double vidurkis(studentas temp) {
    double suma = 0, kiek = 0;
    for (int i = 0; i < temp.paz_sk; i++) {
        suma += temp.paz[i];
        kiek++;
    }
    return suma / kiek;
}

double mediana(studentas temp) {
    double mediana = 0;
    if ((temp.paz_sk % 2) != 0) {
        mediana = (double) (temp.paz[temp.paz_sk / 2]);
    }
    else {
        mediana = (double) (temp.paz[temp.paz_sk / 2 - 1] + temp.paz[temp.paz_sk / 2]) / 2;
    }
    return mediana;
}

void spausd(studentas temp) {
    cout << left << setfill(' ') << setw(20) << temp.pavarde << setw(24) << temp.vardas;
    if (temp.gal == 1) {
        cout << left << setprecision(3) << setw(11) << temp.gal_paz << setw(4) << "x.xx" << endl;
    }
    else {
        cout << left << setprecision(3) << setw(11) << "x.xx" << setw(4) << temp.gal_paz << endl;
    }
}

int main() {
    int m = -1, n = -1;
    string skaiciuokle, tikr;
    do {
        cout << "Iveskite kiek bus studentu: ";
        cin >> tikr;
        if (numeris(tikr)) {
            n = stoi(tikr);
            if (n < 0) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Klaidinga ivestis" << endl;
            }
        }
        else {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Klaidinga ivestis" << endl;
        } 
    } while (n < 0);
    studentas* stud = new studentas[n];
    for (int i = 0; i < n; i++) {
        pild(stud[i], m);
    }
    for (int i = 0; i < n; i++) {
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
            stud[i].gal_paz = vidurkis(stud[i]) * 0.4 + stud[i].egz * 0.6;
        }
        else {
            stud[i].gal = 0;
            stud[i].gal_paz = mediana(stud[i]) * 0.4 + stud[i].egz * 0.6;
        }
    }
    cout << "Pavarde" << setw(20) << "Vardas" << setw(20) << "Galutinis (Vid.)" << "  /  " << "Galutinis (Med.)" << endl;
    cout << setfill('-') << setw(60) << "-" << endl;
    for (int i = 0; i < n; i++) {
        spausd(stud[i]);
    }  
}
