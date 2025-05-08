# 1193
# 숫자의 합으로 몇 번째 라인인지 확인 가능
# 1/1 -> 1/2 -> 2/1 -> 3/1 -> 2/2 -> 1/3 -> 1/4

x = int(input())
n = 0
i = 1
while n < x:
    n += i
    i += 1

t = n - x + 1
if i % 2 == 0:
    print(f"{t}/{i - t}")
else:
    print(f"{i - t}/{t}")
