// Solution for Longest Subsequence With Non-Zero Bitwise XOR in CPP

class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();

        // If every element is zero, any subsequence XORs to 0 — no valid subsequence exists.
        bool allZero = true;
        for (int num : nums) {
            if (num > 0) { allZero = false; break; }
        }
        if (allZero) return 0;

        // XOR of the entire array tells us whether the full array is already a valid answer.
        // If totalXor != 0, the full array itself has non-zero XOR — take all n elements.
        // If totalXor == 0, removing any single element that contributes an odd number of
        // times to the XOR will make the rest non-zero — so n-1 is always achievable.
        int totalXor = 0;
        for (int num : nums) totalXor ^= num;

        return totalXor != 0 ? n : n - 1;
    }
};
