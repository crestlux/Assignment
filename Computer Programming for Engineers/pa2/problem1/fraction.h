#ifndef FRACTION_H
#define FRACTION_H
#include <string>

class Fraction{
  //Write class definition here
private:
	long long NU = 0; //numerator
	long long D = 0; //denominator
	long long N = 0; //integer
public:
	Fraction() {}
	Fraction sum(Fraction b);
	Fraction sum(double b);
	Fraction multiply(Fraction b);
	Fraction multiply(double b);
	void abbreviation();
	bool toMixedNum();
	void print();
	double toDouble();
	Fraction str2Fraction(std::string str);
	Fraction double2Fraction(double val);
};
#endif
