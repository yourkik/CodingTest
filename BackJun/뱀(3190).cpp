//����� �ִ� ���� 1 ���� ���� �ִ� ���� 2�� ǥ��
//queue�� �Ӹ��� ���� ������ ����? -> ������ queue�� ��� ������ ���� �Ұ� -> �迭 ���(dequeue�� ����ϴ� ����� ����)
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 101

int N, K, L; // ������ ũ��, ����� ����, ���� ��ȯ Ƚ��
int board[MAX_SIZE][MAX_SIZE]; // ����
int snake[MAX_SIZE * MAX_SIZE][2]; // ���� ��ġ ����
char direction[MAX_SIZE * MAX_SIZE]; // ���� ���� ��ȯ ����

int dx[] = { 0, 1, 0, -1 }; // ��, ��, ��, ��
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

    // ��� ��ġ �ʱ�ȭ
    for (int i = 0; i < K; i++) {
        int row, col;
        scanf("%d %d", &row, &col);
        board[row - 1][col - 1] = 1; // ����� �ִ� ��ġ�� 1�� ǥ��
    }

    scanf("%d", &L);

    // ���� ��ȯ ���� �ʱ�ȭ
    for (int i = 0; i < L; i++) {
        int time;
        char dir;
        scanf("%d %c", &time, &dir);
        direction[time] = dir;
    }

    // �ʱ� ���� ��ġ �� ���� ����
    int time = 0, dir = 0, head = 0, tail = 0;
    snake[head][0] = 0;
    snake[head][1] = 0;
    board[0][0] = 2; // ���� ��ġ�� 2�� ǥ��

    while (1) {
        time++;

        // ���� �Ӹ� �̵�
        int nx = snake[head][0] + dx[dir];
        int ny = snake[head][1] + dy[dir];

        // ���� �ε����ų� �ڱ� �ڽ��� ���� �ε����� ����
        if (nx < 0 || nx >= N || ny < 0 || ny >= N || board[nx][ny] == 2) {
            printf("%d\n", time);
            break;
        }

        // ���� �̵��� ĭ�� ����� �ִ� ���
        if (board[nx][ny] == 1) {
            board[nx][ny] = 2;
            head++;
            snake[head][0] = nx;
            snake[head][1] = ny;
        }
        else { // ����� ���� ���
            board[nx][ny] = 2;
            head++;
            snake[head][0] = nx;
            snake[head][1] = ny;

            // ���� ����
            board[snake[tail][0]][snake[tail][1]] = 0;
            tail++;
        }

        // ���� ��ȯ
        if (direction[time] == 'L') {
            dir = (dir + 3) % 4; // �������� 90�� ȸ��
        }
        else if (direction[time] == 'D') {
            dir = (dir + 1) % 4; // ���������� 90�� ȸ��
        }
    }

    return 0;
}
