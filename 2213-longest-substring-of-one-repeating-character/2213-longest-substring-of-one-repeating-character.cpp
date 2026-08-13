class Solution {
public:

    struct Node {
        char left, right;
        int pre, suf, best, len;

        Node() {
            left = right = '#';
            pre = suf = best = len = 0;
        }
    };

    vector<Node> seg;

    Node merge(Node a, Node b) {

        if (a.len == 0) return b;
        if (b.len == 0) return a;

        Node res;

        res.left = a.left;
        res.right = b.right;
        res.len = a.len + b.len;

        res.pre = a.pre;
        res.suf = b.suf;

        res.best = max(a.best, b.best);

        if (a.right == b.left) {

            // Join suffix of left + prefix of right
            res.best = max(res.best, a.suf + b.pre);

            // Entire left segment is same
            if (a.pre == a.len) {
                res.pre = a.len + b.pre;
            }

            // Entire right segment is same
            if (b.suf == b.len) {
                res.suf = b.len + a.suf;
            }
        }

        return res;
    }

    void build(int idx, int l, int r, string &s) {

        if (l == r) {
            seg[idx].left = s[l];
            seg[idx].right = s[l];

            seg[idx].pre = 1;
            seg[idx].suf = 1;
            seg[idx].best = 1;
            seg[idx].len = 1;

            return;
        }

        int mid = (l + r) / 2;

        build(2 * idx, l, mid, s);
        build(2 * idx + 1, mid + 1, r, s);

        seg[idx] = merge(seg[2 * idx], seg[2 * idx + 1]);
    }

    void update(int idx, int l, int r, int pos, char ch) {

        if (l == r) {
            seg[idx].left = ch;
            seg[idx].right = ch;

            seg[idx].pre = 1;
            seg[idx].suf = 1;
            seg[idx].best = 1;

            return;
        }

        int mid = (l + r) / 2;

        if (pos <= mid) {
            update(2 * idx, l, mid, pos, ch);
        }
        else {
            update(2 * idx + 1, mid + 1, r, pos, ch);
        }

        seg[idx] = merge(seg[2 * idx], seg[2 * idx + 1]);
    }

    vector<int> longestRepeating(
        string s,
        string queryCharacters,
        vector<int>& queryIndices
    ) {

        int n = s.size();

        seg.resize(4 * n);

        build(1, 0, n - 1, s);

        vector<int> ans;

        for (int i = 0; i < queryCharacters.size(); i++) {

            int pos = queryIndices[i];
            char ch = queryCharacters[i];

            update(1, 0, n - 1, pos, ch);

            ans.push_back(seg[1].best);
        }

        return ans;
    }
};