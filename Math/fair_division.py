t = int(input())
for _ in range(t):
    n = int(input())
    candy = list(map(int, input().split()))
    n1 = candy.count(1)
    n2 = candy.count(2)
    if n1 % 2 == 0 and (n1 >= 2 or n2 % 2 == 0):
        print("YES")
    else:
        print("NO")
