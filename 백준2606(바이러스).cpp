#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int MAX = 101;

bool visited[MAX]; // 방문 배열. visited[node] = true이면 node는 방문이 끝난 상태이다.
vector<int> graph[MAX];
int cnt = 0;

void dfs(int current) { // graph는 인접 리스트, current는 현재 노드
    visited[current] = true; // current 방문

    for (int next : graph[current]) { // current의 인접 노드를 확인한다. 이 노드를 next라고 하자.
        if (!visited[next]) { // 만일 next에 방문하지 않았다면
            dfs(next); // next 방문
            cnt++;
        }
    }
}

int main() {
    int x, y, a, b;
    cin >> x >> y;
    for (int i = 0; i < y; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);//하나만 넣어도 되지만 2, 5와 같은 순서로 연결시 5 2로 저장하면 5에 넘어갈 수 없어 끝나게 될 수 있음
    }

    dfs(1);
    cout << cnt << endl;
}