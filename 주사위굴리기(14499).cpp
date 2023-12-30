//주사위가 움직였을 때 아래에 닿는 면을 알기 위해서 주사위에 내용을 저장할 방법 필요
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 21

int N, M; // 지도의 세로, 가로 크기
int x, y; // 주사위의 초기 위치
int K; // 명령의 개수

int map[MAX_SIZE][MAX_SIZE];
int dice[6]; // 주사위의 각 면에 적힌 숫자

void rollEast() {
    int temp = dice[1];
    dice[1] = dice[5];
    dice[5] = dice[3];
    dice[3] = dice[4];
    dice[4] = temp;
}

void rollWest() {
    int temp = dice[1];
    dice[1] = dice[4];
    dice[4] = dice[3];
    dice[3] = dice[5];
    dice[5] = temp;
}

void rollNorth() {
    int temp = dice[0];
    dice[0] = dice[1];
    dice[1] = dice[2];
    dice[2] = dice[3];
    dice[3] = temp;
}

void rollSouth() {
    int temp = dice[0];
    dice[0] = dice[3];
    dice[3] = dice[2];
    dice[2] = dice[1];
    dice[1] = temp;
}

int main() {
    // 입력
    scanf("%d %d %d %d %d", &N, &M, &x, &y, &K);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &map[i][j]);
        }
    }

    // 명령 수행
    while (K--) {
        int command;
        scanf("%d", &command);

        int nx = x, ny = y;
        switch (command) {
        case 1: // 동쪽
            nx = x;
            ny = y + 1;
            if (ny >= M) continue;
            rollEast();
            break;
        case 2: // 서쪽
            nx = x;
            ny = y - 1;
            if (ny < 0) continue;
            rollWest();
            break;
        case 3: // 북쪽
            nx = x - 1;
            ny = y;
            if (nx < 0) continue;
            rollNorth();
            break;
        case 4: // 남쪽
            nx = x + 1;
            ny = y;
            if (nx >= N) continue;
            rollSouth();
            break;
        }

        if (map[nx][ny] == 0) {
            map[nx][ny] = dice[3];
        }
        else {
            dice[3] = map[nx][ny];
            map[nx][ny] = 0;
        }

        x = nx;
        y = ny;

        printf("%d\n", dice[1]);
    }

    return 0;
}