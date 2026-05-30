// Solution for Block Placement Queries in CPP

class SegmentTree {
    vector<int> tree;
    int n;

public:
    SegmentTree(int size) : n(size) {
        // We need 4*n nodes to safely store a segment tree over n positions,
        // because the tree can be up to 2 levels deeper than a perfect binary tree.
        tree.resize(4 * n, 0);
    }

    void update(int idx, int val) {
        update(idx, val, 0, 0, n - 1);
    }

    int query(int left, int right) {
        return query(left, right, 0, 0, n - 1);
    }

private:
    void update(int idx, int val, int node, int nodeLeft, int nodeRight) {
        if (nodeLeft == nodeRight) {
            // We've reached the exact leaf that represents position idx.
            // Store the gap value here directly.
            tree[node] = val;
            return;
        }

        int mid = nodeLeft + (nodeRight - nodeLeft) / 2;

        if (idx <= mid)
            // idx is in the left half, so recurse left.
            update(idx, val, 2 * node + 1, nodeLeft, mid);
        else
            // idx is in the right half, so recurse right.
            update(idx, val, 2 * node + 2, mid + 1, nodeRight);

        // After updating a child, pull the max up to this node so that
        // any query passing through here always sees the largest gap below.
        tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);
    }

    int query(int left, int right, int node, int nodeLeft, int nodeRight) {
        if (nodeRight < left || nodeLeft > right)
            // This node's range has no overlap with [left, right].
            // Return 0 so it doesn't affect the max calculation above.
            return 0;

        if (left <= nodeLeft && nodeRight <= right)
            // This node's entire range sits inside [left, right],
            // so its stored max is already the correct answer for this subtree.
            return tree[node];

        int mid = nodeLeft + (nodeRight - nodeLeft) / 2;

        // The query range partially overlaps this node, so we split and
        // check both children, then return whichever half has the bigger gap.
        return max(
            query(left, right, 2 * node + 1, nodeLeft, mid),
            query(left, right, 2 * node + 2, mid + 1, nodeRight)
        );
    }
};

class Solution {
    // Per constraints, x and sz can be at most min(5*10^4, 3*|queries|).
    // We use 50000 as a safe upper bound for the segment tree size.
    static constexpr int N = 50000;

public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        SegmentTree segTree(N);

        // We track obstacle positions in a sorted set so we can quickly find
        // the nearest obstacle to the left or right of any point.
        // 0 is inserted as a sentinel so every obstacle always has a left neighbor,
        // avoiding null checks when computing gap widths.
        set<int> obstacles{0};
        vector<bool> results;

        for (const auto& q : queries) {
            if (q[0] == 1) {
                int x = q[1];

                // upper_bound(x) gives the first obstacle strictly to the right of x.
                // prev of that gives the closest obstacle to the left of x.
                auto rightIt     = obstacles.upper_bound(x);
                int leftObstacle  = *prev(rightIt);
                int rightObstacle = (rightIt != obstacles.end()) ? *rightIt : -1;

                // Before x was placed, the gap between leftObstacle and rightObstacle
                // was one big open space. Now x splits it into two smaller gaps.
                // We record the left portion: from leftObstacle up to x.
                segTree.update(x, x - leftObstacle);

                // The right neighbor previously owned the full gap from leftObstacle
                // to itself. Now that x exists, its left boundary shrinks to x.
                if (rightObstacle != -1)
                    segTree.update(rightObstacle, rightObstacle - x);

                obstacles.insert(x);
            }
            else {
                int x  = q[1];
                int sz = q[2];

                // Find the last obstacle that is at or before x.
                // Everything to the right of this obstacle up to x is free space,
                // but this trailing gap is not stored in the segment tree because
                // it keeps changing as new obstacles are added.
                int lastObstacle = *prev(obstacles.upper_bound(x));

                // Query the segment tree for the largest gap that is fully enclosed
                // between two obstacles, anywhere in the range [0, lastObstacle].
                int maxStoredGap = segTree.query(0, lastObstacle);

                // The open space from the last obstacle to x is not in the tree,
                // so we compute it manually and consider it as a candidate gap.
                int trailingGap = x - lastObstacle;

                // A block of size sz fits if at least one gap is wide enough to hold it.
                results.push_back(max(maxStoredGap, trailingGap) >= sz);
            }
        }

        return results;
    }
};
