# 문제 분석
    # 1인 곳을 찾으면 아래, 오른쪽, 왼쪽 순서로 1인지 확인하고 맞으면 기존 주소를 2로 바꾸고 포함하고 거기서 다시 탐색
    # 없으면 정지하고 돌아오면서 1을 2로 체인지하고 set에 가로 주소를 입력
    # 이후 가로 주소가 저장된 set으로 최대 석유를 얻는 시추관 위치 획득 가능

# # DFS는 효율성 테스트에서 통과하지 못함
# class OilLump:
#     def __init__(self):
#         self.size = 0                  # 석유 덩어리의 총 크기
#         self.cols_included = set()     # 해당 석유 덩어리에 포함된 열(column) 인덱스

# def check_oil_lump(land, row, col, lump):
#     rows = len(land)
#     cols = len(land[0])
    
#     # 재귀 탈출 조건
#     if row < 0 or row >= rows or col < 0 or col >= cols:
#         return
#     if land[row][col] != 1:
#         return

#     # 현재 위치 방문 처리
#     land[row][col] = 2
#     lump.size += 1
#     lump.cols_included.add(col)

#     # 아래, 오른쪽, 위, 왼쪽 순으로 탐색
#     check_oil_lump(land, row + 1, col, lump)
#     check_oil_lump(land, row, col + 1, lump)
#     check_oil_lump(land, row - 1, col, lump)
#     check_oil_lump(land, row, col - 1, lump)

# def solution(land):
#     rows = len(land)
#     cols = len(land[0])
#     oil_lumps = []
#     total_size = [0] * cols   # 각 열마다 얻을 수 있는 석유량 저장용

#     for i in range(rows):
#         for j in range(cols):
#             if land[i][j] == 1:
#                 lump = OilLump()
#                 check_oil_lump(land, i, j, lump)
#                 oil_lumps.append(lump)

#     # 각 oil lump에 대해 포함된 열마다 크기를 더해줌
#     for lump in oil_lumps:
#         for col in lump.cols_included:
#             total_size[col] += lump.size

#     return max(total_size)


# BFS 버전 -> 효율성도 통과함함
from collections import deque

# 석유 덩어리를 나타내는 클래스
class OilLump:
    def __init__(self):
        self.size = 0                 # 덩어리의 총 크기 (셀 개수)
        self.cols_included = set()    # 이 덩어리가 포함된 열(column)들

# BFS를 이용해 하나의 석유 덩어리를 탐색하는 함수
def bfs(land, start_row, start_col, visited):
    rows, cols = len(land), len(land[0])
    queue = deque()
    queue.append((start_row, start_col))       # 시작 위치 추가
    lump = OilLump()
    visited[start_row][start_col] = True       # 시작 위치 방문 처리

    # BFS 시작
    while queue:
        r, c = queue.popleft()
        lump.size += 1                         # 셀 개수 추가
        lump.cols_included.add(c)              # 현재 열을 덩어리 열에 추가

        # 4방향 (아래, 오른쪽, 위, 왼쪽) 탐색
        for dr, dc in [(1,0), (0,1), (-1,0), (0,-1)]:
            nr, nc = r + dr, c + dc
            # 유효한 인덱스이고, 아직 방문하지 않았고, 석유가 존재할 경우
            if 0 <= nr < rows and 0 <= nc < cols:
                if not visited[nr][nc] and land[nr][nc] == 1:
                    visited[nr][nc] = True
                    queue.append((nr, nc))     # 큐에 추가하여 계속 탐색
    
    return lump    # 탐색이 끝난 덩어리 정보 반환

# 문제 해결을 위한 메인 함수
def solution(land):
    rows = len(land)
    cols = len(land[0])
    visited = [[False] * cols for _ in range(rows)]  # 방문 여부를 저장하는 배열
    total_size = [0] * cols  # 각 열마다 얻을 수 있는 석유량 저장용

    # 모든 셀을 순회하며 석유 덩어리 탐색
    for i in range(rows):
        for j in range(cols):
            # 아직 방문하지 않았고 석유(1)가 있는 경우
            if land[i][j] == 1 and not visited[i][j]:
                lump = bfs(land, i, j, visited)        # 덩어리 탐색
                for c in lump.cols_included:
                    total_size[c] += lump.size         # 포함된 모든 열에 덩어리 크기 더하기

    return max(total_size)  # 가장 많은 석유를 얻을 수 있는 열의 값 반환

