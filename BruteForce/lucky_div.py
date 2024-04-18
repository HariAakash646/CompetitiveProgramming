n = int(input())

no = True
for i in ['', '4', '7']:
    for j in ['', '4', '7']:
        for k in ['4', '7']:
            num = int(i + j + k)
            if n % num == 0:
                print("YES")
                no = False
                break
        if not no:
            break
    if not no:
        break
if no:
    print("NO")
    
