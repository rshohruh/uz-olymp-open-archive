def phi(n):
    result = n
    i = 2
    while i * i <= n:
        if n % i == 0:
            while n % i == 0:
                n //= i
            result -= result // i
        i += 1
    if n > 1:
        result -= result // n
    return result

n = int(input())
cnt = 0
for i in range(2, n+1):
    cnt += phi(i)
print(cnt * 2 + 3)