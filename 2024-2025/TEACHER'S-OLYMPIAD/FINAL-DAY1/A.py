n, m = map(int, input().split())
for i in range(n):
    s = input()
    for j in range(m):
        cur = '?'
        if (i + j) % 2 == 1:
            cur = 'A'
            if s[j] == cur:
                cur = 'C'
        else:
            cur = 'B'
            if s[j] == cur:
                cur = 'D'
        print(cur, end="")
    print()