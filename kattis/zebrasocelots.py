n = int(input())
res = 0
for _ in range(n):
    res *= 2
    if input() == 'O':
        res += 1

print(res)
