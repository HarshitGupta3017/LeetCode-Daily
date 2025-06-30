// Solution for Longest Harmonious Subsequence in CPP

class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> freqMap;

        // Count the frequency of each element
        for (int num : nums) {
            freqMap[num]++;
        }

        int maxLength = 0;

        // Check for harmonious pairs (x, x + 1)
        for (const auto& [num, count] : freqMap) {
            if (freqMap.count(num + 1)) {
                int currentLength = count + freqMap[num + 1];
                maxLength = max(maxLength, currentLength);
            }
        }

        return maxLength;
    }
};
