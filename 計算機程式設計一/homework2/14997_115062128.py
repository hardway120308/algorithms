X, N = map(int, input().split())
represent = input()

ans = []

while X > 0:
    ans.append(represent[X % N])
    X //= N

ans.reverse()

print(" ".join(ans))
