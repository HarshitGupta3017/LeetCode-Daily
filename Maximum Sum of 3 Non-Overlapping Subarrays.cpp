class Solution {
public:
    int t[20001][4];
    int helper(vector<int>& subarray, int k, int count, int i) {
        if (count == 0) return 0;
        if (i >= subarray.size()) return INT_MIN;
        if (t[i][count] != -1) return t[i][count];
        int take = subarray[i] + helper(subarray, k, count - 1, i + k);
        int notTake = helper(subarray, k, count, i + 1);
        return t[i][count] = max(take, notTake);
    }

    void solve(vector<int>& subarray, int k, vector<int>& res, int count, int i) {
        if (count == 0 || i >= subarray.size()) return;
        int take = subarray[i] + helper(subarray, k, count - 1, i + k);
        int notTake = helper(subarray, k, count, i + 1);
        if (take >= notTake) {
            res.push_back(i);
            solve(subarray, k, res, count - 1, i + k);
        } else {
            solve(subarray, k, res, count, i + 1);
        }
    }

    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        memset(t, -1, sizeof(t));
        vector<int> subarray;
        int i = 0, sum = 0;
        for (int j = 0; j < nums.size(); j++) {
            sum += nums[j];
            if (j - i + 1 == k) {
                subarray.push_back(sum);
                sum -= nums[i++];
            }
        }
        vector<int> res;
        solve(subarray, k, res, 3, 0);
        return res;
    }
};
