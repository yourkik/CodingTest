#include <stdio.h>
#include <queue>
#include<stdlib.h>

using namespace std;

struct State {
    int rx, ry, bx, by, depth;
};

int N, M;
char board[10][11];

int dx[] = { 0, 0, -1, 1 }; // 상하좌우
int dy[] = { -1, 1, 0, 0 };

// 이동할 수 있는 방향으로 기울이기
void tilt(int& x, int& y, int d) {
    while (board[x + dx[d]][y + dy[d]] != '#' && board[x][y] != 'O') {
        x += dx[d];
        y += dy[d];
    }
}

// 두 구슬의 위치를 저장하여 방문 여부 확인
bool visited[10][10][10][10] = { false };

// BFS 탐색
int bfs(int rx, int ry, int bx, int by) {
    queue<State> q;
    q.push({ rx, ry, bx, by, 0 });
    visited[rx][ry][bx][by] = true;

    while (!q.empty()) {
        State cur = q.front();
        q.pop();

        // 10번 이하로 움직여서 빨간 구슬을 빼낼 수 없는 경우
        if (cur.depth > 10) {
            return -1;
        }

        // 빨간 구슬이 구멍에 빠진 경우, 현재까지의 이동 횟수를 반환
        if (board[cur.rx][cur.ry] == 'O' && board[cur.bx][cur.by] != 'O') {
            return cur.depth;
        }

        // 네 방향으로 기울이기 시도
        for (int i = 0; i < 4; i++) {
            int nrx = cur.rx, nry = cur.ry;
            int nbx = cur.bx, nby = cur.by;

            tilt(nrx, nry, i);
            tilt(nbx, nby, i);

            // 파란 구슬이 구멍에 빠지면 안됨
            if (board[nbx][nby] == 'O') {
                continue;
            }

            // 두 구슬의 위치가 겹칠 경우, 이동 거리가 더 긴 구슬을 한 칸 뒤로 이동
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

            // 방문한 적이 없는 경우, 큐에 추가
            if (!visited[nrx][nry][nbx][nby]) {
                visited[nrx][nry][nbx][nby] = true;
                q.push({ nrx, nry, nbx, nby, cur.depth + 1 });
            }
        }
    }

    // 빨간 구슬을 빼내지 못하는 경우
    return -1;
}

int main() {
    int rx, ry, bx, by;

    // 입력
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

    // BFS 탐색 수행
    int result = bfs(rx, ry, bx, by);

    // 결과 출력
    printf("%d\n", result);

    return 0;
}
