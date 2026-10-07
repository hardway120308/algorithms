n, m = map(int, input().split())

data = [[0 for _ in range(m)] for _ in range(n)]
ans = {}
for r in range(n):
    data[r] = list(map(int, input().split()))
for r in range(n):
    for c in range(m):
        ans[data[r][c]] = []
        ur, dr, lc, rc = (
            (r - 1 + n) % n,
            (r + 1 + n) % n,
            (c - 1 + m) % m,
            (c + 1 + m) % m,
        )
        ans[data[r][c]].append(data[ur][c])
        ans[data[r][c]].append(data[dr][c])
        ans[data[r][c]].append(data[r][lc])
        ans[data[r][c]].append(data[r][rc])

Q = int(input())
for _ in range(Q):
    x = int(input())
    ans[x] = list(set(ans[x]))
    ans[x].sort()
    print(" ".join(map(str, ans[x])))
