// Solution for Make Array Elements Equal to Zero in CPP

class Solution {
public:
    bool simulateProcess(vector<int> nums, int curr, int dir) {
        int n = nums.size();

        // Step 1️⃣: Continue moving while inside valid index range
        while (curr >= 0 && curr < n) {
            // Case 1: Current cell already 0 → move one step in the same direction
            if (nums[curr] == 0) {
                curr += dir;
            }
            // Case 2: Current cell > 0 → decrement, reverse direction, then move
            else {
                nums[curr]--;
                dir = -dir;  // Reverse movement direction
                curr += dir;
            }
        }

        // Step 2️⃣: After exiting the array bounds, check if all elements became zero
        return all_of(nums.begin(), nums.end(), [](int x) { return x == 0; });
    }

    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        int validSelections = 0;

        // Step 1️⃣: Try every position that initially has value 0
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                // Step 2️⃣: Try both movement directions from this position
                if (simulateProcess(nums, i, 1)) validSelections++;   // Move right
                if (simulateProcess(nums, i, -1)) validSelections++;  // Move left
            }
        }

        return validSelections;
    }
};
