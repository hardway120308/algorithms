# BFS問題

## Monsters

先使用Multi-source bfs 記錄每個Monster到達graph上每一個格子所需的最小時間，用min更新跑完整張圖

記錄層數的bfs:

```cpp
int step = 0;
while (!q.empty()) {
    int q_size = q.size();
    for (int _i = 0 ; _i < q_size; _i++) {
        auto cur = q.front();
        q.pop()
        // do something
    }
    step++;
}
```

然後再從A出發，同時記錄bfs層數（抵達時間），檢查是否合法（現在層數+1早於新格子monster到達的時間）
當走到B時，根據visited記錄的方向往回走，直到走回A，最後再反轉path

## Bacteria Reproduction

先排序使得編號較小的細菌總是先到達，然後再使用Multi-source bfs，確保第一個被狀態擴展到的格子一定是由最小編號的細菌抵達。這樣就可以直接用visited排除以及訪問過的格子。

## Wizard in Maze

0-1 BFS 或者 Dijkstra(會TLE)

0-1 BFS：

- cost=0的狀態push到deque前面。
- cost=1的push到deque後面
