"""
https://www.acmicpc.net/problem/10775
13168 내일로 여행
Memory: 31129 KB, Time: 944 ms

플로이드 와샬을 이용해서 푸는 문제이지만, 도시가 문자열로 주어진다던가 두 개의 경우의 최단거리를 구한다던가 등의
그래프를 복잡하게 다루는 문제였다. 그 중에서도 실수하기 가장 좋고, 내가 제일 했던 이슈는

1. 문제에서 교통수단의 양쪽 도시라고만 언급하는데, 이는 왕복이 가능하다는 것을 의미
2. 같은 경로에 여러 교통수단이 주어지므로, 더 최소 교통수단으로 갱신해야 함
3. 내일로를 통해 50% 할인을 받을 때, 실수로 계산해야 함 
"""""


import sys; readline = sys.stdin.readline
INF = 9876543210

def get_t_price(type, price):
    if type == "Mugunghwa" or type == "ITX-Saemaeul" or type == "ITX-Cheongchun":
        return 0
    elif type == "S-Train" or type == "V-Train":
        return price / 2
    else:
        return price


N, R = map(int, readline().split())
cities = list(set(readline().split()))
C = len(cities)
city_idx = dict()
for i in range(C):
    city_idx[cities[i]] = i

M = int(readline())
path = list(readline().split())
K = int(readline())

prices = [[INF for _ in range(C)] for _ in range(C)]
t_prices = [[INF for _ in range(C)] for _ in range(C)]
for _ in range(K):
    typei, a, b, price = readline().split()
    a = city_idx[a]
    b = city_idx[b]
    price = int(price)

    prices[a][b] = min(prices[a][b], price)
    prices[b][a] = min(prices[b][a], price)
    t_prices[a][b] = min(t_prices[a][b], get_t_price(typei, price))
    t_prices[b][a] = min(t_prices[b][a], get_t_price(typei, price))

# 플로이드 와샬
for mid in range(C):
    for start in range(C):
        for end in range(C):
            prices[start][end] = min(prices[start][end], prices[start][mid] + prices[mid][end])
            t_prices[start][end] = min(t_prices[start][end], t_prices[start][mid] + t_prices[mid][end])

total_price = 0
t_total_price = R
for i in range(M - 1):
    start = city_idx[path[i]]
    end = city_idx[path[i + 1]]

    total_price += prices[start][end]
    t_total_price += t_prices[start][end]


if total_price > t_total_price:
    print("Yes")
else:
    print("No")