#include "MyLib.h"
#include "header.h"
#include "func.cpp"



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
