n, k, q = map(int, input().split())
mod = 10**9 + 7
def f(t):
    ans = 0
    c = 1
    while t > 0:
        if t % 2 == 1:
            ans = (ans + c) % mod
        c = (c * k) % mod
        t //= 2
    return ans

for i in range(q):
    p = int(input())
    p = n - p + 1
    print(f(p))