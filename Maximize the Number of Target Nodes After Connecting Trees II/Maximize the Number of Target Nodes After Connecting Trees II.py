# Solution for Maximize the Number of Target Nodes After Connecting Trees II in PY

class Solution:
    def maxTargetNodes(self, edges1: List[List[int]], edges2: List[List[int]]) -> List[int]:
        def dfs(curr: int, parent: int, adj: dict, mark: List[int], count: List[int]):
            count[mark[curr]] += 1
            for neighbor in adj[curr]:
                if neighbor != parent:
                    mark[neighbor] = 1 - mark[curr]
                    dfs(neighbor, curr, adj, mark, count)

        n = len(edges1) + 1
        m = len(edges2) + 1

        adj1 = defaultdict(list)
        for u, v in edges1:
            adj1[u].append(v)
            adj1[v].append(u)

        adj2 = defaultdict(list)
        for u, v in edges2:
            adj2[u].append(v)
            adj2[v].append(u)

        mark1 = [-1] * n
        mark1[0] = 0
        count1 = [0, 0]
        dfs(0, -1, adj1, mark1, count1)

        mark2 = [-1] * m
        mark2[0] = 0
        count2 = [0, 0]
        dfs(0, -1, adj2, mark2, count2)

        max_from_tree2 = max(count2[0], count2[1])

        result = [count1[mark1[i]] + max_from_tree2 for i in range(n)]
        return result
