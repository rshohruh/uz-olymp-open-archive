t = int(input())
for i in range(t):
    a, b, c, d = map(int, input().split())
    mn_a = min(d%a, a - d%a)
    mn_b = min(d%b, b - d%b)
    mn_c = min(d%c, c - d%c)
    mn = min(mn_a, mn_b, mn_c)
    cnt = (mn_a == mn) + (mn_b == mn) + (mn_c == mn)
    if cnt == 1:
        print(mn)
    else:
        print(mn, "Istaganingizni tanlashingiz mumkin!")