class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        // simple sliding window ques need to maintain window of size k
        // and calculate sum, need to keep one point in mind that no duplicate elements allowed in window
        // for that we can use set to keep track of that
        int n = nums.size();
        unordered_set<int> st;
        long long res = 0, sum = 0;
        int i = 0;
        for (int j = 0; j < n; j++) {
            // now if nums[j] already present in set so remove that from window and shrink from left side
            // oh we need to shrink from left so remove nums[i], mb 
            while (st.count(nums[j])) {
                sum -= nums[i];
                st.erase(nums[i]);
                i++;
            }
            sum += nums[j];
            st.insert(nums[j]);
            if (j - i + 1 == k) {
                res = max(res, sum);
                // also shrink from left as it equal to k
                sum -= nums[i];
                st.erase(nums[i]);
                i++;
            }
        }
        return res;
    }
};
