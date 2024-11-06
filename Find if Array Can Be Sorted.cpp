class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        // so a sorting question, we should think and check if we can use any sorting approach
        // we need to swap elements in this and sort them and its done in bubble sort right???
        // so lets write bubble sort 
        // only condition here added is that when we swap in bubble sort also check if setbits are 
        // equal or not
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            // there can be a situation when swaps are done in one pass only and array is sorted
            // lets check that too for reducing time complexity
            bool isSorted = false;
            for (int j = 0; j < n - i - 1; j++) {
                // if first element is less or equal no need of sorting
                if (nums[j] <= nums[j + 1]) continue;
                // if first element is larger than second one then we need to swap
                // but also need to check if set bits are equal or not
                // we have a function to find setbits i.e. __builtin_popcount
                else if (__builtin_popcount(nums[j]) == __builtin_popcount(nums[j + 1])) {
                    swap(nums[j], nums[j + 1]);
                    // swap is done so need to change this variable
                    isSorted = true;
                } else {
                    // if swap isnt done i.e. bits aren't equal so swap can't be done hence return false
                    return false;
                }
            }
            if (!isSorted) break;
        }
        // all swaps done
        return true;
    }
};
