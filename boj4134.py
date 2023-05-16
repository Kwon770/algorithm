import sys; readline = sys.stdin.readline

T = int(input())
for _ in range(T):

    n = int(input())
    while True:
        is_prime = True
        if n <= 1:
            n = 2

        for i in range(2, int(n ** 0.5) + 1):
            if n % i == 0:
                is_prime = False
                break

        if is_prime:
            print(n)
            break
        else:
            n += 1