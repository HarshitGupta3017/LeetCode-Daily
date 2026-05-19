// Solution for Minimum Common Value in CPP

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {

        int pointer1 = 0;
        int pointer2 = 0;

        // Traverse both sorted arrays simultaneously
        while (pointer1 < nums1.size() &&
               pointer2 < nums2.size()) {

            // Move pointer of smaller element
            if (nums1[pointer1] < nums2[pointer2]) {

                pointer1++;
            }

            else if (nums1[pointer1] > nums2[pointer2]) {

                pointer2++;
            }

            // Common element found
            else {

                return nums1[pointer1];
            }
        }

        // No common element exists
        return -1;
    }
};
