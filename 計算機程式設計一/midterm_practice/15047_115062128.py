n, m, k = map(int, input().split())
arr = [[0] * m for _ in range(n)]


def reachable(x, y):
    maxx, maxy = x, y
    for dx in [i for i in range(-k, k + 1)]:
        for dy in [j for j in range(-k, k + 1)]:
            nx = x + dx
            ny = y + dy
            if (
                0 <= nx < n
                and 0 <= ny < m
                and abs(nx - x) + abs(ny - y) <= k
                and arr[nx][ny] > arr[maxx][maxy]
            ):
                maxx, maxy = nx, ny
    if (maxx, maxy) == (x, y):
        return (-1, -1)
    return (maxx, maxy)


def reach(x, y):
    tmp = arr[x][y]
    arr[x][y] = 0
    return tmp


for i in range(n):
    arr[i] = list(map(int, input().split()))

x, y = map(int, input().split())
ans = 0
# reachable(2, 0)
while True:
    ans += reach(x, y)
    x, y = reachable(x, y)
    if x == -1 and y == -1:
        break
print(ans)
