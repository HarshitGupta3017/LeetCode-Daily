// Solution for Sum of All Subset XOR Totals in CPP

class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int res = 0;
        for (const int& num: nums) res |= num;
        return res << (nums.size() - 1);
    }
};
