#include <bits/stdc++.h>

using namespace std;
#include <bits/stdc++.h>
using namespace std;

class Graph {
  private:
    vector<vector<int>> adj;

  public:
    // 建構子（可選初始節點數）
    Graph(int n = 0) { adj.resize(n); }

    // 新增一個節點，回傳 index
    int addVertex() {
        adj.emplace_back();
        return adj.size() - 1;
    }

    // 加邊
    void addEdge(int u, int v, bool directed = false) {
        adj[u].push_back(v);
        if (!directed) {
            adj[v].push_back(u);
        }
    }

    // 印出圖（debug用）
    void print() const {
        for (int i = 0; i < adj.size(); i++) {
            cout << i << ": ";
            for (int v : adj[i]) {
                cout << v << " ";
            }
            cout << "\n";
        }
    }
};

signed main() {
    int t;
    cin >> t;
    while (t--) {
        bool ok = false;
        int x, y;
        // 偶數,奇數
        cin >> x >> y;
        Graph G(x + y + 100);
        // 若可以必定奇node>偶node

        // 先建立一個長鏈
        int n = min(x, y);
        int now_x, now_y = 0;
        now_x = n;
        now_y = n;
        for (int i = 1; i <= n * 2; i += 2) {
            G.addEdge(i, i + 1);
        }
        if (now_x == x and now_y == y) {
            ok = true;
        } else {
            // 在偶數號加節點:奇+2偶-1
            int node = 2 * n + 1;
            int h = x - now_x;
            int g = y - 2 * x + 2 * now_x - now_y;
            // 在奇數號加節點:奇+1偶不變
            for (int i = 0; i <= n * 2; i++) {
                if (not g--)
                    break;

                G.addEdge(i, node);
                now_y += 1;

                if (now_x == x and now_y == y) {
                    ok = true;
                    break;
                }
                node++;
            }

            // 先減少偶數
            for (int i = 2; i <= n * 2; i += 2) {
                if (not h--)
                    break;
                G.addEdge(i, node);
                now_x--;
                now_y += 2;
                if (now_x == x) {
                    break;
                }
                node++;
            }
        }

        if (ok) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}
