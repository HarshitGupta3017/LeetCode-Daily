// Solution for Longest Balanced Subarray II in CPP

class Solution {
public:

    /*
        We maintain a segment tree that stores:
        - Minimum value in the segment
        - Maximum value in the segment
        - Lazy propagation values (for range updates)

        Why min and max?
        Because to check if ZERO exists in a segment,
        we need to verify:
            segMin <= 0 <= segMax

        If zero lies within that range,
        then some index inside this segment has value 0.
    */
    vector<int> segMin, segMax, lazy;
    int n;

    /*
        Push pending lazy updates down to children.

        Why needed?
        Because we are doing range updates.
        Instead of updating each leaf directly (O(n)),
        we mark a segment as "lazy" and apply when needed.
    */
    void propagate(int node, int left, int right) {

        if (lazy[node] != 0) {

            // Apply pending value to this segment
            segMin[node] += lazy[node];
            segMax[node] += lazy[node];

            // If not a leaf, push to children
            if (left != right) {
                lazy[2*node + 1] += lazy[node];
                lazy[2*node + 2] += lazy[node];
            }

            // Clear lazy value
            lazy[node] = 0;
        }
    }

    /*
        Add 'val' to all elements in range [start, end].

        This updates prefix differences.
    */
    void updateRange(int start, int end,
                     int node, int left, int right,
                     int val) {

        propagate(node, left, right);

        // No overlap
        if (left > end || right < start)
            return;

        // Complete overlap
        if (left >= start && right <= end) {
            lazy[node] += val;
            propagate(node, left, right);
            return;
        }

        // Partial overlap → go deeper
        int mid = (left + right) / 2;

        updateRange(start, end, 2*node + 1, left, mid, val);
        updateRange(start, end, 2*node + 2, mid + 1, right, val);

        // Update current node from children
        segMin[node] = min(segMin[2*node + 1], segMin[2*node + 2]);
        segMax[node] = max(segMax[2*node + 1], segMax[2*node + 2]);
    }

    /*
        Find the leftmost index whose value is ZERO.

        If a segment's min > 0 OR max < 0,
        then zero does NOT exist inside it.
    */
    int findLeftMostZero(int node, int left, int right) {

        propagate(node, left, right);

        // If zero cannot exist in this segment
        if (segMin[node] > 0 || segMax[node] < 0)
            return -1;

        // If leaf node and contains zero
        if (left == right)
            return left;

        int mid = left + (right - left) / 2;

        // Try left child first (we want leftmost)
        int leftResult = findLeftMostZero(2*node + 1, left, mid);
        if (leftResult != -1)
            return leftResult;

        // Otherwise check right child
        return findLeftMostZero(2*node + 2, mid + 1, right);
    }

    int longestBalanced(vector<int>& nums) {

        n = nums.size();

        // Allocate segment tree arrays
        segMin.assign(4*n, 0);
        segMax.assign(4*n, 0);
        lazy.assign(4*n, 0);

        int maxLength = 0;

        /*
            Map to track last occurrence of each number.
            Because we count DISTINCT elements.
        */
        unordered_map<int, int> lastIndex;

        for (int right = 0; right < n; right++) {

            // Even contributes +1
            // Odd contributes -1
            int contribution = (nums[right] % 2 == 0) ? 1 : -1;

            // Check if this number appeared before
            int previousIndex =
                (lastIndex.count(nums[right])) ? lastIndex[nums[right]] : -1;

            /*
                If number appeared before,
                remove its old contribution
                from prefix [0, previousIndex]
            */
            if (previousIndex != -1) {
                updateRange(0, previousIndex,
                            0, 0, n - 1,
                            -contribution);
            }

            /*
                Add new contribution
                to prefix [0, right]
            */
            updateRange(0, right,
                        0, 0, n - 1,
                        contribution);

            /*
                Find earliest index where prefix diff == 0
            */
            int left = findLeftMostZero(0, 0, n - 1);

            if (left != -1) {
                maxLength = max(maxLength, right - left + 1);
            }

            // Update last occurrence
            lastIndex[nums[right]] = right;
        }

        return maxLength;
    }
};
