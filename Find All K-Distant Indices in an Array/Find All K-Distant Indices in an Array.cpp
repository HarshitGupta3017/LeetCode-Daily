// Solution for Find All K-Distant Indices in an Array in CPP

class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> kDistantIndices;  // Stores result indices
        int n = nums.size();

        for (int j = 0; j < n; j++) {
            if (nums[j] == key) {
                // Compute the range [start, end] for k-distant indices
                int start = max(0, j - k);
                int end = min(n - 1, j + k);

                // Avoid adding duplicates: skip indices already added
                if (!kDistantIndices.empty() && kDistantIndices.back() >= start) {
                    start = kDistantIndices.back() + 1;
                }

                // Add all indices from start to end
                for (int i = start; i <= end; i++) {
                    kDistantIndices.push_back(i);
                }
            }
        }

        return kDistantIndices;
    }
};
