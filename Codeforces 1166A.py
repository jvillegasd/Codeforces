import math

n = int(input())
dic = {}
for i in range(n):
    name = input()[0]
    dic[name] = dic.get(name, 0) + 1
cnt = list(dic.values())
comb = 0
for i in cnt:
    k = i//2
    comb+= k*(k-1)//2
    k = i - k
    comb+= k*(k-1)//2
print(comb)