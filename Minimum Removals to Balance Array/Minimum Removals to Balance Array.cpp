// Solution for Minimum Removals to Balance Array in CPP

class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {

        /*
            Step 1: Sort the array.

            WHY?
            ----
            To keep a subarray balanced, we only care about:
              max_element <= k * min_element

            If the array is sorted:
            - minimum is at the left end of a window
            - maximum is at the right end

            This allows us to use a sliding window efficiently.
        */
        sort(nums.begin(), nums.end());

        int n = nums.size();

        // left pointer of the sliding window (minimum element index)
        int left = 0;

        /*
            maxBalancedLength stores the maximum size of
            any balanced subarray found so far.
            At minimum, a single element is always balanced.
        */
        int maxBalancedLength = 1;

        /*
            right pointer expands the window and acts
            as the index of the maximum element.
        */
        for (int right = 0; right < n; right++) {

            /*
                While the current window is NOT balanced:
                nums[right] > k * nums[left]

                WHY advance left?
                -----------------
                Since nums[right] is fixed (current maximum),
                the only way to restore balance is to increase
                the minimum element by moving `left` forward.
            */
            while (left <= right && 1LL * nums[right] > 1LL * k * nums[left]) {
                left++;
            }

            /*
                Now the window [left ... right] is balanced.
                Update the best balanced subarray length.
            */
            maxBalancedLength = max(maxBalancedLength, right - left + 1);
        }

        /*
            We want to KEEP the largest balanced subarray.
            So we REMOVE everything else.
        */
        return n - maxBalancedLength;
    }
};
