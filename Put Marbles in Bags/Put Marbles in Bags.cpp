// Solution for Put Marbles in Bags in CPP

class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        vector<int> pairSum(n - 1, 0);
        for (int i = 0; i < n - 1; i++) {
            pairSum[i] = weights[i] + weights[i + 1];
        }
        sort(pairSum.begin(), pairSum.end());
        long long minSum = 0, maxSum = 0;
        for (int i = 0; i < k - 1; i++) {
            minSum += pairSum[i];
            maxSum += pairSum[n - 1 - i - 1];
        }
        return maxSum - minSum;
    }
};
