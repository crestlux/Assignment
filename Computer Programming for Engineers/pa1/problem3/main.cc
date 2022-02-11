#include <iostream>
#include "guess.h"

int main()
{
  //write your code here
  //call genRandomNum function to generate a random number.
  //Use while loop here to start the game.
  //call guess function to check whether a user entered the correct target number.
	cpe::genRandomNum();
	int input;
	while(1){
		std::cin >> input;
		if (std::cin.fail()||input<0||input>99) {
			std::cout << "Enter 0 to 99" << std::endl;
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			continue;
		}
		if (static_cast<int>(cpe::guess(input)) == 0) {
			std::cout << "More Smaller" << std::endl;
		}
		else if (static_cast<int>(cpe::guess(input)) == 1) {
			std::cout << "More Larger" << std::endl;
		}
		else if (static_cast<int>(cpe::guess(input)) == 2) {
			std::cout << "You Won"<<std::endl;
			break;
		}
	} 

  return 0; 
}
