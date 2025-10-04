// Solution for Container With Most Water in CPP

class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();

        // Stores the maximum area found
        int max_area = 0;

        // Two pointers: left starts at 0, right starts at n-1
        int left = 0, right = n - 1;

        // Iterate until the two pointers meet
        while (left < right) {
            // Width of the container
            int width = right - left;

            // Height of the container is determined by the shorter line
            int container_height = min(heights[left], heights[right]);

            // Calculate current area
            int current_area = width * container_height;

            // Update maximum area if current is larger
            max_area = max(max_area, current_area);

            // Move the pointer pointing to the shorter line inward
            if (heights[left] < heights[right]) {
                left++;
            } else {
                right--;
            }
        }

        return max_area;
    }
};
