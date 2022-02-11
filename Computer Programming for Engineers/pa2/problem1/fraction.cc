#include "fraction.h"
#include <iostream>
#include <string>
using namespace std;

//Implement Member Functions
Fraction Fraction::sum(Fraction b) {
	Fraction f;
	f.D = b.D * D;
	f.NU = b.NU * D + NU * b.D;
	f.N = b.N + N;
	return f;
}
Fraction Fraction::sum(double b) {
	Fraction f1 = Fraction::double2Fraction(b);
	return this->sum(f1);
}
Fraction Fraction::multiply(Fraction b) {
	Fraction f;
	f.D = D * b.D;
	f.NU = (N * D + NU) * (b.N * b.D + b.NU);
	f.abbreviation();
	f.toMixedNum();
	return f;
}
Fraction Fraction::multiply(double b) {
	Fraction f;
	f = f.double2Fraction(b);
	return this->multiply(f);
}
void Fraction::abbreviation() {
	long long temp_nu = NU, temp_d = D, tmp, n;
	if (temp_nu < temp_d) {
		tmp = temp_nu; temp_nu = temp_d; temp_d = tmp;
	}
	while (temp_d != 0) {
		n = temp_nu % temp_d; temp_nu = temp_d; temp_d = n;
	}
	if (temp_nu == 0) return;
	else {
		NU /= temp_nu;
		D /= temp_nu;
	}
}
bool Fraction::toMixedNum() {
	if (NU == D) {
		N += 1;
		NU = 0; D = 0;
		return true;
	}
	else if (NU > D) {
		long long rem = NU / D;
		N += rem;
		NU -= rem * D;
		if (NU == 0) D = 0;
		return true;
	}
	else {
		return false;
	}
}
void Fraction::print() {
	toMixedNum();
	abbreviation();
	if (NU == 0) cout << N << " and " << NU << "/0\n";
	else cout << N << " and " << NU << "/" << D << "\n";
}
double Fraction::toDouble() {
	double ret;
	cout << fixed; cout.precision(6);
	if (D != 0) ret = N + (static_cast<double>(NU) / D);
	else ret = N;
	ret = static_cast<int>(ret * 1e5) / 1e5;
	cout << ret << "\n";
	cout.unsetf(ios::fixed);
	return ret;
}
Fraction Fraction::str2Fraction(std::string str) {
	Fraction f; string tok, temp; int pos = 0, chk = 0, count = 0;
	for (auto it = str.begin(); it < str.end(); it++) {
		if (*(str.end() - 1) == '/') {
			cout << "Incorrect Input\n";
			exit(1);
		}
		if (*str.begin() == '/') {
			str.insert(0, "0");
		}
		if (*it >= '0' && *it <= '9') continue;
		else if (*it == '/') {
			count++;
			if (it != str.end() - 1) {
				if (*(it + 1) == '/') {
					cout << "Incorrect Input\n";
					exit(1);
				}
			}
		}
		else {
			cout << "Incorrect Input\n";
			exit(1);
		}
	}
	if (count != 2) {
		cout << "Incorrect Input\n";
		exit(1);
	}
	for (int i = 0; i < 2; i++) {
		while ((pos = str.find('/')) != string::npos) {
			tok = str.substr(0, pos);
			temp = tok;
			str.erase(0, pos + 1);
			chk++;
			break;
		}
		if (chk == 1) f.N = stoi(temp);
	}
	f.NU = static_cast<long long>(stoi(temp));
	f.D = static_cast<long long>(stoi(str));
	if (f.D == 0) {
		cout << "Incorrect Input\n";
		exit(1);
	}
	return f;
}
Fraction Fraction::double2Fraction(double val) {
	Fraction f; double temp = val; int count = 0;
	f.N = static_cast<long long>(temp);
	temp -= f.N;
	f.D = static_cast <long long>(1e6);
	f.NU = static_cast<long long>(temp *= 1e6);
	return f;
}
