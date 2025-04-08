import ast
# t초 붕대 감음 -> 1초당 x만틈 체력 회복
# t초 연속 붕대 감음 -> y만틈 추가 회복
# 최대 체력보다 커지는 것은 불가능
# 공격을 당하면 기술이 취소 and 체력이 회복되지 않음
# 공격 당해 기술이 최소당하거나 끝나면 '붕개 감기'를 다시 사용
# -> 연속 성공 시간 0으로 초기화
# 0이 되면 죽음(회복 불가)
# '붕대 감기' 기술 정보, 최대 체력, 몬스터 공격 패턴이 주어짐

# Argument:
# bandage[시전 시간, 초당 회복량, 추가 회복량]: 정수 1차원 배열
# health: 1~1000, 정수
# attacks:
#   len = 1~100,
#   2차원 정수 배열, attacks[i]: [공격 시간, 피해량]
#       공격 시간을 기준으로 오름차순 정렬되어 있음
#       공격 시간은 모두 다름(동시에 여러 공격이 들어오지 않음)
#       공격 시간: 1~1000
#   피해량: 1~100
# Return: 남은 체력을 반환, 죽었을 경우 -1을 반환

# def solution(bandage, health, attacks):
#     # bandage[시전 시간, 초당 회복량, 추가 회복량]
#     bandage_time = bandage[0]
#     recovery_per_second = bandage[1]
#     additional_recovery = bandage[2]

#     # 최대 체력
#     max_health = health

#     # 현재 시간
#     current_time = 0

#     for i in range(len(attacks)):
#         # 연속 성공 시간
#         consecutive_success_time = 0

#         attack_time = attacks[i][0]
#         damage = attacks[i][1]

#         # 공격 시간과 현재 시간의 차이
#         time_difference = attack_time - current_time - 1
#         print("시간 차이", time_difference)

#         if(time_difference>0):
#             # 공격이 들어오기 전까지 회복
#             health += time_difference * recovery_per_second
            
#             consecutive_success_time += time_difference

#             # 추가 회복
#             if(consecutive_success_time >= bandage_time):
#                 health += additional_recovery * (consecutive_success_time // bandage_time)

#             # 최대 체력보다 커지면 최대 체력으로 설정
#             if(health > max_health):
#                 # print("최대 체력 초과", health, max_health)
#                 health = max_health

#         health -= damage
#         if health <= 0:
#             # print("죽음", health)
#             return -1
#         current_time = attack_time
#         # print("현재 시간과 체력, 데미지", current_time, health, damage)
#         # print("------------------------")
#     return health if health > 0 else -1

def solution(bandage, health, attacks):
    bandage_time, recovery_per_sec, extra_recovery = bandage
    max_health = health
    current_time = 0

    for attack_time, damage in attacks:
        duration = attack_time - current_time - 1

        if duration > 0:
            # 초당 회복량 적용
            total_recovery = duration * recovery_per_sec

            # 추가 회복 적용 (연속 성공 시간 >= 시전 시간)
            total_recovery += (duration // bandage_time) * extra_recovery

            health = min(max_health, health + total_recovery)

        # 공격 당함
        health -= damage
        if health <= 0:
            return -1

        # 시간 업데이트
        current_time = attack_time

    return health

    
    


while(True):
    bandage = [0, 0, 0]
    health = 0
    attacks = [[]]

    # print("bandage 입력")
    # input_str = input()
    # bandage = ast.literal_eval(input_str)
    # # print(bandage)

    # print("health 입력")
    # health = input()
    # # print(health)

    # print("attacks 입력")
    # input_str = input()

    # # 문자열을 이차원 배열로 변환
    # attacks = ast.literal_eval(input_str)
    # # print("attacks 배열:", attacks)

    bandage = [1, 1, 1]
    health = 5
    attacks = [[1, 2], [3, 2]]

    print(solution(bandage, health, attacks))
    break
