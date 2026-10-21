N, Q = map(int, input().split())
# nxn graph
graph = [[0] * N for _ in range(N)]
sum_diag1 = [0 for _ in range(2 * N)]  # 左上到右下的對角線總和（主對角線）
sum_diag2 = [0 for _ in range(2 * N)]  # 右上到左下的對角線總和（次對角線）

for i in range(N):
    graph[i] = list(map(int, input().split()))

for i in range(N):
    for j in range(N):
        # 計算主對角線和 (x,y)所在的對角線編號爲x-y+N-1
        # 計算次對角線和 (x,y)所在的對角線編號爲x+y
        diag1_idx = i - j + N
        diag2_idx = i + j
        sum_diag1[diag1_idx] += graph[i][j]
        sum_diag2[diag2_idx] += graph[i][j]


for _ in range(Q):
    x, y = map(int, input().split())
    diag1_idx = x - y + N
    diag2_idx = x + y
    print(sum_diag1[diag1_idx] + sum_diag2[diag2_idx] - graph[x][y])
