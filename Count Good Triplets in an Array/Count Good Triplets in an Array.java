// Solution for Count Good Triplets in an Array in JAVA

class Solution {

    void updateSegTree(int i, int l, int r, int idx, long[] segTree) {
        if (l == r) {
            segTree[i] = 1;
            return;
        }
        int mid = l + (r - l) / 2;
        if (idx <= mid) {
            updateSegTree(2 * i + 1, l, mid, idx, segTree);
        } else {
            updateSegTree(2 * i + 2, mid + 1, r, idx, segTree);
        }
        segTree[i] = segTree[2 * i + 1] + segTree[2 * i + 2];
    }

    long querySegTree(int qs, int qe, int i, int l, int r, long[] segTree) {
        if (r < qs || l > qe) return 0;
        if (l >= qs && r <= qe) return segTree[i];
        int mid = l + (r - l) / 2;
        long left = querySegTree(qs, qe, 2 * i + 1, l, mid, segTree);
        long right = querySegTree(qs, qe, 2 * i + 2, mid + 1, r, segTree);
        return left + right;
    }

    public long goodTriplets(int[] nums1, int[] nums2) {
        int n = nums1.length;
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < n; i++) {
            map.put(nums2[i], i);
        }

        long[] segTree = new long[4 * n];
        long result = 0;

        updateSegTree(0, 0, n - 1, map.get(nums1[0]), segTree);

        for (int i = 1; i < n; i++) {
            int idx = map.get(nums1[i]);
            long leftCommonCount = querySegTree(0, idx, 0, 0, n - 1, segTree);
            long leftNotCommonCount = i - leftCommonCount;
            long elementsAfterIdxNums2 = n - 1 - idx;
            long rightCommonCount = elementsAfterIdxNums2 - leftNotCommonCount;
            result += leftCommonCount * rightCommonCount;
            updateSegTree(0, 0, n - 1, idx, segTree);
        }

        return result;
    }
}
