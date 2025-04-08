#include <iostream>

using namespace std;

int main() {
	int r, c, res = 0;
	int ld[100][100], rd[100][100];//동적 배열도 가능하나 그냥 충분히 큰 배열을 생성

	cin >> r >> c;


	char input;

	for (int i = 0; i < r; i++)//입력하는 배열의 상태를 저장
		for (int j = 0; j < c; j++) {
			cin >> input;
			if (input == '0') {
				ld[i][j] = 0;
				rd[i][j] = 0;
			}
			else {
				ld[i][j] = 1;
				rd[i][j] = 1;
			}
		}

	for (int i = r - 2; i >= 0; i--) {//r-2인 이유는 맨 끝에 있는 것은 검사할 필요가 없어서 그리고 아래서부터 진행해야 길이 중첩 가능(1부터 시작일시 올라오는 방향으로 변경 필요)
		for (int j = 0; j < c; j++) {
			if (ld[i][j] == 1 && j != 0) {//j가 0일 때를 피하는 이유도 맨 끝에 있는 것을 피하기 위해서
				ld[i][j] += ld[i + 1][j - 1];//아래로 한칸 왼쪽으로 한칸
			}
			if (rd[i][j] == 1 && j != c - 1) {//요겄도 같은 이유
				rd[i][j] += rd[i + 1][j + 1];//아래로 한칸 오른쪽을 한칸
			}
		}
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (ld[i][j] != 0 && rd[i][j] != 0) {//한 지점에서 왼쪽 아래와 오른쪽 아래 모두 1인 지점을 탐색
				res = max(res, 1);//아래 if문에 들어가지 않았을 경우 최소 크기 1(위 if에 안걸리면 최소는 0)
				if (ld[i][j] != 1 && rd[i][j] != 1) {//0과 1이 아니니 무조건 2이상 == 한 지점도 1이고 왼쪽 아래와 오른쪽 아래 모두 1 -> 조건 만족
					int n = min(ld[i][j], rd[i][j]);//왼쪽 대각선과 오른쪽 대각선 중 작은 것에 맞춰야함(마름모)
					while (n > 1) {//while문을 통해 가장 위 지점에서 연결되는 양 점을 확인(안되면 n을 계속 줄임)
						if (rd[i + n - 1][j - n + 1] >= n && ld[i + n - 1][j + n - 1] >= n) {//마름모가 되는 경우을 확인
							res = max(res, n);//res는 지점마다의 마름모의 최대크기를 저정 이후 한 지점에서의 최대인 n과 계속 비교하여 최대 크기를 탐색
						}
						n--;
					}
				}
			}
		}
	}
	cout << res << endl;
	return 0;
}