class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        // so in this question we need to find pairs that make a total sum under the limit of lower and
        // upper as given
        // its clearly seen, order of elements is of no need so we can sort array
        // after sorting we can apply binary search
        // before that we can just loop for each element like
        // we can find a number nums[j] under limit lower - nums[i] and upper - nums[i]
        // if we subtract nums[i] from that limit we will get this only right??
        sort(nums.begin(), nums.end());
        long long count = 0;
        for (int i = 0; i < nums.size(); i++) {
            // so for each element nums[i] we can find other element nums[j] which is just higher or equal
            // to the lower limit i.e. 
            // we will start from i + 1 to n - 1 for finding j, after considering nums[i] as first element 
            // and limit is lower - nums[i] as told above
            // now it will return a element with atleast lower limit or above that 
            // subtracting nums.begin() to get index
            int left = lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]) - nums.begin(); 
            // same for upper limmit 
            int right = upper_bound(nums.begin() + i + 1, nums.end(), upper - nums[i]) - nums.begin(); 
            // this means for eg
            // [0,1,7,4,4,5] sort this - [0,1,4,4,5,7]
            // now left will give index as 2 and right will give index as 4
            // because nums[2] = 4 and nums[4] = 5, when we add this in nums[i] = nums[0] = 0
            // it will give 4 and 5 which lie under the lower and upper limit of 3 and 6
            // so from index 2 to index 4 all elements will lie within it with nums[i]
            // so count for it
            count += (right - left);
            // same will go for next elements
        }
        return count;
    }
};
