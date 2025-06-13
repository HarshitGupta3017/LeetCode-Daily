class Solution {
public:

    // Function to check if it's possible to form at least 'p' valid pairs
    // such that the difference in each pair is <= 'maxDiffAllowed'
    bool isValid(vector<int>& nums, int maxDiffAllowed, int p, int size) {
        int index = 0;
        int pairCount = 0;

        while (index < size - 1) {
            // If the difference between current and next number is small enough, form a pair
            if (nums[index + 1] - nums[index] <= maxDiffAllowed) {
                pairCount++;
                index += 2;  // Move past both elements in the pair
            } else {
                index++;     // Otherwise, try the next element
            }
        }

        return pairCount >= p;
    }

    int minimizeMax(vector<int>& nums, int p) {
        int n = nums.size();
        sort(nums.begin(), nums.end());  // Sort the array to enable greedy pairing

        int low = 0;
        int high = nums[n - 1] - nums[0];  // Maximum possible difference
        int result = INT_MAX;

        // Binary search to find the minimum possible maximum difference
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (isValid(nums, mid, p, n)) {
                result = mid;       // Update result and try smaller maximum
                high = mid - 1;
            } else {
                low = mid + 1;      // Try larger maximum
            }
        }

        return result;
    }
};
