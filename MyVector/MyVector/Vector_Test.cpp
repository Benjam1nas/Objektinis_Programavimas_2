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
	for (int i = 1; i <= sz; ++i) { //Push_back testas
		v2.push_back(i);
	}	
	end = high_resolution_clock::now();
	laikas = end - start;
	veikimo_laikas_class = laikas.count();
	cout << sz << setprecision(2) << " elementu su mano uztruko " << veikimo_laikas_class << endl;

	cout << "Vektoriaus dydis pries pop_back: " << v2.size() << endl;

	for (int i = 1; i <= sz / 2; i++) { //pop_back testas
		v2.pop_back();
	}
	
	cout << "Vektoriaus dydis po pop_back: " << v2.size() << endl;

	cout << "Vektoriaus capacity pries reserve: " << v2.capacity() << endl; //reserve testas
	v2.reserve(10000000);
	cout << "Vektoriaus capacity po reserve: " << v2.capacity() << endl;

	cout << "Vektoriaus dydis prie resize: " << v2.size() << endl; //resize testas
	v2.resize(100);
	cout << "Vektoriaus dydis po resize: " << v2.size() << endl;

	cout << "Vektoriaus dydis pries shrink_to_fit: " << v2.capacity() << endl; //shrink_to_fit
	v2.shrink_to_fit();
	cout << "Vektoriaus dydis po shrink_to_fit: " << v2.capacity() << endl;
}
