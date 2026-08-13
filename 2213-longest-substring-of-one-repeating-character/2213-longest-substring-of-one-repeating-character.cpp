class Solution {
    struct Node { int mx, lmx, rmx, sz; char lc, rc; };
    vector<Node> tree;
    string s;

    void pushup(int u) {
        int L = u << 1, R = u << 1 | 1;
        tree[u].lc = tree[L].lc;
        tree[u].rc = tree[R].rc;
        tree[u].sz = tree[L].sz + tree[R].sz;
        tree[u].mx = max(tree[L].mx, tree[R].mx);
        tree[u].lmx = tree[L].lmx;
        tree[u].rmx = tree[R].rmx;

        if (tree[L].rc == tree[R].lc) {
            tree[u].mx = max(tree[u].mx, tree[L].rmx + tree[R].lmx);
            if (tree[L].lmx == tree[L].sz) tree[u].lmx = tree[L].sz + tree[R].lmx;
            if (tree[R].rmx == tree[R].sz) tree[u].rmx = tree[R].sz + tree[L].rmx;
        }
    }

    void build(int u, int l, int r) {
        if (l == r) {
            tree[u] = {1, 1, 1, 1, s[l], s[l]};
            return;
        }
        int mid = (l + r) >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }

    void update(int u, int l, int r, int idx, char c) {
        if (l == r) {
            tree[u] = {1, 1, 1, 1, c, c};
            return;
        }
        int mid = (l + r) >> 1;
        if (idx <= mid) update(u << 1, l, mid, idx, c);
        else update(u << 1 | 1, mid + 1, r, idx, c);
        pushup(u);
    }

public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        this->s = s;
        int n = s.length();
        tree.resize(4 * n);
        build(1, 0, n - 1);
        vector<int> ans;
        for (int i = 0; i < queryIndices.size(); ++i) {
            update(1, 0, n - 1, queryIndices[i], queryCharacters[i]);
            ans.push_back(tree[1].mx);
        }
        return ans;
    }
};