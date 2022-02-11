#include "display.h"
#include <iostream>

//implement this function
void cpe::customPrint(const std::string& s){
  //write your code here!
  for(const auto& i :s){
    std::cout<<i;
  }
  std::cout<<std::endl;
}

