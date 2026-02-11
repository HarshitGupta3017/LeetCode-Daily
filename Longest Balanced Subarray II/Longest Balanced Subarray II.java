// Solution for Longest Balanced Subarray II in JAVA

class Solution {

    int[] segMin, segMax, lazy;
    int n;

    void propagate(int node, int left, int right) {

        if (lazy[node] != 0) {

            segMin[node] += lazy[node];
            segMax[node] += lazy[node];

            if (left != right) {
                lazy[2 * node + 1] += lazy[node];
                lazy[2 * node + 2] += lazy[node];
            }

            lazy[node] = 0;
        }
    }

    void updateRange(int start, int end,
                     int node, int left, int right,
                     int val) {

        propagate(node, left, right);

        if (left > end || right < start)
            return;

        if (left >= start && right <= end) {
            lazy[node] += val;
            propagate(node, left, right);
            return;
        }

        int mid = (left + right) / 2;

        updateRange(start, end, 2 * node + 1, left, mid, val);
        updateRange(start, end, 2 * node + 2, mid + 1, right, val);

        segMin[node] = Math.min(segMin[2 * node + 1], segMin[2 * node + 2]);
        segMax[node] = Math.max(segMax[2 * node + 1], segMax[2 * node + 2]);
    }

    int findLeftMostZero(int node, int left, int right) {

        propagate(node, left, right);

        if (segMin[node] > 0 || segMax[node] < 0)
            return -1;

        if (left == right)
            return left;

        int mid = left + (right - left) / 2;

        int leftResult = findLeftMostZero(2 * node + 1, left, mid);
        if (leftResult != -1)
            return leftResult;

        return findLeftMostZero(2 * node + 2, mid + 1, right);
    }

    public int longestBalanced(int[] nums) {

        n = nums.length;

        segMin = new int[4 * n];
        segMax = new int[4 * n];
        lazy = new int[4 * n];

        int maxLength = 0;

        Map<Integer, Integer> lastIndex = new HashMap<>();

        for (int right = 0; right < n; right++) {

            int contribution = (nums[right] % 2 == 0) ? 1 : -1;

            int previousIndex = lastIndex.getOrDefault(nums[right], -1);

            if (previousIndex != -1) {
                updateRange(0, previousIndex,
                        0, 0, n - 1,
                        -contribution);
            }

            updateRange(0, right,
                    0, 0, n - 1,
                    contribution);

            int left = findLeftMostZero(0, 0, n - 1);

            if (left != -1) {
                maxLength = Math.max(maxLength, right - left + 1);
            }

            lastIndex.put(nums[right], right);
        }

        return maxLength;
    }
}
