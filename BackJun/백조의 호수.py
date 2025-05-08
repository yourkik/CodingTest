# 3197 백조의 호수

# 1. 보기 편한 버전전
# 시간 초과 뜸
# from collections import deque

# def get_input(R, C):
#     return [list(input().strip()) for _ in range(R)]

# def bfs(start, end, grid, R, C):
#     queue = deque([start])
#     visited = set()
#     visited.add(start)
    
#     while queue:
#         x, y = queue.popleft()
#         if (x, y) == end:
#             return True
#         for dx, dy in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
#             nx, ny = x + dx, y + dy
#             if 0 <= nx < R and 0 <= ny < C and (nx, ny) not in visited and grid[nx][ny] != 'X':
#                 visited.add((nx, ny))
#                 queue.append((nx, ny))
#     return False

# def melt(grid, R, C):
#     new_grid = [row[:] for row in grid]
#     for i in range(R):
#         for j in range(C):
#             if grid[i][j] in ('.', 'L'):
#                 for dx, dy in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
#                     nx, ny = i + dx, j + dy
#                     if 0 <= nx < R and 0 <= ny < C and grid[nx][ny] == 'X':
#                         new_grid[nx][ny] = '.'
#     return new_grid

# def main():
#     R, C = map(int, input().split())
#     grid = get_input(R, C)

#     # 두 백조의 좌표 찾기
#     swans = [(i, j) for i in range(R) for j in range(C) if grid[i][j] == 'L']
#     start, end = swans[0], swans[1]

#     day = 0
#     while True:
#         if bfs(start, end, grid, R, C):
#             print(day)
#             break
#         grid = melt(grid, R, C)
#         day += 1

# if __name__ == "__main__":
#     main()

# 2. 시간 효율적인 버전
from collections import deque

def get_input(R, C):
    return [list(input().strip()) for _ in range(R)]

def main():
    R, C = map(int, input().split())
    grid = get_input(R, C)

    # 백조의 위치 2개를 찾기
    swans = [(i, j) for i in range(R) for j in range(C) if grid[i][j] == 'L']
    start, end = swans[0], swans[1]

    # 물 위치 초기화 (물 또는 백조 위치는 물로 취급)
    water_q = deque()
    for i in range(R):
        for j in range(C):
            if grid[i][j] in ('.', 'L'):
                water_q.append((i, j))

    # 백조 이동 BFS용 큐
    swan_q = deque([start])
    # 방문 체크 (2D 배열)
    visited = [[False]*C for _ in range(R)]
    visited[start[0]][start[1]] = True

    day = 0  # 날짜 카운트
    dirs = [(-1,0), (1,0), (0,-1), (0,1)]  # 4방향

    while True:
        next_swan_q = deque()  # 다음 날 백조가 이동할 곳

        # 오늘 백조가 이동 가능한 범위 탐색
        while swan_q:
            x, y = swan_q.popleft()
            if (x, y) == end:
                # 다른 백조 만나면 종료
                print(day)
                return
            for dx, dy in dirs:
                nx, ny = x + dx, y + dy
                if 0 <= nx < R and 0 <= ny < C and not visited[nx][ny]:
                    visited[nx][ny] = True
                    if grid[nx][ny] == 'X':
                        # 얼음은 오늘 못 가지만 다음날 시도
                        next_swan_q.append((nx, ny))
                    else:
                        # 물 위는 바로 이동 가능
                        swan_q.append((nx, ny))
        
        # 물 확산 (얼음을 녹임)
        next_water_q = deque()
        while water_q:
            x, y = water_q.popleft()
            for dx, dy in dirs:
                nx, ny = x + dx, y + dy
                if 0 <= nx < R and 0 <= ny < C and grid[nx][ny] == 'X':
                    grid[nx][ny] = '.'  # 얼음을 녹여 물로 변경
                    next_water_q.append((nx, ny))
        
        # 다음날 준비
        water_q = next_water_q
        swan_q = next_swan_q
        day += 1  # 날짜 증가

if __name__ == "__main__":
    main()