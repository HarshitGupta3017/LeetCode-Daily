class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        // simple ques 
        // its a 32 bit integer so we can check each bit for each number and compare total bits set
        int res = 0;
        for (int i = 0; i < 32; i++) {
            int count = 0;
            for (const int& num: candidates) {
                // for each number num we will check each bit i if its 1 i.e. set bit then we will increase 
                // count as we need total number of set bits 
                if (num & (1 << i)) count++;
            }
            res = max(count, res);
        }
        return res;
    }
};
