mod = 10**9 + 9

def solve(arr):
    n = len(arr)

    b = sorted(arr)
    d = {}

    for i in range(n):
        d[b[i]] = i+1
    
    t = [0] * (n + 1)

    def add(id, val):
        while id <= n:
            t[id] += val
            t[id] %= mod
            id += id & -id
    def pref_sum(id):
        ans = 0
        while id > 0:
            ans += t[id]
            ans %= mod
            id -= id & -id
        return ans
    
    ans = 0
    for num in arr:
        k = pref_sum(d[num]-1)
        ans += k + 1
        ans %= mod
        add(d[num], k+1)

    return ans - n


n = int(input())
odd = []
even = []
for x in input().split():
    x = int(x)
    if x % 2 == 1:
        odd.append(x)
    else:
        even.append(x)

print((solve(odd) + solve(even)) % mod)