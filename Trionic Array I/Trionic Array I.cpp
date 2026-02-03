// Solution for Trionic Array I in CPP

class Solution {
public:
    bool isTrionic(vector<int>& nums) {

        int n = nums.size();
        int index = 0;

        /*
            Phase 1: Strictly Increasing
            nums[0 ... p] must be strictly increasing
        */
        while (index + 1 < n && nums[index] < nums[index + 1]) {
            index++;
        }

        /*
            If no increasing part exists
            OR increasing goes till the last element,
            then trionic condition fails.
        */
        if (index == 0 || index == n - 1) {
            return false;
        }

        /*
            Phase 2: Strictly Decreasing
            nums[p ... q] must be strictly decreasing
        */
        while (index + 1 < n && nums[index] > nums[index + 1]) {
            index++;
        }

        /*
            If decreasing part ends at the last element,
            there is no final increasing phase.
        */
        if (index == n - 1) {
            return false;
        }

        /*
            Phase 3: Strictly Increasing again
            nums[q ... n-1] must be strictly increasing
        */
        while (index + 1 < n && nums[index] < nums[index + 1]) {
            index++;
        }

        /*
            Valid trionic array only if
            we consumed the entire array exactly.
        */
        return index == n - 1;
    }
};
