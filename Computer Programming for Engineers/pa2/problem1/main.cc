#include <iostream>
#include <string>
#include "fraction.h"

using namespace std;
int main(){
  //write your code here
	string s1, temp; double d2; Fraction f1, f2;
	cin >> s1;
	while (!(cin >> d2)) {
		cout << "Incorrect Input\n";
		exit(1);
	}
	f1 = f1.str2Fraction(s1);
	f1.print();
	f2 = f2.double2Fraction(d2);
	f2.print();
	f1.sum(f1).print();
	f1.sum(d2).print();
	f2.multiply(f1).print();
	f2.multiply(d2).print();
	f1.toDouble();
	f2.toDouble();
  return 0;
}
