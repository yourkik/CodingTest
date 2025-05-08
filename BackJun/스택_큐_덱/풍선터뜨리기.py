# 2346
# deque(덱)을 사용하는 문제
# deque(덱)은 양쪽 끝에서 삽입과 삭제가 가능한 자료구조

# Deque를 직접 구현
# 음수 방향 처리에서 문제가 있는 듯함 -> 이에 관해서 rotate 함수를 직접 만드는 과정 필요
# class Deque:
#     def __init__(self):
#         self.items = []

#     def is_empty(self):
#         return len(self.items) == 0

#     def size(self):
#         return len(self.items)

#     def add_front(self, item):
#         self.items.append(item)

#     def add_rear(self, item):
#         self.items.insert(0, item)

#     def remove_front(self):
#         return self.items.pop()

#     def remove_rear(self):
#         return self.items.pop(0)
    
# def main():
#     n = int(input())
#     d = Deque()
#     a = list(map(int, input().split()))
#     buf = Deque()

#     for i in range(n):
#         d.add_front((i+1,a[i]))
    
#     result = []

#     # print(d.items)
#     # print(d.remove_front()) # front = 마지막에 넣은 것, rear = 처음에 넣은 것

#     x = 1

#     while not d.is_empty():
#         if x > 0:
#             if x > d.size():
#                 x = x % d.size()
#             for i in range(x-1):
#                 buf.add_front(d.remove_rear())
#             index, x = d.remove_rear()
#             result.append(index)
#             # print(x)
#             for i in range(buf.size()):
#                 d.add_front(buf.remove_rear())

#             # print(d.items)
#         else:
#             x = -x
#             if x > d.size():
#                 x = x % d.size()
#             for i in range(x-1):
#                 buf.add_rear(d.remove_front())
#             index, x = d.remove_rear()
#             result.append(index)
#             # print(x)
#             for i in range(buf.size()):
#                 d.add_front(buf.remove_front())
#             # print(d.items)
#     print(*result)

# if __name__ == '__main__':   
#     main()


# # deque library 사용
from collections import deque

n = int(input())
balloons = deque(enumerate(map(int, input().split()), start=1))

result = []

while balloons:
    index, move = balloons.popleft()
    result.append(index)
    
    if not balloons:
        break
    
    if move > 0:
        balloons.rotate(-(move - 1))  # 오른쪽 회전
    else:
        balloons.rotate(-move)        # 왼쪽 회전

print(' '.join(map(str, result)))