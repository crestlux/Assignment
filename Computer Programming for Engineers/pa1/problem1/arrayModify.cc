#include "arrayModify.h"
#include <iostream>
#include <vector>
#include <algorithm>
//implement these functions
void printArray(int *arr, int num){
  //write your code here!
  std::vector<int> v;
	for (int i = 0; i < num; i++) {
		v.push_back(arr[i]);
	}
	for (const auto& ele :v) {
		std::cout << ele << " ";
	}
}
void arrayModify(int *arr, int num){
  //write your code here!
	std::vector<int> odd(0), even(0);
	for (int i = 0; i < num; i++) {
		if (arr[i] % 2 == 0) {
			even.push_back(arr[i]);
		}
		if (arr[i] % 2 != 0) {
			odd.push_back(arr[i]);
		}
	}
	std::sort(odd.begin(), odd.end());
	std::sort(even.begin(), even.end());
	std::reverse(std::begin(even), std::end(even));
	for (const auto& ele : even) {
		odd.push_back(ele);
	}
	for (int i = 0; i < num; i++) {
		arr[i] = odd[i];
	}
}
