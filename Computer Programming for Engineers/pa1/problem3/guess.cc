#include "guess.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int randomNum = 0;

cpe::Result cpe::guess(int num) { 
  //write your code here!
	if(num != randomNum) return num > randomNum ? Result::SMALL : Result::LARGE;
	else return Result::CORRECT; 
}
  //Implement genRandomNum function here
  //This generate random number and store it into randomNum variable
  //reference guess.h file for the function signature
void cpe::genRandomNum() {
	srand((unsigned int)(time(NULL)));
	randomNum = rand() % 100;
 }
