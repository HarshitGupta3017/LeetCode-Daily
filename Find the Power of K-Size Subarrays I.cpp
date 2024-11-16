class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        // so a new question but easy one :)
        // we can see its clear that we can make window of size k and traverse in array 
        // and use sliding window to solve this
        // but we won't use this today
        // I won't to show you all new method through which we can do this
        int n = nums.size();
        vector<int> res(n - k + 1, -1);
        for (int i = 0; i < n - k + 1; i++) {
            // so we need to check now 2 things
            // in window of k 
            // we need to check 2 things in that array of size k
            // 1st - it should be sorted
            // 2nd - elements should be consecutive
            // as said in question
            // generated a subarray of size k
            vector<int> subarray(nums.begin() + i, nums.begin() + i + k);
            // for checking sorted array there is a method called is_sorted
            // it will tell if subarray is sorted or not
            bool isSorted = is_sorted(subarray.begin(), subarray.end());
            // adjacent_find - it can be used to check consecutive ones
            // it takes start point, end point and a parameter
            // parameter - we can pass the breaking point if the element is not consecutive and break 
            // and it will be false
            // now if it will be consecutives then that return will not be executed as it is executed
            // if it have non-consecutive number else it will go to end and return true;
            bool isConsecutive = adjacent_find(subarray.begin(), subarray.end(), [&](int& a, int& b){return b != a + 1;}) == subarray.end();
            if (isSorted && isConsecutive) {
                // need to store max element so as it will be in ascending order in this 
                // if statement so last element of that will be max one right
                res[i] = nums[i + k - 1];
            }
        }
        return res;
    }
};
