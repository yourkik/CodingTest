a = input().strip()
b = input().strip()

n, m = len(a), len(b)
dp = [[0] * (m+1) for _ in range(n+1)]

for i in range(1, n+1):
    for j in range(1, m+1):
        if a[i-1] == b[j-1]:
            dp[i][j] = dp[i-1][j-1] + 1
        else:
            # dp[i-1][j]그전 i의 dp 값을 꺼내옴, dp[i][j-1]그전 j의 dp 값을 꺼내옴
            dp[i][j] = max(dp[i-1][j], dp[i][j-1])

print(dp[n][m])  # LCS 길이

#       C  A  P  C  A  K
#    ---------------------
#   | 0  0  0  0  0  0  0
# A | 0  0  1  1  1  1  1
# C | 0  1  1  1  2  2  2
# A | 0  1  2  2  2  3  3
# Y | 0  1  2  2  2  3  3
# K | 0  1  2  2  2  3  4
# P | 0  1  2  3  3  3  4
