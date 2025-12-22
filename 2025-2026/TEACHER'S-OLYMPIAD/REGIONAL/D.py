n = int(input())
a = [[False]*n for i in range(n)]
b = [False]*n
def check():
    for u in range(1, n):
        if not (a[u][0]^b[u]):
            b[u] ^= True
    for u in range(1, n):
        for v in range(u+1, n):
            if not(a[u][v] ^ b[u] ^ b[v]):
                return False
    return True

for i in range(int(input())):
    x, y = map(int, input().split())
    x -= 1
    y -= 1
    a[x][y], a[y][x] = True, True

if check():
    print("HA")
else:
    print("YO'Q")