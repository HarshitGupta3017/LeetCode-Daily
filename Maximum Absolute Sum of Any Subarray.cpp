class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxsum = 0, minsum = 0, currmax = 0, currmin = 0;
        for (const int& num: nums) {
            currmax = max(num, currmax + num);
            maxsum = max(maxsum, currmax);
            currmin = min(num, currmin + num);
            minsum = min(minsum, currmin);
        }
        return max(abs(maxsum), abs(minsum));
    }
};
