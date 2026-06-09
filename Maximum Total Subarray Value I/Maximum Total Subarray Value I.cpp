// Solution for Maximum Total Subarray Value I in CPP

class Solution {
public:
   long long maxTotalValue(vector<int>& nums, int k) {
       // The value of any subarray is max - min within that subarray.
       // The single subarray [nums[0]..nums[n-1]] (the whole array) achieves
       // the global max minus the global min, which is the largest possible
       // value any subarray can contribute.
       // Since subarrays may overlap and be reused, we simply pick this
       // maximum-value subarray all k times.
       long long globalMax = *max_element(nums.begin(), nums.end());
       long long globalMin = *min_element(nums.begin(), nums.end());

       return (globalMax - globalMin) * k;
   }
};
