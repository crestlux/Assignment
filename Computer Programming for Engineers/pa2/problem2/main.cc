#include <iostream>
#include "calculator.h"

using namespace std;

int main(){
  //write your code here
	string s1; Calculator c;
	while (s1 != "quit") {
		cout << "Enter your equation to calculate: ";
		getline(cin, s1);
		if (s1 == "quit") break;
		c.parse(s1);
	}
  return 0;
}