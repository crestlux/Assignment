#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

int N, X, answer = 0;

int arrSum(int N, int **arr, int i, int cnt) {
	if (cnt > N) return 0;
	return arr[i][cnt] + arrSum(N, arr, i, cnt + 1);
}

void copyArr(int N, int **arr, int i, int cnt) {
	if (cnt > N) return;
	else {
		arr[i + 1][cnt] = arr[i][cnt];
		copyArr(N, arr, i, cnt + 1);
	}
}

void makeArr(int N, int **arr, int i, int cnt, bool ifCopyArr) {
	if (ifCopyArr == true) copyArr(N, arr, i, 0);
	if (cnt < 0) return;
	if (cnt == N) {
		arr[i + 1][cnt - 1]++;
	}
	if (arr[i + 1][cnt - 1] == 4) {
		arr[i + 1][cnt - 1] = 0;
		arr[i + 1][cnt - 2]++;
	}
	if (arr[i + 1][0] == 4) return;
	makeArr(N, arr, i, cnt - 1, false);
}

bool chkPalindrome(int N, int **arr, int i, int cnt) {
	if(cnt != N/2){
		if (arr[i][cnt] != arr[i][N-cnt-1]) return false;
		else return chkPalindrome(N, arr, i, cnt+1);
	}
	else {
		return true;
	}
}

void calc(int N, int **arr, int i) {
	if (i >= pow(3, N)) return;

	while (arrSum(N, arr, i, 0) != X || !chkPalindrome(N, arr, i, 0)) {
		makeArr(N, arr, i - 1, N, false);
		if (arr[i][0] == 4) return;
	}
	if (arr[i][0] == 4) return;
	answer++;
	makeArr(N, arr, i, N, true);
	if (arr[i][0] + 1 > X) { return; }

	calc(N, arr, i + 1);
}

int main(int argc, char* argv[])
{
	scanf("%d %d", &N, &X);
	int **arr;
	arr = (int**)calloc(sizeof(int*) * (int)pow(3, N), sizeof(int));
	for (int i = 0; i < pow(3, N); i++) {
		arr[i] = (int*)calloc(sizeof(int) * N, sizeof(int));
	}

	if (N == 1) {
		if (X < 4 && X >= 0) {
			printf("%d", X);
		}
	}

	else if (N > 1 && N < 7) {
		calc(N, arr, 0);
		for (int i = 0; i < answer; i++) {
			for (int j = 0; j < N; j++) {
				printf("%d", arr[i][j]);
			}
			printf("\n");
		}
	}

	for (int i = 0; i < pow(3, N); i++) {
		free(arr[i]);
	}
	free(arr);

	return 0;
}
