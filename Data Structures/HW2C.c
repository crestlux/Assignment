#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
	int misscnt;
	int i;
	int arrloc_first;
	int arrloc_second;
}map;

void swap(char* arr, int i, int j);
bool chkPalindrome(char *arr, int size);
void init(map *stmp, int count);
void swapMinLoc(map *stmp, char *arr, int matchcnt);

map stmp[10000]; //swap_temp

int main() {
	int alphcnt[26] = { 0, }, oddcnt = 0, oddalph = -1, swapcnt = 0, misscnt = 0, matchcnt = 0;
	char arr[101] = { '\0', };
	scanf("%s", arr);
	for (int i = 0; i < strlen(arr); i++) {
		alphcnt[arr[i] - 'A']++;
	}
	for (int i = 0; i < 26; i++) {
		if (alphcnt[i] % 2 == 1) {
			oddcnt++;
			oddalph = i;
		}
	}
	if (oddcnt > 1) {
		printf("Impossible\n");
		return 0;
	}

	if (oddalph == -1) { // all even
		for (int i = 0; i < strlen(arr) / 2; i++) {
			if (arr[i] == arr[strlen(arr) - 1 - i]) {
				if (i == strlen(arr) / 2 - 1 && matchcnt != 0);
				else if (i == strlen(arr) / 2 - 1 && matchcnt == 0) break;
				else continue;
			}
			else {
				for (int j = i + 1; j < strlen(arr); j++) {
					if (arr[i] == arr[j]) { // if swappable same alph is found
						misscnt = 0;
						swap(arr, j, strlen(arr) - 1 - i); //swap
						for (int k = 0; k < strlen(arr) / 2; k++) {
							if (arr[k] == arr[strlen(arr) - 1 - k]) continue;
							else {
								misscnt++; //count remaining the number of alph mismatch
							}
						}
						stmp[matchcnt].misscnt = misscnt; //the number of mismatch alph when swapped
						stmp[matchcnt].i = i;
						stmp[matchcnt].arrloc_first = j;
						stmp[matchcnt].arrloc_second = strlen(arr) - 1 - i;
						swap(arr, j, strlen(arr) - 1 - i);
						++matchcnt;
					}
				}
			}

			if (i == strlen(arr) / 2 - 1) { // swap with the lowest misscnt in struct
				swapMinLoc(stmp, arr, matchcnt);
				init(stmp, matchcnt);
				printf("%s\n", arr);
				++swapcnt;
				i = -1; matchcnt = 0;
				if (chkPalindrome(arr, strlen(arr))) break;
				else continue;
			}
		}
	}

	else { //odd exist
		for (int i = 0; i < (strlen(arr) - 1) / 2; i++) {
			if (arr[i] == arr[strlen(arr) - 1 - i]) {
				if (i == (strlen(arr) - 1) / 2 - 1 && matchcnt != 0);
				else if (i == (strlen(arr) - 1) / 2 - 1 && matchcnt == 0) break;
				else continue;
			}
			else {
				for (int j = i + 1; j < strlen(arr); j++) {
					if (arr[i] == arr[j]) { // if swappable same alphabet found
						misscnt = 0;
						swap(arr, j, strlen(arr) - 1 - i); //swap

						for (int k = 0; k < (strlen(arr) - 1) / 2; k++) {
							if (arr[k] == arr[strlen(arr) - 1 - k]) continue;
							else {
								misscnt++; //count the number of remaining mismatch alph
							}
						}
						stmp[matchcnt].misscnt = misscnt; //the number of mismatching alph if swapped to same alph
						stmp[matchcnt].i = i;
						stmp[matchcnt].arrloc_first = j;
						stmp[matchcnt].arrloc_second = strlen(arr) - 1 - i;
						swap(arr, j, strlen(arr) - 1 - i);
						++matchcnt;
					}

				}
			}
			if (i == ((strlen(arr) - 1) / 2) - 1) { // swap with the lowest misscnt in struct
				swapMinLoc(stmp, arr, matchcnt);
				init(stmp, matchcnt);
				printf("%s\n", arr);
				++swapcnt;
				i = -1; matchcnt = 0;
				if (chkPalindrome(arr, strlen(arr))) break;
				else continue;
			}

		}
	}
	for (int i = 0; i < (strlen(arr) - 1) / 2; i++) {
		if (arr[i] != arr[strlen(arr) - i - 1]) {
			swap(arr, i, strlen(arr) / 2);
			printf("%s\n", arr);
			++swapcnt;
		}
	}
	printf("%d", swapcnt);
	return 0;
}

void swap(char* arr, int i, int j) {
	char temp;
	temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

bool chkPalindrome(char *arr, int size) {
	for (int i = 0; i < size / 2; i++) {
		if (arr[i] != arr[size - i - 1]) return false;
		else continue;
	}
	return true;
}

void init(map *stmp, int count) {
	for (int i = 0; i < count; i++) {
		stmp[i].misscnt = 0;
		stmp[i].i = 0;
		stmp[i].arrloc_first = 0;
		stmp[i].arrloc_second = 0;
	}
}

void swapMinLoc(map *stmp, char *arr, int matchcnt) {
	int minmissloc = -1;
	int change = -1;
	int min = 98765432;
	for (int k = 0; k < matchcnt; k++) {
		if (stmp[k].misscnt < min) {
			min = stmp[k].misscnt;
			minmissloc = stmp[k].arrloc_first;
			change = stmp[k].arrloc_second;
		}
		else continue;
	}
	swap(arr, minmissloc, change);
}
