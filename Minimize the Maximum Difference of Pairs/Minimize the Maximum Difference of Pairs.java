class Solution {
    // Function to check if it's possible to form at least 'p' valid pairs
    // such that the difference in each pair is <= 'maxDiffAllowed'
    private boolean isValid(int[] nums, int maxDiffAllowed, int p, int size) {
        int index = 0;
        int pairCount = 0;

        while (index < size - 1) {
            if (nums[index + 1] - nums[index] <= maxDiffAllowed) {
                pairCount++;
                index += 2; // Move past both elements in the pair
            } else {
                index++; // Try the next element
            }
        }

        return pairCount >= p;
    }

    public int minimizeMax(int[] nums, int p) {
        int n = nums.length;
        Arrays.sort(nums);

        int low = 0;
        int high = nums[n - 1] - nums[0];
        int result = Integer.MAX_VALUE;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (isValid(nums, mid, p, n)) {
                result = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return result;
    }
}
