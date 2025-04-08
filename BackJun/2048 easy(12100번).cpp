//2023.12.29 up/down/left/right가 잘 작동하는 것 같으나 정답이 다르게 나옴 
// https://www.acmicpc.net/board/view/104832#post 여기에 있는 반례가 해결 되지 않음 아마 dfs 과정에서 문제가 생긴 듯 함
//현재 처음에 빈공간이 있었을 경우 2칸 이상 0이 연속으로 있게 되는데 이 부분에서 문제 발생(현재는 빈공간 한 칸만 가능) -> 해결

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define max(a, b) a > b ? a : b


int maxResult = 0;

int findMax(int** arr, int n) {
    int max = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] > max) max = arr[i][j];
        }
    }
    return max;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int** left(int** arr, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n -1; j++) {
            if (arr[i][j] == arr[i][j + 1]) {
                arr[i][j] = 2 * arr[i][j];
                arr[i][j + 1] = 0;
            }
        }
        for (int j = 1; j < n; j++) {
            if (arr[i][j - 1] == 0 && arr[i][j] != 0) {//모든 이동 함수에서 이 부분 수정 필요 -> 한 칸일 때만 가능
                for (int k = j; k > 0; k--) {
                    if (arr[i][k - 1] != 0)break;
                    swap(&arr[i][k - 1], &arr[i][k]);
                }
            }
        }
    }
    return arr;
}

int** right(int** arr, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = n - 1; j > 0; j--) {
            if (arr[i][j] == arr[i][j - 1]) {
                arr[i][j] = 2 * arr[i][j];
                arr[i][j - 1] = 0;
            }
        }
        for (int j = n - 2; j >= 0; j--) {
            if (arr[i][j + 1] == 0 && arr[i][j]!=0) {
                for (int k = j; k <n-1; k++) {
                    if (arr[i][k + 1] != 0)break;
                    swap(&arr[i][k + 1], &arr[i][k]);
                }
            }
        }
    }
    return arr;
}

int** up(int** arr, int n) {
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n - 1; i++) {
            if (arr[i][j] == arr[i + 1][j]) {
                arr[i][j] = 2 * arr[i][j];
                arr[i + 1][j] = 0;
            }
        }
        for (int i = 1; i < n; i++) {
            if (arr[i - 1][j] == 0&&arr[i][j]!=0) {
                for (int k = i; k > 0; k--) {
                    if (arr[k - 1][j] != 0)break;
                    swap(&arr[k - 1][j], &arr[k][j]);
                }
            }
        }
    }
    return arr;
}

int** down(int** arr, int n) {
    for (int j = 0; j < n; j++) {
        for (int i = n - 1; i > 0; i--) {
            if (arr[i][j] == arr[i - 1][j]) {
                arr[i][j] = 2 * arr[i][j];
                arr[i - 1][j] = 0;
            }
        }
        for (int i = n - 2; i >= 0; i--) {
            if (arr[i + 1][j] == 0&&arr[i][j]!=0) {
                for (int k = i; k < n - 1; k++) {
                    if (arr[k + 1][j] != 0)break;
                    swap(&arr[k + 1][j], &arr[k][j]);
                }
            }
        }
    }
    return arr;
}

void dfs(int** arr, int cnt, int n) {
    maxResult = max(maxResult, findMax(arr, n));
    if (cnt == 5) return;
    dfs(left(arr, n), cnt + 1, n);
    dfs(right(arr, n), cnt + 1, n);
    dfs(up(arr, n), cnt + 1, n);
    dfs(down(arr, n), cnt + 1, n);
}

int main() {
    int n = 0;

    scanf("%d", &n);

    // Dynamic allocate for 2 array
    int** board = (int**)malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++) {
        board[i] = (int*)malloc(sizeof(int) * n);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &board[i][j]);
        }
    }

    //함수 확인 코드
    down(board, n);
    printf("\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }


    dfs(board, 0, n);

    printf("%d\n", maxResult);

    // Free allocated memory
    for (int i = 0; i < n; i++) {
        free(board[i]);
    }
    free(board);

    return 0;
}
