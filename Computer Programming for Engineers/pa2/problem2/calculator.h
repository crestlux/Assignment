#ifndef CALCULATOR_H
#define CALCULATOR_H
#include <string>

class Calculator{
  //Write class definition here
private:
	float a = 0.0f, b = 0.0f;
	float x = 0.0f, y = 0.0f, z = 0.0f;
	float ans = 0.0f;
	bool input_float = false, x_float = false, y_float = false, z_float = false;
public:
	Calculator() {}
	float addition();
	float subtraction();
	float multiplication();
	float division();
	int remainder();
	int exponentiation();
	void print();
	void parse(std::string s1);
};

#endif
