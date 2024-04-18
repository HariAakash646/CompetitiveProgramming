n = int(input())
array = list(map(int, input().split()))

table = [1] * n
for i in range(n):
    if i == 0:
        continue
    if array[i-1] <= array[i]:
        table[i] = table[i-1] + 1

print(max(table))
