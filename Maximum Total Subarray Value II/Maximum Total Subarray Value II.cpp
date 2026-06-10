// Solution for Maximum Total Subarray Value II in CPP

class SegmentTree {
public:
    vector<int> tree;
    bool isMinTree;

    SegmentTree(vector<int>& nums, bool isMinTree) : isMinTree(isMinTree) {
        int n = nums.size();
        tree.resize(4 * n);
        build(0, 0, n - 1, nums);
    }

    int query(int queryLeft, int queryRight, int n) {
        return queryRange(queryLeft, queryRight, 0, 0, n - 1);
    }

private:
    void build(int node, int nodeLeft, int nodeRight, vector<int>& nums) {
        if (nodeLeft == nodeRight) {
            tree[node] = nums[nodeLeft];
            return;
        }

        int mid = nodeLeft + (nodeRight - nodeLeft) / 2;

        build(2 * node + 1, nodeLeft, mid, nums);
        build(2 * node + 2, mid + 1, nodeRight, nums);

        // Each internal node stores the min (or max) of its subtree so any
        // range query can be answered in O(log n) without scanning every leaf.
        tree[node] = isMinTree
            ? min(tree[2 * node + 1], tree[2 * node + 2])
            : max(tree[2 * node + 1], tree[2 * node + 2]);
    }

    int queryRange(int queryLeft, int queryRight, int node, int nodeLeft, int nodeRight) {
        if (nodeLeft > queryRight || nodeRight < queryLeft)
            // This node's range is fully outside the query window.
            // Return a neutral value that won't affect the min/max result above.
            return isMinTree ? INT_MAX : INT_MIN;

        if (nodeLeft >= queryLeft && nodeRight <= queryRight)
            // This node's range is fully inside the query window.
            // Its stored value is already the correct answer for this subtree.
            return tree[node];

        int mid = nodeLeft + (nodeRight - nodeLeft) / 2;

        int leftResult  = queryRange(queryLeft, queryRight, 2 * node + 1, nodeLeft, mid);
        int rightResult = queryRange(queryLeft, queryRight, 2 * node + 2, mid + 1, nodeRight);

        return isMinTree ? min(leftResult, rightResult) : max(leftResult, rightResult);
    }
};

class Solution {
public:
    using ll = long long;

    // Returns max - min over nums[l..r] using the prebuilt segment trees.
    ll subarrayValue(int l, int r, SegmentTree& minST, SegmentTree& maxST, int n) {
        return (ll)maxST.query(l, r, n) - minST.query(l, r, n);
    }

    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();

        SegmentTree minST(nums, true);
        SegmentTree maxST(nums, false);

        // Max-heap of {value, l, r}: always gives the highest-value subarray seen so far.
        priority_queue<tuple<ll, int, int>> maxHeap;

        // Seed the heap with the widest possible subarray starting at each index l.
        // nums[l..n-1] is the largest window starting at l, so it gives the best
        // starting candidate for that left boundary.
        for (int l = 0; l < n; l++) {
            ll value = subarrayValue(l, n - 1, minST, maxST, n);
            maxHeap.push({value, l, n - 1});
        }

        ll totalValue = 0;

        while (k--) {
            auto [value, l, r] = maxHeap.top();
            maxHeap.pop();

            totalValue += value;

            // We've consumed nums[l..r]. The next best distinct subarray sharing
            // this left boundary is nums[l..r-1] (shrink from the right).
            // Only push if the shrunk subarray is still valid (l <= r - 1).
            // Bug fix: original code pushed even when r - 1 < l, causing invalid
            // segment tree queries on degenerate ranges.
            if (l <= r - 1) {
                ll nextValue = subarrayValue(l, r - 1, minST, maxST, n);
                maxHeap.push({nextValue, l, r - 1});
            }
        }

        return totalValue;
    }
};
