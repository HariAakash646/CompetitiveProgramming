n = int(input())
arr = [int(x) for x in input().split()]
table = [1] * n

for i in range(1, n):
    if arr[i-1] < arr[i]:
        table[i] += table[i-1]

print(max(table))
