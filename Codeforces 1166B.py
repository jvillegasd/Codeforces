k = int(input())
n = k

while n >= 5:
    if k%n == 0 and k//n >= 5:
        break
    n-=1

if n < 5:
    print(-1)
else:
    for i in range(n):
        for j in range(k//n):
            print('aeiou'[(i+j)%5], end = '')