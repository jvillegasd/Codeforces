from sys import stdin

MOD = 998244353
n = int(stdin.readline())
a = list(map(int, stdin.readline().split()))
b = sorted(list(map(int, stdin.readline().split())), reverse = True)
val = sorted([a[i]*(i+1)*(n-i) for i in range(n)])
print(sum([vali*bi%MOD for vali, bi in zip(val, b)])%MOD)