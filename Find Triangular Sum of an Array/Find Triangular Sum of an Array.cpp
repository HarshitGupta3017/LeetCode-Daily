// Solution for Find Triangular Sum of an Array in CPP

class Solution {
public:
    // Function to compute the triangular sum of nums
    int triangularSum(vector<int>& nums) {
        // Keep reducing nums until only one element remains
        while (nums.size() > 1) {
            // Create a temporary vector of reduced size
            vector<int> reduced(nums.size() - 1);
            
            // Compute each element in the reduced array
            for (int i = 0; i < nums.size() - 1; i++) {
                reduced[i] = (nums[i] + nums[i + 1]) % 10;
            }
            
            // Replace nums with reduced version
            nums = reduced;
        }
        
        // Final remaining element is the triangular sum
        return nums[0];
    }
};
