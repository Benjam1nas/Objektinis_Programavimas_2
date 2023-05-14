/**

@file main.cpp
@brief A program for managing student records and calculating their final grades.
The program allows the user to input student records manually or from a file, and calculate their final grades
using either the average or median method. The program can also sort the records by name or final grade.

*/
#include "header.h"
#include "MyLib.h"

/**

@brief Main function of the program

@return 0 on successful execution
*/

int main() {
    time_point<high_resolution_clock> start, end; /// Time points used to calculate execution times
    duration<double> laikas; /// Duration used to store execution times
    double generavimo_laikas = 0, nuskaitymo_laikas = 0, skirstymo_laikas = 0, liudnuku_laikas = 0, linksmuku_laikas = 0, rusiavimo_laikas = 0; /// Variables to store execution times
    int m = 0; /// Number of students
    string indeksas, skaiciuokle = "-1", rusiavimas, failai, pav, out_pav, testavimas; /// String variables for user input
    vector <studentas> stud, liudnukai; /// Vector of student records
    studentas st; /// Temporary student record object
 /**
 @brief Allows user to choose whether to input data or read it from a file.

 @details If the user chooses to input the data, the function pild() is called.
 If the user chooses to read data from a file, the function pild_failas() or generavimas()
 is called depending on the user's input, and then the data is read from the file.

 @param stud Vector of student objects.
 @param m Integer value indicating the number of grades for each student.

 @return None.
 */
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
 /**
 * @brief Calculates the final grade for each student using either the average or the median.
 *
 * @details If the user chooses to input the data, the final grade is calculated using
 * either the average or the median depending on the user's input. If the user chooses to
 * read the data from a file, the final grade is calculated using the average.
 *
 * @param stud Vector of student objects.
 * @param skaiciuokle String value indicating the method of calculation for the final grade ('1' - average, '0' - median).
 *
 * @return None.
 */
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
                stud[i].setGal(1);
                stud[i].setVid((stud[i].getSum() / stud[i].pazSize()) * 0.4 + stud[i].getEgz() * 0.6);
            }
            else {
                stud[i].setGal(0);
                if (stud[i].pazSize() % 2 != 0) {
                    stud[i].setMed((double)(stud[i].getPaz(stud[i].pazSize() / 2)));
                }
                else {
                    stud[i].setMed((double)stud[i].getPaz(stud[i].pazSize() / 2) + (double)(stud[i].getPaz(stud[i].pazSize() / 2 - 1) / 2));
                }
            }
        }
    }
    else {
        for (int i = 0; i < stud.size(); i++) {
            stud[i].setVid(stud[i].getSum() / stud[i].pazSize() * 0.4 + stud[i].getEgz() * 0.6);
            if (stud[i].pazSize() % 2 != 0) {
                stud[i].setMed((double)(stud[i].getPaz(stud[i].pazSize() / 2)));
            }
            else {
                stud[i].setMed((double)stud[i].getPaz(stud[i].pazSize() / 2) + (double)(stud[i].getPaz(stud[i].pazSize() / 2 - 1) / 2));
            }
        }
    }
/**
 * @brief Sorts the vector of student objects based on the user's choice.
 *
 * @details The vector is sorted based on the user's input, which can be either by name,
 * surname, final grade (average), or final grade (median).
 *
 * @param stud Vector of student objects.
 * @param rusiavimas String value indicating the sorting method ('1' - by name, '2' - by surname, '3' - by final grade (average), '4' - by final grade (median)).
 *
 * @return None.
*/
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

    cout << "Failo veikimo laikas: " << setprecision(2) << nuskaitymo_laikas + skirstymo_laikas + 
        liudnuku_laikas + linksmuku_laikas + rusiavimo_laikas << endl;
    return 0;
}
