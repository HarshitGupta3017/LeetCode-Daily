class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        // so its a simple ques
        // need to find all valid peaks in the array and then check for maximum peak 
        // maximum peak = max length of total elements from left and right
        // such that we need to remove minimum no. of elements from array
        // so we can find that max peak length and will return n - mxlen
        // as remaining ones are that need to be removed
        // so for finding mxlen we can compute longest inreasing and decreasing subsequence for each
        // element in the array 
        int n = nums.size();
        vector<int> lis(n, 1), lds(n, 1);
        for(int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                // mountain array is first increasing to peak then decreasing
                // if current one is larger than previous one so its valid peak
                if (nums[i] > nums[j]) {
                    // storing lengths of each increasing element till peak in lis 
                    // if current one is greater than adding 1 to lis[j]
                    lis[i] = max(lis[i], lis[j] + 1);
                }
            }
        }
        // same for lds we can calculate from back
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j > i; j--) {
                if (nums[i] > nums[j]) {
                    lds[i] = max(lds[i], lds[j] + 1);
                }
            }
        }
        // now we can calculate mxlen for each element
        // we will exclude first and last element as they cant be mountain peak
        int mxlen = 0;
        for (int i = 1; i < n - 1; i++) {
            // if for each element lis and lds is greater than 1 that means it can be peak
            // so will calculate max
            if (lis[i] > 1 && lds[i] > 1) {
                // first increasing lis length to peak lis[i]
                // then decreasing from peak till element i.e. lds[i]
                // peak will be calculated 2 times so decreasing 1
                mxlen = max(mxlen, lis[i] + lds[i] - 1);
            }
        }
        // now return n - mxlen as that will be elements to remove
        return n - mxlen;
    }
};
