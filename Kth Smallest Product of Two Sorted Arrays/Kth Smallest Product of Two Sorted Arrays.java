// Solution for Kth Smallest Product of Two Sorted Arrays in JAVA

class Solution {
    public long kthSmallestProduct(int[] nums1, int[] nums2, long k) {
        long low = -10000000000L;
        long high = 10000000000L;
        long result = 0;

        while (low <= high) {
            long mid = low + (high - low) / 2;
            long count = countProductsLessEqual(nums1, nums2, mid);

            if (count >= k) {
                result = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return result;
    }

    private long countProductsLessEqual(int[] nums1, int[] nums2, long midProd) {
        long count = 0;
        int m = nums2.length;

        for (int i = 0; i < nums1.length; i++) {
            int a = nums1[i];

            if (a >= 0) {
                int left = 0, right = m - 1;
                int validRight = -1;

                while (left <= right) {
                    int mid = left + (right - left) / 2;
                    long product = (long) a * nums2[mid];
                    if (product <= midProd) {
                        validRight = mid;
                        left = mid + 1;
                    } else {
                        right = mid - 1;
                    }
                }

                count += (validRight + 1);
            } else {
                int left = 0, right = m - 1;
                int validLeft = m;

                while (left <= right) {
                    int mid = left + (right - left) / 2;
                    long product = (long) a * nums2[mid];
                    if (product <= midProd) {
                        validLeft = mid;
                        right = mid - 1;
                    } else {
                        left = mid + 1;
                    }
                }

                count += (m - validLeft);
            }
        }

        return count;
    }
}
