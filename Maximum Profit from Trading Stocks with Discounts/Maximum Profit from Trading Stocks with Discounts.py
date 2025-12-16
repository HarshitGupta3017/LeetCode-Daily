# Solution for Maximum Profit from Trading Stocks with Discounts in PY

class Solution:
    def maxProfit(self, n, present, future, hierarchy, budget):
        from collections import defaultdict
        sys.setrecursionlimit(10**7)

        tree = defaultdict(list)
        for u, v in hierarchy:
            tree[u - 1].append(v - 1)

        dp = [[[0] * (budget + 1) for _ in range(2)] for _ in range(n)]

        def dfs(u):
            children = tree[u]
            for v in children:
                dfs(v)

            for parentBought in (0, 1):
                buyPrice = present[u] // 2 if parentBought else present[u]
                profit = future[u] - buyPrice

                # ---------- Case 1: Not buy ----------
                base = [0] * (budget + 1)
                for v in children:
                    childDP = dp[v][0]
                    new = [0] * (budget + 1)
                    for i in range(budget + 1):
                        if base[i] == 0 and i != 0:
                            continue
                        bi = base[i]
                        for j in range(budget - i + 1):
                            val = bi + childDP[j]
                            if val > new[i + j]:
                                new[i + j] = val
                    base = new

                best = base[:]

                # ---------- Case 2: Buy ----------
                if buyPrice <= budget:
                    base = [0] * (budget + 1)
                    for v in children:
                        childDP = dp[v][1]
                        new = [0] * (budget + 1)
                        for i in range(budget + 1):
                            if base[i] == 0 and i != 0:
                                continue
                            bi = base[i]
                            for j in range(budget - i + 1):
                                val = bi + childDP[j]
                                if val > new[i + j]:
                                    new[i + j] = val
                        base = new

                    for b in range(buyPrice, budget + 1):
                        val = base[b - buyPrice] + profit
                        if val > best[b]:
                            best[b] = val

                dp[u][parentBought] = best

        dfs(0)
        return max(dp[0][0])
