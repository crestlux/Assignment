#include <iostream>
#include <fstream>
#include <vector>
#include "wordProcess.h"

int main()
{
  std::string a[300];
  
  //Write your code here!
  //You should read file words.txt
  //call getMostParisWord function to find the most pairs of consecutive double letters
  std::ifstream readFile;
  std::vector<std::string> s1;
  readFile.open("words.txt");
  if (readFile.fail()) {
	  std::cout << "File open failed" << std::endl;
	  return(1);
  }
  if (readFile.is_open()) {
	  int count = 0;
	  while (!readFile.eof()) {
		  if (count>=300) {
			  std::string temp;
			  std::getline(readFile, temp);
			  s1.push_back(temp);
		  }
		  else {
			  std::getline(readFile, a[count]);
		  }
		count++;
	  }
	  std::string *arr = new std::string[count];
	  for (int i = 0; i < count; i++) {
		  if (i < 300) {
			  arr[i] = a[i];
		  }
		  else {
			  arr[i] = s1[i-300];
		  }
	  }

	  std::cout << cpe::getMostPairsWord(arr) << std::endl;
	  delete[] arr;
  }
  readFile.close();
  return 0;
}
