#include <bits/stdc++.h>
using namespace std;

struct LazyTag {
    int toAdd;
    LazyTag() : toAdd(0) {}
    void add(const LazyTag &other) { toAdd += other.toAdd; }
    bool hasTag() const { return toAdd != 0; }
    void clear() { toAdd = 0; }
};

struct SegmentTreeNode {
    int minValue;
    int maxValue;
    LazyTag lazyTag;
    SegmentTreeNode() : minValue(0), maxValue(0) {}
};

struct SegmentTree {
    int n;
    vector<SegmentTreeNode> tree;

    SegmentTree(const vector<int> &data) {
        n = data.size();
        tree.resize(n * 4 + 1);
        build(data, 1, n, 1);
    }

    void add(int l, int r, int val) {
        LazyTag tag;
        tag.toAdd = val;
        update(l, r, tag, 1, n, 1);
    }

    int findLast(int start, int val) {
        if (start > n) return -1;
        return find(start, n, val, 1, n, 1);
    }

private:
    void applyTag(int i, const LazyTag &tag) {
        tree[i].minValue += tag.toAdd;
        tree[i].maxValue += tag.toAdd;
        tree[i].lazyTag.add(tag);
    }

    void pushdown(int i) {
        if (tree[i].lazyTag.hasTag()) {
            LazyTag tag;
            tag.toAdd = tree[i].lazyTag.toAdd;
            applyTag(i * 2, tag);
            applyTag(i * 2 + 1, tag);
            tree[i].lazyTag.clear();
        }
    }

    void pushup(int i) {
        tree[i].minValue = min(tree[i*2].minValue, tree[i*2+1].minValue);
        tree[i].maxValue = max(tree[i*2].maxValue, tree[i*2+1].maxValue);
    }

    void build(const vector<int> &data, int l, int r, int i) {
        if (l == r) {
            tree[i].minValue = tree[i].maxValue = data[l-1];
            return;
        }
        int mid = l + (r - l) / 2;
        build(data, l, mid, i*2);
        build(data, mid+1, r, i*2+1);
        pushup(i);
    }

    void update(int targetL, int targetR, const LazyTag &tag, int l, int r, int i) {
        if (targetL <= l && r <= targetR) {
            applyTag(i, tag);
            return;
        }
        pushdown(i);
        int mid = l + (r - l) / 2;
        if (targetL <= mid) update(targetL, targetR, tag, l, mid, i*2);
        if (targetR > mid) update(targetL, targetR, tag, mid+1, r, i*2+1);
        pushup(i);
    }

    int find(int targetL, int targetR, int val, int l, int r, int i) {
        if (tree[i].minValue > val || tree[i].maxValue < val) return -1;
        if (l == r) return l;
        pushdown(i);
        int mid = l + (r - l) / 2;
        if (targetR >= mid + 1) {
            int res = find(targetL, targetR, val, mid+1, r, i*2+1);
            if (res != -1) return res;
        }
        if (targetL <= mid) {
            return find(targetL, targetR, val, l, mid, i*2);
        }
        return -1;
    }
};

class Solution {
public:
    int longestBalanced(vector<int> &nums) {
        unordered_map<int, queue<int>> occurrences;
        int len = 0;
        int n = nums.size();
        vector<int> prefixSum(n);

        prefixSum[0] = sgn(nums[0]);
        occurrences[nums[0]].push(1);

        for (int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i-1];
            auto &occ = occurrences[nums[i]];
            if (occ.empty()) {
                prefixSum[i] += sgn(nums[i]);
            }
            occ.push(i+1);
        }

        SegmentTree seg(prefixSum);

        for (int i = 0; i < n; i++) {
            len = max(len, seg.findLast(i+len+1, 0) - (i+1) + 1);

            int nextPos = n + 1;
            auto &occ = occurrences[nums[i]];
            occ.pop();
            if (!occ.empty()) nextPos = occ.front();

            seg.add(i+1, nextPos-1, -sgn(nums[i]));
        }

        return len;
    }

private:
    int sgn(int x) {
        return (x % 2 == 0) ? 1 : -1;
    }
};
