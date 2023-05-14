#pragma once
#ifndef _DLL_H_
#define _DLL_H_

#include <iostream>
#include <stdio.h>
#include <windows.h>

#ifdef DLL_EXPORTS
#define DLL_API __declspec(dllexport)
#else
#define DLL_API __declspec(dllimport)
#endif

#include <iomanip>      /// Input/output manipulators
#include <string>       /// String library
#include <algorithm>    /// Algorithms library
#include <vector>       /// Vector library
#include <fstream>      /// File stream library
#include <cstdlib>      /// Standard library utilities
#include <sstream>      /// String stream library
#include <chrono>       /// Time utilities library
#include <random>       /// Random number generators library

using std::cout;        /// Standard output stream
using std::cin;         /// Standard input stream
using std::endl;        /// Standard end-of-line marker
using std::left;        /// Output manipulator for left-justified output
using std::right;       /// Output manipulator for right-justified output
using std::setw;        /// Output manipulator for setting width of output
using std::setprecision; /// Output manipulator for setting precision of floating-point output
using std::fixed;       /// Output manipulator for setting floating-point output to fixed notation
using std::setfill;     /// Output manipulator for filling output with a certain character
using std::string;      /// String data type
using std::stoi;        /// String-to-integer conversion function
using std::isdigit;     /// Determines if a character is a digit
using std::copy;        /// Copies elements from one range to another
using std::vector;      /// Dynamic array data structure
using std::fstream;     /// File stream
using std::ios_base;    /// Base class for stream formatting
using std::getline;     /// Reads a line from input stream
using std::sort;        /// Sorts elements in a range
using std::ofstream;    /// Output file stream
using std::stringstream;/// String stream class for string manipulation
using std::ifstream;    /// Input file stream
using std::to_string;   /// Converts various data types to string
using namespace std::chrono; /// Contains classes for time manipulation


extern "C"
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

extern "C"
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

extern "C"
DLL_API bool numeris(string temp);

extern "C"
DLL_API bool lyginimas_1(const studentas& a, const studentas& b);

extern "C"
DLL_API bool lyginimas_2(const studentas& a, const studentas& b);

extern "C"
DLL_API bool lyginimas_3(const studentas& a, const studentas& b);

extern "C"
DLL_API bool lyginimas_4(const studentas& a, const studentas& b);

extern "C"
DLL_API void atsitiktinis(studentas& temp, int m);

extern "C"
DLL_API void pild(vector<studentas>& temp, int& m);

extern "C"
DLL_API void pild_failas(vector <studentas>& temp, int& m, string pav);

extern "C"
DLL_API void spausd(vector<studentas> temp, string skaiciuokle, string out_pav);

extern "C"
DLL_API void generavimas(string& pav, double& generavimo_laikas);

extern "C"
DLL_API void skirstymas(vector<studentas>& temp, vector<studentas>& liudnukai);

#endif
