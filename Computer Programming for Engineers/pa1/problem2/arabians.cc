#include "arabians.h"
#include <algorithm>
#include <stack>

//implement this function
std::string cpe::reverseString(const std::string& target) {
  //write your code here!
  std::string s2;
  std::stack<char> st1;
  for (auto i = 0; i < target.size(); i++) {
	  if (target[i] >= '0' && target[i] <= '9') {
		  int begin = i, end, cur;
		  while (target[i] >= '0' && target[i] <= '9') {
			  ++i;
		  }
		  end = i;
		  cur = end-1;
		  while (cur >= begin) {
			  st1.push(target[cur]);
			  --cur;
		  }
		  --i;
	  }
	  else {
		  st1.push(target[i]);
	  }
  }
  while (!st1.empty()) {
	  s2.push_back(st1.top());
	  st1.pop();
  }

  return s2;
}

