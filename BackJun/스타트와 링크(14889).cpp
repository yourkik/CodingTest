#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int n,min=INT_MAX;
int stat[20][20];
bool check[20];//start�� ��� true link�� ��� false�� ����
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

void backtracking(int cnt) {//�̸��� backtracking������ ��� ����ġ�� �κ��� �����Ƿ� bruteforce....
	//printf("cnt : %d cntStart : %d cntLink : %d\n", cnt,cntStart,cntLink);
	if (cnt==n) {
		int temp = computing();
		if (temp < min)min = temp;
		return;
	}

	if (cntStart > 0) {//cntStart�� Start ���� ����ִ� �ڸ� ���� �ǹ� so 0�̸� Link ���� ����
		cntStart--;
		check[cnt] = true;
		backtracking(cnt+1);//cnt++�� ��� �����ϴ� �Լ��� ������ ����� ���� so ++cnt or cnt+1 �ʿ�
		cntStart++;//�ѹ� start���� ���� �� Link�� ���� ���̹Ƿ� cntStart++
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