#include <iostream>
#include <string>
#include "arrayModify.h"

using namespace std;

int main(){
  //write your code here!
  //you should call arrayModify function to modify array
  //you should call printArray function to print array
	int numArr[10], i = 0;
	string s1;
	do {
		cin >> numArr[i];
		++i;
	} while (getc(stdin) == ' ');
	if (i != 10) {
		for (int j = 0; j < i; j++) {
			if (numArr[j] < 0 || numArr[j]>9) {
				cout << "Number must be between 0~9" << endl;
				return 0;
			}
		}
		cout << "Enter 10 numbers" << endl;
		return 0;
	}
	for (int i = 0; i < 10; i++) {
		if (numArr[i] < 0 || numArr[i] > 9) {
			cout << "Number must be between 0~9" << endl;
			return 0;
		}
	}
	arrayModify(numArr, 10);
	printArray(numArr, 10);
	cout<<endl;
  return 0;
}
