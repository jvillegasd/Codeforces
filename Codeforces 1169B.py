from sys import stdin
from sys import stdout

n, m = map(int, stdin.readline().split())
pairs = []
flag = 0

for i in range (m):
    u, v = map(int, stdin.readline().split())
    pairs.append((u, v))

for i in pairs[0]:
    cnt = 0
    val = [0]*(n + 1)
    for p in pairs:
        if p[0] != i and p[1] != i:
            val[p[0]]+=1
            val[p[1]]+=1
            cnt+=1
    if cnt in val:
        flag = 1
        break

if flag == 1:
    stdout.write("YES")
else:
    stdout.write("NO")