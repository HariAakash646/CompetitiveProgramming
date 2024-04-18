t = int(input())

for _ in range(t):
    
    n = int(input())
    ltr_ls = list(input())
    
    try:
        R_idx = ltr_ls.index("R")
    except ValueError:
        R_idx = 1000
        
    try:
        B_idx = ltr_ls.index("B")
    except ValueError:
        B_idx = 1000
        
    first = min(R_idx, B_idx)
    if first == 1000:
        first = 0
        
    for i in range(first-1, -1, -1):
        if ltr_ls[i+1] == "B":
            ltr_ls[i] = "R"
        else:
            ltr_ls[i] = "B"
            
    for i in range(first, n):
        if ltr_ls[i] != "?":
            continue
        if ltr_ls[i-1] == "R":
            ltr_ls[i] = "B"
        else:
            ltr_ls[i] = "R"
    
    print("".join(ltr_ls))
    
