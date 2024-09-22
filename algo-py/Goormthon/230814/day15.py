# https://level.goorm.io/exam/195697/%EA%B3%BC%EC%9D%BC-%EA%B5%AC%EB%A7%A4/quiz/1

# https://goorm.notion.site/Python3-87a8c4826e754fefa3791b3ada975a93
# 과일을 조각 단위로 살 수 있다는 내용을 빼고 보면, 이 문제는 전형적인 `배낭 문제` 입니다. 배낭 문제는 `무게`와 `가치`가 다른 여러 개의 물건이 있고,
# 배낭에 담을 수 있는 무게의 제한이 있을 때, 배낭에 담은 물건들의 가치 합이 가장 높도록 물건을 담는 방법을 구하는 문제입니다. 이는 `다이나믹 프로그래밍` 으로 해결할 수 있음이 잘 알려져 있습니다.
#
# 이 문제도 과일의 가격(무게), 가치(포만감)가 주어졌을 때 가장 높은 포만감 합을 구해야 한다는 점에서 배낭 문제와 유사하게 보입니다.
# 하지만 제한이 크기 때문에 다이나믹 프로그래밍으로는 해결하기 어렵습니다. 대신에, `과일을 조각낼 수 있다`는 점을 이용해 다른 해법을 찾는 것이 문제의 핵심이라고 할 수 있습니다.


import sys; readline = sys.stdin.readline

N, K = map(int, readline().split())
fruit = []
for i in range(N):
    p, c = map(int, readline().split())
    fruit.append([c // p, p])

full = 0
fruit.sort(reverse=True)
for i in range(N):
    if fruit[i][1] <= K:
        full += fruit[i][0] * fruit[i][1]
        K -= fruit[i][1]

    else:
        full += fruit[i][0] * K
        K = 0

    if K <= 0:
        break

print(full)