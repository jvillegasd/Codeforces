tc = int(input())

for i in range(tc):
    n = int(input())
    number = input()
    if '8' in number[:-10]:
        print("YES")
    else:
        print("NO")