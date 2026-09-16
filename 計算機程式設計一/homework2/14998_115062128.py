L, R, T = list(map(int, input().split()))

mid = -1
i = 0
while L <= R:
    mid = (L + R) // 2
    print("Guess", mid)
    i += 1
    if mid == T:
        break
    elif mid < T:
        L = mid + 1
    else:
        R = mid - 1

print("Take", i, "times to find", T)
