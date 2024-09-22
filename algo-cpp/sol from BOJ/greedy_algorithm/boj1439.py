# https://www.acmicpc.net/problem/1439, 뒤집기
# Memory : 30864 KB , Time : 72 ms

# 같은 숫자가 연속된 것을 하나의 파트로 보고, 0과 1의 파트가 몇 개인지 파악하면
# 풀 수 있는 그리디 문제

string = input()

zero_part = 0
one_part = 0
prev_part = -1
    

for char in string:
    if prev_part != char:    
        if char == "0":
            zero_part += 1
        else:
            one_part += 1
            
            
    prev_part = char
    
            
print(min(zero_part, one_part))
