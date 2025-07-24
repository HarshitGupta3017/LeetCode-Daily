# Solution for Minimum Score After Removals on a Tree in PY

class Solution:
    def dfs(self, node, parent, subTreeXOR, inTime, outTime, timer, adj, nums):
        subTreeXOR[node] = nums[node]
        inTime[node] = timer[0]
        timer[0] += 1
        for ngbr in adj[node]:
            if ngbr != parent:
                self.dfs(ngbr, node, subTreeXOR, inTime, outTime, timer, adj, nums)
                subTreeXOR[node] ^= subTreeXOR[ngbr]
        outTime[node] = timer[0]
        timer[0] += 1

    def isAncestor(self, u, v, inTime, outTime):
        return inTime[v] >= inTime[u] and outTime[v] <= outTime[u]

    def getScore(self, a, b, c):
        return max(a, b, c) - min(a, b, c)

    def minimumScore(self, nums: List[int], edges: List[List[int]]) -> int:
        n = len(nums)
        adj = defaultdict(list)
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)

        subTreeXOR = [0] * n
        inTime = [0] * n
        outTime = [0] * n
        timer = [0]

        self.dfs(0, -1, subTreeXOR, inTime, outTime, timer, adj, nums)

        result = float('inf')
        for u in range(1, n):
            for v in range(u + 1, n):
                if self.isAncestor(u, v, inTime, outTime):
                    xor1 = subTreeXOR[v]
                    xor2 = subTreeXOR[u] ^ subTreeXOR[v]
                    xor3 = subTreeXOR[0] ^ xor1 ^ xor2
                elif self.isAncestor(v, u, inTime, outTime):
                    xor1 = subTreeXOR[u]
                    xor2 = subTreeXOR[v] ^ subTreeXOR[u]
                    xor3 = subTreeXOR[0] ^ xor1 ^ xor2
                else:
                    xor1 = subTreeXOR[u]
                    xor2 = subTreeXOR[v]
                    xor3 = subTreeXOR[0] ^ xor1 ^ xor2
                result = min(result, self.getScore(xor1, xor2, xor3))

        return result
