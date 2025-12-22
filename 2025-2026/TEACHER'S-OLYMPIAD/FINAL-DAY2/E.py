x, y = map(int, input().split())
k = int(input())
if (x + y) % (k+1) == 0:
    print("Shohruh")
else:
    print("Husanboy")