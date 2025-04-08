#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int MAX = 101;

bool visited[MAX]; // �湮 �迭. visited[node] = true�̸� node�� �湮�� ���� �����̴�.
vector<int> graph[MAX];
int cnt = 0;

void dfs(int current) { // graph�� ���� ����Ʈ, current�� ���� ���
    visited[current] = true; // current �湮

    for (int next : graph[current]) { // current�� ���� ��带 Ȯ���Ѵ�. �� ��带 next��� ����.
        if (!visited[next]) { // ���� next�� �湮���� �ʾҴٸ�
            dfs(next); // next �湮
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
        graph[b].push_back(a);//�ϳ��� �־ ������ 2, 5�� ���� ������ ����� 5 2�� �����ϸ� 5�� �Ѿ �� ���� ������ �� �� ����
    }

    dfs(1);
    cout << cnt << endl;
}