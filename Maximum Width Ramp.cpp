class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> pairs(n);
        for (int i = 0; i < n; i++) {
            pairs[i] = {nums[i], i};
        }
        sort(pairs.begin(), pairs.end());
        int minInd = pairs[0].second;
        int maxWid = 0;
        for (int i = 1; i < n; i++) {
            minInd = min(minInd, pairs[i].second);
            maxWid = max(maxWid, pairs[i].second - minInd);
        }
        return maxWid;
    }
};
