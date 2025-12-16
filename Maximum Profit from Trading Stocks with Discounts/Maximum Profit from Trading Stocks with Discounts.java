// Solution for Maximum Profit from Trading Stocks with Discounts in JAVA

class Solution {

    // --------------------------------------------------
    // DFS computes DP states for employee 'current'
    // --------------------------------------------------
    private void dfs(
        int current,
        int[] present,
        int[] future,
        Map<Integer, List<Integer>> tree,
        int[][][] dp,
        int budget
    ) {

        // Collect DP results of all children
        List<int[][]> childrenDP = new ArrayList<>();

        for (int child : tree.getOrDefault(current, new ArrayList<>())) {
            dfs(child, present, future, tree, dp, budget);
            childrenDP.add(new int[][]{ dp[child][0], dp[child][1] });
        }

        // parentBought = 0 or 1
        for (int parentBought = 0; parentBought <= 1; parentBought++) {

            int buyPrice = parentBought == 1 ? present[current] / 2 : present[current];
            int stockProfit = future[current] - buyPrice;

            int[] bestProfit = new int[budget + 1];

            // --------------------------------------------------
            // CASE 1: Do NOT buy at current employee
            // --------------------------------------------------
            int[] profitWithoutBuying = new int[budget + 1];

            for (int[][] child : childrenDP) {
                int[] next = new int[budget + 1];

                for (int used = 0; used <= budget; used++) {
                    for (int take = 0; used + take <= budget; take++) {
                        next[used + take] = Math.max(
                            next[used + take],
                            profitWithoutBuying[used] + child[0][take]
                        );
                    }
                }
                profitWithoutBuying = next;
            }

            bestProfit = profitWithoutBuying;

            // --------------------------------------------------
            // CASE 2: Buy at current employee (if affordable)
            // --------------------------------------------------
            if (buyPrice <= budget) {

                int[] profitWithBuying = new int[budget + 1];

                for (int[][] child : childrenDP) {
                    int[] next = new int[budget + 1];

                    for (int used = 0; used <= budget; used++) {
                        for (int take = 0; used + take <= budget; take++) {
                            next[used + take] = Math.max(
                                next[used + take],
                                profitWithBuying[used] + child[1][take]
                            );
                        }
                    }
                    profitWithBuying = next;
                }

                for (int b = buyPrice; b <= budget; b++) {
                    bestProfit[b] = Math.max(
                        bestProfit[b],
                        profitWithBuying[b - buyPrice] + stockProfit
                    );
                }
            }

            dp[current][parentBought] = bestProfit;
        }
    }

    // --------------------------------------------------
    // Main function
    // --------------------------------------------------
    public int maxProfit(
        int n,
        int[] present,
        int[] future,
        int[][] hierarchy,
        int budget
    ) {

        Map<Integer, List<Integer>> tree = new HashMap<>();

        for (int[] h : hierarchy) {
            int boss = h[0] - 1;
            int employee = h[1] - 1;
            tree.computeIfAbsent(boss, k -> new ArrayList<>()).add(employee);
        }

        int[][][] dp = new int[n][2][budget + 1];

        dfs(0, present, future, tree, dp, budget);

        int answer = 0;
        for (int b = 0; b <= budget; b++) {
            answer = Math.max(answer, dp[0][0][b]);
        }

        return answer;
    }
}
