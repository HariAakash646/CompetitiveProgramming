n = int(input())

total = 0
s = 0
while n > 0:
    if (n % 2**(s+1)) != 0:
        total += 1
        n -= 2**s
    s+=1

print(total)
