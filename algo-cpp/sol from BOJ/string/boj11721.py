# https://www.acmicpc.net/problem/11721
# 11721 열 개씩 끊어 출력하기

# Slicing을 이용한 문자열 자르기

sentence = input()
for i in range(0, len(sentence), 10):
    print(sentence[i:i + 10])