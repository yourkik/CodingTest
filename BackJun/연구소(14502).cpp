#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_N 8

int N, M, maxSafeArea=0;
int lab[MAX_N][MAX_N];
int tempLab[MAX_N][MAX_N];

int max(int a, int b) {
    return a > b ? a : b;
}

void copyLab(int src[MAX_N][MAX_N], int dest[MAX_N][MAX_N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            dest[i][j] = src[i][j];
        }
    }
}

int countSafeArea() {
    int count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (tempLab[i][j] == 0) {
                count++;
            }
        }
    }
    return count;
}

void spreadVirus(int row, int col) {
    if (row < 0 || row >= N || col < 0 || col >= M || tempLab[row][col] != 0) {
        return;
    }

    tempLab[row][col] = 2;

    spreadVirus(row + 1, col);
    spreadVirus(row - 1, col);
    spreadVirus(row, col + 1);
    spreadVirus(row, col - 1);
}

void buildWalls(int cnt) {
    if (cnt == 3) {
        copyLab(lab, tempLab);//lab�� �ʱ� ���·� �����ϱ� ���� tempLab�� �����͸� ���� �־ ���(spreadVirus ���Ŀ��� �ǵ����� �����)

        // ���̷��� �۶߸���
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (tempLab[i][j] == 2) {
                    spreadVirus(i + 1, j);
                    spreadVirus(i - 1, j);
                    spreadVirus(i, j + 1);
                    spreadVirus(i, j - 1);
                }
            }
        }

        maxSafeArea = max(maxSafeArea, countSafeArea());
        return;
    }

    // �� ������ �� �����
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (lab[i][j] == 0) {
                lab[i][j] = 1;
                buildWalls(cnt + 1);
                lab[i][j] = 0;//��Ͱ� ������ lab�� �ʱ� ���·� ���ƿ�
            }
        }
    }
}

int main() {
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &lab[i][j]);
        }
    }

    maxSafeArea = 0;
    buildWalls(0);

    printf("%d\n", maxSafeArea);

    return 0;
}