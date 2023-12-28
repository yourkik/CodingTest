#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define max(a, b) a > b ? a : b

//결과는 나오나 백준에서는 현재 런타임 에러 발생

int maxResult=0;

int findMax(int **arr,int n) {
	int max = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] > max)max = arr[i][j];
		}
	}
	return max;
}

void swap(int *a,int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int **left(int **arr,int n) {//배열의 주소가 넘어가서 배열 자체가 수정되지 않을까?
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n-1; j++) {
			if (arr[i][j] == arr[i][j + 1]) {
				arr[i][j] = 2 * arr[i][j];
				arr[i][j + 1] = 0;
			}
		}
		for (int j = 1; j < n; j++) {
			if (arr[i][j - 1] == 0) {
				swap(&arr[i][j - 1], &arr[i][j]);
			}
		}
	}
	return arr;
}

int** right(int** arr, int n) {
	for (int i = 0; i <n; i++) {
		for (int j = n-1; j >0; j--) {
			if (arr[i][j] == arr[i][j -1]) {
				arr[i][j] = 2 * arr[i][j];
				arr[i][j - 1] = 0;
			}
		}
		for (int j = n-2; j >=0; j--) {
			if (arr[i][j + 1] == 0) {
				swap(&arr[i][j + 1], &arr[i][j]);
			}
		}
	}
	return arr;
}

int** up(int**arr, int n) {
	for (int j = 0; j < n; j++) {
		for (int i = 0; i < n - 1; i++) {
			if (arr[i][j] == arr[i+1][j]) {
				arr[i][j] = 2 * arr[i][j];
				arr[i+1][j] = 0;
			}
		}
		for (int i = 1; i < n; i++) {
			if (arr[i-1][j] == 0) {
				swap(&arr[i-1][j], &arr[i][j]);
			}
		}
	}
	return arr;
}

int** down(int** arr, int n) {
	for (int j = 0; j < n; j++) {
		for (int i = n - 1; i > 0; i--) {
			if (arr[i][j] == arr[i-1][j]) {
				arr[i][j] = 2 * arr[i][j];
				arr[i-1][j] = 0;
			}
		}
		for (int i = n - 2; i >= 0; i--) {
			if (arr[i+1][j] == 0) {
				swap(&arr[i+1][j], &arr[i][j]);
			}
		}
	}
	return arr;
}
//2023.12.28 left/right/up/down 작동 확인

void dfs(int** arr, int cnt, int n) {
	maxResult = max(maxResult, findMax(arr, n));
	if (cnt == 5)return;
	dfs(left(arr, n), cnt + 1, n);
	dfs(right(arr, n), cnt + 1, n);
	dfs(up(arr, n), cnt + 1, n);
	dfs(down(arr, n), cnt + 1, n);
}

int main() {
	int n=0;

	scanf("%d", &n);

	//Dynamic allocate for 2 array
	int** board = (int**)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		board[i] = (int*)malloc(sizeof(int) * n);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &board[i][j]);
		}
	}

	//함수 확인 코드
	/*up(board, n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d", board[i][j]);
		}
		printf("\n");
	}*/

	dfs(board, 0, n);

	printf("%d", maxResult);

	free(board);

	return 0;
}