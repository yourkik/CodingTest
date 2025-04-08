//사과가 있는 곳을 1 뱀이 현재 있는 곳을 2로 표현
//queue에 머리와 꼬리 정보를 저장? -> 하지만 queue의 경우 꼬리만 수정 불가 -> 배열 사용(dequeue를 사용하는 방법도 존재)
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 101

int N, K, L; // 보드의 크기, 사과의 개수, 방향 변환 횟수
int board[MAX_SIZE][MAX_SIZE]; // 보드
int snake[MAX_SIZE * MAX_SIZE][2]; // 뱀의 위치 정보
char direction[MAX_SIZE * MAX_SIZE]; // 뱀의 방향 변환 정보

int dx[] = { 0, 1, 0, -1 }; // 동, 남, 서, 북
int dy[] = { 1, 0, -1, 0 };

void initBoard() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            board[i][j] = 0;
        }
    }
}

int main() {
    scanf("%d", &N);
    scanf("%d", &K);

    // 사과 위치 초기화
    for (int i = 0; i < K; i++) {
        int row, col;
        scanf("%d %d", &row, &col);
        board[row - 1][col - 1] = 1; // 사과가 있는 위치는 1로 표시
    }

    scanf("%d", &L);

    // 방향 변환 정보 초기화
    for (int i = 0; i < L; i++) {
        int time;
        char dir;
        scanf("%d %c", &time, &dir);
        direction[time] = dir;
    }

    // 초기 뱀의 위치 및 방향 설정
    int time = 0, dir = 0, head = 0, tail = 0;
    snake[head][0] = 0;
    snake[head][1] = 0;
    board[0][0] = 2; // 뱀의 위치는 2로 표시

    while (1) {
        time++;

        // 뱀의 머리 이동
        int nx = snake[head][0] + dx[dir];
        int ny = snake[head][1] + dy[dir];

        // 벽에 부딪히거나 자기 자신의 몸에 부딪히면 종료
        if (nx < 0 || nx >= N || ny < 0 || ny >= N || board[nx][ny] == 2) {
            printf("%d\n", time);
            break;
        }

        // 뱀이 이동한 칸에 사과가 있는 경우
        if (board[nx][ny] == 1) {
            board[nx][ny] = 2;
            head++;
            snake[head][0] = nx;
            snake[head][1] = ny;
        }
        else { // 사과가 없는 경우
            board[nx][ny] = 2;
            head++;
            snake[head][0] = nx;
            snake[head][1] = ny;

            // 꼬리 제거
            board[snake[tail][0]][snake[tail][1]] = 0;
            tail++;
        }

        // 방향 변환
        if (direction[time] == 'L') {
            dir = (dir + 3) % 4; // 왼쪽으로 90도 회전
        }
        else if (direction[time] == 'D') {
            dir = (dir + 1) % 4; // 오른쪽으로 90도 회전
        }
    }

    return 0;
}
