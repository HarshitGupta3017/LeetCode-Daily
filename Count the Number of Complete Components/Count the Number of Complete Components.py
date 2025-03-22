# Solution for Count the Number of Complete Components in PY

class Solution:

    def dfs(self, i: int, adj: defaultdict, vis: List[bool], count: List[int]):
        vis[i] = True
        count[0] += 1
        count[1] += len(adj[i])
        for ngbr in adj[i]:
            if not vis[ngbr]:
                self.dfs(ngbr, adj, vis, count)

    def countCompleteComponents(self, n: int, edges: List[List[int]]) -> int:
        adj = defaultdict(list)
        res = 0
        for u,v in edges:
            adj[u].append(v)
            adj[v].append(u)
        vis = [False] * n
        for i in range(n):
            if vis[i]:
                continue
            count = [0, 0]
            self.dfs(i, adj, vis, count)
            v, e = count[0], count[1]
            if (v * (v - 1)) == e:
                res += 1
        return res
