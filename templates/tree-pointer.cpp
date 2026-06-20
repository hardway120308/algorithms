#include <bits/stdc++.h>

using namespace std;

class TreeNode {
  public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    };
};

// 使用指標
void dfs(TreeNode* root) {
    cout << "DFS:" << root->val << endl;
    if (root->left != nullptr) {
        dfs(root->left);
    }
    if (root->right != nullptr) {
        dfs(root->right);
    }
}

// BFS: Layer-ordered
void bfs(TreeNode* root) {
    queue<TreeNode*> Q;
    Q.push(root);
    while (not Q.empty()) {
        auto V = Q.front();
        Q.pop();
        cout << "BFS:" << V->val << endl;
        if (V->left != nullptr)
            Q.push(V->left);
        if (V->right != nullptr)
            Q.push(V->right);
    }
}

signed main() {
    int n;

    //          1
    //     2        3
    //  4    5
    // 6
    TreeNode root(1);
    TreeNode n2(2);
    TreeNode n3(3);
    TreeNode n4(4);
    TreeNode n5(5);
    TreeNode n6(6);

    root.left = &n2;
    root.right = &n3;

    n2.left = &n4;
    n2.right = &n5;

    n4.left = &n6;

    dfs(&root);
    cout << "-----------" << endl;
    bfs(&root);
}
