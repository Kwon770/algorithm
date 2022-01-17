# https://www.acmicpc.net/problem/10825
# 국영수

# Memory : 51488 KB, Time : 372 ms

# 1. 정렬의 우선 순위와 기준을 설정하는 법을 알아야 함
# 1-1. sort(arr, key=lambda arr: [arr[1], arr[0]]) : arr[1] -> arr[0] 순으로 우선순위
# 1-2. key 함수 안에서 - 부호로 정렬 순서 역전 가능
# 시간복잡도 : "sort() 함수에 key 함수를 넘기기" > "디폴트 정렬 기준에 맞춰 정렬 대상 원소 설정하기"

import sys
input=sys.stdin.readline

n = int(input())
students = []
for _ in range(n):
    name, kor, eng, math = input().split()
    students.append((-int(kor), int(eng), -int(math), name))

students.sort()
for student in students:
    print(student[3])