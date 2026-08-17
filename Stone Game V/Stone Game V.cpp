// Solution for Stone Game V in CPP

class Solution {
public:
    // Returns the maximum score Alice can achieve from the subarray stoneValue[left..right].
    // At each step Alice splits the range, Bob discards the heavier half,
    // and Alice scores the lighter half then recurses on it.
    int solve(int left, int right, vector<int>& prefix, vector<vector<int>>& memo) {
        // A single stone cannot be split — no more score can be gained.
        if (left >= right) return 0;

        if (memo[left][right] != -1) return memo[left][right];

        int bestScore = 0;

        for (int mid = left; mid < right; mid++) {
            int leftSum  = prefix[mid] - (left > 0 ? prefix[left - 1] : 0);
            int rightSum = prefix[right] - prefix[mid];

            if (leftSum < rightSum) {
                // Bob discards the right (larger) half; Alice scores leftSum and recurses left.
                bestScore = max(bestScore, leftSum + solve(left, mid, prefix, memo));
            } else if (rightSum < leftSum) {
                // Bob discards the left (larger) half; Alice scores rightSum and recurses right.
                bestScore = max(bestScore, rightSum + solve(mid + 1, right, prefix, memo));
            } else {
                // Both halves are equal — Alice chooses whichever continuation is better.
                int keepLeft  = leftSum  + solve(left,    mid,   prefix, memo);
                int keepRight = rightSum + solve(mid + 1, right, prefix, memo);
                bestScore = max(bestScore, max(keepLeft, keepRight));
            }
        }

        return memo[left][right] = bestScore;
    }

    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();

        // prefix[i] = sum of stoneValue[0..i], used for O(1) range-sum queries.
        vector<int> prefix(n);
        prefix[0] = stoneValue[0];
        for (int i = 1; i < n; i++)
            prefix[i] = prefix[i - 1] + stoneValue[i];

        vector<vector<int>> memo(n, vector<int>(n, -1));
        return solve(0, n - 1, prefix, memo);
    }
};
