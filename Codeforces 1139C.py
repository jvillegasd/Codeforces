from sys import stdin

n, k = map(int, stdin.readline().split())
parent = [i for i in range(n + 1)]
size = [1]*(n+1)
MOD = 10**9+7
ans = pow(n, k, MOD)

def find(u):
    if parent[u] == u:
        return u
    parent[u] = find(parent[u])
    return parent[u]

for i in range(n-1):
    u, v, c = map(int, stdin.readline().split())
    if not c:
        pu = find(u)
        pv = find(v)
        size[pu]+=size[pv]
        parent[pv] = pu

print((ans - sum([pow(size[u], k, MOD) for u in range(1, n + 1) if parent[u] == u]))%MOD)