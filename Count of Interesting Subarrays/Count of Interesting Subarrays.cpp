// Solution for Count of Interesting Subarrays in CPP

class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int prefix = 0;
        long long res = 0;
        unordered_map<int, long long> freq;
        freq[0] = 1;
        for (int num: nums) {
            if (num % modulo == k) prefix++;
            int modPrefix = prefix % modulo;
            int prevPrefix = (modPrefix - k + modulo) % modulo;
            if (freq.count(prevPrefix)) res += freq[prevPrefix];
            freq[modPrefix]++;
        }
        return res;
    }
};
