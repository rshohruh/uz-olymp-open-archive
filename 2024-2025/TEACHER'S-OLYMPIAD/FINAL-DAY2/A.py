def isPrime(n):
    if n < 2:
        return False
    i = 2
    while i * i <= n:
        if n % i == 0:
            return False
        i += 1
    return True


def rec(n):
    if not isPrime(n):
        return 0
    mx = 0
    c = 1
    while c < n:
        cur = n % c + n // (c * 10) * c
        mx = max(mx, rec(cur))
        c *= 10
    return mx + 1

print(rec(int(input())))