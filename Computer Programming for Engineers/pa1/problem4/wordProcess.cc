#include "wordProcess.h"
#include <iostream>
#include <fstream>

std::string cpe::getMostPairsWord(std::string words[300])
{
  //write your code here!
	std::string ret, temp;
	int count = 0, maxcount = -1, wordsnum = 0;
	std::ifstream readFile;
	readFile.open("words.txt");
	if (readFile.is_open()) {
		std::string tmp;
		while (!readFile.eof()) {
			std::getline(readFile, tmp);
			wordsnum++;
		}
	}
	readFile.close();

	for (int i = 0; i < wordsnum; i++) {
		count = 0;
		temp = words[i];
		
		for (auto it = temp.begin(); it <temp.end();) {
			for (auto iter = temp.begin(); iter < temp.end(); iter++) {
				if (*iter >= 'A' && *iter <= 'Z') {
					*iter += 32;
				}
			}
			if (it != temp.end() - 1  && *it == *(it + 1)) {
				count++;
				it += 2;
				continue;
			}
			else {
				++it;
				continue;
			}
		}
		if (count == maxcount) {
			ret += " ";
			ret += words[i];
		}
		if (count > maxcount) {
			ret.clear();
			ret = words[i];
			maxcount = count;
		}
	}

  return ret;
}
