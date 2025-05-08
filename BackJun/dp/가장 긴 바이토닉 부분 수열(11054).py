n = int(input())
a = list(map(int, input().split()))

dp_ac = [1] * n  # 증가 부분 수열
dp_dc = [1] * n  # 감소 부분 수열

# index 시작을 0, i+1과 1, i의 차이는 크지 않음(4ms) -> 더 직관적인게 중요하면 그냥 i의 시작을 1, n으로 해도 무방

# 증가 부분 수열 (앞에서부터)
for i in range(1,n):
    for j in range(i):
        if a[j] < a[i]:
            dp_ac[i] = max(dp_ac[i], dp_ac[j] + 1)

# 감소 부분 수열 (뒤에서부터)
for i in range(n-1, -1, -1):
    for j in range(i, n):
        if a[j] < a[i]:  # 여기서 'a[j] < a[i]'는 감소 방향
            dp_dc[i] = max(dp_dc[i], dp_dc[j] + 1)

# 최대 바이토닉 수열 길이 계산
print(max(dp_ac[i] + dp_dc[i] - 1 for i in range(n)))
