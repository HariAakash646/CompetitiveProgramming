n, q = input().split()
n, q = int(n), int(q)
song = input()

a_ascii = ord('a')
table = [0] * n

for i in range(n):
    table[i] += ord(song[i]) - a_ascii + 1 + table[i-1]

for _ in range(q):
    l, r = input().split()
    l, r = int(l), int(r)
    print(table[r-1] - table[l-2]*(l!=1))
    
