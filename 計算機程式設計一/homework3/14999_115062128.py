import collections

n, m, k = map(int, input().split())
edges = collections.defaultdict(list)
for _ in range(m):
    u, v = map(int, input().split())
    edges[u].append(v)
    edges[v].append(u)

visited = [False] * (n + 1)
q = collections.deque()

q.append((k, 0))
visited[k] = True
ans = 0

# bfs
while q:
    # 取出node
    v, deg = q.popleft()
    ans += 1

    if deg == 2:
        continue

    for neighbor in edges[v]:
        # 如果unvisited則加進去queue中
        if not visited[neighbor]:
            visited[neighbor] = True
            q.append((neighbor, deg + 1))

print(ans - 1)
