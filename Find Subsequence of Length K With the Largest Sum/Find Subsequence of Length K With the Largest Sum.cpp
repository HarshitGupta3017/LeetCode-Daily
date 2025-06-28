// Solution for Find Subsequence of Length K With the Largest Sum in CPP

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        
        // Edge case: if k == size of array, return full array
        if (k == n) return nums;

        // Step 1: Copy nums and partially sort to find top k elements
        vector<int> temp(nums);
        // Place the k-th largest element at index k-1 (using nth_element)
        nth_element(temp.begin(), temp.begin() + k - 1, temp.end(), greater<int>());
        int kthLargest = temp[k - 1];

        // Step 2: Count how many times kthLargest appears in top k elements
        int remainingKthCount = count(temp.begin(), temp.begin() + k, kthLargest);

        // Step 3: Build the result by selecting from original array while preserving order
        vector<int> result;
        for (int num : nums) {
            if (num > kthLargest) {
                result.push_back(num);
            } else if (num == kthLargest && remainingKthCount > 0) {
                result.push_back(num);
                remainingKthCount--;
            }

            // Stop once we have selected k elements
            if (result.size() == k) break;
        }

        return result;
    }
};
