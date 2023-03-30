#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

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

bool numeris(string temp);
bool lyginimas_1(const studentas& a, const studentas& b);
bool lyginimas_2(const studentas& a, const studentas& b);
bool lyginimas_3(const studentas& a, const studentas& b);
bool lyginimas_4(const studentas& a, const studentas& b);
void atsitiktinis(vector<studentas>& temp, int m);
void pild(vector<studentas>& temp, int& m);
void pild_failas(vector <studentas>& temp, int& m, string pav);
void spausd(vector<studentas> temp, string skaiciuokle, string out_pav);
void generavimas(string& pav, double &generavimo_laikas);
void skirstymas(vector<studentas>& temp, vector<studentas>& liudnukai, vector<studentas>& linksmukai);

#endif
