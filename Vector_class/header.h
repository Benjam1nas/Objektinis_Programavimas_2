#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include "MyLib.h"

class zmogus {
protected:
    string vardas, pavarde;
public:
    zmogus() {
        vardas = "Vardenis";
        pavarde = "Pavardenis";
    }
    virtual void setVardas(string& vard) { vardas = vard; }
    virtual void setPavarde(string& pav) { pavarde = pav; }
    virtual void info() = 0;

};

class studentas : public zmogus {
private:
    vector<int> paz;
    int egz;
    double suma;
    double galutinis_vid;
    double galutinis_med;
    int gal;
public:
    studentas() : zmogus() {
        vardas = "Vardenis";
        pavarde = "Pavardenis";
        egz = 0;
        suma = 0;
        gal = -1;
    }

    // Destruktorius
    ~studentas() { paz.clear(); }

    // Copy konstruktorius
    studentas(const studentas& temp) {
        vardas = temp.vardas;
        pavarde = temp.pavarde;
        paz = temp.paz;
        egz = temp.egz;
        suma = temp.suma;
        galutinis_vid = temp.galutinis_vid;
        galutinis_med = temp.galutinis_med;
        gal = temp.gal;
    }

    // Copy priskirimo konstruktorius
    studentas& operator=(const studentas& temp) {
        if (this != &temp) {
            vardas = temp.vardas;
            pavarde = temp.pavarde;
            paz = temp.paz;
            egz = temp.egz;
            suma = temp.suma;
            galutinis_vid = temp.galutinis_vid;
            galutinis_med = temp.galutinis_med;
            gal = temp.gal;
        }
        return *this;
    }

    //Move konstruktorius 
    studentas(studentas&& temp) noexcept {
        vardas = std::move(temp.vardas);
        pavarde = std::move(temp.pavarde);
        paz = std::move(temp.paz);
        egz = std::move(temp.egz);
        suma = std::move(temp.suma);
        galutinis_vid = std::move(temp.galutinis_vid);
        galutinis_med = std::move(temp.galutinis_med);
        gal = std::move(temp.gal);

        temp.vardas = "";
        temp.pavarde = "";
        temp.egz = 0;
        temp.suma = 0;
        temp.galutinis_med = 0;
        temp.galutinis_vid = 0;
        temp.gal = -1;

    }

    //Move priskirimo konstruktorius
    studentas& operator=(studentas&& temp) noexcept {
        if (this != &temp) {
            vardas = std::move(temp.vardas);
            pavarde = std::move(temp.pavarde);
            paz = std::move(temp.paz);
            egz = std::move(temp.egz);
            suma = std::move(temp.suma);
            galutinis_vid = std::move(temp.galutinis_vid);
            galutinis_med = std::move(temp.galutinis_med);
            gal = std::move(temp.gal);

        }
        return *this;
    }

    //Input operatorius
    friend std::istream& operator>>(std::istream& input, studentas& studentas) {
        input >> studentas.vardas >> studentas.pavarde >> studentas.egz;
        return input;
    }

    //Output operatorius
    friend std::ostream& operator<<(std::ostream& output, const studentas& studentas) {
        output << studentas.vardas << " " << studentas.pavarde << " " << studentas.egz;
        return output;
    }


    inline string getVardas() const { return vardas; }
    void setVardas(string vardas_) { vardas = vardas_; }
    inline string getPavarde() const { return pavarde; }
    void setPavarde(string pavarde_) { pavarde = pavarde_; }

    int getPaz(int i) const { return paz.at(i); }
    int pazSize() const { return paz.size(); }
    void setPaz(int paz_) { paz.push_back(paz_); }
    void backPaz() { paz.pop_back(); }
    void clearPaz() { paz.clear(); }
    inline int getPazSize() { return paz.size(); }

    inline int getEgz() const { return egz; }
    void setEgz(int egz_) { egz = egz_; }

    inline double getMed() const { return galutinis_med; }
    void setMed(double med) { galutinis_med = med; }

    inline double getVid() const { return galutinis_vid; }
    void setVid(double vid) { galutinis_vid = vid; }

    inline double getSum() const { return suma; }
    void addSum(int sum) { suma += sum; }
    void minusSum(int sum) { suma -= sum; }
    void setSumNull() { suma = 0; }

    inline int getGal(int i) const { return gal; }
    void setGal(int gal_) { gal = gal_; }

    void info()
    {
        cout << getPavarde() << " " << getVardas() << " " << getEgz() << endl;
    }

};

bool numeris(string temp);
bool lyginimas_1(const studentas& a, const studentas& b);
bool lyginimas_2(const studentas& a, const studentas& b);
bool lyginimas_3(const studentas& a, const studentas& b);
bool lyginimas_4(const studentas& a, const studentas& b);
void atsitiktinis(studentas& temp, int m);
void pild(vector<studentas>& temp, int& m);
void pild_failas(vector <studentas>& temp, int& m, string pav);
void spausd(vector<studentas> temp, string skaiciuokle, string out_pav);
void generavimas(string& pav, double& generavimo_laikas);
void skirstymas(vector<studentas>& temp, vector<studentas>& liudnukai);

#endif
