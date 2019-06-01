from sys import stdin
from sys import stdout

n, a, x, b, y = map(int, stdin.readline().split())
flag = 0

while True:
    a = a + 1 if a < n else 1
    b = b - 1 if b > 1 else n
    if a == b:
        flag = 1
        break
    if a == x or b == y:
        break

if flag == 1:
    stdout.write("YES")
else:
    stdout.write("NO")