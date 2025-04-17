# 정해진 시간에서 초침이 분침, 시침하고 만나는 횟수를 구하는 문제
# 1분에 시침과 분침을 한 번씩 -> 2번 단, 59분에서 00으로 넘어갈 때와 00에서 시작했을 때는 1번
# 1시간의 경우 120 - 2 = 118
# 초의 경우 시작과 끝 사이에 분침, 초침이 있는지 확인하면 됨

# 시간에 따른 겹치는 횟수를 규칙화 해 적용(미완성)
def solution(h1, m1, s1, h2, m2, s2):
    result = 0 
    
    h1, h2 = h1 * 3600, h2 * 3600
    m1, m2 = m1 * 60, m2 * 60
    start_time = h1 + m1 + s1
    end_time = h2 + m2 + s2


    # # 이 경우는 주어지지 않음
    # if start_time > end_time:
    #     end_time += 24 * 3600
    
    duration = end_time - start_time
    
    h,m,s = duration // 3600, (duration % 3600) // 60, duration % 60

    # 시간 당 계산
    result += h * 118

    # 분 당 계산
    if (m1 ==0 and s1 == 0) or (m2 == 0 and s2 == 0):
        result += 1
        m = m-1
    
    if m>0:
        result += m * 2

    # 초 당 계산
    s2_buf = s2
    if s2 == 0:
        s2_buf = 60

    if (s1 < m1 and s2_buf >m2) or (s1 > m1 and s2 > m2):
        result += 1
    if (s1%5 < h1 and s2_buf%5 > h1) or (s1%5 > h1 and s2%5 < h1):
        result += 1
    
    return result


# 각도로 계산산
def solution(h1, m1, s1, h2, m2, s2):
    answer = 0
    mcount, hcount = 0, 0  # 각각 초침이 분침, 시침을 넘을 때마다 카운트

    # 시작 시간과 종료 시간을 초 단위로 변환
    second1 = h1 * 3600 + m1 * 60 + s1
    second2 = h2 * 3600 + m2 * 60 + s2

    # 시작점이 0시 0분 0초 또는 12시 0분 0초인 경우, 겹침이 이미 발생한 상태이므로 +1
    if second1 == 0 or second1 == 60 * 60 * 12:
        answer += 1

    # 초 단위로 반복
    for i in range(second1, second2):
        # 현재 시간의 초침, 분침, 시침의 각도 계산
        s = (i * 6) % 360             # 초침: 1초에 6도 (360/60)
        m = (i / 10) % 360            # 분침: 60초에 6도 → 1초에 0.1도 (i/10)
        h = (i / 120) % 360           # 시침: 3600초(1시간)에 30도 → 1초에 1/120도

        # 다음 초의 초침, 분침, 시침 각도 계산
        ns = 360 if (i + 1) * 6 % 360 == 0 else (i + 1) * 6 % 360
        nm = 360 if (i + 1) / 10 % 360 == 0 else (i + 1) / 10 % 360
        nh = 360 if (i + 1) / 120 % 360 == 0 else (i + 1) / 120 % 360

        # 초침이 시침을 지나친 경우 (s < h 이고 다음 초에는 ns >= nh)
        if s < h and ns >= nh:
            hcount += 1

        # 초침이 분침을 지나친 경우
        if s < m and ns >= nm:
            mcount += 1

        # 분침, 시침, 초침이 모두 동시에 겹친 경우는 두 번 카운트 되므로 한 번 빼줌
        if ns == nm == nh:
            answer -= 1

    # 분침, 시침을 각각 지난 횟수 더함
    answer += mcount + hcount
    return answer
