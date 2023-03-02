#include "MyLib.h"

struct studentas {
    string vardas, pavarde;
    vector<int> paz;
    int egz;
    double suma = 0;
    double galutinis_vid;
    double galutinis_med;
    int gal = -1;
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
        temp[m].suma += skaic;
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

void pild_failas(vector <studentas>& temp, int& m) {
    string fill, x;
    fstream data_file("kursiokai.txt", ios_base::in);
    getline(data_file, fill);
    temp.push_back(studentas());
    data_file >> temp[m].vardas;
    data_file >> temp[m].pavarde;
    while (!data_file.eof()) {
        data_file >> x;
        while (numeris(x) && !data_file.eof()) {
            temp[m].paz.push_back(stoi(x));
            temp[m].suma += stoi(x);
            data_file >> x;
        }
        if (data_file.eof()) {
            temp[m].egz = stoi(x);
            m++;
        }
        else {
            temp[m].egz = temp[m].paz[temp[m].paz.size() - 1];
            temp[m].paz.pop_back();
            m++;
            temp.push_back(studentas());
            temp[m].vardas = x;
            data_file >> temp[m].pavarde;
        } 
    }
}

void spausd(vector<studentas> temp, string skaiciuokle) {
    fstream result_file("rezultatai.txt", ios_base::out);
    result_file << "Pavarde" << setw(20) << "Vardas" << setw(20) << "Galutinis (Vid.)" << "  /  " << "Galutinis (Med.)" << endl;
    result_file << setfill('-') << setw(60) << "-" << endl;
    if (skaiciuokle == "1") {
        for (int i = 0; i < temp.size(); i++) {
            result_file << left << setfill(' ') << setw(20) << temp[i].pavarde << setw(24) << temp[i].vardas;
            result_file << left << setprecision(2) << setw(11) << temp[i].galutinis_vid << setw(4) << "x.xx" << endl;
        }
    }
    else if (skaiciuokle == "0") {
        for (int i = 0; i < temp.size(); i++) {
            result_file << left << setfill(' ') << setw(20) << temp[i].pavarde << setw(24) << temp[i].vardas;
            result_file << left << setprecision(2) << setw(11) << "x.xx" << setw(4) << temp[i].galutinis_med << endl;
        }
    }
    else {
        for (int i = 0; i < temp.size(); i++) {
            result_file << left << setfill(' ') << setw(20) << temp[i].pavarde << setw(24) << temp[i].vardas;
            result_file << left << setprecision(2) << setw(11) << temp[i].galutinis_vid << setw(4) << temp[i].galutinis_med << endl;
        }
    }
    result_file.close();
}

int main() {
    vector <studentas> stud;
    int m = 0;
    string indeksas, skaiciuokle = "-1", rusiavimas;
    do {
        cout << "Ar norite duomenis ivesti patys ar norite nuskaityti is failo ('1' - ivesti patys, '0' - nuskaityti is failo): ";
        cin >> indeksas;
        if (indeksas == "1") {
            pild(stud, m);
        }
        else if (indeksas == "0") {
            pild_failas(stud, m);
        }
        else {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Klaidingas ivedimas!" << endl;
        }

    } while (indeksas != "1" && indeksas != "0");
    if (indeksas == "1") {
        cout << "Pasirinkite kokiu budu norite skaiciuoti galutini bala: '1' - vidurkiui, '0' - medianai: ";
        cin >> skaiciuokle;
        while (skaiciuokle != "1" && skaiciuokle != "0") {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Klaidingas ivedimas!" << endl;
            cout << "Pasirinkite kokiu budu norite skaiciuoti galutini bala: '1' - vidurkiui, '0' - medianai: ";
            cin >> skaiciuokle;
        }
        for (int i = 0; i < stud.size(); i++) {
            if (skaiciuokle == "1") {
                stud[i].gal = 1;
                stud[i].galutinis_vid = (stud[i].suma / stud[i].paz.size()) * 0.4 + stud[i].egz * 0.6;
            }
            else {
                stud[i].gal = 0;
                if (stud[i].paz.size() % 2 != 0) {
                    stud[i].galutinis_med = (double)(stud[i].paz[stud[i].paz.size() / 2]);
                }
                else {
                    stud[i].galutinis_med = (double)(stud[i].paz[stud[i].paz.size() / 2] + stud[i].paz[stud[i].paz.size() / 2 - 1]) / 2;
                }
            }
        }
    }
    else {
        for (int i = 0; i < stud.size(); i++) {
            stud[i].galutinis_vid = (stud[i].suma / stud[i].paz.size()) * 0.4 + stud[i].egz * 0.6;
            if (stud[i].paz.size() % 2 != 0) {
                stud[i].galutinis_med = (double)(stud[i].paz[stud[i].paz.size() / 2]);
            }
            else {
                stud[i].galutinis_med = (double)(stud[i].paz[stud[i].paz.size() / 2] + stud[i].paz[stud[i].paz.size() / 2 - 1]) / 2;
            }
        }
    }
    cout << "Pasirinkite kokiu budu norite isrusiuoti studentus: '1' - Pagal varda, '2' - Pagal pavarde, '3' - Pagal Galutini bala(Vid.), '4' - Pagal Galutini bala(Med.): ";
    cin >> rusiavimas;
    while (rusiavimas != "1" && rusiavimas != "2" && rusiavimas != "3" && rusiavimas != "4") {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Klaidingas ivedimas!" << endl;
        cin >> rusiavimas;
    }
    if (rusiavimas == "1") {
        sort(stud.begin(), stud.end(), lyginimas_1);
    }
    else if (rusiavimas == "2") {
        sort(stud.begin(), stud.end(), lyginimas_2);
    }
    else if (rusiavimas == "3") {
        sort(stud.begin(), stud.end(), lyginimas_3);
    }
    else {
        sort(stud.begin(), stud.end(), lyginimas_4);
    }
    spausd(stud, skaiciuokle);
}
