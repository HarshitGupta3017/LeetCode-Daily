// Solution for Count Subarrays With Majority Element I in CPP

class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int result = 0;

        for (int left = 0; left < n; left++) {
            int targetCount = 0;

            for (int right = left; right < n; right++) {
                if (nums[right] == target) targetCount++;

                int subarrayLen = right - left + 1;

                // target is the majority element only when it appears strictly
                // more than half the time, i.e. targetCount * 2 > subarrayLen.
                // Multiplying both sides by 2 avoids floating-point division.
                if (targetCount * 2 > subarrayLen)
                    result++;
            }
        }

        return result;
    }
};
