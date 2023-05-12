/**

@file header.h
@brief Header file containing declarations of classes and functions used for processing student data.
This file contains the declarations of two classes, "zmogus" and "studentas", which are used for
representing people and students, respectively. The "zmogus" class has two protected string members,
"vardas" and "pavarde", and a pure virtual function "info()". The "studentas" class is a derived class
of "zmogus" and has additional members and functions for storing and processing student data.
In addition, the file contains declarations of several functions that are used for various purposes,
such as checking if a string represents a number, comparing student objects, generating random data,
and reading/writing data to files.
*/

#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include "MyLib.h"

class zmogus {
protected: 
    string vardas, pavarde;
public:
/**
* @brief Default constructor for the "zmogus" class.
*
* Initializes the "vardas" and "pavarde" string members to default values.
*/
    zmogus() {
        vardas = "Vardenis";
        pavarde = "Pavardenis";
    }
    /**
    * @brief Pure virtual function for printing information about the person.
    *
    * This function is declared as pure virtual, meaning it must be defined in derived classes.
    */
    virtual void info() = 0;

    /**
     * @brief Function for setting the "vardas" member of the object.
     *
     * @param vard Reference to the string that will be assigned to the "vardas" member.
     */
    virtual void setVardas(string& vard) { vardas = vard; }

    /**
     * @brief Function for setting the "pavarde" member of the object.
     *
     * @param pav Reference to the string that will be assigned to the "pavarde" member.
     */
    virtual void setPavarde(string& pav) { pavarde = pav; }

};

class studentas : public zmogus {
private:
    string vardas, pavarde; // name, surname
    vector<int> paz; // grades
    int egz; // exam grade
    double suma; // sum of grades
    double galutinis_vid; // final grade calculated using average method
    double galutinis_med; // final grade calculated using median method
    int gal; // final grade (0-10)
    /**
    * @brief Default constructor for the "studentas" class.
    *
    * Initializes the "egz", "suma", and "gal" members to default values.
    */
public:
    /**
    * @brief Destructor for the "studentas" class.
    *
    * Clears the "paz" vector.
    */
    studentas() {
        egz = 0;
        suma = 0;
        gal = -1;
    }
    ~studentas() { paz.clear(); }

    /**
     * @brief Copy constructor for the "studentas" class.
     *
     * @param temp The object to be copied.
     */
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

    /**

    @brief Assignment operator for studentas class.
    @param temp Reference to studentas object to be copied.
    @return Reference to the current object (this).
    */
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
    /**

    @brief Returns the student's name.
    @return String containing the student's name.
    */
    inline string getVardas() const { return vardas; }
    /**

    @brief Sets the student's name.
    @param vardas_ New name for the student.
    */
    void setVardas(string vardas_) { vardas = vardas_; }
    /**

    @brief Returns the student's surname.
    @return String containing the student's surname.
    */
    inline string getPavarde() const { return pavarde; }
    /**

    @brief Sets the student's surname.
    @param pavarde_ New surname for the student.
    */
    void setPavarde(string pavarde_) { pavarde = pavarde_; }
    /**

    @brief Returns the i-th grade of the student.
    @param i Index of the grade to be returned.
    @return Value of the i-th grade.
    */
    int getPaz(int i) const { return paz.at(i); }
    /**

    @brief Returns the number of grades for the student.
    @return Number of grades in the paz vector.
    */
    int pazSize() const { return paz.size(); }
    /**

    @brief Adds a new grade to the student's list of grades.
    @param paz_ Value of the new grade to be added.
    */
    void setPaz(int paz_) { paz.push_back(paz_); }
    /**

    @brief Removes the last grade from the student's list of grades.
    */
    void backPaz() { paz.pop_back(); }
    /**

    @brief Removes all grades from the student's list of grades.
    */
    void clearPaz() { paz.clear(); }
    /**

    @brief Returns the size of the paz vector.
    @return Number of grades in the paz vector.
    */
    inline int getPazSize() { return paz.size(); }
    /**

    @brief Returns the student's final exam grade.
    @return Value of the final exam grade.
    */
    inline int getEgz() const { return egz; }
    /**

    @brief Sets the student's final exam grade.
    @param egz_ New value for the final exam grade.
    */
    void setEgz(int egz_) { egz = egz_; }
    /**

    @brief Returns the student's final grade calculated using the median method.
    @return Value of the final grade.
    */
    inline double getMed() const { return galutinis_med; }
    /**

    @brief Sets the student's final grade calculated using the median method.
    @param med New value for the final grade.
    */
    void setMed(double med) { galutinis_med = med; }
    /**

    @brief Returns the student's final grade calculated using the average method.
    @return Value of the final grade.
    */
    inline double getVid() const { return galutinis_vid; }
    /**

    @brief Sets the student's final grade calculated using the average method.
    @param vid New value for the final grade.
    */
    void setVid(double vid) { galutinis_vid = vid; }
    /**

    @brief Returns the sum of all grades for the student.
    @return Value of the sum of all grades.
    */
    inline double getSum() const { return suma; }
    /**

    @brief Adds a grade to the sum.
    @param sum The grade to be added to the sum.
    */
    void addSum(int sum) { suma += sum; }
    /**

    @brief Subtracts a grade from the sum.
    @param sum The grade to be subtracted from the sum.
    */
    void minusSum(int sum) { suma -= sum; }
    /**

    @brief Sets the sum of grades to 0.
    */
    void setSumNull() { suma = 0; }
    /**

    @brief Returns the final grade of a student.
    @param i Index of the final grade to be returned.
    @return The final grade of a student.
    */
    inline int getGal(int i) const { return gal; }
    /**

    @brief Sets the final grade of a student.
    @param gal_ The final grade to be set.
    */
    void setGal(int gal_) { gal = gal_; }
    /**

    @brief Prints the last name, first name, and exam grade of a student.
    */
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
