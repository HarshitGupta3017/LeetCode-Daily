// Solution for Maximum Frequency of an Element After Performing Operations I in JAVA

class Solution {
    public int maxFrequency(int[] nums, int k, int numOperations) {
        int maxVal = Arrays.stream(nums).max().getAsInt() + k;
        int[] prefix = new int[maxVal + 1];

        for (int val : nums) prefix[val]++;
        for (int i = 1; i <= maxVal; i++) prefix[i] += prefix[i - 1];

        int ans = 0;
        for (int target = 0; target <= maxVal; target++) {
            if (prefix[target] == 0) continue;

            int left = Math.max(target - k, 0);
            int right = Math.min(target + k, maxVal);

            int total = prefix[right] - (left > 0 ? prefix[left - 1] : 0);
            int currFreq = prefix[target] - (target > 0 ? prefix[target - 1] : 0);
            int convert = Math.min(total - currFreq, numOperations);

            ans = Math.max(ans, currFreq + convert);
        }
        return ans;
    }
}
