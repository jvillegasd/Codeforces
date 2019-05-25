from sys import stdin
from sys import stdout

n, m = map(int, stdin.readline().split())
parent = list(range(n + 1))
cnt = [0]*(n+1)

def find(u):
    if parent[u] == u:
        return u
    parent[u] = find(parent[u])
    return parent[u]

for i in range(m):
    group = [int(u) for u in stdin.readline().split()][1:]
    for v in group[1:]:
        parent[find(v)] = find(group[0])

for u in range(1, n+1):
    cnt[find(u)]+=1

ans = ' '.join(map(str, [cnt[find(u)] for u in range(1, n + 1)]))
stdout.write('%s' % ans)