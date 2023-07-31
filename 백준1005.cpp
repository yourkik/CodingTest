//백준 1005 ACM Craft
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
//아래 설명 대부분은 백준 문제 1005에서 처음으로 보여주는 예시를 토대로 하고 있습니다.
int main() {
    int T;//테스트케이스의 개수
    cin >> T;
    for (int t = 0; t < T; t++) {
        int N, K;//건물 개수(N), 규칙 개수(K)
        cin >> N >> K;
        vector<int> D(N + 1), res(N + 1), indegree(N + 1);//D는 각 건물의 시간을 저장, res는 누적 시간 저장, indegree는 진입차수 저장
        vector<vector<int>> graph(N + 1);//연결된 노드를 저장(graph[1]이 2와 3을 저장, graph[2]와 graph[3]이 4를 저장)
        for (int i = 1; i <= N; i++) cin >> D[i];
        for (int i = 0; i < K; i++) {
            int X, Y;//연결을 의미 X -> Y 방향
            cin >> X >> Y;
            graph[X].push_back(Y);//연결된 노드를 표시
            indegree[Y]++;//진입차수 증가
        }
        int W;//건설해야할 건물의 번호
        cin >> W;

        queue<int> q;
        for (int i = 1; i <= N; i++) {
            res[i] = D[i];//누적 시간을 저장하기 위해 res를 사용(건물 기본 시간은 변화하면 안 되므로 따로 생성)
            if (indegree[i] == 0) q.push(i);//진입차수가 0인 노드의 번호를 큐에 저장
        }

        while (!q.empty()) {//진입차수가 0인 노드가 없을 때까지 진행(끝났다는 의미)
            int cur = q.front();
            q.pop();
            for (int next : graph[cur]) {//연결된 노드의 값을 next에 넣음
                res[next] = max(res[next], res[cur] + D[next]);//진입차수가 2이상인 즉 들어오는 화살표가 2개 이상인 노드를 해결하기 위한 코드
                //(2 노드를 지날 때의 시간이 먼저 res[4]에 저장되고 3 노드를 지날 때의 시간과 비교해 더 큰 것을 res[4]에 저장)
                indegree[next]--;//누적 시간을 사용하므로 그전 노드는 더 이상 사용 X -> 진입차수를 줄임
                if (indegree[next] == 0) q.push(next);//진입차수가 0인 노드를 다시 큐에 넣음
            }
        }
        cout << res[W] << "\n";
    }
    return 0;
}