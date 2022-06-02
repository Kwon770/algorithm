# https://www.acmicpc.net/problem/1327
# 1327 소트 게임
# Memory : 34936 KB / Time : 304 ms

import sys; readline = sys.stdin.readline
from collections import deque

# 모든 경우의 수를 확인해봐야하는데, 최소로 변형된 시점을 알아햐므로 BFS로 탐색하고
# 이미 확인한 카드로부터 파생되는 카드는 더이상 확인하지 않는 절차를 넣는 것이 핵심이다.

# 중복된 카드 배열인지 확인는 set 을 이용한다
# 1. list는 hashable 하지 않기때문에 set에 넣을 수 없다. => 따라서 리스트를 문자열로 변형해서 관리 및 변형한다.
# 2. 문자열에 바로 정렬 가능하다. '.sort()' 메소드는 지원하지 않지만, 'sorted()' 는 가능하다.
#    단, 반환값이 리스트이므로 다시 문자열로 변형해줘야한다

# 3. 여러 개의 슬라이싱을 적용하면, 앞의 슬라이싱부터 차례대로 적용된다. ( [::-1] 를 추가함으로서, 뒤집을 수 있다. )

# 4. c++과 다르게 list == list 는 레퍼런스 비교가 아니라 원소 비교다.

N, K = map(int, readline().split())
cards = ''.join(readline().split())
sorted_cards = ''.join(sorted(cards))

q = deque([(cards, 0)])
checked = {cards}
ans = -1
while q:
    cur_cards, cnt = q.popleft()
    if cur_cards == sorted_cards:
        ans = cnt
        break

    for i in range(N - K + 1):
        new_cards = cur_cards[:i] + cur_cards[i:i + K][::-1] + cur_cards[i + K:]
        if new_cards in checked:
            continue

        q.append((new_cards, cnt + 1))
        checked.add(new_cards)

print(ans)