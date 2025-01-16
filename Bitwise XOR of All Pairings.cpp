class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int xor1 = 0, xor2 = 0;
        int n = nums1.size(), m = nums2.size();
        for (const auto& num: nums1) {
            xor1 ^= num;
        }
        for (const auto& num: nums2) {
            xor2 ^= num;
        }
        return (n % 2 ? xor2 : 0) ^ (m % 2 ? xor1 : 0);
    }
};
