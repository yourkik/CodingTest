a = input().split()

a = list(map(int, a))
# print(a)

a.sort(reverse=True)
print(a)

if a[0] >= a[1] + a[2]:
    a[0] = a[1] + a[2] - 1
print(sum(a))