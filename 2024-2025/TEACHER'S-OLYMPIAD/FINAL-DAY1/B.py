n = int(input())

parent = [i for i in range(n+1)]
sz = [1 for i in range(n+1)]

def find_set(a):
    if parent[a] == a:
        return a
    parent[a] = find_set(parent[a])
    return parent[a]

def union_sets(a, b):
    a = find_set(a)
    b = find_set(b)
    parent[b] = a
    sz[a] += sz[b]

edges = []
for i in range(n-1):
    u, v, w = map(int, input().split())
    edges.append([w, u, v])

edges.sort()

ans = 0
for x in edges:
    w = x[0]
    u = x[1]
    v = x[2]
    
    u = find_set(u)
    v = find_set(v)
    ans += sz[u] * sz[v] * w
    union_sets(u, v)

print(ans)