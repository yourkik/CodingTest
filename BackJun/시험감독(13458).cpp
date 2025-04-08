#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define max_size 1000001


int main() {
	int n, b, c;
	int a[max_size];
	long long result;

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	scanf("%d %d", &b, &c);

	for (int i = 0; i < n; i++) {
		a[i] = a[i] - b;
	}
	result = n;

	for (int i = 0; i < n; i++) {
		if (a[i] > 0) {
			result += a[i] / c;
			if (a[i] % c > 0)result++;
		}
	}
	printf("%lld", result);

	return 0;
}
