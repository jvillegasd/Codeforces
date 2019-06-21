from sys import stdin
from sys import stdout

n = int(stdin.readline())
d = [0] + list(map(int, stdin.readline().split()))
e = []
for i in range(1, n+1):
	for u in range(d[i-1]+1, d[i]+1):
		for v in range(u+1, d[n-i+1]+2):
			e.append([u,v])
stdout.write("{}\n".format(len(e)))
for ei in e: stdout.write("{} {}\n".format(ei[0], ei[1]))