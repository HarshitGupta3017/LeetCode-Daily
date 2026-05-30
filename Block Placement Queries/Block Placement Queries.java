// Solution for Block Placement Queries in JAVA

class SegmentTree {
    private int[] tree;
    private int n;

    public SegmentTree(int size) {
        this.n = size;
        tree = new int[4 * n];
    }

    public void update(int idx, int val) {
        update(idx, val, 0, 0, n - 1);
    }

    public int query(int left, int right) {
        return query(left, right, 0, 0, n - 1);
    }

    private void update(int idx, int val, int node, int nodeLeft, int nodeRight) {
        if (nodeLeft == nodeRight) {
            tree[node] = val;
            return;
        }

        int mid = nodeLeft + (nodeRight - nodeLeft) / 2;

        if (idx <= mid) {
            update(idx, val, 2 * node + 1, nodeLeft, mid);
        } else {
            update(idx, val, 2 * node + 2, mid + 1, nodeRight);
        }

        tree[node] = Math.max(tree[2 * node + 1], tree[2 * node + 2]);
    }

    private int query(int left, int right, int node, int nodeLeft, int nodeRight) {
        if (nodeRight < left || nodeLeft > right) {
            return 0;
        }

        if (left <= nodeLeft && nodeRight <= right) {
            return tree[node];
        }

        int mid = nodeLeft + (nodeRight - nodeLeft) / 2;

        return Math.max(
            query(left, right, 2 * node + 1, nodeLeft, mid),
            query(left, right, 2 * node + 2, mid + 1, nodeRight)
        );
    }
}

class Solution {
    private static final int N = 50000;

    public List<Boolean> getResults(int[][] queries) {
        SegmentTree segTree = new SegmentTree(N);

        TreeSet<Integer> obstacles = new TreeSet<>();
        obstacles.add(0);

        List<Boolean> results = new ArrayList<>();

        for (int[] q : queries) {
            if (q[0] == 1) {
                int x = q[1];

                Integer rightObstacle = obstacles.higher(x);
                int leftObstacle = obstacles.floor(x);

                segTree.update(x, x - leftObstacle);

                if (rightObstacle != null) {
                    segTree.update(rightObstacle, rightObstacle - x);
                }

                obstacles.add(x);
            } else {
                int x = q[1];
                int sz = q[2];

                int lastObstacle = obstacles.floor(x);

                int maxStoredGap = segTree.query(0, lastObstacle);
                int trailingGap = x - lastObstacle;

                results.add(Math.max(maxStoredGap, trailingGap) >= sz);
            }
        }

        return results;
    }
}
