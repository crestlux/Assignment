#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int N, X, answer = 0;

void printArray(int digit, int **arr) {
	for (int i = 0; i < answer; i++) {
		for (int j = 0; j < digit; j++) {
			printf("%d", arr[i][j]);
		}
		printf("\n");
	}
}
int arrSum(int i, int N, int **arr) {
	int sum = 0;
	for (int j = 0; j < N; j++) {
		sum += arr[i][j];
	}
	return sum;
}
void calc(int N, int **arr) {
	for (int i = 0; i < pow(3, N); i++) {
		while (arrSum(i, N, arr) != X) {
			for (int j = N; j >= 0; j--) {
				if (j == N) {
					arr[i][j - 1]++;
				}
				if (arr[i][j - 1] == 4) {
					arr[i][j - 1] = 0;
					arr[i][j - 2]++;
				}
				if (arr[i][0] == 4) break;
			}
			if (arr[i][0] == 4) break;
		}
		if (arr[i][0] == 4) break;
		answer++;

		for (int j = 0; j < N; j++) {
			arr[i + 1][j] = arr[i][j];
		}

		for (int j = N; j >= 0; j--) {
			if (j == N) {
				arr[i + 1][j - 1]++;
			}
			if (arr[i + 1][j - 1] == 4) {
				arr[i + 1][j - 1] = 0;
				arr[i + 1][j - 2]++;
			}
			if (arr[i + 1][0] == 4) break;
		}
		if (arr[i][0] + 1 > X) { break; }

	}
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
		if (X < 4&&X>=0) {
			printf("%d", X);
		}
	}
	else if (N > 1 && N < 7) {
		calc(N, arr);
		printArray(N, arr);
	}

	for (int i = 0; i < pow(3, N); i++) {
		free(arr[i]);
	}
	free(arr);

	return 0;
}
