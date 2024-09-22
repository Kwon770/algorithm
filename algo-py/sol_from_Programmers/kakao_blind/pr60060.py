# https://programmers.co.kr/learn/courses/30/lessons/60060
# 2020 KAKAO BLUND RECRUITMENT, 가사 검색

# 이 문제는 효율성 평가 항목 때문에, Trie 혹은 이진 탐색을 통해서만 풀 수 있다.
# 이진 탐색을 이용할 때에도 일치하는 가사의 개수를 이진 탐색을 통해 구하는 방법과 같이 풀이에 어떤 선형 탐색도 사용되면 안된다.
# 1. 가사 길이의 범위보다 가사의 갯수가 훨씬 크므로, 가사 길이 만큼의 배열을 정렬해도 큰 문제가 없다.
# 1-1. bisect_left의 low, high 매개 변수를 쓰면 길이마다의 배열을 생성할 필요는 없지만, 지나치게 복잡해지면서 가성비가 맞지 않다.

# 2. bisect_right 와 bisect_left을 이용해서 일정 범위에 만족하는 원소의 개수를 구하는 count_by_range() 함수

# 3. 와일드카드를 범위라는 개념에 적용시켜서 이진 탐색을 수행할 수 있다.
# 3-1. 'ab***'는 'abaaa' ~ 'abzzz' 사이의 문자열들을 포함한다.
# 3-2. 문자열 뒤집기 str[::-1], 문자열 치환 str.replace('from', 'to')

from bisect import bisect_left, bisect_right
import sys
input = sys.stdin.readline

def count_by_range(a, left_value, right_value):
    right_index = bisect_right(a, right_value)
    left_index = bisect_left(a, left_value)
    return right_index - left_index


def solution(words, queries):
    answer = []
    arr = [[] for _ in range(10001)]
    reversed_arr = [[] for _ in range(10001)]

    for word in words:
        arr[len(word)].append(word)
        reversed_arr[len(word)].append(word[::-1])
    for i in range(10001):
        arr[i].sort()
        reversed_arr[i].sort()

    for query in queries:
        count = 0
        if query[0] != '?':
            count = count_by_range(arr[len(query)], query.replace('?', 'a'), query.replace('?', 'z'))
        else:
            count = count_by_range(reversed_arr[len(query)], query[::-1].replace('?', 'a'), query[::-1].replace('?', 'z'))
        answer.append(count)
    return answer

print(solution(["frodo", "front", "frost", "frozen", "frame", "kakao"], ["fro??", "????o", "fr???", "fro???", "pro?"]))