// Solution for Valid Triangle Number in CPP

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();        // Size of the input array
        int totalTriangles = 0;     // Counter to store total valid triangles

        // Step 1: Sort the array so we can apply two-pointer technique
        sort(nums.begin(), nums.end());

        // Step 2: Fix the largest side (nums[k]) and try to find pairs (nums[i], nums[j])
        for (int largest = n - 1; largest >= 2; largest--) {
            int left = 0;                  // Pointer at start
            int right = largest - 1;       // Pointer just before the largest side

            // Step 3: Check triangle inequality with two-pointer approach
            while (left < right) {
                // If nums[left] + nums[right] > nums[largest],
                // then all elements between left and right can form a valid triangle
                if (nums[left] + nums[right] > nums[largest]) {
                    totalTriangles += (right - left);  
                    right--;  // Decrease right to check other possible pairs
                } 
                // Otherwise, move left pointer to increase sum
                else {
                    left++;
                }
            }
        }

        return totalTriangles;  // Return total count of valid triangles
    }
};
