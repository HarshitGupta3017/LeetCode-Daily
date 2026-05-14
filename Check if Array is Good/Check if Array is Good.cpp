// Solution for Check if Array is Good in CPP

class Solution {
public:
    bool isGood(vector<int>& nums) {

        // Sort array to compare with expected pattern
        sort(nums.begin(), nums.end());

        // If array length is n + 1,
        // then expected maximum value is n
        int expectedMaximum = nums.size() - 1;

        // Check values from 1 to n
        for (int index = 0; index < expectedMaximum; index++) {

            // Expected sequence:
            // [1, 2, 3, ..., n]
            if (nums[index] != index + 1)
                return false;
        }

        // Last element must also be n
        // because n appears twice
        return nums[expectedMaximum] == expectedMaximum;
    }
};
