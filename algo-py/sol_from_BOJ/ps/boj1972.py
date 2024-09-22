# https://www.acmicpc.net/problem/1972
# 1972 놀라운 문자열
# Memory: 31256 KB, Time: 52 ms

# 문자열이 최대 100개가 주어지고, 각 문자열 최대 길이는 80이므로, 완전탐색으로 풀 수 있다.
# 문자열과 파이썬 기준 Set 활용에 관한 문제다.

# 문자열에서 두 개의 문자를 뽑는 과정에서, 첫 번째 문자는 몇 번째 인덱스까지 확인하는지를 계산하는데 시간이 허비되었다. (IndexOutOfRange)
# 주로 for loop를 쓰기 때문에, 첫 번째 인덱스의 최대 인덱스를 계산하는 과정이 복잡
# => while loop의 조건은 현재 인덱스를 기준으로 조건이 체크할 수 있으므로 더 직관적 (if in for loop와 유사)
# 잘 안써본 구조라 어색하지만, 직관적이라 연습해볼만하다고 생각

# 최적화를 위해, 잘못된 조건을 확인하자마자 break하는 구조가 익숙하지만, 거의 대게 2중 반복문을 사용하므로, if break을 두 번 써야하는 문제 있음.
# 약간의 시간 손해를 보지만, 가독성 향상시킬 수 있는 코드를 참고해봤음.


import sys; readline = sys.stdin.readline

while True:
    string = input()
    if string == '*':
        break

    # 안번이라도, 중복되면 더 확인하함
    surprising = True
    # N-2 쌍까지 확인
    for distance in range(len(string) - 1):
        # Set이용해서 중복 확인
        # dpair = set()
        # for i in range(len(string) - distance - 1):
        #     new_pair = string[i] + string[i + distance + 1]
        #     if new_pair in dpair:
        #         surprising = False
        #         break
        #
        #     dpair.add(new_pair)
        #
        # if not surprising:
        #     break

        pair = []
        i = 0
        while i + distance + 1 < len(string):
            pair.append((string[i], string[i + distance + 1]))
            i += 1

        if len(pair) != len(set(pair)):
            surprising = False
            break

    if surprising:
        print(f'{string} is surprising.')
    else:
        print(f'{string} is NOT surprising.')