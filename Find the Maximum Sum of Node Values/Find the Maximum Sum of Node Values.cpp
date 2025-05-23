// Solution for Find the Maximum Sum of Node Values in CPP

class Solution {
public:
    using ll = long long;

    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        ll totalSum = 0;
        int countBetterWithXOR = 0;
        int minLossWhenForcedToNotUseXOR = INT_MAX;

        for (int num : nums) {
            int xorValue = num ^ k;

            // If applying XOR increases the value, we tentatively choose it
            if (xorValue > num) {
                countBetterWithXOR++;
                totalSum += xorValue;
            } else {
                totalSum += num;
            }

            // Track the minimum difference between original and XOR value
            minLossWhenForcedToNotUseXOR = min(minLossWhenForcedToNotUseXOR, abs(num - xorValue));
        }

        // If odd number of XOR improvements, one must be undone to keep parity (edges come in pairs)
        if (countBetterWithXOR % 2 == 1) {
            return totalSum - minLossWhenForcedToNotUseXOR;
        }

        return totalSum;
    }
};
