'''
https://www.acmicpc.net/problem/1644
1644 소수의 연속합

연속합들의 특수성 때문에 투포인터를 사용하면
연산량을 대폭 줄일 수 있다.
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
start = 0
stop = 0
calc = 0
cnt = 0
for stop in range(len(primes)):
    calc += primes[stop];
    if calc == n:
        cnt += 1
    while calc >= n and start <= stop:
        calc -= primes[start]
        if calc == n:
            cnt += 1
        start += 1

print(cnt)