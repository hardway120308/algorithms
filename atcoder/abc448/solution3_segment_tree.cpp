#include <bits/stdc++.h>
using namespace std;

struct SegmentNode {
    long long int max, val_l, val_r;
    SegmentNode* left;
    SegmentNode* right;
    SegmentNode(long long int max, int l, int r) {
        this->max = max;
        this->val_l = l;
        this->val_r = r;
        left = NULL;
        right = NULL;
    }
};

SegmentNode* build_segment_tree(vector<long long int> v, int l, int r) {
    if (l == r) {
        return new SegmentNode(v[l], l, r);
    }
    if (l > r)
        return NULL;
    int mid = (l + r) / 2;

    SegmentNode* res = new SegmentNode(0, l, r);
    res->left = build_segment_tree(v, l, mid);
    res->right = build_segment_tree(v, mid + 1, r);
    res->max = min(res->left->max, res->right->max);

    return res;
}

SegmentNode* update_segment_tree(SegmentNode* ptr, int index, long long int val) {
    // 現在節點爲所要修改的節點
    if (ptr->val_l == index and ptr->val_r == index) {
        ptr->max = val;
        return ptr;
    }
    // 中間區間
    int mid = ptr->val_l + ((ptr->val_r - ptr->val_l) / 2);

    if (index <= mid and ptr->left != NULL) {
        update_segment_tree(ptr->left, index, val);
    } else {
        if (ptr->right != NULL) {
            update_segment_tree(ptr->right, index, val);
        }
    }

    ptr->max = min(ptr->left->max, ptr->right->max);
    return ptr;
}

int query_max(SegmentNode* ptr) { return ptr->max; }

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<long long int> A;
    for (int i = 0; i < N; i++) {
        long long int x;
        cin >> x;
        A.push_back(x);
    }

    for (int i = 0; i < Q; i++) {
        int K;
        cin >> K;
        SegmentNode* root = build_segment_tree(A, 0, N - 1);

        for (int j = 0; j < K; j++) {
            int x;
            cin >> x;
            update_segment_tree(root, x - 1, 1e10);
        }

        cout << query_max(root) << endl;
    }
    return 0;
}
