from sys import stdin
from sys import stdout
import math

t = int(stdin.readline())

for i in range(t):
    n = int(stdin.readline())
    adiv = list(map(int, stdin.readline().split()))
    adiv.sort()
    x = adiv[0] * adiv[n - 1]
    div = set()
    number = 2
    while number * number <= x:
        if x % number == 0:
            div.add(number)
            div.add(x//number)
        number+=1
    if set(adiv) == div:
        stdout.write("%d\n" % x)
    else:
        stdout.write("-1\n")