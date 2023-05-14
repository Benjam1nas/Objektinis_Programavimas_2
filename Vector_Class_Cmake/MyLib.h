/**
 * @file MyLib.h
 * @brief This file includes the standard library headers and declares the using statements
 */

#include <iostream>     /// Input/output stream
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