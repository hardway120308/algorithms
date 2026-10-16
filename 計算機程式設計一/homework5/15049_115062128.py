n, m = map(int, input().split())


class DSU:
    parent: list[int]

    def __init__(self, n: int):
        """一開始每個人的parent是自己"""
        self.parent = list(range(n + 1))
        self.rank = [0] * (n + 1)

    def find(self, x: int) -> int:
        """遞迴找到x的root"""
        if self.parent[x] == x:
            return x
        return self.find(self.parent[x])

    def union(self, x: int, y: int) -> None:
        """把x,y放到同一個集合"""
        root_x = self.find(x)
        root_y = self.find(y)
        if root_x == root_y:
            return

        if self.rank[root_x] < self.rank[root_y]:
            root_x, root_y = root_y, root_x
        self.parent[root_y] = root_x

        if self.rank[root_x] == self.rank[root_y]:
            self.rank[root_x] += 1

    def size(self) -> int:
        """找到有多少集合"""
        distinct_root = set()
        for i in range(n + 1):
            distinct_root.add(self.find(i))

        # 刪除1因爲是1-based index
        return len(distinct_root) - 1


relations = DSU(n)

for _ in range(m):
    a, b = map(int, input().split())
    relations.union(a, b)

print(relations.size())
