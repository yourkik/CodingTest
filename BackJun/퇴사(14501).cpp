//�迭 arr i-0���� ��㿡 �ɸ��� �ð�(���� ��), i-1���� ����� ������ ���� �� �ִ� ������ ����
//�־��� n+1�� ���Ŀ��� ȸ�縦 ����ϹǷ� �� �ȿ� ���� �� �ִ� �ִ� �̵��� ����ϴ� ����
//�׸��� ������δ� �ִ� ���� ���� �� �����Ƿ� dp�� ���� ����

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define max(a, b) ((a) > (b) ? (a) : (b))

int main() {
    int n;
    scanf("%d", &n);

    int arr[15][2];
    int dp[16] = { 0 }; // dp[i]: i�ϱ����� �ִ� ����

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i][0], &arr[i][1]);
    }

    for (int i = n - 1; i >= 0; i--) {
        int endDay = i + arr[i][0];

        // ����� �Ⱓ�� ����� �ʴ´ٸ� ���� ���ο� ���� �ִ� ���� ���
        if (endDay <= n) {
            dp[i] = max(dp[i + 1], arr[i][1] + dp[endDay]);
        }
        else {
            dp[i] = dp[i + 1]; // ����ٸ� ���� ��¥������ �ִ� ������ �������� �ִ� ���Ͱ� ����
        }
    }

    printf("%d\n", dp[0]);

    return 0;
}