t = int(input())

for _ in range(t):
  
    n = int(input())
    arr = list(map(int, input().split()))
    
    min_idx = arr.index(min(arr))
    max_idx = arr.index(max(arr))
    
    a = max(min_idx, max_idx) + 1
    b = n - min(min_idx, max_idx)
    c = min_idx + 1 + n - max_idx
    d = max_idx + 1 + n - min_idx
    
    print(min(a, b, c, d))
