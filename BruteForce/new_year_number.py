t = int(input())

for _ in range(t):
    num = int(input())
    
    while num >= 2020:
      
        if num % 2020 == 0 or num % 2021 == 0:
            print("YES")
            break
        num -= 2021
        
    else:
        print("NO")
        
