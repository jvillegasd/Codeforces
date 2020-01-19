from sys import stdin, stdout

t = int(stdin.readline())
for i in range(t):
  n, s, k = map(int, stdin.readline().split())
  a = [int(ai) for ai in stdin.readline().split()]
  for j in range(n + 1):
    if s + j not in a and s + j <= n or s - j not in a and s - j > 0:
      stdout.write('{}\n'.format(j))
      break