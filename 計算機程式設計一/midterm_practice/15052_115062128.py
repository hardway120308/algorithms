n = int(input())

res1 = [0] * n
res2 = [0] * n
arr = []
for i in range(n):
    a, b = map(int, input().split())
    arr.append((a, b, i))

arr.sort(key=lambda x: (x[0], -x[1]))

max_right = -1
# 從前往後掃描被包含
# 因爲left遞增，所以只要right小於等於目前的最大right，就表示被包含
for i in range(n):
    left, right, idx = arr[i]
    if right <= max_right:
        res2[idx] = 1
    max_right = max(max_right, right)

min_right = float("inf")

# 從後往前掃描包含別人
# 因爲left遞增，所以只要right大於等於目前的最小right，就表示包含別人
for i in range(n - 1, -1, -1):
    left, right, idx = arr[i]
    if min_right <= right:
        res1[idx] = 1
    min_right = min(min_right, right)


# 包含別人
print(" ".join(map(str, res1)))
# 被包含
print(" ".join(map(str, res2)))
