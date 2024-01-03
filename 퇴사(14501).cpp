//배열 arr i-0에는 상담에 걸리는 시간(단위 일), i-1에는 상담을 끝내고 얻을 수 있는 이익이 저장
//주어진 n+1일 이후에는 회사를 퇴사하므로 그 안에 얻을 수 있는 최대 이득을 계산하는 문제
//그리디 방식으로는 최대 값을 구할 수 없으므로 dp를 통해 구함

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define max(a, b) ((a) > (b) ? (a) : (b))

int main() {
    int n;
    scanf("%d", &n);

    int arr[15][2];
    int dp[16] = { 0 }; // dp[i]: i일까지의 최대 수익

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i][0], &arr[i][1]);
    }

    for (int i = n - 1; i >= 0; i--) {
        int endDay = i + arr[i][0];

        // 상담이 기간을 벗어나지 않는다면 선택 여부에 따른 최대 수익 계산
        if (endDay <= n) {
            dp[i] = max(dp[i + 1], arr[i][1] + dp[endDay]);
        }
        else {
            dp[i] = dp[i + 1]; // 벗어난다면 현재 날짜에서의 최대 수익은 다음날의 최대 수익과 동일
        }
    }

    printf("%d\n", dp[0]);

    return 0;
}