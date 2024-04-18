word = input()
n = len(word)

prev_q = 0
q_count = 0
a_count = 0
table = [0] * n

for i in range(n):
  
    if word[i] == "Q":
        table[i] = prev_q + q_count * a_count
        prev_q = table[i]
        q_count += 1
        a_count = 0
        
    elif word[i] == "A":
        a_count += 1

print(sum(table))
