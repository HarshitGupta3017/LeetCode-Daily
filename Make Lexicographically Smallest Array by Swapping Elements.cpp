class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> vec = nums;
        sort(vec.begin(), vec.end());
        int grpno = 0;
        unordered_map<int, int> numToGroup;
        numToGroup[vec[0]] = grpno;
        unordered_map<int, list<int>> groupToList;
        groupToList[grpno].push_back(vec[0]);
        for (int i = 1; i < n; i++) {
            if (abs(vec[i] - vec[i - 1]) > limit) {
                grpno++;
            }
            numToGroup[vec[i]] = grpno;
            groupToList[grpno].push_back(vec[i]);
        }
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            int grp = numToGroup[nums[i]];
            res[i] = *(groupToList[grp].begin());
            groupToList[grp].pop_front();
        }
        return res;
    }
};
