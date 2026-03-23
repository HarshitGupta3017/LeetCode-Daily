// Solution for Maximum Non Negative Product in a Matrix in CPP

class Solution {
public:

    using ll = long long;
    const int MOD = 1e9 + 7;

    int maxProductPath(vector<vector<int>>& grid) {

        int rows = grid.size();
        int cols = grid[0].size();

        /*
            dp[r][c] = {maxProduct, minProduct}

            WHY both?
            Because:
            - Negative * Negative = Positive
            - So a minimum (negative) value can become maximum later

            So we must track BOTH max and min
        */
        vector<vector<pair<ll, ll>>> dp(rows, vector<pair<ll, ll>>(cols));

        /*
            Base case: starting cell
        */
        dp[0][0] = {grid[0][0], grid[0][0]};

        /*
            Fill first row (only can come from left)
        */
        for (int col = 1; col < cols; col++) {
            ll val = grid[0][col];

            dp[0][col].first  = dp[0][col - 1].first * val;
            dp[0][col].second = dp[0][col - 1].second * val;
        }

        /*
            Fill first column (only can come from top)
        */
        for (int row = 1; row < rows; row++) {
            ll val = grid[row][0];

            dp[row][0].first  = dp[row - 1][0].first * val;
            dp[row][0].second = dp[row - 1][0].second * val;
        }

        /*
            Fill rest of the grid
        */
        for (int row = 1; row < rows; row++) {
            for (int col = 1; col < cols; col++) {

                ll val = grid[row][col];

                /*
                    Values coming from TOP cell
                */
                ll topMax = dp[row - 1][col].first;
                ll topMin = dp[row - 1][col].second;

                /*
                    Values coming from LEFT cell
                */
                ll leftMax = dp[row][col - 1].first;
                ll leftMin = dp[row][col - 1].second;

                /*
                    Try all combinations because sign can flip
                */
                vector<ll> candidates = {
                    topMax * val,
                    topMin * val,
                    leftMax * val,
                    leftMin * val
                };

                /*
                    Store best and worst
                */
                dp[row][col].first  = *max_element(candidates.begin(), candidates.end());
                dp[row][col].second = *min_element(candidates.begin(), candidates.end());
            }
        }

        /*
            Final answer at bottom-right
        */
        ll maxProduct = dp[rows - 1][cols - 1].first;

        /*
            If maximum product is negative → impossible
        */
        if (maxProduct < 0) return -1;

        return maxProduct % MOD;
    }
};
