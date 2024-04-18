t = int(input())

for _ in range(t):
  
    n, m, k = tuple(map(int, input().split()))
    table = [[0]*m]*n
    
    for x in range(n):
        for y in range(m):
            if x > 0:
                table[x][y] = table[x-1][y] + y + 1
            elif y > 0:
                table[x][y] = table[x][y-1] + x + 1

    out = table[n-1][m-1]
    if out == k:
        print("YES")
    else:
        print("NO")
        
