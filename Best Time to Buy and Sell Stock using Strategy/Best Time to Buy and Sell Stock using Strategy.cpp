// Solution for Best Time to Buy and Sell Stock using Strategy in CPP

class Solution {
public:
    using ll = long long;

    ll maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int totalDays = prices.size();

        // ---------------------------------------------------
        // STEP 1: Compute original total profit
        // ---------------------------------------------------
        ll baseProfit = 0;
        vector<ll> dailyProfit(totalDays);

        for (int day = 0; day < totalDays; day++) {
            // Profit contribution of each day
            dailyProfit[day] = 1LL * prices[day] * strategy[day];
            baseProfit += dailyProfit[day];
        }

        // ---------------------------------------------------
        // STEP 2: Sliding window to find best modification
        // ---------------------------------------------------
        ll originalWindowProfit = 0;   // Σ original profits in current window
        ll modifiedWindowProfit = 0;   // Σ profits after modification
        ll bestExtraGain = 0;          // Maximum improvement we can get

        int left = 0;

        for (int right = 0; right < totalDays; right++) {

            // Add current day's original profit into window
            originalWindowProfit += dailyProfit[right];

            // If current index belongs to second half of k-window,
            // it will become a SELL (strategy = 1)
            if (right - left + 1 > k / 2) {
                modifiedWindowProfit += prices[right];
            }

            // If window exceeds size k, shrink from the left
            if (right - left + 1 > k) {
                originalWindowProfit -= dailyProfit[left];

                // Remove price contribution from second-half mapping
                modifiedWindowProfit -= prices[left + k / 2];

                left++;
            }

            // If window size exactly equals k, evaluate gain
            if (right - left + 1 == k) {
                ll currentGain = modifiedWindowProfit - originalWindowProfit;
                bestExtraGain = max(bestExtraGain, currentGain);
            }
        }

        // ---------------------------------------------------
        // STEP 3: Final answer = base profit + best gain
        // ---------------------------------------------------
        return baseProfit + bestExtraGain;
    }
};
