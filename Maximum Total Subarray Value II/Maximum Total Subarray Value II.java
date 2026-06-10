// Solution for Maximum Total Subarray Value II in JAVA

class SegmentTree {
    int[] tree;
    boolean isMinTree;

    public SegmentTree(int[] nums, boolean isMinTree) {
        this.isMinTree = isMinTree;
        int n = nums.length;
        tree = new int[4 * n];
        build(0, 0, n - 1, nums);
    }

    public int query(int queryLeft, int queryRight, int n) {
        return queryRange(queryLeft, queryRight, 0, 0, n - 1);
    }

    private void build(int node, int nodeLeft, int nodeRight, int[] nums) {
        if (nodeLeft == nodeRight) {
            tree[node] = nums[nodeLeft];
            return;
        }

        int mid = nodeLeft + (nodeRight - nodeLeft) / 2;

        build(2 * node + 1, nodeLeft, mid, nums);
        build(2 * node + 2, mid + 1, nodeRight, nums);

        tree[node] = isMinTree
                ? Math.min(tree[2 * node + 1], tree[2 * node + 2])
                : Math.max(tree[2 * node + 1], tree[2 * node + 2]);
    }

    private int queryRange(int queryLeft, int queryRight,
                           int node, int nodeLeft, int nodeRight) {

        if (nodeLeft > queryRight || nodeRight < queryLeft) {
            return isMinTree ? Integer.MAX_VALUE : Integer.MIN_VALUE;
        }

        if (nodeLeft >= queryLeft && nodeRight <= queryRight) {
            return tree[node];
        }

        int mid = nodeLeft + (nodeRight - nodeLeft) / 2;

        int leftResult = queryRange(
                queryLeft, queryRight,
                2 * node + 1, nodeLeft, mid
        );

        int rightResult = queryRange(
                queryLeft, queryRight,
                2 * node + 2, mid + 1, nodeRight
        );

        return isMinTree
                ? Math.min(leftResult, rightResult)
                : Math.max(leftResult, rightResult);
    }
}

class Solution {

    private long subarrayValue(int l, int r,
                               SegmentTree minST,
                               SegmentTree maxST,
                               int n) {
        return (long) maxST.query(l, r, n)
                - minST.query(l, r, n);
    }

    public long maxTotalValue(int[] nums, int k) {
        int n = nums.length;

        SegmentTree minST = new SegmentTree(nums, true);
        SegmentTree maxST = new SegmentTree(nums, false);

        PriorityQueue<long[]> maxHeap =
                new PriorityQueue<>((a, b) -> Long.compare(b[0], a[0]));

        for (int l = 0; l < n; l++) {
            long value = subarrayValue(l, n - 1, minST, maxST, n);
            maxHeap.offer(new long[]{value, l, n - 1});
        }

        long totalValue = 0;

        while (k-- > 0) {
            long[] cur = maxHeap.poll();

            long value = cur[0];
            int l = (int) cur[1];
            int r = (int) cur[2];

            totalValue += value;

            if (l <= r - 1) {
                long nextValue =
                        subarrayValue(l, r - 1, minST, maxST, n);

                maxHeap.offer(new long[]{
                        nextValue, l, r - 1
                });
            }
        }

        return totalValue;
    }
}
