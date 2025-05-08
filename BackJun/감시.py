# # 15683
# # 직선으로 감시가 가능한 다양한 CCTV의 방향을 조절해 가장 많은 사각지대를 없애는 경우를 찾아 최소 사각지대 수를 출력하는 문제
# # https://www.acmicpc.net/problem/15683

# 문제 해결 전략
# 1. CCTV의 위치와 종류를 파악한다.
# 2. 각 CCTV의 방향 조합을 정의한다.
# 3. DFS를 사용하여 모든 CCTV의 방향 조합을 탐색한다.
# 4. 각 조합에 대해 감시 영역을 표시하고, 사각지대를 계산한다.
# 5. 최소 사각지대 수를 업데이트한다.
# dx, dy를 통해 방향을 정의하고, watch 함수를 통해 CCTV가 감시하는 영역을 표시한다.
import sys
import copy

# 입력 빠르게 받기
input = sys.stdin.readline

# 방향: 상, 하, 좌, 우
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

# 감시 함수
def watch(temp, x, y, direction, n, m):
    while True:
        x += dx[direction]
        y += dy[direction]
        if 0 <= x < n and 0 <= y < m:
            if temp[x][y] == 6:  # 벽
                break
            if temp[x][y] == 0:
                temp[x][y] = '#'
        else:
            break

# DFS를 통해 모든 방향 조합 탐색
def dfs(depth, arr):
    global min_blind
    if depth == len(cctvs):
        cnt = sum(row.count(0) for row in arr)
        min_blind = min(min_blind, cnt)
        return

    x, y, cctv_type = cctvs[depth]

    # cctv_dirs[cctv_type]에는 이차원 배열이 들어오고 directions에는 1차원 리스트가 나옴
    for directions in cctv_dirs[cctv_type]:
        temp = copy.deepcopy(arr)
        # print("directions에 들어오는 값")
        # print(directions)
        for d in directions:
            watch(temp, x, y, d, n, m)
        dfs(depth + 1, temp)

# 입력 받기
n, m = map(int, input().split())
graph = []
cctvs = []

for i in range(n):
    row = list(map(int, input().split()))
    graph.append(row)
    for j in range(m):
        if 1 <= row[j] <= 5:
            cctvs.append((i, j, row[j]))

# CCTV 타입별 방향 조합
cctv_dirs = {
    1: [[0], [1], [2], [3]],
    2: [[0, 1], [2, 3]],
    3: [[0, 3], [3, 1], [1, 2], [2, 0]],
    4: [[2, 0, 3], [0, 3, 1], [3, 1, 2], [1, 2, 0]],
    5: [[0, 1, 2, 3]]
}

# 최소 사각지대 수 초기화
min_blind = int(1e9)

# DFS 시작
dfs(0, graph)

# 결과 출력
print(min_blind)
