// Solution for Partition Equal Subset Sum in CPP

class Solution {
public:

    int t[202][20002];

    bool solve(vector<int>& arr, int sum, int n) {
        if (sum == 0) return true;
        if (n == 0) return false;
        if (t[n][sum] != -1) return t[n][sum];
        bool take = false;
        if (arr[n - 1] <= sum) {
            take = solve(arr, sum - arr[n - 1], n - 1);
        }
        bool notTake = solve(arr, sum, n - 1);
        return t[n][sum] = take || notTake;
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) return false;
        memset(t, -1, sizeof(t));
        return solve(nums, sum / 2, n);
    }
};
