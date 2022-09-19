t = int(input())

for _ in range(t):
    
    n = int(input())
    notes = list(map(int, input().split()))
    
    note_lst = set()
    diversity = 0
    
    for i in notes:
        if i in note_lst:
            if i+1 not in note_lst:
                note_lst.add(i+1)
                diversity += 1
        else:
            note_lst.add(i)
            diversity += 1
    
    print(diversity)
    
