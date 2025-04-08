//���� 1005 ACM Craft
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
//�Ʒ� ���� ��κ��� ���� ���� 1005���� ó������ �����ִ� ���ø� ���� �ϰ� �ֽ��ϴ�.
int main() {
    int T;//�׽�Ʈ���̽��� ����
    cin >> T;
    for (int t = 0; t < T; t++) {
        int N, K;//�ǹ� ����(N), ��Ģ ����(K)
        cin >> N >> K;
        vector<int> D(N + 1), res(N + 1), indegree(N + 1);//D�� �� �ǹ��� �ð��� ����, res�� ���� �ð� ����, indegree�� �������� ����
        vector<vector<int>> graph(N + 1);//����� ��带 ����(graph[1]�� 2�� 3�� ����, graph[2]�� graph[3]�� 4�� ����)
        for (int i = 1; i <= N; i++) cin >> D[i];
        for (int i = 0; i < K; i++) {
            int X, Y;//������ �ǹ� X -> Y ����
            cin >> X >> Y;
            graph[X].push_back(Y);//����� ��带 ǥ��
            indegree[Y]++;//�������� ����
        }
        int W;//�Ǽ��ؾ��� �ǹ��� ��ȣ
        cin >> W;

        queue<int> q;
        for (int i = 1; i <= N; i++) {
            res[i] = D[i];//���� �ð��� �����ϱ� ���� res�� ���(�ǹ� �⺻ �ð��� ��ȭ�ϸ� �� �ǹǷ� ���� ����)
            if (indegree[i] == 0) q.push(i);//���������� 0�� ����� ��ȣ�� ť�� ����
        }

        while (!q.empty()) {//���������� 0�� ��尡 ���� ������ ����(�����ٴ� �ǹ�)
            int cur = q.front();
            q.pop();
            for (int next : graph[cur]) {//����� ����� ���� next�� ����
                res[next] = max(res[next], res[cur] + D[next]);//���������� 2�̻��� �� ������ ȭ��ǥ�� 2�� �̻��� ��带 �ذ��ϱ� ���� �ڵ�
                //(2 ��带 ���� ���� �ð��� ���� res[4]�� ����ǰ� 3 ��带 ���� ���� �ð��� ���� �� ū ���� res[4]�� ����)
                indegree[next]--;//���� �ð��� ����ϹǷ� ���� ���� �� �̻� ��� X -> ���������� ����
                if (indegree[next] == 0) q.push(next);//���������� 0�� ��带 �ٽ� ť�� ����
            }
        }
        cout << res[W] << "\n";
    }
    return 0;
}