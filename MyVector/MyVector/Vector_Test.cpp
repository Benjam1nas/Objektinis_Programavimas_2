#include "header.h"
#include "MyLib.h"

void testVector()
{
	unsigned int sz = 100000;  // 100000, 1000000, 10000000, 100000000
	time_point<high_resolution_clock> start, end;
	srand((unsigned int)time(NULL));
	duration<double> laikas;
	double veikimo_laikas = 0, veikimo_laikas_class = 0;
	std::vector<int> v1;
	start = high_resolution_clock::now();
	for (int i = 1; i <= sz; ++i) {
		v1.push_back(i);
	}	
	end = high_resolution_clock::now();
	laikas = end - start;
	veikimo_laikas = laikas.count();
	cout << sz << setprecision(2) << " elementu su originaliu uztruko " << veikimo_laikas << endl;

	MyVector<int> v2;
	start = high_resolution_clock::now();
	for (int i = 1; i <= sz; ++i) {
		v2.push_back(i);
	}	
	end = high_resolution_clock::now();
	laikas = end - start;
	veikimo_laikas_class = laikas.count();
	cout << sz << setprecision(2) << " elementu su mano uztruko " << veikimo_laikas_class << endl;
}
