// Solution for Find Subsequence of Length K With the Largest Sum in JAVA

class Solution {
    public int[] maxSubsequence(int[] nums, int k) {
        int n = nums.length;

        if (k == n) return nums;

        int[] temp = Arrays.copyOf(nums, n);
        Arrays.sort(temp);
        int kthLargest = temp[n - k];

        int remainingKthCount = 0;
        for (int i = n - k; i < n; i++) {
            if (temp[i] == kthLargest) remainingKthCount++;
        }

        List<Integer> result = new ArrayList<>();
        for (int num : nums) {
            if (num > kthLargest) {
                result.add(num);
            } else if (num == kthLargest && remainingKthCount > 0) {
                result.add(num);
                remainingKthCount--;
            }

            if (result.size() == k) break;
        }

        // Convert List to array
        int[] res = new int[k];
        for (int i = 0; i < k; i++) res[i] = result.get(i);
        return res;
    }
}
