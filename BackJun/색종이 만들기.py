# 2630
# 쿼드트리

white = 0
blue = 0

def dfs(arr, x, y, n):
    global white, blue

    if n == 1:
        if arr[x][y] == 0:
            white += 1
        else:
            blue += 1
        return 0

    color = arr[x][y]
    same = True

    for i in range(x, x + n):
        for j in range(y, y + n):
            if arr[i][j] != color:
                same = False
                break
        if not same:
            break

    if same:
        if color == 0:
            white+=1
        else:
            blue+=1
    else:
        dfs(arr, x, y, n // 2)
        dfs(arr, x, y + n // 2, n // 2)
        dfs(arr, x + n // 2, y, n // 2)
        dfs(arr, x + n // 2, y + n // 2, n // 2)


n = int(input())
arr = []
for i in range(n):
    arr.append(list(map(int, input().split())))

dfs(arr, 0, 0, n)
print(white)
print(blue)
