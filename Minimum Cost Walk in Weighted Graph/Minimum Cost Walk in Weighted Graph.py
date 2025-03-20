# Solution for Minimum Cost Walk in Weighted Graph in PY

class Solution:

    def __init__(self):
        self.parent = []
    
    def find(self, x: int) -> int:
        if self.parent[x] != x: 
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]

    def Union(self, x: int, y: int):
        self.parent[y] = x

    def minimumCost(self, n: int, edges: List[List[int]], query: List[List[int]]) -> List[int]:
        self.parent = list(range(n))
        cost = [-1] * n
        for i in range(n):
            self.parent[i] = i
        for u,v,w in edges:
            parent_u, parent_v = self.find(u), self.find(v)
            if parent_u != parent_v:
                self.Union(parent_u, parent_v)
                cost[parent_u] &= cost[parent_v]
            cost[parent_u] &= w
        res = []
        for s,d in query:
            parent_s, parent_d = self.find(s), self.find(d)
            if s == d: 
                res.append(0)
            elif parent_s == parent_d: 
                res.append(cost[parent_s])
            else: 
                res.append(-1)
        return res
