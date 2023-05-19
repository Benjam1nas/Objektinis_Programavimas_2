/**
 * @file func.cpp
 * @brief This file includes all program functions
 */
#include "header.h"
 //#include "MyLib.h"

  /**
   * @brief Check if a string consists only of digits.
   *
   * @param temp The string to check.
   * @return true if all characters in the string are digits, false otherwise.
   */
bool numeris(string temp) {
    bool tiesa = true;
    for (int i = 0; i < temp.size(); i++) {
        if (isdigit(temp[i]) == 0) {
            tiesa = false;
        }
    }
    return tiesa;
}

/**
 * @brief Compare two students by their first names.
 *
 * @param a The first student to compare.
 * @param b The second student to compare.
 * @return true if the first student's first name is lexicographically smaller than the second student's first name, false otherwise.
 */
bool lyginimas_1(const studentas& a, const studentas& b) {
    return a.getVardas() < b.getVardas();
}

/**
 * @brief Compare two students by their last names.
 *
 * @param a The first student to compare.
 * @param b The second student to compare.
 * @return true if the first student's last name is lexicographically smaller than the second student's last name, false otherwise.
 */
bool lyginimas_2(const studentas& a, const studentas& b) {
    return a.getPavarde() < b.getPavarde();
}

/**
 * @brief Compare two students by their average grade.
 *
 * @param a The first student to compare.
 * @param b The second student to compare.
 * @return true if the first student's average grade is smaller than the second student's average grade, false otherwise.
 */
bool lyginimas_3(const studentas& a, const studentas& b) {
    return a.getVid() < b.getVid();
}

/**
 * @brief Compare two students by their median grade.
 *
 * @param a The first student to compare.
 * @param b The second student to compare.
 * @return true if the first student's median grade is smaller than the second student's median grade, false otherwise.
 */
bool lyginimas_4(const studentas& a, const studentas& b) {
    return a.getMed() < b.getMed();
}

/**
 * @brief Generate random grades for a student.
 *
 * The function generates a random number of grades and sets them for the given student.
 *
 * @param temp The student to generate grades for.
 * @param m The number of students.
 */
void atsitiktinis(studentas& temp, int m) {
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
        temp.setPaz(skaic);
        temp.addSum(skaic);
    }
    skaic = (rand() % 10) + 1;
    cout << "Egzamino pazymys: " << skaic << endl;
    temp.setEgz(skaic);
}

/**
 * @brief Read student data from user input.
 *
 * The function reads student data from user input and stores it in a vector.
 *
 * @param temp The vector to store the student data in.
 * @param m The number of students.
 */
void pild(vector<studentas>& temp, int& m) {
    studentas st;
    string t, egz, paz, sk;
    int sk_paz = -1, sk_egz = -1;
    cout << "Jei norite, kad programa sustotu iveskite 'Stop'" << endl;
    cout << "Iveskite varda ir pavarde: ";
    while (cin >> t && t != "Stop") {
        st.setVardas(t);
        cin >> t;
        st.setPavarde(t);
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
            atsitiktinis(st, m);
        }
        else {
            cout << "Kai norite nustoti ivesti pazymius iveskite '0'" << endl;
            cout << "Iveskite pazymius: ";
            while (sk_paz != 0) {
                cin >> paz;
                if (numeris(paz)) {
                    sk_paz = stoi(paz);
                    if (sk_paz > 0 && sk_paz <= 10) {
                        st.setPaz(sk_paz);
                        st.addSum(sk_paz);
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
                    st.setEgz(sk_egz);
                }
            }
        }
        m++;
        temp.push_back(st);
        st.setSumNull();
        st.clearPaz();
        cout << "Iveskite varda ir pavarde: ";
    }
}

/**
 * @brief Read student data from a file.
 *
 * The function reads student data from a file and stores it in a vector.
 *
 * @param temp The vector to store the student data in.
 * @param m The number of students.
 * @param pav The path to the file.
 */
void pild_failas(vector <studentas>& temp, int& m, string pav) {
    int count = 0;
    studentas st;
    string fill, x, t;
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
    data_file >> t;
    st.setVardas(t);
    data_file >> t;
    st.setPavarde(t);
    while (data_file >> x) {
        while (numeris(x) && !data_file.eof()) {
            st.setPaz(stoi(x));
            st.addSum(stoi(x));
            data_file >> x;
        }
        if (data_file.eof()) {
            st.setEgz(stoi(x));
        }
        else {
            st.setEgz(st.getPaz(st.pazSize() - 1));
            st.minusSum(st.getPaz(st.pazSize() - 1));
            st.backPaz();
            m++;
            temp.push_back(st);
            if (temp.size() == temp.capacity()) {
                count++;
            }
            st.clearPaz();
            st.setSumNull();
            st.setVardas(x);
            data_file >> t;
            st.setPavarde(t);
        }
    }
    data_file.close();
    cout << count;
}

/**
@brief Splits the students into two groups based on their average score

This function splits the given vector of students into two groups based on their
average score. The students whose average score is less than 5.0 are moved to the
second vector, and the remaining students are left in the first vector.

@param temp The vector of students to split
@param liudnukai The vector to move the students with less than 5.0 average score
*/
void skirstymas(vector<studentas>& temp, vector<studentas>& liudnukai) {
    std::copy_if(temp.begin(), temp.end(),
        std::back_inserter(liudnukai), [](const auto& i) {return i.getVid() < 5.0; });

    temp.erase(std::remove_if(temp.begin(), temp.end(),
        [](const auto& i) { return i.getVid() < 5.0; }));
}

/**
@brief Prints the student data to a file

This function prints the data of the given vector of students to a file. The file name is
given as an argument. The function also takes a string argument to specify whether to
calculate the final grade using average or median score.

@param temp The vector of students whose data needs to be printed
@param skaiciuokle A string to specify how to calculate the final grade (average or median)
@param out_pav The name of the file to write the output to
*/
void spausd(vector<studentas> temp, string skaiciuokle, string out_pav) {
    ofstream zmogeliukai(out_pav);
    char eilut[100];
    zmogeliukai << "Pavarde" << setw(20) << "Vardas" << setw(20) << "Galutinis (Vid.)" << "  /  " << "Galutinis (Med.)" << endl;
    zmogeliukai << setfill('-') << setw(60) << "-" << endl;
    string filler = "x.xx";
    if (skaiciuokle == "1") {
        for (int i = 0; i < temp.size(); i++) {
            sprintf_s(eilut, "% *s % *s % *.2f % *s\n", -20, temp[i].getPavarde().c_str(), -20, temp[i].getVardas().c_str(), 5, temp[i].getVid(), 5, filler.c_str());
            zmogeliukai << eilut;
        }
    }
    else if (skaiciuokle == "0") {
        for (int i = 0; i < temp.size(); i++) {
            sprintf_s(eilut, "% *s % *s % *s % *.2f\n", -20, temp[i].getPavarde().c_str(), -20, temp[i].getVardas().c_str(), 5, filler.c_str(), 5, temp[i].getMed());
            zmogeliukai << eilut;
        }
    }
    else {
        for (int i = 0; i < temp.size(); i++) {
            sprintf_s(eilut, "% *s % *s % *.2f % *.2f\n", -20, temp[i].getPavarde().c_str(), -20, temp[i].getVardas().c_str(), 5, temp[i].getVid(), 5, temp[i].getMed());
            zmogeliukai << eilut;
        }
    }
    zmogeliukai.close();
}