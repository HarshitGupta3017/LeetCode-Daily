# Solution for Largest Color Value in a Directed Graph in PY

class Solution:
    def largestPathValue(self, colors: str, edges: List[List[int]]) -> int:
        n = len(colors)
        adj = defaultdict(list)
        indegree = [0] * n
        for u, v in edges:
            adj[u].append(v)
            indegree[v] += 1

        color_freq = [[0] * 26 for _ in range(n)]
        queue = deque()
        for i in range(n):
            if indegree[i] == 0:
                queue.append(i)
                color_freq[i][ord(colors[i]) - ord('a')] = 1

        max_color_count = 0
        visited_nodes = 0
        while queue:
            curr = queue.popleft()
            visited_nodes += 1
            max_color_count = max(max_color_count, color_freq[curr][ord(colors[curr]) - ord('a')])
            for neighbor in adj[curr]:
                for c in range(26):
                    add = 1 if ord(colors[neighbor]) - ord('a') == c else 0
                    color_freq[neighbor][c] = max(color_freq[neighbor][c], color_freq[curr][c] + add)
                indegree[neighbor] -= 1
                if indegree[neighbor] == 0:
                    queue.append(neighbor)

        return max_color_count if visited_nodes == n else -1
