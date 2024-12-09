class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        // so a simple ques, you should try Special Array I too, it's easy
        // special pairs means adjacent pairs in which one is even and other is odd
        // if both are even or both odd then not special
        // lets first calculate all special adjacent pairs
        int n = nums.size();
        vector<int> is_special(n - 1, 0);
        for (int i = 0; i < n - 1; i++) {
            // if first is even and other odd i.e. 2 != 3, then it will give true as its special
            // otherwise if 2 != 2, then it will give false
            is_special[i] = (nums[i] % 2 != nums[i + 1] % 2);
        }
        // now lets calculate total special arrays as moving ahead in array
        // total special arrays at a index i
        vector<int> prefix_array(n, 0);
        for (int i = 1; i < n; i++) {
            prefix_array[i] = prefix_array[i - 1] + is_special[i - 1];
        }
        // now we can easily traverse on queries and check which are special in given range
        vector<bool> res(queries.size(), true);
        for (int q = 0; q < queries.size(); q++) {
            int from = queries[q][0], to = queries[q][1];
            int count_special_pairs = prefix_array[to] - prefix_array[from];
            // total special pairs will be to - from as we counting adjacent pairs only
            // so if count_special_pairs are equal to total special pairs that mean it's a special array
            res[q] = (count_special_pairs == to - from);
        }
        return res;
    }
};
