def find(u):
    if u == parent[u]:
        return u
    parent[u] = find(parent[u])
    return parent[u]


def merge(u, v):
    u, v = find(u), find(v)
    if costs[u] > costs[v]:
        parent[u] = v
    else:
        parent[v] = u


n, m, k = map(int, input().split())
parent = list(i for i in range(n))
costs = list(map(int, input().split()))
for _ in range(m):
    u, v = map(int, input().split())
    u -= 1
    v -= 1
    if find(u) != find(v):
        merge(u, v)
for i in range(n):
    parent[i] = find(i)
total = 0
for i in parent:
    total += costs[i]
    costs[i] = 0
if total > k:
    print("Oh no")
else:
    print(total)
