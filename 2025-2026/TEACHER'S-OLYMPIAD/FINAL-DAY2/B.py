s = "SPRLKSLPKRS"
n = int(input())
win = 0
lose = 0
draw = 0
for i in range(n):
    a, b = map(str, input().split())
    if a == b:
        draw += 1
    elif a + b in s:
        win += 1
    else:
        lose += 1
print(win, lose, draw)