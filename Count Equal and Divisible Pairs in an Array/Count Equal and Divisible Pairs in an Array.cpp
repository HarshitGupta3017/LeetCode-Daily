// Solution for Count Equal and Divisible Pairs in an Array in CPP

class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> mp;
        int n = nums.size();
        int count = 0;
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            if (mp.find(num) != mp.end()) {
                for (auto prev_idx: mp[num]) {
                    if ((prev_idx * i) % k == 0) count++;
                }
            }
            mp[num].push_back(i);
        }
        return count;
    }
};
