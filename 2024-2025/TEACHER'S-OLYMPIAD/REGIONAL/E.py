n = int(input())
m = 10**9 + 9
a, b = 0, 1

for _ in range(1, n + 1):
    a, b = ((a + b) * (a + b)) % m, (a * b + 1) % m

print((a + b) % m)
