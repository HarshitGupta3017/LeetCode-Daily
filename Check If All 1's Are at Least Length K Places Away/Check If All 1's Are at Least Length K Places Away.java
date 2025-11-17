// Solution for Check If All 1's Are at Least Length K Places Away in JAVA

class Solution {
    public boolean kLengthApart(int[] nums, int k) {
        int prev = -1;
        for (int curr = 0; curr < nums.length; curr++) {
            if (nums[curr] == 0) continue;
            if (prev != -1 && curr - prev - 1 < k) {
                return false;
            }
            prev = curr;
        }
        return true;
    }
}
