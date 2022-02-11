#include "calculator.h"
#include <iostream>
#include <cmath>
#include <regex>
using namespace std;

//Implement Member Functions

float Calculator::addition() {
	return ans = a + b;
}
float Calculator::subtraction() {
	return ans = a - b;
}
float Calculator::multiplication() {
	return ans = a * b;
}
float Calculator::division() {
	if (b == 0) {
		cout << "Answer: Operation disallowed\n";
		exit(1);
	}
	else return ans = a / b;
}
int Calculator::remainder() {
	if (static_cast<int>(b) == 0) {
		cout << "Answer: Operation disallowed\n";
		exit(1);
	}
	else return ans = static_cast<int>(a) % static_cast<int>(b);
}
int Calculator::exponentiation() {
	if (a > 10 || a < 0 || b > 10 || b < 0) {
		cout << "Invalid input\n";
		exit(1);
	}
	return ans = static_cast<float>(pow(a, static_cast<int>(b)));
}
void Calculator::print() {
	if (cout.precision() == 5) { cout << "Answer: " << ans << "\n"; }
	else if (cout.precision() == 0) { cout << "Answer: " << static_cast<int>(ans) << "\n"; }
}
void Calculator::parse(string s1) {
	vector<string> op; vector<string> num;
	int numcnt = 0, valcnt = 0, opcnt = 0; bool flagchanged = false, input_assg = false;
	bool xi = false, yi = false, zi = false;
	op.clear(); num.clear();
	const regex regop("[\\+\\-\\*\\/\\^\\%\\=]");
	const regex regnum("(\\d*\\.?\\d+)|[xyz]");
	const regex all("[^0-9\\+\\-\\*\\/\\^\\%\\=\\.x-z]|[x-z]{2,}|[\\+\\-\\*\\/\\^\\%\\=\\.]{2,}|^[\\+\\-\\*\\/\\^\\%\\=\\.].*|.*[\\+\\-\\*\\/\\^\\%\\=\\.]$|[x-z][\\.]?[0-9]|[0-9][\\.]?[x-z]|(.*\\..*){2,}");
	const regex regfloat("[\\.\\=x-z]");
	s1.erase(remove(s1.begin(), s1.end(), ' '), s1.end());
	auto all_begin = sregex_iterator(s1.begin(), s1.end(), all);
	auto all_end = sregex_iterator();
	for (auto i = all_begin; i != all_end; ++i) {
		cout << "Invalid input\n";
		exit(1);
	}
	for (auto i = sregex_iterator(s1.begin(), s1.end(), regnum); i != sregex_iterator(); ++i) {
		if ((*i).str() == "x" || (*i).str() == "y" || (*i).str() == "z") valcnt++;
		num.push_back((*i).str());
	}
	for (auto i = sregex_iterator(s1.begin(), s1.end(), regfloat); i != sregex_iterator(); ++i) {
		if ((*i).str() == ".") { input_float = true; flagchanged = true; continue; }
		else if ((*i).str() == "=") { input_assg = true; continue; }
		else if ((*i).str() == "x") { xi = true; continue; }
		else if ((*i).str() == "y") { yi = true; continue; }
		else if ((*i).str() == "z") { zi = true; continue; }
	}

	if (xi == true && flagchanged == true && input_assg == true) { x_float = true; flagchanged = false; input_assg = false; xi = false; }
	else if (xi == true && flagchanged == false && input_assg == true) { x_float = false; flagchanged = false; input_assg = false; xi = false; }
	else if (yi == true && flagchanged == true && input_assg == true) { y_float = true; flagchanged = false; input_assg = false; yi = false; }
	else if (yi == true && flagchanged == false && input_assg == true) { y_float = false; flagchanged = false; input_assg = false; yi = false; }
	else if (zi == true && flagchanged == true && input_assg == true) { z_float = true; flagchanged = false; input_assg = false; zi = false; }
	else if (zi == true && flagchanged == false && input_assg == true) { z_float = false; flagchanged = false; input_assg = false; zi = false; }

	if (flagchanged == false) {
		input_float = false;
	}
	flagchanged = false; //needs improvement
	numcnt = num.size() - valcnt;
	for (auto i = sregex_iterator(s1.begin(), s1.end(), regop); i != sregex_iterator(); ++i) {
		if ((*i).str() == "=") {
			if (valcnt == 1) {
				if (num[0] == "x") {
					x = stof(num[1]); continue;
				}
				else if (num[0] == "y") {
					y = stof(num[1]); continue;
				}
				else if (num[0] == "z") {
					z = stof(num[1]); continue;
				}
				if (num[1] == "x") {
					x = stof(num[0]); continue;
				}
				else if (num[1] == "y") {
					y = stof(num[0]); continue;
				}
				else if (num[1] == "z") {
					z = stof(num[0]); continue;
				}
			}
			if (valcnt == 2) {
				if (num[0] == "x" && num[1] == "y") {
					x = y; 
					if (y_float == true) x_float = true;
					else x_float = false;
					continue;
				}
				else if (num[0] == "x" && num[1] == "z") {
					x = z; 
					if (z_float == true) x_float = true;
					else x_float = false;
					continue;
				}
				else if (num[0] == "y" && num[1] == "x") {
					y = x; 
					if (x_float == true) y_float = true;
					else y_float = false;
					continue;
				}
				else if (num[0] == "y" && num[1] == "z") {
					y = z; 
					if (z_float == true) y_float = true;
					else y_float = false;
					continue;
				}
				else if (num[0] == "z" && num[1] == "x") {
					z = x; 
					if (x_float == true) z_float = true;
					else z_float = false;
					continue;
				}
				else if (num[0] == "z" && num[1] == "y") {
					z = y; 
					if (y_float == true) z_float = true;
					else z_float = false;
					continue;
				}
			}
			continue;
		}
		if (valcnt == 0) {
			a = stof(num[0]);
			b = stof(num[1]);
			if (input_float == true) { cout << fixed; cout.precision(5); }
			else { cout << fixed; cout.precision(0); }
		}
		else if (valcnt == 1) {
			if (num[0] == "x") {
				a = x; b = stof(num[1]);
				if (x_float == true || input_float == true) { cout << fixed; cout.precision(5); }
				else { cout << fixed; cout.precision(0); }
			}
			else if (num[0] == "y") {
				a = y; b = stof(num[1]);
				if (y_float == true || input_float == true) { cout << fixed; cout.precision(5); }
				else { cout << fixed; cout.precision(0); }
			}
			else if (num[0] == "z") {
				a = z; b = stof(num[1]);
				if (z_float == true || input_float == true) { cout << fixed; cout.precision(5); }
				else { cout << fixed; cout.precision(0); }
			}
			if (num[1] == "x") {
				a = stof(num[0]); b = x;
				if (x_float == true || input_float == true) { cout << fixed; cout.precision(5); }
				else { cout << fixed; cout.precision(0); }
			}
			else if (num[1] == "y") {
				a = stof(num[0]); b = y;
				if (y_float == true || input_float == true) { cout << fixed; cout.precision(5); }
				else { cout << fixed; cout.precision(0); }
			}
			else if (num[1] == "z") {
				a = stof(num[0]); b = z;
				if (z_float == true || input_float == true) { cout << fixed; cout.precision(5); }
				else { cout << fixed; cout.precision(0); }
			}
		}
		else {
			char input1, input2;
			if (num[0] == "x") { a = x; input1 = 'x'; }
			else if (num[0] == "y") { a = y; input1 = 'y'; }
			else if (num[0] == "z") { a = z; input1 = 'z'; }
			if (num[1] == "x") { b = x; input2 = 'x'; }
			else if (num[1] == "y") { b = y; input2 = 'y'; }
			else if (num[1] == "z") { b = z; input2 = 'z'; }
			if ((input1 == 'x' && input2 == 'y') || (input1 == 'y' && input2 == 'x')) {
				if (x_float == true || y_float == true) {
					cout << fixed; cout.precision(5);
				}
				else {
					cout << fixed; cout.precision(0);
				}
			}
			if ((input1 == 'x' && input2 == 'z') || (input1 == 'z' && input2 == 'x')) {
				if (x_float == true || y_float == true) {
					cout << fixed; cout.precision(5);
				}
				else {
					cout << fixed; cout.precision(0);
				}
			}
			if ((input1 == 'y' && input2 == 'z') || (input1 == 'z' && input2 == 'x')) {
				if (x_float == true || y_float == true) {
					cout << fixed; cout.precision(5);
				}
				else {
					cout << fixed; cout.precision(0);
				}
			}
			if ((input1 == 'x' && input2 == 'x')) {
				if (x_float == true) {
					cout << fixed; cout.precision(5);
				}
				else {
					cout << fixed; cout.precision(0);
				}
			}
			if ((input1 == 'y' && input2 == 'y')) {
				if (y_float == true) {
					cout << fixed; cout.precision(5);
				}
				else {
					cout << fixed; cout.precision(0);
				}
			}
			if ((input1 == 'z' && input2 == 'z')) {
				if (z_float == true) {
					cout << fixed; cout.precision(5);
				}
				else {
					cout << fixed; cout.precision(0);
				}
			}
		}
		if (a < 0 || a > 255 || b < 0 || b > 255 || x < 0 || x > 255 || y < 0 || y > 255 || z < 0 || z > 255) {
			cout << "Invalid input\n";
			exit(1);
		}
		if ((*i).str() == "+") {
			addition(); print();
		}
		else if ((*i).str() == "-") {
			subtraction(); print();
		}
		else if ((*i).str() == "*") {
			multiplication(); print();
		}
		else if ((*i).str() == "/") {
			division(); print();
		}
		else if ((*i).str() == "^") {
			exponentiation(); print();
		}
		else if ((*i).str() == "%") {
			remainder(); print();
		}
	}
	if (x < 0 || x > 255 || y < 0 || y > 255 || z < 0 || z > 255) {
		cout << "Invalid input\n";
		exit(1);
	}
	opcnt = op.size();
	if (opcnt == 0 && numcnt == 0 && valcnt == 1) {
		if (num[0] == "x") { 
			ans = x; 
			if (x_float == true) { cout << fixed; cout.precision(5); }
			else { cout << fixed; cout.precision(0); }
		}
		else if (num[0] == "y") { 
			ans = y; 
			if (y_float == true) { cout << fixed; cout.precision(5); }
			else { cout << fixed; cout.precision(0); }
		}
		else if (num[0] == "z") { 
			ans = z; 
			if (z_float == true) { cout << fixed; cout.precision(5); }
			else { cout << fixed; cout.precision(0); }
		}
		if (a < 0 || a > 255 || b < 0 || b > 255 || x < 0 || x > 255 || y < 0 || y > 255 || z < 0 || z > 255) {
			cout << "Invalid input\n";
			exit(1);
		}
		this->print();
	}
}
