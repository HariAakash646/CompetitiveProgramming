a = int(input())

n100 = a//100
a %= 100

n20 = a//20
a %= 20

n10 = a//10
a %= 10

n5 = a//5
a %= 5

print(n100 + n20 + n10 + n5 + a)
