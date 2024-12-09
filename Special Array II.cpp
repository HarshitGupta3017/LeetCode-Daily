class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> is_special(n - 1, 0);
        for (int i = 0; i < n - 1; i++) {
            is_special[i] = (nums[i] % 2 != nums[i + 1] % 2);
        }
        vector<int> prefix_special(n, 0);
        for (int i = 1; i < n; i++) {
            prefix_special[i] = prefix_special[i - 1] + is_special[i - 1];
        }
        vector<bool> res(queries.size(), true);
        for (int q = 0; q < queries.size(); q++) {
            int from = queries[q][0], to = queries[q][1];
            int count_special_pairs = prefix_special[to] - prefix_special[from];
            res[q] = (count_special_pairs == to - from);
        }
        return res;
    }
};
