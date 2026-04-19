// Solution for Maximum Distance Between a Pair of Values in CPP

class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {

        int pointer1 = 0; // Pointer for nums1
        int pointer2 = 0; // Pointer for nums2

        int maximumDistance = 0;

        int size1 = nums1.size();
        int size2 = nums2.size();

        // Traverse both arrays using two pointers
        while (pointer1 < size1 && pointer2 < size2) {

            // Check if current pair (i, j) is valid
            if (nums1[pointer1] <= nums2[pointer2]) {

                // Valid pair → update maximum distance
                maximumDistance = max(maximumDistance,
                                      pointer2 - pointer1);

                // Try to expand distance by moving j forward
                pointer2++;

            } else {
                // Invalid pair → need smaller nums1[i]
                // Move i forward to reduce nums1[i]
                pointer1++;
            }
        }

        return maximumDistance;
    }
};
