// Solution for Distribute Elements Into Two Arrays I in JAVA

class Solution {
    public int[] resultArray(int[] nums) {
        int n = nums.length;

        int[] result = new int[n];

        // nums[0] -> arr1, nums[1] -> arr2
        result[0] = nums[0];
        result[n - 1] = nums[1];

        int frontTail = 0;
        int backTail = n - 1;

        for (int i = 2; i < n; i++) {
            if (result[frontTail] > result[backTail]) {
                // Append to arr1
                result[++frontTail] = nums[i];
            } else {
                // Append to arr2
                result[--backTail] = nums[i];
            }
        }

        // Reverse arr2 to restore its original order
        int left = backTail;
        int right = n - 1;

        while (left < right) {
            int temp = result[left];
            result[left] = result[right];
            result[right] = temp;
            left++;
            right--;
        }

        return result;
    }
}
