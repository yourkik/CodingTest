#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int arr[100];
int opr[4];
int max = -1000000001, min = 1000000001, n;

void backtracking(int cnt, int num) {
	//printf("%d\n", num);
	if (cnt == n) {
		if (num > max)max = num;
		if (num < min)min = num;
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (opr[i] > 0) {

			opr[i]--;//연산자 1개를 사용했으니 감소
			if (i==0) {
				backtracking(cnt+1, num + arr[cnt]);
			}
			else if (i==1) {
				backtracking(cnt+1, num - arr[cnt]);
			}
			else if (i==2) {
				backtracking(cnt+1, num * arr[cnt]);
			}
			else if (i==3) {
				backtracking(cnt+1, num / arr[cnt]);
			}
			opr[i]++;//연산자 썼던 것을 다시 리셋
		}
	}
}

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < 4; i++) {
		scanf("%d", &opr[i]);
	}

	backtracking(1, arr[0]);

	printf("%d\n",max);
	printf("%d", min);
	return 0;
}