#include <stdio.h>
#include <queue>
#include<stdlib.h>

using namespace std;

struct State {
    int rx, ry, bx, by, depth;
};

int N, M;
char board[10][11];

int dx[] = { 0, 0, -1, 1 }; // �����¿�
int dy[] = { -1, 1, 0, 0 };

// �̵��� �� �ִ� �������� ����̱�
void tilt(int& x, int& y, int d) {
    while (board[x + dx[d]][y + dy[d]] != '#' && board[x][y] != 'O') {
        x += dx[d];
        y += dy[d];
    }
}

// �� ������ ��ġ�� �����Ͽ� �湮 ���� Ȯ��
bool visited[10][10][10][10] = { false };

// BFS Ž��
int bfs(int rx, int ry, int bx, int by) {
    queue<State> q;
    q.push({ rx, ry, bx, by, 0 });
    visited[rx][ry][bx][by] = true;

    while (!q.empty()) {
        State cur = q.front();
        q.pop();

        // 10�� ���Ϸ� �������� ���� ������ ���� �� ���� ���
        if (cur.depth > 10) {
            return -1;
        }

        // ���� ������ ���ۿ� ���� ���, ��������� �̵� Ƚ���� ��ȯ
        if (board[cur.rx][cur.ry] == 'O' && board[cur.bx][cur.by] != 'O') {
            return cur.depth;
        }

        // �� �������� ����̱� �õ�
        for (int i = 0; i < 4; i++) {
            int nrx = cur.rx, nry = cur.ry;
            int nbx = cur.bx, nby = cur.by;

            tilt(nrx, nry, i);
            tilt(nbx, nby, i);

            // �Ķ� ������ ���ۿ� ������ �ȵ�
            if (board[nbx][nby] == 'O') {
                continue;
            }

            // �� ������ ��ġ�� ��ĥ ���, �̵� �Ÿ��� �� �� ������ �� ĭ �ڷ� �̵�
            if (nrx == nbx && nry == nby) {
                int r_dist = abs(cur.rx - nrx) + abs(cur.ry - nry);
                int b_dist = abs(cur.bx - nbx) + abs(cur.by - nby);

                if (r_dist > b_dist) {
                    nrx -= dx[i];
                    nry -= dy[i];
                }
                else {
                    nbx -= dx[i];
                    nby -= dy[i];
                }
            }

            // �湮�� ���� ���� ���, ť�� �߰�
            if (!visited[nrx][nry][nbx][nby]) {
                visited[nrx][nry][nbx][nby] = true;
                q.push({ nrx, nry, nbx, nby, cur.depth + 1 });
            }
        }
    }

    // ���� ������ ������ ���ϴ� ���
    return -1;
}

int main() {
    int rx, ry, bx, by;

    // �Է�
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        scanf("%s", board[i]);
        for (int j = 0; j < M; j++) {
            if (board[i][j] == 'R') {
                rx = i;
                ry = j;
            }
            else if (board[i][j] == 'B') {
                bx = i;
                by = j;
            }
        }
    }

    // BFS Ž�� ����
    int result = bfs(rx, ry, bx, by);

    // ��� ���
    printf("%d\n", result);

    return 0;
}
