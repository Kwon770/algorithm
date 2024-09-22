'''
https://www.acmicpc.net/problem/1644
1644 소수의 연속합

연속된 소수의 합으로 구해지는 것이므로, 소수의 리스트를 순회하면서
각 소수로 시작되는 연속합을 확인하는 방식
'''

def prime_list(n):
    sieve = [True] * (n+1)

    for i in range(2, int(n**0.5) + 1):
        if not sieve[i]:
            continue

        sieve[i::i] = [False] * ((len(sieve)-1) // i)
        sieve[i] = True

    return [i for i in range(2, n+1) if sieve[i]]


n = int(input())
primes = prime_list(n)
cnt = 0
for i in range(len(primes)):
    if primes[i] == n:
        cnt += 1
        continue

    sumVal = primes[i]
    for j in range(i + 1, len(primes)):
        sumVal += primes[j]

        if sumVal > n:
            break
        if sumVal == n:
            cnt += 1
            break

print(cnt)