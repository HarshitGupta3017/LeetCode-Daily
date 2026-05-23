// Solution for Check if Array Is Sorted and Rotated in CPP

class Solution {
public:
    bool check(vector<int>& nums) {

        int totalElements = nums.size();

        // Count positions where descending order appears
        int rotationBreaks = 0;

        for (int index = 0; index < totalElements; index++) {

            // Compare current element with next element
            // using circular indexing
            if (nums[index] > nums[(index + 1) % totalElements]) {

                rotationBreaks++;
            }
        }

        // A valid sorted rotated array
        // can have at most one breaking point
        return rotationBreaks <= 1;
    }
};
