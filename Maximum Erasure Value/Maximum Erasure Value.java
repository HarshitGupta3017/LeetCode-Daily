// Solution for Maximum Erasure Value in JAVA

class Solution {
    public int maximumUniqueSubarray(int[] nums) {
        int n = nums.length;
        int[] cumSum = new int[n];
        cumSum[0] = nums[0];
        for (int i = 1; i < n; i++) cumSum[i] = cumSum[i - 1] + nums[i];
        
        int left = 0, right = 0, maxScore = 0;
        int[] lastSeen = new int[10001];
        Arrays.fill(lastSeen, -1);
        
        while (right < n) {
            left = Math.max(left, lastSeen[nums[right]] + 1);
            int currentSum = cumSum[right] - (left > 0 ? cumSum[left - 1] : 0);
            maxScore = Math.max(maxScore, currentSum);
            lastSeen[nums[right]] = right;
            right++;
        }
        
        return maxScore;
    }
}
