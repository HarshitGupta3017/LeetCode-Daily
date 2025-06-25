// Solution for Kth Smallest Product of Two Sorted Arrays in CPP

class Solution {
public:
    // Helper function: count how many products are ≤ midProd
    long long countProductsLessEqual(vector<int>& nums1, vector<int>& nums2, long long midProd) {
        long long productCount = 0;
        int m = nums2.size();

        for (int i = 0; i < nums1.size(); i++) {
            // If current number in nums1 is non-negative
            if (nums1[i] >= 0) {
                int left = 0, right = m - 1;
                int validRight = -1;  // Rightmost index where product <= midProd
                while (left <= right) {
                    int mid = left + (right - left) / 2;
                    long long prod = 1LL * nums1[i] * nums2[mid];
                    if (prod <= midProd) {
                        validRight = mid;
                        left = mid + 1;
                    } else {
                        right = mid - 1;
                    }
                }
                productCount += (validRight + 1);  // Add total valid products from nums2
            } else {
                // If current number in nums1 is negative
                int left = 0, right = m - 1;
                int validLeft = m;  // Leftmost index where product <= midProd
                while (left <= right) {
                    int mid = left + (right - left) / 2;
                    long long prod = 1LL * nums1[i] * nums2[mid];
                    if (prod <= midProd) {
                        validLeft = mid;
                        right = mid - 1;
                    } else {
                        left = mid + 1;
                    }
                }
                productCount += (m - validLeft);  // Count how many elements from right half
            }
        }

        return productCount;
    }

    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        long long result = 0;

        // Lower and upper bounds for binary search space
        long long low = -1e10;
        long long high = 1e10;

        // Binary search to find the smallest product such that count ≥ k
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            long long currentCount = countProductsLessEqual(nums1, nums2, mid);

            if (currentCount >= k) {
                result = mid;
                high = mid - 1;  // Try to find a smaller valid product
            } else {
                low = mid + 1;   // Increase product since count is less
            }
        }

        return result;
    }
};
