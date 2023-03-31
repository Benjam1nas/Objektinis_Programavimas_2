#include "MyLib.h"
#include "header.h"

bool numeris(string temp) {
    bool tiesa = true;
    for (int i = 0; i < temp.size(); i++) {
        if (isdigit(temp[i]) == 0) {
            tiesa = false;
        }
    }
    return tiesa;
}

bool lyginimas_1(const studentas& a, const studentas& b) {
    return a.vardas < b.vardas;
}

bool lyginimas_2(const studentas& a, const studentas& b) {
    return a.pavarde < b.pavarde;
}

bool lyginimas_3(const studentas& a, const studentas& b) {
    return a.galutinis_vid < b.galutinis_vid;
}

bool lyginimas_4(const studentas& a, const studentas& b) {
    return a.galutinis_med < b.galutinis_med;
}

void atsitiktinis(deque<studentas>& temp, int m) {
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
        temp[m].suma += skaic;
    }
    skaic = (rand() % 10) + 1;
    cout << "Egzamino pazymys: " << skaic << endl;
    temp[m].egz = skaic;
}

void pild(deque<studentas>& temp, int& m) {
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
                        temp[m].suma += sk_paz;
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
            while (sk_egz < 0 || sk_egz > 10) {
                cin >> egz;
                while (numeris(egz) != true) {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "Klaidingas ivedimas!" << endl;
                    cin >> egz;
                }
                sk_egz = stoi(egz);
                if (sk_egz < 0 || sk_egz > 10) {
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

void pild_failas(deque <studentas>& temp, int& m, string pav) {
    string fill, x;
    bool yra = true;
    try {
        ifstream data_file(pav);
        if (!data_file) {
            throw (!yra);
        }
        else {
            throw (yra);
        }
    }
    catch (bool yra) {
        if (!yra) {
            cout << "Programa neranda duomenu failo!" << endl;
        }
        else {
            cout << "Sekmingai atidarytas duomenu failas!" << endl;
        }
    }
    ifstream data_file(pav);
    getline(data_file, fill);
    temp.push_back(studentas());
    data_file >> temp[m].vardas;
    data_file >> temp[m].pavarde;
    while (data_file >> x) {
        while (numeris(x) && !data_file.eof()) {
            temp[m].paz.push_back(stoi(x));
            temp[m].suma += stoi(x);
            data_file >> x;
        }
        if (data_file.eof()) {
            temp[m].egz = stoi(x);
        }
        else {
            temp[m].egz = temp[m].paz[temp[m].paz.size() - 1];
            temp[m].suma -= temp[m].egz;
            temp[m].paz.pop_back();
            m++;
            temp.push_back(studentas());
            temp[m].vardas = x;
            data_file >> temp[m].pavarde;
        }
    }
    data_file.close();

}

void skirstymas(deque<studentas>& temp, deque<studentas>& liudnukai, deque<studentas>& linksmukai) {
    for (auto& i : temp) {
        if (i.galutinis_vid < 5.0) {
            liudnukai.push_back(i);
        }
        else if (i.galutinis_vid >= 5.0) {
            linksmukai.push_back(i);
        }
    }
}

void spausd(deque<studentas> temp, string skaiciuokle, string out_pav) {
    ofstream zmogeliukai(out_pav);
    char eilut[100];
    zmogeliukai << "Pavarde" << setw(20) << "Vardas" << setw(20) << "Galutinis (Vid.)" << "  /  " << "Galutinis (Med.)" << endl;
    zmogeliukai << setfill('-') << setw(60) << "-" << endl;
    string filler = "x.xx";
    if (skaiciuokle == "1") {
        for (int i = 0; i < temp.size(); i++) {
            sprintf_s(eilut, "% *s % *s % *.2f % *s\n", -20, temp[i].pavarde.c_str(), -20, temp[i].vardas.c_str(), 5, temp[i].galutinis_vid, 5, filler.c_str());
            zmogeliukai << eilut;
        }
    }
    else if (skaiciuokle == "0") {
        for (int i = 0; i < temp.size(); i++) {
            sprintf_s(eilut, "% *s % *s % *s % *.2f\n", -20, temp[i].pavarde.c_str(), -20, temp[i].vardas.c_str(), 5, filler.c_str(), 5, temp[i].galutinis_med);
            zmogeliukai << eilut;
        }
    }
    else {
        for (int i = 0; i < temp.size(); i++) {
            sprintf_s(eilut, "% *s % *s % *.2f % *.2f\n", -20, temp[i].pavarde.c_str(), -20, temp[i].vardas.c_str(), 5, temp[i].galutinis_vid, 5, temp[i].galutinis_med);
            zmogeliukai << eilut;
        }
    }
    zmogeliukai.close();
}