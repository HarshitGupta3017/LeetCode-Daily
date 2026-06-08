// Solution for Partition Array According to Given Pivot in CPP

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> result(n);

        // left fills result from the front, collecting elements less than pivot
        // in the order they appear (left to right in nums).
        // right fills result from the back, collecting elements greater than pivot
        // in the order they appear (right to left in nums, so the final order is preserved).
        int left = 0, right = n - 1;

        // i walks forward to pick up elements less than pivot.
        // j walks backward to pick up elements greater than pivot.
        // Both pointers advance together so neither pass processes an index twice.
        int i = 0, j = n - 1;

        while (i < n && j >= 0) {
            if (nums[i] < pivot)
                result[left++] = nums[i];

            // Placing from the right in reverse so that when the backward pass is
            // done, the greater-than elements end up in their original left-to-right
            // order at the tail of result.
            if (nums[j] > pivot)
                result[right--] = nums[j];

            i++;
            j--;
        }

        // At this point, left is the first unfilled index and right is the last unfilled index.
        // Every slot between them belongs to pivot, since all smaller and larger elements
        // have already been placed at the two ends.
        while (left <= right) {
            result[left++] = pivot;
        }

        return result;
    }
};
