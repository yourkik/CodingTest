//#define _CRT_SECURE_NO_WARNINGS
//#include<vector>
//#include<algorithm>
//#include<iostream>
//#define MAX 25
//using namespace std;
//
//int map[25][25];
//bool visited[25][25] = { false, };
//
//int dr[4] = { -1,0,1,0 };//row
//int dc[4] = { 0,-1,0,1 };//column
//
//int cnt = 0;
//int n;
//
//void dfs(int r,int c) {
//	for (int i = 0; i < 4; i++) {
//		int nr = r + dr[i];
//		int nc = c + dc[i];
//
//		if (nr < 0 || nc < 0||nr>=n||nc>=n)continue;//범위를 벗어나는 경우 예외 처리
//		if (visited[nr][nc] == false&&map[nr][nc]==1) {
//			visited[nr][nc] = true;
//			cnt++;
//			dfs(nr, nc);
//		}
//	}
//}
//
//int main() {
//	scanf("%d", &n);
//	vector<int>v;
//	/*int** arr;
//	arr = (int**)malloc(sizeof(int) * n);
//	for (int i = 0; i < n; i++) {
//		arr[i] = (int*)malloc(sizeof(int) * n);
//	}*/
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			scanf("%1d", &map[i][j]);
//		}
//	}
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			if (visited[i][j] == false && map[i][j] == 1) {
//				cnt = 1;
//				visited[i][j] = true;
//				dfs(i, j);
//				v.push_back(cnt);
//				cnt = 0;
//			}
//		}
//	}
//	cout << v.size() << endl;
//	sort(v.begin(), v.end());
//	for (int i = 0; i < v.size(); i++) {
//		cout << v[i] << endl;
//	}
//}