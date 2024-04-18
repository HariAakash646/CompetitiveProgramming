n = int(input())
arr = list(map(int, input().split()))

negc = 0
coins = 0
neut = False

for i in arr:
    posv = abs(i-1)
    negv = abs(i+1)
    
    if posv > negv:
        coins += negv
        negc += 1
    elif negv > posv:
        coins += posv
    else:
        coins += posv
        neut = True

if negc % 2 != 0 and not neut:
    coins += 2

print(coins)
