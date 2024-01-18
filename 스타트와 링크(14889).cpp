#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int n,min=INT_MAX;
int stat[20][20];
bool check[20];//start인 경우 true link인 경우 false를 저장
int cntStart, cntLink;

int computing() {
	int start = 0, link = 0;
	for(int i=0;i<n;i++){
		if (check[i] == true) {
			for (int j = 0; j < n; j++) {
				if(check[j]==true) start += stat[i][j];
			}
		}
		if (check[i] == false) {
			for (int j = 0; j < n; j++) {
				if (check[j] == false)link += stat[i][j];
			}
		}
	}

	return abs(start - link);
}

void backtracking(int cnt) {//이름은 backtracking이지만 사실 가지치는 부분이 없으므로 bruteforce....
	//printf("cnt : %d cntStart : %d cntLink : %d\n", cnt,cntStart,cntLink);
	if (cnt==n) {
		int temp = computing();
		if (temp < min)min = temp;
		return;
	}

	if (cntStart > 0) {//cntStart는 Start 팀에 비어있는 자리 수를 의미 so 0이면 Link 팀에 넣음
		cntStart--;
		check[cnt] = true;
		backtracking(cnt+1);//cnt++의 경우 진행하던 함수가 끝나고 계산을 진행 so ++cnt or cnt+1 필요
		cntStart++;//한번 start팀에 넣은 후 Link에 넣을 것이므로 cntStart++
	}

	if (cntLink > 0) {
		cntLink--;
		check[cnt] = false;
		backtracking(cnt+1);
		cntLink++;
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &stat[i][j]);
		}
	}
	cntStart = n / 2;
	cntLink = n / 2;

	backtracking(0);

	printf("%d", min);
}