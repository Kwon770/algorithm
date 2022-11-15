# https://www.acmicpc.net/problem/1411
# 1411 비슷한 단어
# Memory: 30840kb / Time: 72ms

# 문제를 푸는 것보다 문제를 이해하고 핵심을 깨닫는데 시간이 엄청 걸렸다.
# 어떤 문자로도 바뀔 수 있는 비슷한 단어라는 조건이 의미하는 문제의 핵심은 같은 알파벳이 뒤죽박죽 바뀌어 있으면 안된다는 것이다.
# 즉, 두 단어 간에 알파벳의 변형의 모순을 찾으면 된다.

# 몇 개의 쌍이 비슷한지 구하라는 부분도 헷갈렸는데, 예제를 보니 몇 개의 Pair 관계가 있냐를 묻는 것이였다.

# 풀이는 dict와 set으로 쉽게 구현가능 했다. 내부 자료형을 잘 활용하자.

import sys; readline = sys.stdin.readline

n = int(readline())
words = [input() for _ in range(n)]
count = 0

for i in range(n):
    for j in range(i + 1, n):
        convert = dict()
        converted_value = set()
        similar = True

        for k in range(len(words[i])):
            if (words[i][k] in convert and convert[words[i][k]] != words[j][k]) or \
                    (words[i][k] not in convert and words[j][k] in converted_value):
                    similar = False
                    break
            else:
                convert[words[i][k]] = words[j][k]
                converted_value.add(words[j][k])

            if not similar: break

        if similar:
            count += 1
print(count)