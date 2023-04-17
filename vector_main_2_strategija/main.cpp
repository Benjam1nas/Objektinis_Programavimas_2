#include "MyLib.h"
#include "header.h"
#include "func.cpp"
#include "generator.cpp"


int main() {
    time_point<high_resolution_clock> start, end;
    duration<double> laikas;
    double generavimo_laikas = 0, nuskaitymo_laikas, skirstymo_laikas, liudnuku_laikas, linksmuku_laikas, rusiavimo_laikas;
    int m = 0;
    string indeksas, skaiciuokle = "-1", rusiavimas, failai, pav, out_pav, testavimas;
    vector <studentas> stud, liudnukai;
    do {
        cout << "Ar norite duomenis ivesti patys ar norite nuskaityti is failo ('1' - ivesti patys, '0' - nuskaityti is failo): ";
        cin >> indeksas;
        if (indeksas == "1") {
            pild(stud, m);
        }
        else if (indeksas == "0") {
            cout << "Koki faila naudosite? 1 - jau sukurta, 0 - Norite sugeneruoti patys: "; cin >> failai;
            while (failai != "0" && failai != "1") {
                cout << "Klaidingas ivedimas!" << endl;
                cout << "Koki faila naudosite? 1 - jau sukurta, 0 - Norite sugeneruoti patys: "; 
                cin >> failai;
            }
            if (failai == "1") {
                cout << "Koks bus failo pavadinimas: ";
                cin >> pav;
                start = high_resolution_clock::now();
                pild_failas(stud, m, pav);
                end = high_resolution_clock::now();
                laikas = end - start;
                nuskaitymo_laikas = laikas.count();
            }
            else if (failai == "0") {
                cout << "Koks bus failo pavadinimas: ";
                cin >> pav;
                generavimas(pav, generavimo_laikas);

                start = high_resolution_clock::now();
                pild_failas(stud, m, pav);
                end = high_resolution_clock::now();
                laikas = end - start;
                nuskaitymo_laikas = laikas.count();
            }
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
    start = high_resolution_clock::now();
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
    end = high_resolution_clock::now();
    laikas = end - start;
    rusiavimo_laikas = laikas.count();

    start = high_resolution_clock::now();
    skirstymas(stud, liudnukai);
    end = high_resolution_clock::now();
    laikas = end - start;
    skirstymo_laikas = laikas.count();

    out_pav = "Liudnukai.txt";

    start = high_resolution_clock::now();
    spausd(liudnukai, skaiciuokle, out_pav);
    end = high_resolution_clock::now();
    laikas = end - start;
    liudnuku_laikas = laikas.count();

    out_pav = "Linksmukai.txt";

    start = high_resolution_clock::now();
    spausd(stud, skaiciuokle, out_pav);
    end = high_resolution_clock::now();
    laikas = end - start;
    linksmuku_laikas = laikas.count();

    //V.05 generavimo_laikas, linksmuku_laikas, liudnuku_laikas, bendras_laikas nera isvedamas, bet yra skaiciuojamas!
    cout << "Nuskaitymas is failo uztruko: " << setprecision(2) << nuskaitymo_laikas << endl
        << "Studentu rusiavimas uztruko: " << rusiavimo_laikas << endl
        << "Studentu suskirstymas uztruko: " << skirstymo_laikas << endl;
    return 0;
}