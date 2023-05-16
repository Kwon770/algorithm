import sys; readline = sys.stdin.readline
sys.setrecursionlimit(10 ** 6)

while True:
    string = input()
    if string == '*':
        break

    # 안번이라도, 중복되면 더 확인하함
    surprising = True
    # N-2 쌍까지 확인
    for distance in range(len(string) - 1):
        # Set이용해서 중복 확인
        dpair = set()
        for i in range(len(string) - distance - 1):
            new_pair = string[i] + string[i + distance + 1]
            if new_pair in dpair:
                surprising = False
                break

            dpair.add(new_pair)

        if not surprising:
            break

    if surprising:
        print(f'{string} is surprising.')
    else:
        print(f'{string} is NOT surprising.')