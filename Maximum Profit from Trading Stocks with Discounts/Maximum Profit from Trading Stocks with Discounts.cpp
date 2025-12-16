// Solution for Maximum Profit from Trading Stocks with Discounts in CPP

class Solution {
public:

    // DFS computes DP states for employee 'current'
    void DFS(
        int current,
        vector<int>& present,
        vector<int>& future,
        unordered_map<int, vector<int>>& tree,
        vector<vector<vector<int>>>& dp,
        int budget
    ) {

        // --------------------------------------------------
        // Collect DP results of all children
        // Each child provides:
        //  - dp[child][0] → if current NOT bought
        //  - dp[child][1] → if current bought
        // --------------------------------------------------
        vector<pair<vector<int>, vector<int>>> childrenDP;

        for (int child : tree[current]) {
            DFS(child, present, future, tree, dp, budget);
            childrenDP.push_back({dp[child][0], dp[child][1]});
        }

        // --------------------------------------------------
        // Two states:
        // parentBought = 0 → parent did NOT buy
        // parentBought = 1 → parent DID buy (discount applies)
        // --------------------------------------------------
        for (int parentBought = 0; parentBought <= 1; parentBought++) {

            // Determine buying price of current employee
            int buyPrice = parentBought ? present[current] / 2 : present[current];
            int stockProfit = future[current] - buyPrice;

            // dp[current][parentBought][b]
            vector<int> bestProfit(budget + 1, 0);

            // --------------------------------------------------
            // CASE 1: Do NOT buy stock at current employee
            // Children behave as if parent did NOT buy
            // --------------------------------------------------
            vector<int> profitWithoutBuying(budget + 1, 0);

            for (auto& child : childrenDP) {
                vector<int> temp(budget + 1, 0);

                for (int used = 0; used <= budget; used++) {
                    for (int take = 0; used + take <= budget; take++) {
                        temp[used + take] = max(
                            temp[used + take],
                            profitWithoutBuying[used] + child.first[take]
                        );
                    }
                }
                profitWithoutBuying = move(temp);
            }

            bestProfit = profitWithoutBuying;

            // --------------------------------------------------
            // CASE 2: Buy stock at current employee (if affordable)
            // Children now get DISCOUNT
            // --------------------------------------------------
            if (buyPrice <= budget) {
                vector<int> profitWithBuying(budget + 1, 0);

                for (auto& child : childrenDP) {
                    vector<int> temp(budget + 1, 0);

                    for (int used = 0; used <= budget; used++) {
                        for (int take = 0; used + take <= budget; take++) {
                            temp[used + take] = max(
                                temp[used + take],
                                profitWithBuying[used] + child.second[take]
                            );
                        }
                    }
                    profitWithBuying = move(temp);
                }

                // Add profit of current stock
                for (int b = buyPrice; b <= budget; b++) {
                    bestProfit[b] = max(
                        bestProfit[b],
                        profitWithBuying[b - buyPrice] + stockProfit
                    );
                }
            }

            dp[current][parentBought] = move(bestProfit);
        }
    }

    int maxProfit(
        int n,
        vector<int>& present,
        vector<int>& future,
        vector<vector<int>>& hierarchy,
        int budget
    ) {

        // --------------------------------------------------
        // Build tree (0-based indexing)
        // --------------------------------------------------
        unordered_map<int, vector<int>> tree;
        for (auto& h : hierarchy) {
            int boss = h[0] - 1;
            int employee = h[1] - 1;
            tree[boss].push_back(employee);
        }

        // --------------------------------------------------
        // dp[u][0][b] → parent did NOT buy
        // dp[u][1][b] → parent DID buy
        // --------------------------------------------------
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(2, vector<int>(budget + 1, 0))
        );

        // Start DFS from CEO (employee 0)
        DFS(0, present, future, tree, dp, budget);

        // CEO has no parent → parentBought = 0
        int answer = 0;
        for (int b = 0; b <= budget; b++) {
            answer = max(answer, dp[0][0][b]);
        }

        return answer;
    }
};
