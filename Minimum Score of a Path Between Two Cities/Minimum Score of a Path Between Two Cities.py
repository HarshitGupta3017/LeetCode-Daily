# Solution for Minimum Score of a Path Between Two Cities in PY

class Solution:
    def minScore(self, n: int, roads: List[List[int]]) -> int:
        g = defaultdict(list)
        for u, v, w in roads:
            g[u].append((v, w))
            g[v].append((u, w))

        vis = set()
        ans = float('inf')

        def dfs(u):
            nonlocal ans
            vis.add(u)
            for v, w in g[u]:
                ans = min(ans, w)
                if v not in vis:
                    dfs(v)

        dfs(1)
        return ans
